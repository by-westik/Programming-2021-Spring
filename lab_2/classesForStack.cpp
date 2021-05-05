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

void Person::setFirstName(std::string _firstName){
    this -> firstName = _firstName;
};

void Person::setMiddleName(std::string _middleName){
    this -> middleName = _middleName;
};

void Person::setLastName(std::string _lastName){
    this -> lastName = _lastName;
};

void Person::setAge(int _age){
    this -> age = _age;
};

bool Person::operator== (Person &_person) const{
    return ((this -> getFirstName() == _person.getFirstName()) && (this -> getLastName() == _person.getLastName())
        && (this -> getMiddleName() == _person.getMiddleName()) && (this -> getAge() == _person.getAge()));
};
// Эти перегрузки оператора работают, но есть немного ниже вопрос
/*
std::istream& operator>> (std::istream &in, Person &_person){
    std::cout << "Введите имя"<< std::endl;
    std::string _firstName, _middleName, _lastName;
    in >> _firstName;
    _person.setFirstName(_firstName);
    std::cout << "Введите фамилию"<< std::endl;
    in >> _lastName;
    _person.setLastName(_lastName);
    std::cout << "Введите отчество"<< std::endl;
    in >> _middleName;
    _person.setMiddleName(_middleName);
    int _age;
    std::cout << "Введите возраст"<< std::endl;
    in >> _age;
    _person.setAge(_age);
    return in;
};*/

void Person::createPerson(){
    std::cout << "Введите имя"<< std::endl;
    std::string _firstName, _middleName, _lastName;
    std::cin >> _firstName;
    this -> setFirstName(_firstName);
    std::cout << "Введите фамилию"<< std::endl;
    std::cin >> _lastName;
    this -> setLastName(_lastName);
    std::cout << "Введите отчество"<< std::endl;
    std::cin >> _middleName;
    this -> setMiddleName(_middleName);
    int _age;
    std::cout << "Введите возраст"<< std::endl;
    std::cin >> _age;
    this -> setAge(_age);
};

std::istream& operator>> (std::istream &in, Person &_person){
    _person.createPerson();
    return in;
};


Student::Student(int _age, std::string _firstName, std::string _middleName, std::string _lastName, string _group)
    :Person(_age, _firstName, _middleName, _lastName)
    ,group(std::move(_group))
    {
    };

std::string Student::getGroup() const{
    return group;
};

void Student::setGroup(std::string _group){
    this -> group = _group;
};

void Student::printStudent() const{
    printPerson();
    std::cout << "Group - " << getGroup() << std::endl;
};

bool Student::operator==(Student &_student) const{
    return ((this -> getFirstName() == _student.getFirstName()) && (this -> getLastName() == _student.getLastName())
        && (this -> getMiddleName() == _student.getMiddleName()) && (this -> getAge() == _student.getAge()) && (this -> getGroup() == _student.getGroup()));
//    return ((*this == _student) && (this -> getGroup() == _student.getGroup()));
// Я никак не смогу использовать == перегруженный в Person для == в Student/Teacher?
};

bool Student::operator>(Student &_student) const{
    return (this -> getAge() > _student.getAge());
};

std::istream& operator>> (std::istream &in, Student &_student){
 //   in >> _student; //И тут тоже не получиться вызвать >> для Person?
    _student.createPerson();
    std::string _group;
    std::cout << "Введите группу" << std::endl;
    in >> _group;
    _student.setGroup(_group);
    return in;
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

void Teacher::setSubject(std::string _subject){
    this -> subject = _subject;
};

bool Teacher::operator==(Teacher &_teacher) const{
    return ((this -> getFirstName() == _teacher.getFirstName()) && (this -> getLastName() == _teacher.getLastName())
        && (this -> getMiddleName() == _teacher.getMiddleName()) && (this -> getAge() == _teacher.getAge()) && (this -> getSubject() == _teacher.getSubject()));
};

bool Teacher::operator>(Teacher &_teacher) const{
    return (this -> getAge() > _teacher.getAge());
};

std::istream& operator>> (std::istream &in, Teacher &_teacher){
    _teacher.createPerson();
    std::string _subject;
    std::cout << "Введите преподаваемый предмет" << std::endl;
    in >> _subject;
    _teacher.setSubject(_subject);
    return in;
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

Complex& Complex::operator+= (const Complex &_complex){
    real += _complex.real;
    imaginary += _complex.imaginary;
    return *this;
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

std::istream& operator>> (std::istream &in, Complex &complex){
    std::cout << "Введите реальную часть числа"<< std::endl;
    double _real;
    in >> _real;
    complex.setReal(_real);
    std::cout << "Введите мнимую часть числа"<< std::endl;
    double _imaginary;
    in >> _imaginary;
    complex.setImaginary(_imaginary);
    return in;
};

std::ostream& operator<< (std::ostream &out, const Complex &complex){
    out << complex.getReal() << "x + " << complex.getImaginary() << "y" << std::endl;
    return out;
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


