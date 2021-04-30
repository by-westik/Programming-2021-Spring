#ifndef LABA_2_CLASSESFORSTACK_CPP
#define LABA_2_CLASSESFORSTACK_CPP

#include "classesForStack.h"

Person::Person(int _age, std::string _firstName, std::string _middleName, std::string _lastName)
    :firstName(std::move(_firstName))
    ,middleName(std::move(_middleName))
    ,lastName(std::move(_lastName))
    ,age(_age)
    {
    };

std::string Person::getFirstName() const{
    return firstName;
};

std::string Person::getMiddleName() const{
    return middleName;
};

std::string Person::getLastName() const{
    return lastName;
};

void Person::printPerson() const{
    std::cout << "FIO - " << getLastName() << " " << getFirstName() << " " << getMiddleName() <<std::endl;
    std::cout << "Age - " << getAge() << std::endl;
};

int Person::getAge() const{
    return age;
};

Student::Student(int _age, std::string _firstName, std::string _middleName, std::string _lastName, string _group)
    :Person(_age, _firstName, _middleName, _lastName)
    ,group(std::move(_group))
    {
    };

std::string Student::getGroup() const{
    return group;
};

void Student::printStudent() const{
    printPerson();
    std::cout << "Group - " << getGroup() << std::endl;
};

bool Student::operator==(Student &_student) const{
    return ((this -> getFirstName() == _student.getFirstName()) && (this -> getLastName() == _student.getLastName())
        && (this -> getMiddleName() == _student.getMiddleName()) && (this -> getAge() == _student.getAge()) && (this -> getGroup() == _student.getGroup()));
};

bool Student::operator>(Student &_student) const{
    return (this -> getAge() > _student.getAge());
};
Teacher::Teacher(int _age, std::string _firstName, std::string _middleName, std::string _lastName, string _subject)
    :Person(_age, _firstName, _middleName, _lastName)
    ,subject(std::move(_subject))
    {
    };

std::string Teacher::getSubject() const{
    return subject;
};

void Teacher::printTeacher() const{
    printPerson();
    std::cout << "Subject - " << getSubject() << std::endl;
};

bool Teacher::operator==(Teacher &_teacher) const{
    return ((this -> getFirstName() == _teacher.getFirstName()) && (this -> getLastName() == _teacher.getLastName())
        && (this -> getMiddleName() == _teacher.getMiddleName()) && (this -> getAge() == _teacher.getAge()) && (this -> getSubject() == _teacher.getSubject()));
};
bool Teacher::operator>(Teacher &_teacher) const{
    return (this -> getAge() > _teacher.getAge());
};

Complex::Complex(double _real, double _imaginary)
    :real(_real)
    ,imaginary(_imaginary)
    {
    };

Complex Complex::operator+ (const Complex &_complex) const{
    Complex result;
    result.real = real + _complex.real;
    result.imaginary = imaginary + _complex.imaginary;
    return result;
};
Complex Complex::operator- (const Complex &_complex) const{
    Complex result;
    result.real = real - _complex.real;
    result.imaginary = imaginary - _complex.imaginary;
    return result;
};

Complex Complex::operator* (const Complex &_complex) const{
    Complex result;
    result.real = real * _complex.real;
    result.imaginary = imaginary * _complex.imaginary;
    return result;
};

Complex Complex::operator/ (const Complex &_complex) const{
    Complex result;
    result.real = real / _complex.real;
    result.imaginary = imaginary / _complex.imaginary;
    return result;
};

bool Complex::operator== (const Complex &_complex) const{
    return ((real == _complex.real) && (imaginary == _complex.imaginary));
};

bool Complex::operator< (const Complex &_complex) const{
    return ((real < _complex.real) && (imaginary < _complex.imaginary));
};

bool Complex::operator> (const Complex &_complex) const{
    return ((real > _complex.real) && (imaginary > _complex.imaginary));
};

double Complex::getReal() const{
    return real;
};

double Complex::getImaginary() const{
    return imaginary;
};

void Complex::setReal(double _real){
    this -> real = _real;
};

void Complex::setImaginary(double _imaginary){
    this -> imaginary = _imaginary;
};

void Complex::printComplex() const{
    std::cout << getReal() << "x + " << getImaginary() << "y" << std::endl;
};

#endif //LABA_2_CLASSESFORSTACK_H

