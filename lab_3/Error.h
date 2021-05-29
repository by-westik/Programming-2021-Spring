#define LABA_2_ERROR_H

class Error{
private:
    std::string error;
public:
    Error(std::string _error);
    std::string getError();
};

#endif //LABA_2_ERROR_H



