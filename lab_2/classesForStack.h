
#ifndef LABA_2_CLASSESFORSTACK_H
#define LABA_2_CLASSESFORSTACK_H

class Person{
private:
    const char *firstName;
    const char *middleName;
    const char *lastName;
    int age;
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
    int getAge(){
        return age;
    };
    Person(const char *_firstName = NULL, const char *_middleName = NULL, const char *_lastName = NULL, int _age = 0)
    :firstName(std::move(_firstName))
    ,middleName(std::move(_middleName))
    ,lastName(std::move(_lastName))
    ,age(_age)
    {
    };
    void printPerson(){
        std::cout << "FIO - " << getLastName() << " " << getFirstName() << " " << getMiddleName() <<std::endl;
        std::cout << "Age - " << getAge() << std::endl;
    };
};

class Student: public Person{
private:
    const char *group;
public:
    const char *getGroup(){
        return group;
    };
    Student(const char *_firstName = NULL, const char *_middleName = NULL, const char *_lastName = NULL, int _age = 0, const char *_group = NULL)
    :Person(_firstName, _middleName, _lastName, _age)
    ,group(std::move(_group))
    {
    };
    void printStudent(){
        printPerson();
        std::cout << "Group - " << getGroup() << std::endl;
    }
    bool operator== (Student &_student){
        return ((this -> getFirstName() == _student.getFirstName()) && (this -> getLastName() == _student.getLastName())
                 && (this -> getMiddleName() == _student.getMiddleName()) && (this -> getAge() == _student.getAge()) && (this -> getGroup() == _student.getGroup()));
    }
};

class Teacher: public Person{
private:
    const char *subject;
public:
    const char *getSubject(){
        return subject;
    };
    Teacher(const char *_firstName = NULL, const char *_middleName = NULL, const char *_lastName = NULL, int _age = 0, const char *_subject = NULL)
    :Person(_firstName, _middleName, _lastName, _age)
    ,subject(std::move(_subject))
    {
    };
    void printTeacher(){
        printPerson();
        std::cout << "Subject - " << getSubject() << std::endl;
    }
    bool operator== (Teacher &_teacher){
        return ((this -> getFirstName() == _teacher.getFirstName()) && (this -> getLastName() == _teacher.getLastName())
                 && (this -> getMiddleName() == _teacher.getMiddleName()) && (this -> getAge() == _teacher.getAge()) && (this -> getSubject() == _teacher.getSubject())$    }
};
                
 class Complex{
private:
    double real;
    double imaginary;
public:
    Complex(){};
    Complex(double _real, double _imaginary)
    :real(_real)
    ,imaginary(_imaginary)
    {
    };
    Complex operator+ (const Complex &_complex) const{
        Complex result;
        result.real = real + _complex.real;
        result.imaginary = imaginary + _complex.imaginary;
        return result;
    }
    Complex operator- (const Complex &_complex) const{
        Complex result;
        result.real = real - _complex.real;
        result.imaginary = imaginary - _complex.imaginary;
        return result;
    }
    Complex operator* (const Complex &_complex) const{
        Complex result;
        result.real = real * _complex.real;
        result.imaginary = imaginary * _complex.imaginary;
        return result;
    }
    Complex operator/ (const Complex &_complex) const{
        Complex result;
        result.real = real / _complex.real;
        result.imaginary = imaginary / _complex.imaginary;
        return result;
    }
    bool operator== (const Complex &_complex) const{
        return ((real == _complex.real) && (imaginary == _complex.imaginary));
    }
    bool operator< (const Complex &_complex) const{
        return ((real < _complex.real) && (imaginary < _complex.imaginary));
    }
    bool operator> (const Complex &_complex) const{
        return ((real > _complex.real) && (imaginary > _complex.imaginary));
    }
    double getReal(){
        return real;
    }
    double getImaginary(){
        return imaginary;
    }
    void printComplex(){
        std::cout << getReal() << "x + " << getImaginary() << "y" << std::endl;
    }
};

#endif //LABA_2_CLASSESFORSTACK_H


#endif //LABA_2_CLASSESFORSTACK_H



