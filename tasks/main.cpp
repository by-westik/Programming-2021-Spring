#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
#include <typeinfo>
#include <map>

using namespace std;

class Animal{
public:
    string name;
    int age;
    int weight;
    Animal(string _name ="", int _age = 0, int _weight = 0)
            :name(_name)
            ,age(_age)
            ,weight(_weight)
            {

            }
    virtual string Say() = 0;
};

class Cat: public Animal{
public:
    string vote = "May-May";
   Cat(string _name="", int _age = 0, int _weight = 0):Animal(_name, _age, _weight)
   {

   }
    virtual string Say() override {return vote;}
};

class Dog: public Animal{
public:
    string vote = "Gav-Gav";
    Dog(string _name="", int _age = 0, int _weight = 0):Animal(_name, _age, _weight)
    {

    }
    virtual string Say() override {return vote;}
};
class Kangaroo: public Animal{
public:
    string vote = "Kyr-Kyr";
    Kangaroo(string _name="", int _age = 0, int _weight = 0):Animal(_name, _age, _weight)
    {

    }
    virtual string Say() override {return vote;}
};

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

int create_random_age(){
    int max =12, min =  2;
    int age = rand() % (max + 1 - min) + min;
    return age;
}

int create_random_weight(){
    int max =23, min =  4;
    int weight = rand() % (max + 1 - min) + min;
    return weight;
}

void create_dog_vector(vector <Dog*> *dog){
    int max = 10, min = 5;
    int size = rand() % (max + 1 - min) + min;
    vector <Dog*> dogs(size);
    for(int i = 0; i < size; i++){
        dogs[i] = new Dog(create_random_name() + "_god", create_random_age(), create_random_weight());
    }
    *dog = dogs;
}

void create_cat_vector(vector <Cat*> *cat){
    int max = 10, min = 5;
    int size = rand() % (max + 1 - min) + min;
    vector <Cat*> cats(size);
    for(int i = 0; i < size; i++){
        cats[i] = new Cat(create_random_name() + "_cat", create_random_age(), create_random_weight());
    }
    *cat = cats;
}

void create_kangaroo_vector(vector <Kangaroo*> *kangaroo){
    int max = 10, min = 3;
    int size = rand() % (max + 1 - min) + min;
    vector <Kangaroo*> kangaroos(size);
    for(int i = 0; i < size; i++){
        kangaroos[i] = new Kangaroo(create_random_name() + "_kangaroo", create_random_age(), create_random_weight());;
    }
    *kangaroo = kangaroos;
} //Я не поняла разницы между 4 и 5 заданием... Поэтому вот три генаратора одних животных

void create_random_vector(vector <Animal*> *animal){
    int max = 23, min = 5;
    int size = rand() % (max + 1 - min) + min;
    vector <Animal*> animals(size);
    for (int i = 0; i < size; i++){
        if( i % 3  == 0) {
            animals[i] = new Cat(create_random_name() + "_cat", create_random_age(), create_random_weight());
        } else if (i % 2 == 0) {
            animals[i] = new Dog(create_random_name() + "_dog", create_random_age(), create_random_weight());
        } else {
            animals[i] = new Kangaroo(create_random_name() + "_kangaroo", create_random_age(), create_random_weight());
        }
    }
   *animal = animals;
}

void print_vector(vector <Animal*> animals){
    for(int i = 0; i < animals.size(); i++){
        cout << animals[i] -> name << " " << animals[i] -> age << " " << animals[i] -> weight << endl;
    }
    cout << endl;
}

void print_cat(vector <Cat*> animals){
    for(int i = 0; i < animals.size(); i++){
        cout << animals[i] -> name << " " << animals[i] -> age << " " << animals[i] -> weight << endl;
    }
    cout << endl;
}

int the_biggest_animal(vector <Animal*> animals){
    int size = animals.size();
    vector <int> sort_weight(animals.size());
    for(int i = 0; i < animals.size(); i++){
        sort_weight[i] = animals[i] -> weight;
    }
    sort(sort_weight.begin(), sort_weight.end());
    return sort_weight[sort_weight.size() - 1];
}

void say_animals(vector <Animal*> animal) {
    for (int i = 0; i < animal.size(); i++) {
        cout<< animal[i] -> name << " say " << animal[i] -> Say() << endl;
    }
    cout << endl;
}

void max_animals(vector <Animal*> animal){
    int cat =0, dog = 0, kangaroo = 0;
    for(int i = 0; i < animal.size(); i++){
        if(typeid(*animal[i]) == typeid(Cat)){
            cat++;
        } else if(typeid(*animal[i]) == typeid(Dog)){
            dog++;
        } else {
            kangaroo++;
        }
    }
    cout << "Max animals = " << max(cat, max(dog, kangaroo)) << endl;
}

void max_cats(vector <Animal*> animal){
    map <int, string> biggest_cat;
    for(int i = 0; i < animal.size(); i++){
        if(typeid(*animal[i]) == typeid(Cat)){
            biggest_cat.insert ( pair <int, string>(animal[i] -> weight, animal[i] -> name) );

        }
    }
    for (auto it = biggest_cat.begin(); it != biggest_cat.end(); ++it)
    {
        cout << it -> first << " : " << it->second << endl;
    }
}


int main() {
    srand(time(NULL));
    vector <Animal*> animals;
    create_random_vector(&animals);
    print_vector(animals);
    vector <Cat*> cat;
    create_cat_vector(&cat);
    print_cat(cat);
    int max_weight = the_biggest_animal(animals);
    cout << "The biggest weight is " << max_weight << endl;
    say_animals(animals);
    max_animals(animals);
    max_cats(animals);
    return 0;
}