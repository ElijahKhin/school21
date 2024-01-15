#ifndef INC_3DVIEWER_V1_MAIN_H
#define INC_3DVIEWER_V1_MAIN_H

// Include system library
#include <stdlib.h>
#include <check.h>
#include <stdio.h>
#include <time.h>


// Include custom library


#define EPS 1e-6

long double get_EPS(long double true_result, long double result);
long double get_random(long double start, long double stop);
void run_testcase(Suite *testcase);

Suite *create_parser_testcase();
Suite *create_move_testcase();
Suite *create_rotate_testcase();
Suite *create_scale_testcase();

#endif  // INC_3DVIEWER_V1_MAIN_H
