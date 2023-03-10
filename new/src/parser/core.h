//
// Created by stf20 on 28.09.2022.
//

#ifndef C8_3DVIEWER_V1_0_0_CORE_H
#define C8_3DVIEWER_V1_0_0_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

// Include external libraries
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Include own libraries
#include "../struct/object3/object3.h"

object3_t* parse_object3_from_obj_file(const char* filename);

#ifdef __cplusplus
}
#endif

#endif  // C8_3DVIEWER_V1_0_0_CORE_H
