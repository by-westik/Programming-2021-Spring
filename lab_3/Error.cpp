#ifndef LAB_3_ERROR_CPP
#define LAB_3_ERROR_CPP
#include "Error.h"

Error::Error(std::string _error)
    :error(std::move(_error))
    {
    };

std::string Error::getError(){
        return error.c_str();
};

#endif //LAB_3_ERROR_CPP


