#include "object3.h"

object3_t* create_object3() {
  object3_t* new_object = calloc(1, sizeof(object3_t));
  if (!new_object) exit(LOW_MEMORY);

  new_object->scale.x = 1;
  new_object->scale.y = 1;
  new_object->scale.z = 1;

  return new_object;
}
