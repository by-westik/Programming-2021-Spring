#ifndef LABA_2_CLASSESFORSTACK_H
#define LABA_2_CLASSESFORSTACK_H
#include <string>

using namespace std;

class Person{
private:
    std::string firstName;
    std::string middleName;
    std::string lastName;
    int age;
public:
    Person(){};
    Person(int _age, std::string _firstName, std::string _middleName, std::string _lastName);
    std::string getFirstName() const;
    std::string getMiddleName() const;
    std::string getLastName() const;
    int getAge() const;
    void setFirstName(std::string _firstName);
    void setMiddleName(std::string _middleName);
    void setLastName(std::string _lastName);
    void setAge(int _age);
    void printPerson() const;
    Person operator+ (const Person &_person) const;
    Person operator- (const Person &_person) const;
    Person operator* (const Person &_person) const;
    Person operator/ (const Person &_person) const;
    Person& operator+= (const Person &_person);
    bool operator== (Person &person) const;
    bool operator< (Person &person) const;
    bool operator> (Person &person) const;
};

class Student: public Person{
private:
    std::string group;
public:
    Student(){};
    Student(int _age, std::string _firstName, std::string _middleName, std::string _lastName, string _group);
    std::string getGroup() const;
    void setGroup(std::string _group);
    void printStudent() const;
    Student operator+ (const Student &_student) const;
    Student operator- (const Student &_student) const;
    Student operator* (const Student &_student) const;
    Student operator/ (const Student &_student) const;
    Student& operator+= (const Student &_student);
    bool operator== (Student &_student);
    bool operator< (Student &_student) const;
    bool operator> (Student &_student) const;
};

class Teacher: public Person{
private:
    std::string subject;
public:
    Teacher(){};
    Teacher(int _age, std::string _firstName, std::string _middleName, std::string _lastName, string _subject);
    std::string getSubject() const;
    void setSubject(std::string _subject);
    void printTeacher() const;
    Teacher operator+ (const Teacher &_teacher) const;
    Teacher operator- (const Teacher &_teacher) const;
    Teacher operator* (const Teacher &_teacher) const;
    Teacher operator/ (const Teacher &_teacher) const;
    Teacher& operator+= (const Teacher &_teacher);
    bool operator== (Teacher &_teacher);
    bool operator< (Teacher &_teacher) const;
    bool operator> (Teacher &_teacher) const;
};

class Complex{
private:
    double real;
    double imaginary;
public:
    Complex();
    Complex(double _real, double _imaginary);
    double getReal() const;
    double getImaginary() const;
    void setReal(double _real);
    void setImaginary(double _imaginary);
    void printComplex() const;
    Complex operator+ (const Complex &_complex) const;
    Complex operator- (const Complex &_complex) const;
    Complex operator* (const Complex &_complex) const;
    Complex operator/ (const Complex &_complex) const;
    Complex& operator+= (const Complex &_complex);
    bool operator== (const Complex &_complex) const;
    bool operator< (const Complex &_complex) const;
    bool operator> (const Complex &_complex) const;
};

#endif //LABA_2_CLASSESFORSTACK_H
