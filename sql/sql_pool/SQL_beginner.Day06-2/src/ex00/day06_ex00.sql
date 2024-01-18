create table person_discounts (
	id bigint primary key,
	person_id bigint not null,
	pizzeria_id bigint not null,
	discount numeric(5, 2),
	constraint ft_person_discounts_person_id foreign key (person_id) references person(id),
	constraint ft_person_discounts_pizzeria_id foreign key (pizzeria_id) references pizzeria(id)
)
