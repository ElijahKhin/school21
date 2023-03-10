#include "vector3.h"

void vector3_rotate(vector3_t *vector, vector3_t angle) {
  angle.x = fmod(angle.x, 360) * M_PI / 180;
  angle.y = fmod(angle.y, 360) * M_PI / 180;
  angle.z = fmod(angle.z, 360) * M_PI / 180;

  double x;
  double y = vector->y;
  double z = vector->z;

  if (fabs(angle.x) > 0.001) {
    vector->y = y * cos(angle.x) - z * sin(angle.x);
    vector->z = y * sin(angle.x) + z * cos(angle.x);
  }
  x = vector->x;
  z = vector->z;
  if (fabs(angle.y) > 0.001) {
    vector->x = x * cos(angle.y) + z * sin(angle.y);
    vector->z = -x * sin(angle.y) + z * cos(angle.y);
  }
  x = vector->x;
  y = vector->y;
  if (fabs(angle.z) > 0.001) {
    vector->x = x * cos(angle.z) - y * sin(angle.z);
    vector->y = x * sin(angle.z) + y * cos(angle.z);
  }
}
