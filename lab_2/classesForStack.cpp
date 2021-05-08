#ifndef LABA_2_CLASSESFORSTACK_CPP
#define LABA_2_CLASSESFORSTACK_CPP

#include "classesForStack.h"

template <class typeOne, class typeTwo> std::ostream& operator<< (std::ostream &out, const std::pair<typeOne,typeTwo> &_pair){
    out << "[ " << _pair.first << " " << _pair.second << " ]";
    return out;
};

template <class typeOne, class typeTwo> std::pair<typeOne, typeTwo> operator+ (const std::pair<typeOne, typeTwo> &_pairL, const std::pair<typeOne, typeTwo> &_pairR){
    return {_pairL.first + _pairR.first, _pairL.second + _pairR.second};
};

template <class typeOne, class typeTwo> std::pair<typeOne, typeTwo> operator- (const std::pair<typeOne, typeTwo> &_pairL, const std::pair<typeOne, typeTwo> &_pairR){
    return {_pairL.first - _pairR.first, _pairL.second - _pairR.second};
};

template <class typeOne, class typeTwo> std::pair<typeOne, typeTwo> operator* (const std::pair<typeOne, typeTwo> &_pairL, const std::pair<typeOne, typeTwo> &_pairR){
    return {_pairL.first * _pairR.first, _pairL.second * _pairR.second};
};

template <class typeOne, class typeTwo> std::pair<typeOne, typeTwo> operator/ (const std::pair<typeOne, typeTwo> &_pairL, const std::pair<typeOne, typeTwo> &_pairR){
    return {_pairL.first / _pairR.first, _pairL.second / _pairR.second};
};

template <class typeOne, class typeTwo> std::pair<typeOne, typeTwo> operator+= (std::pair<typeOne, typeTwo> &_pairL, const std::pair<typeOne, typeTwo> &_pairR){
    return {_pairL.first += _pairR.first, _pairL.second += _pairR.second};
};

template <class typeOne, class typeTwo> std::istream& operator>> (std::istream &in, std::pair<typeOne,typeTwo> &_pair){
    std::cout << "Введите значение элемента" << std::endl;
    typeOne _first;
    in >> _first;
    _pair.first = _first;
    typeTwo _second;
    in >> _second;
    _pair.second = _second;
    return in;
};

template <> std::istream& operator>> (std::istream &in, std::pair<int,int> &_pair){
    std::cout << "Введите значение элемента" << std::endl;
    int _first;
    in >> _first;
    _pair.first = _first;
    _pair.second = _first;
    return in;
};

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

void Person::printPerson() const{
    std::cout << "FIO - " << getLastName() << " " << getFirstName() << " " << getMiddleName() <<std::endl;
    std::cout << "Age - " << getAge() << std::endl;
};

Person Person::operator+ (const Person &_person) const{
    Person result;
    result.setFirstName(firstName + _person.firstName);
    result.setMiddleName(middleName + _person.middleName);
    result.setLastName(lastName + _person.lastName);
    result.setAge(age  + _person.age);
    return result;
};

Person Person::operator- (const Person &_person) const{
    Person result(age, firstName, middleName, lastName);
    result.setAge(age  - _person.age);
    return result;
};

Person Person::operator* (const Person &_person) const{
    Person result(age, firstName, middleName, lastName);
    result.setAge(age  * _person.age);
    return result;
};

Person Person::operator/ (const Person &_person) const{
    Person result(age, firstName, middleName, lastName);
    result.setAge(age  / _person.age);
    return result;
};

Person& Person::operator+= (const Person &_person){
    firstName += _person.firstName;
    middleName += _person.middleName;
    lastName += _person.lastName;
    age += _person.age;
    return *this;
};

bool Person::operator== (Person &_person) const{
    return ((this -> getFirstName() == _person.getFirstName()) && (this -> getLastName() == _person.getLastName())
        && (this -> getMiddleName() == _person.getMiddleName()) && (this -> getAge() == _person.getAge()));
};

bool Person::operator< (Person &_person) const{
    return (this -> getAge() < _person.getAge());
};

bool Person::operator> (Person &_person) const{
    return (this -> getAge() > _person.getAge());
};

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
};

std::ostream& operator<< (std::ostream &out, const Person &_person){
    out << "FIO - " << _person.getLastName() << " " << _person.getFirstName() << " " << _person.getMiddleName() <<std::endl;
    out << "Age - " << _person.getAge() << std::endl;
    return out;
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

Student Student::operator+ (const Student &_student) const{
    Student result(this -> getAge() + _student.getAge(), this -> getFirstName() + _student.getFirstName(),
                   this -> getMiddleName() + _student.getMiddleName(), this -> getLastName() + _student.getLastName(), this -> getGroup() + _student.getGroup());
    return result;
};

Student Student::operator- (const Student &_student) const{
    Student result(this -> getAge() - _student.getAge(), this -> getFirstName(),this -> getMiddleName(), this -> getLastName(), this -> getGroup());
    return result;
};


Student Student::operator* (const Student &_student) const{
    Student result(this -> getAge() * _student.getAge(), this -> getFirstName(),this -> getMiddleName(), this -> getLastName(), this -> getGroup());
    return result;
};

Student Student::operator/ (const Student &_student) const{
    Student result(this -> getAge() / _student.getAge(), this -> getFirstName(),this -> getMiddleName(), this -> getLastName(), this -> getGroup());
    return result;
};

Student& Student::operator+= (const Student &_student){
    this -> setFirstName(_student.getFirstName() + this -> getFirstName());
    this -> setMiddleName(_student.getMiddleName() + this -> getMiddleName());
    this -> setLastName(_student.getLastName() + this -> getLastName());
    this -> setGroup(_student.getGroup() + this -> getGroup());
    this -> setAge(_student.getAge() + this -> getAge());
    return *this;
};

bool Student::operator==(Student &_student){
    return ((dynamic_cast <Person&> (*this) == dynamic_cast <Person&> (_student)) && (this -> getGroup() == _student.getGroup()));
};

bool Student::operator< (Student &_student) const{
    return (this -> getAge() < _student.getAge());
};

bool Student::operator> (Student &_student) const{
    return (this -> getAge() > _student.getAge());
};

std::istream& operator>> (std::istream &in, Student &_student){
    in >> dynamic_cast <Person&> (_student);
    std::string _group;
    std::cout << "Введите группу" << std::endl;
    in >> _group;
    _student.setGroup(_group);
    return in;
}

std::ostream& operator<< (std::ostream &out, Student &_student){
    out << dynamic_cast <Person&> (_student);
    out << "Group - " << _student.getGroup() << std::endl;
    return out;
};

Teacher::Teacher(int _age, std::string _firstName, std::string _middleName, std::string _lastName, string _subject)
    :Person(_age, _firstName, _middleName, _lastName)
    ,subject(std::move(_subject))
    {
    };

std::string Teacher::getSubject() const{
    return subject;
};

void Teacher::setSubject(std::string _subject){
    this -> subject = _subject;
};

void Teacher::printTeacher() const{
    printPerson();
    std::cout << "Subject - " << getSubject() << std::endl;
};

Teacher Teacher::operator+ (const Teacher &_teacher) const{
    Teacher result(this -> getAge() + _teacher.getAge(), this -> getFirstName() + _teacher.getFirstName(),
                   this -> getMiddleName() + _teacher.getMiddleName(), this -> getLastName() + _teacher.getLastName(), this -> getSubject() + _teacher.getSubject());
    return result;
};

Teacher Teacher::operator- (const Teacher &_teacher) const{
    Teacher result(this -> getAge() - _teacher.getAge(), this -> getFirstName(), this -> getMiddleName(), this -> getLastName(), this -> getSubject());
    return result;
};

Teacher Teacher::operator* (const Teacher &_teacher) const{
    Teacher result(this -> getAge() * _teacher.getAge(), this -> getFirstName(), this -> getMiddleName(), this -> getLastName(), this -> getSubject());
    return result;
};

Teacher Teacher::operator/ (const Teacher &_teacher) const{
    Teacher result(this -> getAge() / _teacher.getAge(), this -> getFirstName(), this -> getMiddleName(), this -> getLastName(), this -> getSubject());
    return result;
};

Teacher& Teacher::operator+= (const Teacher &_teacher){
    this -> setFirstName(_teacher.getFirstName() + this -> getFirstName());
    this -> setMiddleName(_teacher.getMiddleName() + this -> getMiddleName());
    this -> setLastName(_teacher.getLastName() + this -> getLastName());
    this -> setSubject(_teacher.getSubject() + this -> getSubject());
    this -> setAge(_teacher.getAge() + this -> getAge());
    return *this;
};

bool Teacher::operator==(Teacher &_teacher){
    return ((dynamic_cast <Person&> (*this) == dynamic_cast <Person&> (_teacher)) && (this -> getSubject() == _teacher.getSubject()));
}

bool Teacher::operator< (Teacher &_teacher) const{
    return (this -> getAge() < _teacher.getAge());
};

bool Teacher::operator> (Teacher &_teacher) const{
    return (this -> getAge() > _teacher.getAge());
};

std::istream& operator>> (std::istream &in, Teacher &_teacher){
    in >> dynamic_cast <Person&> (_teacher);
    std::string _subject;
    std::cout << "Введите преподаваемый предмет" << std::endl;
    in >> _subject;
    _teacher.setSubject(_subject);
    return in;
};

std::ostream& operator<< (std::ostream &out, Teacher &_teacher){
    out << dynamic_cast <Person&> (_teacher);
    out << "Subject - " << _teacher.getSubject() << std::endl;
    return out;
};

Complex::Complex()
    :real(0)
    ,imaginary(0)
    {
    };

Complex::Complex(double _real, double _imaginary)
    :real(_real)
    ,imaginary(_imaginary)
    {
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
    out << " " <<complex.getReal() << "x + " << complex.getImaginary() << "y ";
    return out;
};

#endif //LABA_2_CLASSESFORSTACK_H
