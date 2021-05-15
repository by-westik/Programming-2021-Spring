#ifndef LABA_2_ERROR_CPP
#define LABA_2_ERROR_CPP
#include "Error.h"

Error::Error(std::string _error)
    :error(std::move(_error))
    {
    };

std::string Error::getError(){
        return error.c_str();
};

#endif //LABA_2_ERROR_CPP






