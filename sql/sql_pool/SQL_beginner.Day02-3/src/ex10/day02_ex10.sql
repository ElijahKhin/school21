SELECT p1.name as person_name1, p2.name as person_name2, p1.address as common_name
FROM person AS p1, person AS p2
WHERE p1.address = p2.address AND p1.id > p2.id
order by person_name1, person_name2, common_name
