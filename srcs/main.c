#include <json-c/json.h>
#include "libari.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define file_name_buffer_size 100
#define example_json_string_size 1000000

// ======================================================
void ari_json_object_print(json_object *json)
{
    const char *print_string = json_object_to_json_string_ext(json, JSON_C_TO_STRING_PRETTY);

    ari_putendl_fd(print_string, 1);
}

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

    ari_json_object_print(json);
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

    ari_json_object_print(json);

}

void practice_insert_int(json_object *json) 
{
    ari_title_print("\n2. json_object에 int 삽입하기 - json_object_new_int", COLOR_GREEN_CODE);

    char *key = "insert int";
    int value_int = 100;

    json_object_object_add(json, key, json_object_new_int(value_int));
    ari_json_object_print(json);
}


void practice_insert_boolean(json_object *json) 
{
    ari_title_print("\n3. json_object에 boolean 삽입하기 - json_object_new_boolean", COLOR_GREEN_CODE);

    char *key = "insert boolean";
    int value_boolean = 1;

    json_object_object_add(json, key, json_object_new_boolean(value_boolean));
    ari_json_object_print(json);
}

void practice_insert_array(json_object *json) 
{
    ari_title_print("\n4. json_object에 array 삽입하기 - json_object_new_array", COLOR_GREEN_CODE);

    json_object *json_array = json_object_new_array();
    json_object_array_add(json_array, json_object_new_string("hello array"));
    json_object_array_add(json_array, json_object_new_int(100));

    char *key = "array insert string and int";
    json_object_object_add(json, key, json_array);

    ari_json_object_print(json);
}

void practice_insert_NULL(json_object *json) 
{
    ari_title_print("\n5. json_object에 NULL 삽입하기 - json_type_null", COLOR_GREEN_CODE);

    char *key = "insert NULL";

    json_object_object_add(json, key, json_type_null);
    ari_json_object_print(json);
}

void practice_insertion(json_object *json)
{
    practice_insert_string(json);
    practice_insert_int(json);
    practice_insert_boolean(json);
    practice_insert_array(json);
    practice_insert_NULL(json);
}

// ======================================================

void practice_get_array(json_object *json)
{
    json_object *array = json_object_object_get(json, "array insert string and int");

    ari_title_print("\n6. array 찾아 수정", COLOR_YELLOW_CODE);
    ari_title_print("origin json", COLOR_MAGENTA_CODE);

    ari_json_object_print(json);

    ari_title_print("get json array property : \"array insert string and int\"", COLOR_MAGENTA_CODE);
    ari_putendl_fd((char *)json_object_get_string(array), 1);

    ari_title_print("json array add test", COLOR_MAGENTA_CODE);

    json_object_array_add(array, json_object_new_string("test"));
    ari_putendl_fd((char *)json_object_get_string(array), 1);

    ari_title_print("result", COLOR_MAGENTA_CODE);
    ari_json_object_print(json);
}

void practice_get_object(json_object *json)
{
    json_object *object = json_object_get(json);

    ari_title_print("\n7. object의 횟수를 늘려 권한 획득", COLOR_YELLOW_CODE);
    
    ari_title_print("origin json", COLOR_MAGENTA_CODE);
    ari_json_object_print(json);

    ari_title_print("get json object property", COLOR_MAGENTA_CODE);
    ari_json_object_print(object);

    // object를 생성했으면 바로 지워줄 것
    json_object_put(object);
}

/*
void practice_get_userdata(json_object *json)
{
    const char *user_data;

    ari_title_print("\n8.userdata 찾기", COLOR_YELLOW_CODE);
    // this is null
    user_data = json_object_get_userdata(json);
    if (user_data)
    {
        ari_putendl_fd("json_object_get_userdata is exist", 1);
        return;
    }

    ari_putendl_fd("json_object_get_userdata is exist : empty", 1);
}
*/

void practice_get_boolean(json_object *json)
{
    ari_title_print("\n9. boolean 찾기", COLOR_YELLOW_CODE);
    
    json_object *object_boolean = NULL;

    json_object_object_get_ex(json, "insert boolean", &object_boolean);
    if (json_object_get_boolean(object_boolean))
    {
        ari_putendl_fd("true", 1);
        return;
    }
    
    ari_putendl_fd("false", 1);
}

void practice_get_int(json_object *json)
{
    json_object *object_int = NULL;

    ari_title_print("\n10. int 찾기", COLOR_YELLOW_CODE);
    
    json_object_object_get_ex(json, "insert int", &object_int);
    printf("json_object_get_int : %d\n", json_object_get_int(object_int));

    ari_title_print("origin print", COLOR_MAGENTA_CODE);
    ari_json_object_print(json);

    ari_title_print("object_int print", COLOR_MAGENTA_CODE);
    ari_json_object_print(object_int);

    ari_title_print("after json print", COLOR_MAGENTA_CODE);
    ari_json_object_print(json);
}

void practice_get_type(json_object *json)
{
    ari_title_print("\n10. type 찾기", COLOR_YELLOW_CODE);
    
    ari_title_print("what type is json_object", COLOR_MAGENTA_CODE);
    if(json_type_object == json_object_get_type(json))
    {
        ari_title_print("this is object type", COLOR_MAGENTA_CODE);
        return ;
    }

    ari_title_print("this is unknown type", COLOR_MAGENTA_CODE);
}

void practice_get(json_object *json)
{
    // object -> array로 달려있는 걸 떼는 것,
    // 즉 트리의 루트에서 떼면 당연히 없다.
    practice_get_array(json);
    practice_get_object(json);
    // practice_get_userdata(json);
    practice_get_boolean(json);
    practice_get_int(json);
    practice_get_type(json);
}

// ======================================================

int main()
{
    // json object 파일 받기
    ari_title_print("0. get json file", COLOR_GREEN_CODE);
    json_object *json = get_json_file_from( "/home/juha/json-c-practice/test/reqSet/mcp_req.json");

    practice_insertion(json);
    // system("sleep 5 && clear");
    // system("clear");

    practice_get(json);
    // system("sleep 5 && clear");
    
    json_object_put(json);

    return 0;
}

