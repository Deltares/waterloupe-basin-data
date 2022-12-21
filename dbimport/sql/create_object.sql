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
