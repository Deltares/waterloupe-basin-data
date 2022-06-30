drop schema if exists wl cascade;
create schema wl /*authorization rw*/;

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
    area    text,
    date    date,
    value   double precision
);

drop view if exists wl.scenariodata_per_date cascade;
create or replace view wl.scenariodata_per_date as
select fi.sub_parameter, fi.parameter, fi.scenario, fi.solution, pe.period_id, pe.period_name, sd.date, sd.area, count(*) count_value, sum(value) sum_value
from wl.scenariodata sd
join (
    select case when parameter ilike '%%availability%%' then 'availability'
            when parameter ilike '%%demand%%' then 'demand'
        end sub_parameter
    , *
    from wl.file
) fi on fi.file_id=sd.file_id
join wl.period pe on sd.date between pe.start_date and pe.end_date
group by fi.sub_parameter, fi.parameter, fi.scenario, fi.solution, pe.period_id, pe.period_name, sd.date, sd.area
;

drop view if exists wl.scenariodata_series_date cascade;
create or replace view wl.scenariodata_series_date as
select sub_parameter, parameter, scenario, solution, area, array_agg(sum_value order by date) as data, array_agg(distinct date order by date) as date_agg
from  wl.scenariodata_per_date
group by sub_parameter, parameter, scenario, solution, area;

drop view if exists wl.scenariodata_agg cascade;
create or replace view wl.scenariodata_agg as
select sub_parameter, parameter, scenario, solution, period_id, period_name, area, count(*) count_value, sum(sum_value) sum_value
from wl.scenariodata_per_date
group by sub_parameter, parameter, scenario, solution, period_id, period_name, area
;

drop view if exists wl.scenariodata_series_agg cascade;
create or replace view wl.scenariodata_series_agg as
select sub_parameter, parameter, scenario, solution, area, array_agg(sum_value order by period_id) as data
from wl.scenariodata_agg
group by sub_parameter, parameter, scenario, solution, area;

drop view if exists wl.scenariodata_series_data_total cascade;
create or replace view wl.scenariodata_series_data_total as 
select * from wl.scenariodata_series_date where parameter in ('waterAvailability', 'waterDemand', 'waterGap');

drop function if exists wl.scenariodata_agg_json(selected_area varchar, selected_scenario varchar, selected_solution varchar);
create or replace function wl.scenariodata_agg_json(selected_area varchar, selected_scenario varchar, selected_solution varchar) returns setof json as
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
        where sda.area=selected_area and sda.scenario=selected_scenario and sda.solution=selected_solution
    ) j
    , (select array_agg(period_name order by period_id) period_name_agg from wl.period) pe
$$ language sql
;
-- example:
-- select * from wl.scenariodata_agg_json('altoChillon', 'SSP2','none');


drop function if exists wl.scenariodata_per_date_json(selected_area varchar, selected_scenario varchar, selected_solution varchar);
create or replace function wl.scenariodata_per_date_json(selected_area varchar, selected_scenario varchar, selected_solution varchar) returns setof json as
$$
with x as (
        select *
        from wl.scenariodata_series_date sda
        where sda.area=selected_area and sda.scenario=selected_scenario and sda.solution=selected_solution
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

drop function if exists wl.scenariodata_per_date_total_json(selected_area varchar, selected_scenario varchar, selected_solution varchar);
create or replace function wl.scenariodata_per_date_total_json(selected_area varchar, selected_scenario varchar, selected_solution varchar) returns setof json as
$$
with x as (
        select *
        from wl.scenariodata_series_data_total sda
        where sda.area=selected_area and sda.scenario=selected_scenario and sda.solution=selected_solution
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
