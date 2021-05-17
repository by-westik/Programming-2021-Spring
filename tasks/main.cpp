#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

class Animal{
public:
    string name;
    int age;
    int weight;
    explicit Animal(string _name ="", int _age = 0, int _weight = 0)
            :name(move(_name))
            ,age(_age)
            ,weight(_weight)
            {

            }
    virtual string Say() = 0;
};

class Cat: public Animal{
public:
    string vote = "May-May";
    explicit Cat(string _name="", int _age = 0, int _weight = 0):Animal(move(_name), _age, _weight)
    {

    }
    string Say() override {return vote;}
};

class Dog: public Animal{
public:
    string vote = "Gav-Gav";
    explicit Dog(string _name="", int _age = 0, int _weight = 0):Animal(move(_name), _age, _weight)
    {

    }
    string Say() override {return vote;}
};

class Kangaroo: public Animal{
public:
    string vote = "Kyr-Kyr";
    explicit Kangaroo(string _name="", int _age = 0, int _weight = 0):Animal(move(_name), _age, _weight)
    {

    }
    string Say() override {return vote;}
};

//Создаем рандомное имя
string create_random_name(){
    int max =10, min =  3;
    int len = rand() % (max + 1 - min) + min;
    string tmp_s;
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i)
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

    return tmp_s;

}
//

//Создаем рандомный возраст в диапазоне от 2 до 12
int create_random_age(){
    int max =12, min =  2;
    int age = rand() % (max + 1 - min) + min;
    return age;
}

//Создаем рандомный вес в диапазоне от 4 до 23
int create_random_weight(){
    int max =23, min =  4;
    int weight = rand() % (max + 1 - min) + min;
    return weight;
}

//Создаем вектор, состоящий только из Собак
/*
void create_dog_vector(vector <Dog*> &dogs){
    int max = 10, min = 5;
    int size = rand() % (max + 1 - min) + min;
    vector <Dog*> dogs_tmp(size);
    for(int i = 0; i < size; i++){
        dogs_tmp[i] = new Dog(create_random_name() + "_god", create_random_age(), create_random_weight());
    }
    dogs = dogs_tmp;
}*/

//Создаем вектор, состоящий только из Котов
void create_cat_vector(vector <Cat*> &cats){
    int max = 10, min = 5;
    int size = rand() % (max + 1 - min) + min;
    vector <Cat*> cats_tmp(size);
    for(int i = 0; i < size; i++){
        cats_tmp[i] = new Cat(create_random_name() + "_cat", create_random_age(), create_random_weight());
    }
    cats = cats_tmp;
}

//Создаем вектор, состоящий только из Кенгуру
/*
void create_kangaroo_vector(vector <Kangaroo*> &kangaroos){
    int max = 10, min = 3;
    int size = rand() % (max + 1 - min) + min;
    vector <Kangaroo*> kangaroos_tmp(size);
    for(int i = 0; i < size; i++){
        kangaroos_tmp[i] = new Kangaroo(create_random_name() + "_kangaroo", create_random_age(), create_random_weight());;
    }
    kangaroos = kangaroos_tmp;
}*/

//Создаем вектор, который содержит все три вида животных
void create_random_vector(vector <Animal*> &animals){
    int max = 25, min = 5;
    int size = rand() % (max + 1 - min) + min;
    vector <Animal*> animals_tmp(size);
    for (int i = 0; i < size; i++){
        if( i % 3  == 0) {
            animals_tmp[i] = new Cat(create_random_name() + "_cat", create_random_age(), create_random_weight());
        } else if (i % 2 == 0) {
            animals_tmp[i] = new Dog(create_random_name() + "_dog", create_random_age(), create_random_weight());
        } else {
            animals_tmp[i] = new Kangaroo(create_random_name() + "_kangaroo", create_random_age(), create_random_weight());
        }
    }
    animals = animals_tmp;
}

//Выводим элементы "смешанного" вектора на экран в формате - имя возраст вес
void print_vector(const vector <Animal*> &animals){
    for(int i = 0; i < animals.size(); ++i){
        cout << animals[i] -> name << " " << animals[i] -> age << " " << animals[i] -> weight << endl;
    }
    cout << endl;
}

//Выводим элементы вектора котов в формате - имя возраст вес
void print_cat(const vector <Cat*> &cats){
    for(int i = 0; i < cats.size(); ++i){
        cout << cats[i] -> name << " " << cats[i] -> age << " " << cats[i] -> weight << endl;
    }
    cout << endl;
}

//Находим наибольший вес животного
int the_biggest_animal(vector <Animal*> animals) {
    sort(animals.rbegin(), animals.rend(), [](const Animal *left, const Animal *right) {
        return left->weight < right->weight;
    });
    return animals[0]->weight;
}

//Выводим, что говорят животные
void say_animals(const vector <Animal*> &animals) {
    for (int i = 0; i < animals.size(); i++) {
        cout<< animals[i] -> name << " say " << animals[i] -> Say() << endl;
    }
    cout << endl;
}

//Находим, каких животных больше - Кошек, Собак или же Кенгуру
void max_animals(vector <Animal*> animals){
    int cat =0, dog = 0, kangaroo = 0;
    for(int i = 0; i < animals.size(); i++){
        if(dynamic_cast <Cat*> (animals[i])){
            cat++;
        } else if(dynamic_cast <Dog*> (animals[i])){
            dog++;
        } else {
            kangaroo++;
        }
    }
    cout << "Max type of animals = " << max(cat, max(dog, kangaroo)) << endl;
    cout << endl;
}

bool sort_cat(Animal *left, Animal *right){
    if((!dynamic_cast <Cat*> (left)) && (dynamic_cast <Cat*> (right))){
        return false;
    } else if((dynamic_cast <Cat*> (left)) && (dynamic_cast <Cat*> (right))){
        return left -> weight > right -> weight;
    } else if ((dynamic_cast <Cat*> (left)) && (!dynamic_cast <Cat*> (right))){
        return true;
    } else if ((!dynamic_cast <Cat*> (left)) && (!dynamic_cast <Cat*> (right))){
        return true;
    }
}
//Находим 5 самых толстеньнких котиков
void max_cats(vector <Animal*> animals){
    print_vector(animals);
    sort(animals.begin(), animals.end(), sort_cat);
    print_vector(animals);
    int i = 0;
    while((dynamic_cast <Cat*> (animals[i])) && (i < 5)){
        cout << animals[i] -> name << " " << animals[i] -> weight << endl;
        i++;
    }
}
//Котиков много не быввает, особенно, толстеньких)
/*
¨/\_/\ ♥
>^,^<
¨¨/ \
’¨(__)__
*/
int main() {
    srand(time(NULL));
    vector <Animal*> animals;
    create_random_vector(animals);
    print_vector(animals);
    vector <Cat*> cat;
    create_cat_vector(cat);
    print_cat(cat);
    int max_weight = the_biggest_animal(animals);
    cout << "The biggest weight is " << max_weight << endl;
    say_animals(animals);
    max_animals(animals);
    max_cats(animals);
    cout << "runtime = " << clock() / 1000.0 << endl;
    return 0;
}
