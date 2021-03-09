#include <stdlib.h>

struct void_str{
    size_t element_size;
    size_t size;
    size_t volume;
    void* data;
    void* (*el_of_indx)(const struct void_str* const this, const size_t index);
    void* (*push_back)(struct void_str* const this);
    struct void_str* (*copy)(const struct void_str* const this);
};

struct void_str init_void_str(size_t size_of_str, size_t size_of_one_element);
struct void_str* init_void_ptr_str(size_t size_of_str, size_t size_of_one_element);

void delete_void_str(struct void_str str);
void delete_void_ptr_str(struct void_str* str);
