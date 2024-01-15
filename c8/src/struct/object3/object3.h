#ifndef INC_3DVIEWER_V1_OBJECT3_H
#define INC_3DVIEWER_V1_OBJECT3_H

#ifdef __cplusplus
extern "C" {
#endif

// Include external libraries
#include <stdlib.h>

// Include own libraries
#include "../vector3/vector3.h"
#include "../other.h"

#define POLYGON_SIZE (2)
#define VERTEX_SIZE (3)

typedef struct object3_s {
  vector3_t shift;
  vector3_t rotate;
  vector3_t scale;

  list_vertex3_t list_origin_vertex3;
  list_polygon_t list_origin_polygon;

  list_vertex3_t list_vertex3;
  list_polygon_t list_polygon;
} object3_t;

object3_t* create_object3();
void object3_update(object3_t *obj3);
void free_object3(object3_t** object3);
void object3_move(object3_t *obj3, vector3_t shift);
void object3_rotate(object3_t *obj3, vector3_t angle);
void object3_scale(object3_t *obj3, vector3_t scale);


#ifdef __cplusplus
}
#endif

#endif  // INC_3DVIEWER_V1_OBJECT3_H
