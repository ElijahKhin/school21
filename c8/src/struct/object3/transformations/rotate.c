#include "../../vector3/vector3.h"
#include "../object3.h"

void object3_rotate(object3_t *obj3, vector3_t angle) {
  vector3_add(&obj3->rotate, angle);

  object3_update(obj3);
}
