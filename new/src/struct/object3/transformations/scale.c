#include "../object3.h"

void object3_scale(object3_t *obj3, vector3_t scale) {
  if (fabs(scale.x) > 1e-6) obj3->scale.x *= scale.x;
  if (fabs(scale.y) > 1e-6) obj3->scale.y *= scale.y;
  if (fabs(scale.z) > 1e-6) obj3->scale.z *= scale.z;

  object3_update(obj3);
}
