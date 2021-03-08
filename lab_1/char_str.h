#include <stdlib.h>

struct char_str{
    size_t size;
    size_t volume;
    char *data;
    char* (*el_of_indx)(const struct char_str* const this, const size_t index);
    char (*push_back)(struct char_str* const this, char value);
    struct char_str* (*copy)(const struct char_str* const this);
};

struct char_str init_char_str(size_t size_of_str);
struct char_str* init_char_ptr_str(size_t size_of_str);

void delete_char_str(struct char_str str);
void delete_char_ptr_str(struct char_str* str);