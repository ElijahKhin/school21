#ifndef INC_3DVIEWER_V1_OTHER_H
#define INC_3DVIEWER_V1_OTHER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum status_code_e { OK = 0, BAD, LOW_MEMORY } status_code;

typedef struct list_vertex3_s {
  unsigned long count;  // текущие кол-во строк вершин
  unsigned long size;  // реальное кол-во выделеной памяти
  double* vertex3;  // Массив с вершинами [x, y, z, ..., x, y, z]
} list_vertex3_t;

typedef struct list_polygon_s {
  unsigned long count;  // текущие кол-во строк полигонов
  unsigned long size;  // реальное кол-во выделеной памяти
  int* polygons;  // Массив с вершинами [x, y, y, z, ..., z, p, p, x]
} list_polygon_t;

#ifdef __cplusplus
}
#endif

#endif  // INC_3DVIEWER_V1_OTHER_H
