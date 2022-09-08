drop schema if exists wl cascade;
create schema wl /*authorization rw*/;

-- drop schema if exists import cascade;
-- create schema import /*authorization rw*/;

create table wl.area
(
    area_id int primary key,
    name varchar,
    km2 decimal(9,2),
    geometry geometry (Polygon, 4326)
);

create table wl.file
(
    file_id serial primary key,
    filename  text,
    parameter text,
    scenario  text,
    solution  text
);

-- insert into wl.file(filename) values ('test');

create table wl.period
(
    period_id smallint,
    period_name  text,
    start_date date,
    end_date date
);

create table wl.scenariodata
(
    file_id int references wl.file(file_id),
    area_id int references wl.area(area_id),
    date    date,
    value   double precision
);


drop view if exists wl.area_json cascade;
create or replace view wl.area_json as
select a.area_id, name, km2, st_asgeojson(geometry) geometry
from wl.area a
;

drop view if exists wl.area_geojson cascade;
create or replace view wl.area_geojson as
select *
from wl.area a
;

drop view if exists wl.scenariodata_per_date cascade;
create or replace view wl.scenariodata_per_date as
select fi.sub_parameter, fi.parameter, fi.scenario, fi.solution, pe.period_id, pe.period_name, sd.date, a.area_id, a.name as area, count(*) count_value, sum(value) sum_value
from wl.scenariodata sd
join wl.area a on a.area_id=sd.area_id
join (
    select case when parameter ilike '%%availability%%' then 'availability'
            when parameter ilike '%%demand%%' then 'demand'
            when parameter ilike '%%gap%%' then 'gap'
        end sub_parameter
    , f.*
    from wl.file f
) fi on fi.file_id=sd.file_id
join wl.period pe on sd.date between pe.start_date and pe.end_date
group by fi.sub_parameter, fi.parameter, fi.scenario, fi.solution, pe.period_id, pe.period_name, sd.date, a.area_id, a.name
;

drop view if exists wl.scenariodata_series_date cascade;
create or replace view wl.scenariodata_series_date as
select sub_parameter, parameter, scenario, solution, area_id, area, array_agg(sum_value order by date) as data, array_agg(distinct date order by date) as date_agg
from  wl.scenariodata_per_date
group by sub_parameter, parameter, scenario, solution, area_id, area;

drop view if exists wl.scenariodata_agg cascade;
create or replace view wl.scenariodata_agg as
select sub_parameter, parameter, scenario, solution, period_id, period_name, area_id, area, count(*) count_value, sum(sum_value) sum_value
from wl.scenariodata_per_date
group by sub_parameter, parameter, scenario, solution, period_id, period_name, area_id, area
;

drop view if exists wl.scenariodata_series_agg cascade;
create or replace view wl.scenariodata_series_agg as
select sub_parameter, parameter, scenario, solution, area_id, area, array_agg(sum_value order by period_id) as data
from wl.scenariodata_agg
group by sub_parameter, parameter, scenario, solution, area_id, area;

drop view if exists wl.scenariodata_series_data_total cascade;
create or replace view wl.scenariodata_series_data_total as
select * from wl.scenariodata_series_date where parameter in ('waterAvailability', 'waterDemand', 'waterGap');

drop function if exists wl.scenariodata_agg_json(selected_area_id int, selected_scenario varchar, selected_solution varchar);
create or replace function wl.scenariodata_agg_json(selected_area_id int, selected_scenario varchar, selected_solution varchar) returns setof json as
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
        from wl.scenariodata_series_agg sda
        where sda.area_id=selected_area_id and sda.scenario=selected_scenario and sda.solution=selected_solution
        and sda.sub_parameter <> 'gap'
    ) j
    , (select array_agg(period_name order by period_id) period_name_agg from wl.period) pe
$$ language sql
;
-- example:
-- select * from wl.scenariodata_agg_json('altoChillon', 'SSP2','none');
-- select * from wl.scenariodata_agg_json(1, 'SSP2','none');


drop function if exists wl.scenariodata_per_date_json(selected_area_id int, selected_scenario varchar, selected_solution varchar);
create or replace function wl.scenariodata_per_date_json(selected_area_id int, selected_scenario varchar, selected_solution varchar) returns setof json as
$$
with x as (
        select *
        from wl.scenariodata_series_date sda
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
$$ language sql
;

drop function if exists wl.scenariodata_per_date_total_json(selected_area_id int, selected_scenario varchar, selected_solution varchar);
create or replace function wl.scenariodata_per_date_total_json(selected_area_id int, selected_scenario varchar, selected_solution varchar) returns setof json as
$$
with x as (
        select *
        from wl.scenariodata_series_data_total sda
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
$$ language sql
;
-- example:
-- select * from wl.scenariodata_per_date_json('altoChillon', 'SSP3','none');
-- select * from wl.scenariodata_per_date_json(1, 'SSP3','none');
