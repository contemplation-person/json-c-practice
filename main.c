#include <json-c/json.h>
#include "libari/libari.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define file_name_buffer_size 100
#define example_json_string_size 1000000

int main()
{
    /*
    char file_name[file_name_buffer_size] = {0,};
    int file_read_cnt = 0;
    int prefix_size = 0;

    strcat(file_name, "./test/reqSet/");
    prefix_size = strlen(file_name);

// good : printf("file_name : %s\n", file_name); //test
    file_read_cnt = read(0, &file_name[prefix_size], file_name_buffer_size - prefix_size);
    if (!file_read_cnt) 
    {
        char *error_msg = "read is error\n";
        ari_putendl_fd(error_msg, 2);
        return -1;
    }
// good : printf("total_name: %s\n", file_name);

    */
// ==================================================
    
    // char example_json_string[example_json_string_size] = {0,};
    // read(0, example_json_string, example_json_string_size);
    // ari_putendl_fd(example_json_string, 1);   //good

    //json_object *json = json_object_from_file("./test/reqSet/mcp_req.json");
    json_object *json = json_object_from_file("/home/juha/json-c-practice/test/reqSet/mcp_req.json");
    
    if (!json)
    {
        ari_putendl_fd("error", 2);
        ari_putendl_fd(json_util_get_last_err(), 2);
        ari_putendl_fd("\nwhat?",2);

        return -1;
    }

    ari_putendl_fd("good\n", 1);
    ari_putendl_fd((char *)json_object_get_string(json), 1);

    return 0;
}
