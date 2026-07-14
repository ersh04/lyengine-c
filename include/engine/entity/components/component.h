#include "project.h"

#ifndef ENGINE_COMPONENTS_H
#define ENGINE_COMPONENTS_H

typedef struct
{
    char* component_names[MAX_COMPONENTS_PER_ENTITY];
    char* component_data[MAX_COMPONENTS_PER_ENTITY];
} EntitiesComponentsArray;

#endif /* ENGINE_COMPONENTS_H */