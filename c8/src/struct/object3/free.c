#include "object3.h"

void free_object3(object3_t** object3) {
  if (!(*object3)) return;

  if ((*object3)->list_vertex3.size && (*object3)->list_vertex3.vertex3)
    free((*object3)->list_vertex3.vertex3);
  if ((*object3)->list_polygon.size && (*object3)->list_polygon.polygons)
    free((*object3)->list_polygon.polygons);

  if ((*object3)->list_origin_vertex3.size &&
      (*object3)->list_origin_vertex3.vertex3)
    free((*object3)->list_origin_vertex3.vertex3);
  if ((*object3)->list_origin_polygon.size &&
      (*object3)->list_origin_polygon.polygons)
    free((*object3)->list_origin_polygon.polygons);

  free((*object3));
}
