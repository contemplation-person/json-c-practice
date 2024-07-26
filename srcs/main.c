#include <json-c/json.h>
#include "libari.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define file_name_buffer_size 100
#define example_json_string_size 1000000

json_object *get_json_file_from(const char *path)
{
    json_object *json = json_object_from_file(path);
    if (!json)
    {
        ari_putendl_fd(ASCII_COLOR_RED, 1);
        ari_putendl_fd("error:", 2);
        ari_putendl_fd(json_util_get_last_err(), 2);
        ari_putendl_fd("\nwhat's wrong?",2);
        ari_putendl_fd(ASCII_COLOR_RESET, 1);
        exit(-1);
    }

    ari_putendl_fd((char *)json_object_get_string(json), 1);
    return json;
}

void practice_insert_string(json_object *json) 
{
    ari_title_print("\n1. json_object에 string 삽입하기 - json_object_new_string", COLOR_GREEN_CODE);

    char *key = NULL;
    char *value_string = NULL;

    key = "insert string";
    value_string = "string is good";

    json_object_object_add(json, key, json_object_new_string(value_string));

    ari_putendl_fd((char *)json_object_get_string(json), 1);

}

void practice_insert_int(json_object *json) 
{
    ari_title_print("\n2. json_object에 int 삽입하기 - json_object_new_int", COLOR_GREEN_CODE);

    char *key = "insert int";
    int value_int = 100;

    json_object_object_add(json, key, json_object_new_int(value_int));
    ari_putendl_fd((char *)json_object_get_string(json), 1);
}


void practice_insert_boolean(json_object *json) 
{
    ari_title_print("\n3. json_object에 boolean 삽입하기 - json_object_new_boolean", COLOR_GREEN_CODE);

    char *key = "insert boolean";
    int value_boolean = 1;

    json_object_object_add(json, key, json_object_new_boolean(value_boolean));
    ari_putendl_fd((char *)json_object_get_string(json), 1);
}

void practice_insert_array(json_object *json) 
{
    ari_title_print("\n4. json_object에 array 삽입하기 - json_object_new_array", COLOR_GREEN_CODE);

    json_object *json_array = json_object_new_array();
    json_object_array_add(json_array, json_object_new_string("hello array"));
    json_object_array_add(json_array, json_object_new_int(100));

    char *key = "array insert string and int";
    json_object_object_add(json, key, json_array);

    ari_putendl_fd((char *)json_object_get_string(json), 1);
}

void practice_insert_NULL(json_object *json) 
{
    ari_title_print("\n5. json_object에 NULL 삽입하기 - json_type_null", COLOR_GREEN_CODE);

    char *key = "insert NULL";

    json_object_object_add(json, key, json_type_null);
    ari_putendl_fd((char *)json_object_get_string(json), 1);
}

void practice_insertion(json_object *json)
{
    practice_insert_string(json);
    practice_insert_int(json);
    practice_insert_boolean(json);
    practice_insert_array(json);
    practice_insert_NULL(json);
}

void practice_search_array(json_object *json)
{
    ari_title_print("\n6. array 찾아 수정", COLOR_YELLOW_CODE);
    json_object *array = json_object_object_get(json, "array insert string and int");
    
    ari_title_print("origin json", COLOR_MAGENTA_CODE);
    ari_putendl_fd((char *)json_object_get_string(json), 1);
    ari_title_print("get json array property : \"array insert string and int\"", COLOR_MAGENTA_CODE);
    ari_putendl_fd((char *)json_object_get_string(array), 1);

    ari_title_print("json array add test", COLOR_MAGENTA_CODE);
    json_object_array_add(array, json_object_new_string("test"));
    ari_putendl_fd((char *)json_object_get_string(array), 1);

    ari_title_print("result", COLOR_MAGENTA_CODE);
    ari_putendl_fd((char *)json_object_get_string(json), 1);
}

void practice_search(json_object *json)
{
   practice_search_array(json);
}

int main()
{
    // json object 파일 받기
    ari_title_print("0. get json file", COLOR_GREEN_CODE);
    json_object *json = get_json_file_from( "/home/juha/json-c-practice/test/reqSet/mcp_req.json");


    practice_insertion(json);
    // system("sleep 5 && clear");
    practice_search(json);

    return 0;
}




