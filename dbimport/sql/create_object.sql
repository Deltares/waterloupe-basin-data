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

drop view if exists wl.scenariodata_agg cascade;
create or replace view wl.scenariodata_agg as
select fi.sub_parameter, fi.parameter, fi.scenario, fi.solution, pe.period_id, pe.period_name, sd.area, count(*) count_value, sum(value) sum_value
from wl.scenariodata sd
join (
    select case when parameter ilike '%%availability%%' then 'availability'
            when parameter ilike '%%demand%%' then 'demand'
        end sub_parameter
    , *
    from wl.file
) fi on fi.file_id=sd.file_id
join wl.period pe on sd.date between pe.start_date and pe.end_date
group by fi.sub_parameter, fi.parameter, fi.scenario, fi.solution, pe.period_id, pe.period_name, sd.area
;

drop view if exists wl.scenariodata_series_agg cascade;
create or replace view wl.scenariodata_series_agg as
select sub_parameter, parameter, scenario, solution, area, array_agg(sum_value order by period_id) as data
from wl.scenariodata_agg
group by sub_parameter, parameter, scenario, solution, area;

drop function if exists wl.scenariodata_agg_json(selected_area varchar, selected_scenario varchar, selected_solution varchar);
create or replace function wl.scenariodata_agg_json(selected_area varchar, selected_scenario varchar, selected_solution varchar) returns setof json as
$$
    select
    json_object_agg(
            'series',j.jdata
    )
    from (
        select
        json_agg(
                json_build_object(
                'name', sda.parameter
                ,'sub_parameter', sda.sub_parameter
--                 ,'period',sda.period_name
                ,'data', to_json(sda.data)
--                 ,'data', to_json(sda.*)
                )
        ) jdata
        from wl.scenariodata_series_agg sda
        where sda.area=selected_area and sda.scenario=selected_scenario and sda.solution=selected_solution
    ) j
$$ language sql
;
-- example:
-- select * from wl.scenariodata_agg_json('altoChillon', 'SSP3','none');