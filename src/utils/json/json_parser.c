#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

char* get_variable_from_json(char *json_string, char *variable_name) {
    cJSON *json = cJSON_Parse(json_string);
    if (json == NULL) {
        printf("JSON parsing error\n");
        return NULL;
    }

    cJSON *variable_item = cJSON_GetObjectItem(json, variable_name);

    cJSON_Delete(json);

    return variable_item->valuestring;
}
