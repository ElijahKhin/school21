#include "object3.h"

void object3_update(object3_t *obj3) {
  for (unsigned long int i = 0; i < obj3->list_vertex3.size; i += VERTEX_SIZE) {
    vector3_t tmp = {obj3->list_origin_vertex3.vertex3[i + 0] * obj3->scale.x,
                     obj3->list_origin_vertex3.vertex3[i + 1] * obj3->scale.y,
                     obj3->list_origin_vertex3.vertex3[i + 2] * obj3->scale.z};

    vector3_rotate(&tmp, obj3->rotate);
    obj3->list_vertex3.vertex3[i + 0] = tmp.x + obj3->shift.x;
    obj3->list_vertex3.vertex3[i + 1] = tmp.y + obj3->shift.y;
    obj3->list_vertex3.vertex3[i + 2] = tmp.z + obj3->shift.z;
  }
}
