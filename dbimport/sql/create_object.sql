drop schema if exists {db_schema} cascade;
create schema {db_schema} /*authorization rw*/;

create table {db_schema}.area
(
    area_id int,
    name varchar,
    km2 decimal(9,2),
    geometry geometry (Polygon, 4326),
    primary key (area_id)
);

create table {db_schema}.file
(
    file_id serial primary key,
    filename  text,
    users text,
    parameter text,
    scenario  text,
    solution  text
);

create table {db_schema}.period
(
    period_id smallint primary key,
    period_name  text,
    start_date date,
    end_date date
);

create table {db_schema}.scenariodata
(
    file_id int references {db_schema}.file(file_id),
    area_id int references {db_schema}.area(area_id),
    period_id int,-- references {db_schema}.period(period_id),
    date    date,
    value   double precision
);

drop view if exists {db_schema}.list_parameter cascade;
create or replace view {db_schema}.list_parameter as select distinct parameter from {db_schema}.file order by 1;

drop view if exists {db_schema}.list_users cascade;
create or replace view {db_schema}.list_users as select distinct users from {db_schema}.file where parameter not ilike 'wateravailability' order by 1;

drop view if exists {db_schema}.list_scenario cascade;
create or replace view {db_schema}.list_scenario as select distinct scenario from  {db_schema}.file order by 1;

drop view if exists {db_schema}.list_solution cascade;
create or replace view {db_schema}.list_solution as select distinct solution from  {db_schema}.file order by 1;

drop view if exists {db_schema}.scenariodata_per_date cascade;
create or replace view {db_schema}.scenariodata_per_date as
select fi.sub_parameter, fi.parameter, fi.users, fi.scenario, fi.solution, pe.period_id, pe.period_name, sd.date, a.area_id, a.name as area, a.km2 as area_km2, a.geometry, count(*) count_value, sum(sd.value) as value
from {db_schema}.scenariodata sd
join {db_schema}.area a on a.area_id=sd.area_id
join (
    select case when parameter ilike '%%availability%%' then 'availability'
            when parameter ilike '%%demand%%' then 'demand'
            when parameter ilike '%%gap%%' then 'gap'
        end sub_parameter
    , f.*
    from {db_schema}.file f
) fi on fi.file_id=sd.file_id
join {db_schema}.period pe on sd.date between pe.start_date and pe.end_date
group by fi.sub_parameter, fi.parameter, fi.users, fi.scenario, fi.solution, pe.period_id, pe.period_name, sd.date, a.area_id, a.km2, a.geometry, a.name;

drop view if exists {db_schema}.scenariodata_series_date cascade;
create or replace view {db_schema}.scenariodata_series_date as
select sub_parameter, parameter, scenario, solution, area_id, area, array_agg(value order by date) as data, array_agg(distinct date order by date) as date_agg
from  {db_schema}.scenariodata_per_date
group by sub_parameter, parameter, scenario, solution, area_id, area;

drop view if exists {db_schema}.scenariodata_agg cascade;
create or replace view {db_schema}.scenariodata_agg as
select sub_parameter, parameter, users, scenario, solution, period_id, period_name, area_id, area, area_km2, count(*) count_value, sum(value) as value, geometry
from {db_schema}.scenariodata_per_date
group by sub_parameter, parameter, users, scenario, solution, period_id, period_name, area_id, area, area_km2, geometry;

drop view if exists {db_schema}.scenariodata_series_agg cascade;
create or replace view {db_schema}.scenariodata_series_agg as
select sub_parameter, parameter, users, scenario, solution, area_id, area, array_agg(value order by period_id) as data
from {db_schema}.scenariodata_agg
group by sub_parameter, parameter, users, scenario, solution, area_id, area;

drop view if exists {db_schema}.scenariodata_series_data_total cascade;
create or replace view {db_schema}.scenariodata_series_data_total as
select * from {db_schema}.scenariodata_series_date where parameter in ('waterAvailability', 'waterDemand', 'waterGap');

drop view if exists {db_schema}.scenariodata_per_period cascade;
create or replace view {db_schema}.scenariodata_per_period as
with data_with_period as(
    select fi.parameter, fi.users, fi.scenario, fi.solution, pe.period_id, pe.period_name, ar.area_id, ar.name as area, ar.km2 as area_km2, sc.value, ar.geometry
    , 'The risk for {name} is {value}.' as "popupHTML"
    from {db_schema}.scenariodata sc
    join {db_schema}.file fi on fi.file_id=sc.file_id
    join {db_schema}.period pe on pe.period_id=sc.period_id
    join {db_schema}.area ar on ar.area_id=sc.area_id
)
, data_with_date as (
    select parameter, users, scenario, solution, period_id, period_name, area_id, area, area_km2, value, geometry
        , 'The risk for {name} is {value}.' as "popupHTML"
    from {db_schema}.scenariodata_agg sd
)
select * from data_with_period
union all
select * from data_with_date
;

drop view if exists {db_schema}.scenariodata_risk_per_period cascade;
create or replace view {db_schema}.scenariodata_risk_per_period as
select fi.filename, fi.users, fi.scenario, fi.solution, pe.period_id, pe.period_name, ar.area_id, ar.name as area, ar.km2 as area_km2, sc.value as risk_value, ar.geometry
, 'The risk for {name} is {value}.' as "popupHTML"
from {db_schema}.scenariodata sc
join {db_schema}.file fi on fi.file_id=sc.file_id
join {db_schema}.period pe on pe.period_id=sc.period_id
join {db_schema}.area ar on ar.area_id=sc.area_id
where fi.parameter in ('risk', 'waterScarcityIndex');

drop function if exists {db_schema}.scenariodata_agg_json(selected_area_id int, selected_scenario varchar, selected_solution varchar, selected_users varchar);
create or replace function {db_schema}.scenariodata_agg_json(selected_area_id int, selected_scenario varchar, selected_solution varchar, selected_users varchar) returns setof json as
$$
    select
   json_build_object(
     		'xAxis', json_build_object(
     			'type', 'category'
     			,'data',to_json(pe.period_name_agg) )
            ,'series',j.jdata
    )
    from (
        select
        json_agg(
                json_build_object(
                'name', sda.parameter
                ,'stack', sda.sub_parameter
                ,'data', to_json(sda.data)
                ,'type', 'bar'
                )
        ) jdata
        from {db_schema}.scenariodata_series_agg sda
        where sda.area_id=selected_area_id and sda.scenario=selected_scenario and sda.solution=selected_solution
        and sda.sub_parameter <> 'gap'
        and sda.users=selected_users
    ) j
    , (select array_agg(period_name order by period_id) period_name_agg from {db_schema}.period) pe
$$ language sql
;
-- example:
-- select * from {db_schema}.scenariodata_agg_json('1', 'SSP2','none','Agriculture');

drop function if exists {db_schema}.scenariodata_per_date_json(selected_area_id int, selected_scenario varchar, selected_solution varchar);
create or replace function {db_schema}.scenariodata_per_date_json(selected_area_id int, selected_scenario varchar, selected_solution varchar) returns setof json as
$$
with x as (
        select *
        from {db_schema}.scenariodata_series_date sda
        where sda.area_id=selected_area_id and sda.scenario=selected_scenario and sda.solution=selected_solution
)
    select
   json_build_object(
   			'xAxis', json_build_object(
   					'type', 'category'
   				   ,'data', to_json(da.date_agg)
   				)
            ,'series',j.jdata
    )
    from (
        select
        json_agg(
                json_build_object(
                 'type', 'line'
                ,'name', x.parameter
                ,'sub_parameter', x.sub_parameter
                ,'data', to_json(x.data)
                )
        ) jdata
        from x
    ) j
    , (select date_agg from x limit 1) da
$$ language sql;

drop function if exists {db_schema}.scenariodata_per_date_total_json(selected_area_id int, selected_scenario varchar, selected_solution varchar);
create or replace function {db_schema}.scenariodata_per_date_total_json(selected_area_id int, selected_scenario varchar, selected_solution varchar) returns setof json as
$$
with x as (
        select *
        from {db_schema}.scenariodata_series_data_total sda
        where sda.area_id=selected_area_id and sda.scenario=selected_scenario and sda.solution=selected_solution
)
    select
   json_build_object(
   			'xAxis', json_build_object(
   					'type', 'category'
   				   ,'data', to_json(da.date_agg)
   				)
            ,'series',j.jdata
    )
    from (
        select
        json_agg(
                json_build_object(
                 'type', 'line'
                ,'name', x.parameter
                ,'sub_parameter', x.sub_parameter
                ,'data', to_json(x.data)
                )
        ) jdata
        from x
    ) j
    , (select date_agg from x limit 1) da
$$ language sql;
-- example:
-- select * from {db_schema}.scenariodata_per_date_json('altoChillon', 'SSP3','none');
-- select * from {db_schema}.scenariodata_per_date_json(1, 'SSP3','none');

drop function if exists {db_schema}.risk_data_geojson(period_id int, scenario varchar, solution varchar, users varchar);
create or replace function {db_schema}.risk_data_geojson(period_id int, scenario varchar, solution varchar='none', users varchar='none') returns setof jsonb as
$$
    with x as (
        select *
        from (
            select area_id, area, area_km2, risk_value, "popupHTML", geometry
            ,sc.period_id sc_period_id, sc.scenario sc_scenario, sc.solution sc_solution, sc.users sc_users
            from {db_schema}.scenariodata_risk_per_period sc
        ) sub
        where sc_period_id=period_id
        and sc_scenario=scenario
        and sc_solution=coalesce(solution, 'none')
        and sc_users=users
    )
    select jsonb_build_object(
        'type','FeatureCollection'
        ,'features', json_agg(st_asgeojson(x.*)::json)
        )
    from x;
$$ language sql
;
-- example:
-- select * from {db_schema}.risk_data_geojson(1,'SSP2', 'none', 'Agriculture');


drop function if exists {db_schema}.all_data_geojson(parameter varchar, period_id int, scenario varchar, solution varchar, users varchar);
create or replace function {db_schema}.all_data_geojson(parameter varchar, period_id int, scenario varchar, solution varchar='none', users varchar='none') returns setof jsonb as
$$
    with x as (
        select *
        from (
            select area_id, area, area_km2, value, "popupHTML", geometry
            ,sc.period_id sc_period_id, sc.scenario sc_scenario, sc.solution sc_solution, sc.users sc_users, sc.parameter sc_parameter
            from {db_schema}.scenariodata_per_period sc
        ) sub
        where sc_period_id=period_id
        and sc_scenario=scenario
        and sc_solution=coalesce(solution, 'none')
        and sc_users=users
        and sc_parameter=parameter
    )
    select jsonb_build_object(
        'type','FeatureCollection'
        ,'features', json_agg(st_asgeojson(x.*)::json)
        )
    from x;
$$ language sql
;
-- example:
-- select * from {db_schema}.all_data_geojson('waterDemand', 1,'SSP2', 'none', 'none');
-- select * from {db_schema}.all_data_geojson('waterGapScore', 1,'SSP2', 'none', 'Agriculture');
