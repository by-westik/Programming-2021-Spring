
#ifndef LABA_2_CLASSESFORSTACK_H
#define LABA_2_CLASSESFORSTACK_H

class Student{
private:
    const char *firstName;
    const char *middleName;
    const char *lastName;
    int age;
    const char *group;
public:
    const char *getFirstName(){
        return firstName;
    };
    const char *getMiddleName(){
        return middleName;
    };
    const char *getLastName(){
        return lastName;
    };
    const char *getGroup(){
        return group;
    };
    int getAge(){
        return age;
    };
    void changeGoup(const char *newGroup){
        this -> group = std::move(newGroup);
    };
    Student(const char *_firstName = NULL, const char *_middleName = NULL, const char *_lastName = NULL, const char *_group = NULL, int _age = 0)
    :firstName(std::move(_firstName))
    ,middleName(std::move(_middleName))
    ,lastName(std::move(_lastName))
    ,group(std::move(_group))
    ,age(_age)
    {
    };
    void printStudent(){
        std::cout << "FCS - " << getLastName() << " " << getFirstName() << " " << getMiddleName() << std::endl;
        std::cout << "Group - " << getGroup() << std::endl;
    };
};



#endif //LABA_2_CLASSESFORSTACK_H



