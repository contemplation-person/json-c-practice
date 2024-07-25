#include <json-c/json.h>
#include "libari.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define file_name_buffer_size 100
#define example_json_string_size 1000000

int main()
{
    // json object 파일 받기
    ari_title_print("0. get json file");

    char *json_example_pwd = "/home/juha/json-c-practice/test/reqSet/mcp_req.json";
    json_object *json = json_object_from_file(json_example_pwd);
    if (!json)
    {
        ari_putendl_fd(ASCII_COLOR_RED, 1);
        ari_putendl_fd("error:", 2);
        ari_putendl_fd(json_util_get_last_err(), 2);
        ari_putendl_fd("\nwhat's wrong?",2);
        ari_putendl_fd(ASCII_COLOR_RESET, 1);

        return -1;
    }

    ari_putendl_fd((char *)json_object_get_string(json), 1);

// ==================================================
    
    ari_title_print("\n1. json_object에 string 삽입하기 - json_object_new_string");

    char *key = NULL;
    char *value_string = NULL;

    key = "insert string";
    value_string = "string is good";

    json_object_object_add(json, key, json_object_new_string(value_string));

    ari_putendl_fd((char *)json_object_get_string(json), 1);
    
// ==================================================

    ari_title_print("\n2. json_object에 int 삽입하기 - json_object_new_int");

    key = "insert int";
    int value_int = 100;

    json_object_object_add(json, key, json_object_new_int(value_int));
    ari_putendl_fd((char *)json_object_get_string(json), 1);

// ==================================================
    
    ari_title_print("\n3. json_object에 boolean 삽입하기 - json_object_new_boolean");

    key = "insert boolean";
    int value_boolean = 1;

    json_object_object_add(json, key, json_object_new_boolean(value_boolean));
    ari_putendl_fd((char *)json_object_get_string(json), 1);

// ==================================================
    
    ari_title_print("\n4. json_object에 array 삽입하기 - json_object_new_array");

    // array 생성
    json_object *json_array = json_object_new_array();
    json_object_array_add(json_array, json_object_new_string("hello array"));
    json_object_array_add(json_array, json_object_new_int(100));

    key = "array insert string and int";
    json_object_object_add(json, key, json_array);

    //출력
    ari_putendl_fd((char *)json_object_get_string(json), 1);

// ==================================================

    ari_title_print("\n5. json_object에 NULL 삽입하기 - json_type_null");

    key = "array insert string and int";
    value_string = "string 2";

    json_object_object_add(json, key, json_type_null);
    ari_putendl_fd((char *)json_object_get_string(json), 1);

    return 0;
}

