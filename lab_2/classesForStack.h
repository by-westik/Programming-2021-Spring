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
    std::string getFirstName() const;
    std::string getMiddleName() const;
    std::string getLastName() const;
    int getAge() const;
    void setFirstName(std::string _firstName);
    void setMiddleName(std::string _middleName);
    void setLastName(std::string _lastName);
    void setAge(int _age);
    Person(){};
    Person(int _age, std::string _firstName, std::string _middleName, std::string _lastName);
    void printPerson() const;
    void createPerson();
    bool operator== (Person &person) const;
};

class Student: public Person{
private:
    std::string group;
public:
    std::string getGroup() const;
    void setGroup(std::string _group);
    Student(){};
    Student(int _age, std::string _firstName, std::string _middleName, std::string _lastName, string _group);
    void printStudent() const;
    bool operator== (Student &_student) const;
    bool operator> (Student &_student) const;
};

class Teacher: public Person{
private:
    std::string subject;
public:
    std::string getSubject() const;
    Teacher(){};
    Teacher(int _age, std::string _firstName, std::string _middleName, std::string _lastName, string _subject);
    void printTeacher() const;
    bool operator== (Teacher &_teacher) const;
    bool operator> (Teacher &_teacher) const;
};


class Complex{
private:
    double real;
    double imaginary;
public:
    Complex(){};
    Complex(double _real, double _imaginary);
    Complex operator+ (const Complex &_complex) const;
    Complex operator- (const Complex &_complex) const;
    Complex operator* (const Complex &_complex) const;
    Complex operator/ (const Complex &_complex) const;
    Complex& operator+= (const Complex &_complex);
    bool operator== (const Complex &_complex) const;
    bool operator< (const Complex &_complex) const;
    bool operator> (const Complex &_complex) const;
    double getReal() const;
    double getImaginary() const;
    void setReal(double _real);
    void setImaginary(double _imaginary);
    void printComplex() const;
};

#endif //LABA_2_CLASSESFORSTACK_H
