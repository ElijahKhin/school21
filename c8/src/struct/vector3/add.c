#include "vector3.h"

void vector3_add(vector3_t *a, vector3_t b) {
  a->x += b.x;
  a->y += b.y;
  a->z += b.z;
}
