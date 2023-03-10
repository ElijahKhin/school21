#include <check.h>

#include "../parser/core.h"
#include "../struct/object3/object3.h"
#include "main.h"

START_TEST(test_scale_object) {
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

  vector3_t scale = {0.1, 0.1, 0.1};
  object3_scale(object3, scale);

  double new_a[24] = {
      -1.00000 * 0.1, -1.00000 * 0.1, 1.00000 * 0.1,  1.00000 * 0.1,
      -1.00000 * 0.1, 1.00000 * 0.1,  -1.00000 * 0.1, 1.00000 * 0.1,
      1.00000 * 0.1,  1.00000 * 0.1,  1.00000 * 0.1,  1.00000 * 0.1,
      -1.00000 * 0.1, 1.00000 * 0.1,  -1.00000 * 0.1, 1.00000 * 0.1,
      1.00000 * 0.1,  -1.00000 * 0.1, -1.00000 * 0.1, -1.00000 * 0.1,
      -1.00000 * 0.1, 1.00000 * 0.1,  -1.00000 * 0.1, -1.00000 * 0.1};

  for (int i = 0; i < 24; i++) {
    ck_assert_double_eq_tol(object3->list_vertex3.vertex3[i], new_a[i], EPS);
  }

  free_object3(&object3);
}
END_TEST

Suite *create_scale_testcase() {
  Suite *s = suite_create("scale_suite");
  TCase *tc = tcase_create("scale_testcase");

  tcase_add_test(tc, test_scale_object);

  suite_add_tcase(s, tc);
  return s;
}
