#include "Stack.h"
#include "Sequence.h"
const char *MENU[] = {"0.Exit", "1.Int", "2.Float", "3.Complex numbers" "4.Char", "5.Function" "6.Students", "7.Teachers"};
const int MENU_SIZE = sizeof(MENU) / sizeof(MENU[0]);

const char *FUNCTION[] = {"0.Exit", "1. Map", "2.Where", "3.Reduce", "4.Conatenation", "5.SubSequence(index)", "6.Find SubSequence"};
const int FUNCTION_SIZE = sizeof(FUNCTION) / sizeof(FUNCTION[0]);

const char *MAP_FOR_INT_FLOAT_COMPLEX[] = {"1.Addition", "2.Subtraction", "3.Multiplication", "4.Division"};
const int MAP_FOR_INT_FLOAT_COMPLEX_SIZE = sizeof(MAP_FOR_INT_FLOAT_COMPLEX) / sizeof(MAP_FOR_INT_FLOAT_COMPLEX[0]);

int dialog(const char *msgs[], const int size){
    for(int i = 0; i < size; i++){
        std::cout << msgs[i] << std::endl;
    }
    std::cout << "Make your choice:" << std::endl;
    int choice;
    std::cin >> choice;
    return choice;
};
//Я еще не знаю, как лучше сделать  меню, но, наверное, буду передавать указатели на функции
template <class T> T functionForIntFloat(Stack <T, Sequence> *stack){
    std::cout << "What!?" << std::endl;
    bool choiceFunction = true;
    int a = 0;
    while(choiceFunction){
        a = dialog(FUNCTION, FUNCTION_SIZE);
        switch (a) {
            case 1:
                std::cout << "Map" << std::endl;
                break;
            case 2:
                 std::cout << "Where" << std::endl;
                 break;
            case 3:
                std::cout << "Reduce" << std::endl;
                break;
            case 4:
                std::cout << "Concatenation" << std::endl;
                break;
            case 5:
                std::cout << "SubSequence(index)" << std::endl;
                break;
            case 6:
                std::cout << "Find SubSequence" << std::endl;
                break;
            case 0:
                std::cout << "Exit" << std::endl;
                choiceFunction = false;
                break;
            default:
                std::cout << "Error" << std::endl;
                choiceFunction = false;
                break;
        }
    }
};
/*
typename <class T> choiceFunction(Stack <class T, Sequence> *stack){
    bool choiceFunction = true;
    int a = 0;
    while(choiceFunction){
        a = dialog(FUNCTION, FUNCTION_SIZE);
        switch(a){

        }
    }
}*/
void menu(){
    bool choiceType = true;
    int a = 0;
    while(choiceType){
        a = dialog(MENU,MENU_SIZE);
        switch(a) {
            case 1:
                {
                    std::cout << "Int" << std::endl;
                    Stack <int, LinkedListSequence> *stackInt = new Stack <int, LinkedListSequence>();
                    functionForIntFloat(dynamic_cast <Stack <int, Sequence>*> (stackInt));
                    delete stackInt;
                }
                break;
            case 2:
                {
                    std::cout << "Float" << std::endl;
                    Stack <float, LinkedListSequence> *stackInt = new Stack <float, LinkedListSequence>();
                    functionForIntFloat(dynamic_cast <Stack <float, Sequence>*> (stackInt));
                    delete stackInt;
                }
                break;
            case 3:
                std::cout << "Complex numbers" << std::endl;
                break;
            case 4:
                std::cout << "Char" << std::endl;
                break;
            case 5:
                std::cout << "Function" << std::endl;
                break;
            case 6:
                std::cout << "Students" << std::endl;
                break;
            case 7:
                std::cout << "Teachers" << std::endl;
                break;
            case 0:
                std::cout << "Exit" << std::endl;
                choiceType = false;
                break;
            default:
                std::cout << "Error" << std::endl;
                choiceType = false;
                break;
        }
    }
}