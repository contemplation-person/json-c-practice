#include "let_dancing_with_json.h"

json_object *get_json_from_file(const char *json_file_path) 
{
    json_object *json = json_object_from_file(json_file_path);
    if (!json)
    {
        ari_putendl_fd(ASCII_COLOR_RED, 1);
        ari_putendl_fd("error:", 2);
        ari_putendl_fd(json_util_get_last_err(), 2);
        ari_putendl_fd("\nwhat's wrong?",2);
        ari_putendl_fd(ASCII_COLOR_RESET, 1);

        return NULL;
    }

    return json;
}
