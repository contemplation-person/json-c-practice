#include "libari.h"

void ari_title_print(const char *string) 
{
    ari_putendl_fd(ASCII_COLOR_GREEN, 1);
    ari_putstr_fd(string, 1);
    ari_putendl_fd(ASCII_COLOR_RESET, 1);
}
