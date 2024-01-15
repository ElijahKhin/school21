#include "../object3.h"

void object3_move(object3_t *obj3, vector3_t shift) {
  vector3_add(&obj3->shift, shift);
  object3_update(obj3);
}
