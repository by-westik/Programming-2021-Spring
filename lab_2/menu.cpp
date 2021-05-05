//
// Created by User on 10.04.2021.
//

#include "Stack.h"
#include "Sequence.h"

const char *MENU[] = {"0.Exit", "1.Int", "2.Double", "3.Complex numbers", "4.Char", "5.Function", "6.Students", "7.Teachers"};
const int MENU_SIZE = sizeof(MENU) / sizeof(MENU[0]);

const char *SEQ[] = {"0.Exit", "1.DynamicArraySequence", "2.LinkedListSequence"};
const int SEQ_SIZE = sizeof(SEQ) / sizeof(SEQ[0]);

const char *FUNCTION[] = {"0.Exit", "1.Map", "2.Where", "3.Reduce", "4.Conatenation", "5.SubSequence(index)", "6.Find SubSequence"};
const int FUNCTION_SIZE = sizeof(FUNCTION) / sizeof(FUNCTION[0]);

const char *MAP[] = {"0.Exit", "1.Addition", "2.Subtraction", "3.Multiplication", "4.Division"};
const int MAP_SIZE = sizeof(MAP) / sizeof(MAP[0]);

const char *WHERE[] = {"0.Exit", "1.IsSmaller", "2.IsBigger", "3.IsEqual", "4.IsUnEqual"};
const int WHERE_SIZE = sizeof(WHERE) / sizeof(WHERE[0]);

int dialog(const char *msgs[], const int size);
template <class T, template <class> class Sequence> void createStack(Stack <T, Sequence> &stack);
template <class T, template <class> class Sequence> void functionChoisenWhere(Stack <T, Sequence> *stack,  bool function(T, T));
template <class T, template <class> class Sequence> void functionForWhere(Stack <T, Sequence> *stack);
template <class T, template <class> class Sequence> void functionChoisenMap(Stack <T, Sequence> *stack,  T function(T, T));
template <class T, template <class> class Sequence> void functionChoisenReduce(Stack <T, Sequence> *stack,  T function(T, T));
template <class T, template <class> class Sequence> void functionForMapReduce(Stack <T, Sequence> *stack, void functionChoisen(Stack <T, Sequence> *stack, T function (T, T)));
template <class T, template <class> class Sequence> void functionForStack(Stack <T, Sequence> *stack);
template <class T, template <class> class Sequence> void createTypeStack();
template <class T> void choisenSequence();

void menu(){
    bool choiceType = true;
    int a = 0;
    while(choiceType){
        a = dialog(MENU,MENU_SIZE);
        switch(a) {
            case 1:
                {
                    std::cout << "Int" << std::endl;
                    choisenSequence <int> ();
                }
                break;
            case 2:
                {
                    std::cout << "Double" << std::endl;
                    choisenSequence <double> ();
                }
                break;
            case 3:
                {
                    std::cout << "Complex numbers" << std::endl;
                    choisenSequence <Complex> ();
                }
                break;
            case 4:
                {
                    std::cout << "Char" << std::endl;
                    choisenSequence <char> ();
                }
                break;
            case 5:
                std::cout << "Function" << std::endl;
                std::cout << "Coming soon" << std::endl;
                break;
            case 6:
                {
                    std::cout << "Students" << std::endl;
                    Stack <Student, LinkedListSequence> *stackStudent = new Stack <Student, LinkedListSequence>();
                    createStack <Student, LinkedListSequence> (*stackStudent);
                    stackStudent -> printStack();
                  //  Student n;
                 //   std::cin >> n;
              //      functionChoisenWhere(stackStudent, isEqual);
//                    functionForStack <Student, LinkedListSequence>(stackStudent);
                    delete stackStudent;
                }
                break;
            case 7:
                std::cout << "Teachers" << std::endl;
                std::cout << "Coming soon" << std::endl;
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
};

template <class T> void choisenSequence(){
    bool choiceSequence = true;
    int a = 0;
    a = dialog(SEQ, SEQ_SIZE);
    switch(a) {
        case 0:
            break;
        case 1:
            {
                createTypeStack <T, ArraySequence> ();
            }
            break;
        case 2:
            {
                createTypeStack <T, LinkedListSequence> ();
            }
            break;
         default:
            std::cout << "Error" << std::endl;
            break;
     };
};

template <class T, template <class> class Sequence> void createTypeStack(){
    Stack <T, Sequence> *stackType = new Stack <T, Sequence> ();
    createStack <T, Sequence> (*stackType);
    stackType -> printStack();
    functionForStack <T, Sequence> (stackType);
    delete stackType;
};

int dialog(const char *msgs[], const int size){
    for(int i = 0; i < size; i++){
        std::cout << msgs[i] << std::endl;
    }
    std::cout << "Make your choice:" << std::endl;
    int choice;
    std::cin >> choice;
    return choice;
};

template <class T, template <class> class Sequence> void createStack(Stack <T, Sequence> &stack){
    std::cout << "Сколько элементов Вы хотите добавить в стек?" << std::endl;
    int len = 0;
    while(len <= 0){
        std::cin >> len;
    }
    for(int i = 0; i < len; i++){
        std::cout << "Введите элемент" << std::endl;
        T n;
        std::cin >> n;
        stack.push(n);
    }
};

template <class T, template <class> class Sequence> void functionChoisenWhere(Stack <T, Sequence> *stack,  bool function(T, T)){
    std::cout << "Введите элемент для сравнения" << std::endl;
    T n;
    std::cin >> n;
    stack -> where(function, n);
    stack -> printStack();
};

template <class T, template <class> class Sequence> void functionForWhere(Stack <T, Sequence> *stack){
    bool choiceFunction = true;
    int a = 0;
    while(choiceFunction){
        a = dialog(WHERE, WHERE_SIZE);
        switch (a) {
            case 0:
                std::cout << "Exit" << std::endl;
                choiceFunction = false;
                break;
            case 1:
                {
                    functionChoisenWhere(stack, isSmaller);
                }
                break;
            case 2:
                {
                    functionChoisenWhere(stack, isBigger);
                }
                break;
            case 3:
                {
                    functionChoisenWhere(stack, isEqual);
                }
                break;
            case 4:
                {
                    functionChoisenWhere(stack, isUnEqual);
                }
                break;
            default:
                choiceFunction = false;
                break;
        };
    };

};

template <class T, template <class> class Sequence> void functionChoisenMap(Stack <T, Sequence> *stack,  T function(T, T)){
    std::cout << "Введите элемент для выполнения дейсвий со стеком" << std::endl;
    T n;
    std::cin >> n;
    stack -> map(function, n);
    stack -> printStack();
};

template <class T, template <class> class Sequence> void functionChoisenReduce(Stack <T, Sequence> *stack,  T function(T, T)){
    std::cout << "Введите элемент для выполнения дейсвий со стеком" << std::endl;
    T n;
    std::cin >> n;
    std::cout << stack -> reduce(function, n) << std::endl;
};

template <class T, template <class> class Sequence> void functionForMapReduce(Stack <T, Sequence> *stack, void functionChoisen(Stack <T, Sequence> *stack, T function (T, T))){
    bool choiceFunction = true;
    int a = 0;
    while(choiceFunction){
        a = dialog(MAP, MAP_SIZE);
        switch (a) {
            case 0:
                std::cout << "Exit" << std::endl;
                choiceFunction = false;
                break;
            case 1:
                {
                    functionChoisen(stack, addition);
                }
                break;
            case 2:
                {
                    functionChoisen(stack, subtraction);
                }
                break;
            case 3:
                {
                    functionChoisen(stack, multiply);
                }
                break;
            case 4:
                {
                    functionChoisen(stack, division);
                }
                break;
            default:
                choiceFunction = false;
                break;
          };
     };
};

template <class T, template <class> class Sequence> void functionForStack(Stack <T, Sequence> *stack){
    bool choiceFunction = true;
    int a = 0;
    while(choiceFunction){
        a = dialog(FUNCTION, FUNCTION_SIZE);
        switch (a) {
            case 1:
                std::cout << "Map" << std::endl;
                functionForMapReduce(stack, functionChoisenMap);
                break;
            case 2:
                std::cout << "Where" << std::endl;
                functionForWhere(stack);
                break;
            case 3:
                std::cout << "Reduce" << std::endl;
                functionForMapReduce(stack, functionChoisenReduce);;
                break;
            case 4:
                std::cout << "Concatenation" << std::endl;
                {
                    Stack <T, Sequence> *newStack = new Stack <T, Sequence> ();
                    createStack <T, Sequence> (*newStack);
                    newStack -> printStack();
                    Stack <T, Sequence> *concatStack = new Stack <T, Sequence> ();
                    stack -> concatStack(newStack, *concatStack);
                    concatStack -> printStack();
                    delete newStack;
                    delete concatStack;
                }
                break;
            case 5:
                std::cout << "SubSequence(index)" << std::endl;
                {
                    Stack <T, Sequence> *newStack = new Stack <T, Sequence> ();
                    int start, end;
                    std::cout << "Введите начальный индекс" << std::endl;
                    std::cin >> start;
                    std::cout << "Введите конечный индекс" << std::endl;
                    std::cin >> end;
                    stack -> subStack(start, end,*newStack);
                    newStack -> printStack();
                    delete newStack;
                }
                break;
            case 6:
                std::cout << "Find SubSequence" << std::endl;
                {
                    Stack <T, Sequence> *newStack = new Stack <T, Sequence> ();
                    createStack <T, Sequence> (*newStack);
                    newStack -> printStack();
                    std::cout << "Начальная позиция - " << stack -> findSubStack(newStack) << std::endl;
                    delete newStack;
                }
                break;
            case 0:
                std::cout << "Exit" << std::endl;
                choiceFunction = false;
                break;
            default:
                std::cout << "Error" << std::endl;
                choiceFunction = false;
                break;
        };
    };
};
