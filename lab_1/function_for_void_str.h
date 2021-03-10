#include "void_str.h"
#include <stdio.h>

struct void_str* concatenation_2(struct void_str* void_str_1, const struct void_str* const void_str_2);
struct void_str* substring(const struct void_str* const this, const size_t start, const size_t end);
size_t find_substr_r(const struct void_str* const this, const struct void_str* substring);
size_t find_substr_unr(const struct void_str* const this, const struct void_str* substring);
