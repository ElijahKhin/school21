create sequence if not exists seq_person_discounts start 1;
select setval('seq_person_discounts', (select max(id) from person_discounts));
alter table person_discounts
alter column id set default nextval('seq_person_discounts');
