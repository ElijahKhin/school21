//
// Created by stf20 on 28.09.2022.
//

#include "core.h"

#define BUF_SIZE (1024 * 16)

void parse_size_object3_from_obj_file(FILE* file, object3_t* object3);
void parse_vertex3_from_obj_file(FILE* file, list_vertex3_t* list_vertex3);
void parse_polygon_from_obj_file(FILE* file, list_polygon_t* list_polygon);
void normalize_vertex3(list_vertex3_t* list_vertex3, double max_size);

object3_t* parse_object3_from_obj_file(const char* filename) {
  FILE* file = fopen(filename, "r");
  if (!file) return NULL;

  object3_t* new_object = create_object3();

  parse_size_object3_from_obj_file(file, new_object);
  fseek(file, 0, SEEK_SET);

  parse_vertex3_from_obj_file(file, &new_object->list_origin_vertex3);
  fseek(file, 0, SEEK_SET);

  parse_polygon_from_obj_file(file, &new_object->list_origin_polygon);

  fclose(file);

  new_object->list_vertex3.size = new_object->list_origin_vertex3.size;
  new_object->list_polygon.size = new_object->list_origin_polygon.size;

  new_object->list_vertex3.count = new_object->list_origin_vertex3.count;
  new_object->list_polygon.count = new_object->list_origin_polygon.count;

  new_object->list_vertex3.vertex3 =
      calloc(new_object->list_vertex3.size, sizeof(double));
  if (!new_object->list_vertex3.vertex3) {
    free_object3(&new_object);
    exit(LOW_MEMORY);
  }

  new_object->list_polygon.polygons =
      calloc(new_object->list_polygon.size, sizeof(int));
  if (!new_object->list_polygon.polygons) {
    free_object3(&new_object);
    exit(LOW_MEMORY);
  }

  for (unsigned long i = 0; i < new_object->list_origin_vertex3.size; i++) {
    new_object->list_vertex3.vertex3[i] =
        new_object->list_origin_vertex3.vertex3[i];
  }

  for (unsigned long i = 0; i < new_object->list_origin_polygon.size; i++) {
    new_object->list_polygon.polygons[i] =
        new_object->list_origin_polygon.polygons[i];
  }

  return new_object;
}

void parse_size_object3_from_obj_file(FILE* file, object3_t* object3) {
  object3->list_origin_vertex3.size = 0;
  object3->list_origin_polygon.size = 0;

  char buff[BUF_SIZE];
  while (fgets(buff, BUF_SIZE, file))
    if (buff[0] == 'v' && buff[1] == ' ') {
      object3->list_origin_vertex3.count++;
      object3->list_origin_vertex3.size += VERTEX_SIZE;
    } else if (buff[0] == 'f' && buff[1] == ' ') {
      object3->list_origin_polygon.count++;
      for (char* tmp = buff; *tmp; tmp++)
        if (*tmp == ' ' && isdigit(*(tmp + 1))) {
          object3->list_origin_polygon.size += POLYGON_SIZE;
        }
    }

  object3->list_origin_vertex3.vertex3 =
      calloc(object3->list_origin_vertex3.size, sizeof(double));
  if (!object3->list_origin_vertex3.vertex3) {
    free_object3(&object3);
    exit(LOW_MEMORY);
  }

  object3->list_origin_polygon.polygons =
      calloc(object3->list_origin_polygon.size, sizeof(int));
  if (!object3->list_origin_polygon.polygons) {
    free_object3(&object3);
    exit(LOW_MEMORY);
  }
}

void parse_vertex3_from_obj_file(FILE* file, list_vertex3_t* list_vertex3) {
  char buff[BUF_SIZE];

  double max_vertex = 0;
  for (unsigned int i = 0; i < list_vertex3->size;) {
    fgets(buff, BUF_SIZE, file);

    if (buff[0] == 'v' && buff[1] == ' ') {
      sscanf(buff + 2, "%lf%lf%lf", list_vertex3->vertex3 + i,
             list_vertex3->vertex3 + i + 1, list_vertex3->vertex3 + i + 2);
      for (int z = 0; z < VERTEX_SIZE; z++)
        if (fabs(*(list_vertex3->vertex3 + i + z)) > max_vertex)
          max_vertex = fabs(*(list_vertex3->vertex3 + i + z));
      i += VERTEX_SIZE;
    }
  }

  normalize_vertex3(list_vertex3, max_vertex);
}

void normalize_vertex3(list_vertex3_t* list_vertex3, double max_size) {
  for (unsigned int i = 0; i < list_vertex3->size; i++) {
    list_vertex3->vertex3[i] /= max_size;
  }
}

void parse_polygon_from_obj_file(FILE* file, list_polygon_t* list_polygon) {
  char buff[BUF_SIZE];

  for (unsigned int i = 0; i < list_polygon->size;) {
    fgets(buff, sizeof(buff), file);

    if (buff[0] == 'f' && buff[1] == ' ') {
      unsigned int start_i = i;

      for (char* tmp = buff + 1; *tmp; tmp++) {
        while (*tmp == ' ' && isdigit(*(tmp + 1))) {
          tmp++;
          if ((i - start_i) >= 2) {
            list_polygon->polygons[i] = list_polygon->polygons[i - 1];
            i++;
          }
          list_polygon->polygons[i++] = strtoul(tmp, &tmp, 10) - 1;
        }
      }
      list_polygon->polygons[i] = list_polygon->polygons[i - 1];
      i++;
      list_polygon->polygons[i] = list_polygon->polygons[start_i];
      i++;
    }
  }
}
