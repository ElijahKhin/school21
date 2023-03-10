#ifndef INC_3DVIEWER_V1_VECTOR3_H
#define INC_3DVIEWER_V1_VECTOR3_H

#ifdef __cplusplus
extern "C" {
#endif

// Include external libraries
#include <math.h>

// Include own libraries


typedef struct vector3_s {
  double x;
  double y;
  double z;
} vector3_t;

void vector3_add(vector3_t *a, vector3_t b);
void vector3_rotate(vector3_t *a, vector3_t b);

#ifdef __cplusplus
}
#endif

#endif  // INC_3DVIEWER_V1_VECTOR3_H
