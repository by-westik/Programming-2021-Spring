#include "void_str.h"
#include <stdio.h>

struct void_str* concatenation(struct void_str* void_str_1, const struct void_str* const void_str_2);
struct void_str* substring(const struct void_str* const this, const size_t start, const size_t end);
size_t find_substr(const struct void_str* const this, const struct void_str* substring, int function(int));
struct void_str* delete_all_sub_str(struct void_str* this, const struct void_str* const sub_str);
