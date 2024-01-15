#include <check.h>

#include "../parser/core.h"
#include "../struct/object3/object3.h"
#include "main.h"

START_TEST(test_load_object) {
  object3_t *object3 = parse_object3_from_obj_file("./obj/cube.obj");
  ck_assert_int_eq(object3->list_polygon.count, 12);
  ck_assert_int_eq(object3->list_vertex3.count, 8);

  ck_assert_int_eq(object3->list_polygon.size, 72);
  ck_assert_int_eq(object3->list_vertex3.size, 24);

  double a[24] = {-1.00000, -1.00000, 1.00000,  1.00000, -1.00000, 1.00000,
                  -1.00000, 1.00000,  1.00000,  1.00000, 1.00000,  1.00000,
                  -1.00000, 1.00000,  -1.00000, 1.00000, 1.00000,  -1.00000,
                  -1.00000, -1.00000, -1.00000, 1.00000, -1.00000, -1.00000};

  for (int i = 0; i < 24; i++) {
    ck_assert_double_eq_tol(object3->list_vertex3.vertex3[i], a[i], EPS);
  }

  free_object3(&object3);
}
END_TEST

Suite *create_parser_testcase() {
  Suite *s = suite_create("parser_suite");
  TCase *tc = tcase_create("parser_testcase");

  tcase_add_test(tc, test_load_object);

  suite_add_tcase(s, tc);
  return s;
}
