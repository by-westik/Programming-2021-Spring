#ifndef LABA_2_MENU_CPP
#define LABA_2_MENU_CPP

#include "Stack.h"
#include "Sequence.h"
#include "LinearShape.h"

const char *MAIN[] = {"0.Exit", "1.Stack", "2.LinearShape", "3.Stack with max element"};
const int MAIN_SIZE = sizeof(MAIN) / sizeof(MAIN[0]);

const char *MENU[] = {"0.Exit", "1.Int", "2.Double", "3.Complex numbers", "4.String", "5.Functions", "6.Students", "7.Teachers"};
const int MENU_SIZE = sizeof(MENU) / sizeof(MENU[0]);

const char *SHAPE[] = {"0.Exit", "1.Int", "2.Double", "3.Complex numbers"};
const int SHAPE_SIZE = sizeof(SHAPE) / sizeof(SHAPE[0]);

const char *SEQ[] = {"0.Exit", "1.DynamicArraySequence", "2.LinkedListSequence"};
const int SEQ_SIZE = sizeof(SEQ) / sizeof(SEQ[0]);

const char *FUNCTION[] = {"0.Exit", "1.Map", "2.Where", "3.Reduce", "4.Conatenation", "5.SubSequence(index)", "6.Find SubSequence"};
const int FUNCTION_SIZE = sizeof(FUNCTION) / sizeof(FUNCTION[0]);

const char *SHAPE_FUNC[] = {"0.Exit", "1.Addition", "2.Substraction", "3.Multiplication", "4.Solve"};
const int SHAPE_FUNC_SIZE = sizeof(SHAPE_FUNC) / sizeof(SHAPE_FUNC[0]);

const char *MAP[] = {"0.Exit", "1.Addition", "2.Subtraction", "3.Multiplication", "4.Division"};
const int MAP_SIZE = sizeof(MAP) / sizeof(MAP[0]);

const char *WHERE[] = {"0.Exit", "1.IsSmaller", "2.IsBigger", "3.IsEqual", "4.IsUnEqual"};
const int WHERE_SIZE = sizeof(WHERE) / sizeof(WHERE[0]);

int dialog(const char *msgs[], const int size);
void mainMenu();
void menuForStack();
void menuForLinearShape();
template <class T> void choisenSequence();
template <class T> void choisenSequenceShape();
template <class T, template <class> class Sequence> void createTypeStack();
template <class T, template <class> class Sequence> void createTypeShape();
template <class T, template <class> class Sequence> void createStack(Stack <T, Sequence> &stack);
template <class T, template <class> class Sequence> void createShape(LinearShape <T, Sequence> &shape);
template <class T, template <class> class Sequence> void functionForStack(Stack <T, Sequence> *stack);
template <class T, template <class> class Sequence> void functionForShape(LinearShape <T, Sequence> *shape);
template <class T, template <class> class Sequence> void functionForMapReduce
(Stack <T, Sequence> *stack, void functionChoisen(Stack <T, Sequence> *stack, T function (T, T)));
template <class T, template <class> class Sequence> void functionChoisenMap(Stack <T, Sequence> *stack,  T function(T, T));
template <class T, template <class> class Sequence> void functionChoisenReduce(Stack <T, Sequence> *stack,  T function(T, T));
template <class T, template <class> class Sequence> void functionForWhere(Stack <T, Sequence> *stack);
template <class T, template <class> class Sequence> void functionChoisenWhere(Stack <T, Sequence> *stack,  bool function(T, T));
template <class T, template <class> class Sequence> void functionForScalar(LinearShape <T, Sequence> *shape,  T function(T, T));
template <class T, template <class> class Sequence> void functionShape(LinearShape <T, Sequence> *shape,  T function(T, T));

template <> void choisenSequence<std::pair<int,int>>(){
    bool choiceSequence = true;
    int a = 0;
    a = dialog(SEQ, SEQ_SIZE);
    switch(a) {
        case 0:
            break;
        case 1:
            {
                createTypeStack <std::pair<int,int>, ArraySequence> ();
            }
            break;
        case 2:
            {
                createTypeStack <std::pair<int,int>, LinkedListSequence> ();
            }
            break;
         default:
            std::cout << "Error" << std::endl;
            break;
     };
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

void mainMenu(){
    bool choiceOption = true;
    int a = 0;
    while(choiceOption){
        a = dialog(MAIN, MAIN_SIZE);
        switch(a){
            case 0:
                choiceOption = false;
                break;
            case 1:
                menuForStack();
                break;
            case 2:
                menuForLinearShape();
                break;
            case 3:
                choisenSequence<std::pair<int,int>> ();
                break;
            default:
                std::cout << "Error" << std::endl;
                choiceOption = false;
        };
    };
};

void menuForStack(){
    bool choiceType = true;
    int a = 0;
    while(choiceType){
        a = dialog(MENU, MENU_SIZE);
        switch(a) {
            case 0:
                std::cout << "Exit" << std::endl;
                choiceType = false;
                break;
            case 1:
                {
                    choisenSequence <int> ();
                }
                break;
            case 2:
                {
                    choisenSequence <double> ();
                }
                break;
            case 3:
                {
                    choisenSequence <Complex> ();
                }
                break;
            case 4:
                {
                    choisenSequence <std::string> ();
                }
                break;
            case 5:
                std::cout << "Function" << std::endl;
                std::cout << "Функций нет, но Вы держитесь" << std::endl;
                break;
            case 6:
                {
                    choisenSequence <Student> ();
                }
                break;
            case 7:
                {
                    choisenSequence <Teacher> ();
                }
                break;
            default:
                std::cout << "Error" << std::endl;
                choiceType = false;
                break;
        };
    };
};

void menuForLinearShape(){
    bool choiceType = true;
    int a = 0;
    while(choiceType){
        a = dialog(SHAPE, SHAPE_SIZE);
        switch(a) {
            case 0:
                choiceType = false;
                break;
            case 1:
                {
                    choisenSequenceShape <int> ();
                }
                break;
            case 2:
                {
                    choisenSequenceShape <double> ();
                }
                break;
            case 3:
                {
                    choisenSequenceShape <Complex> ();
                }
                break;
            default:
                std::cout << "Error" << std::endl;
                break;
        };
    };
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

template <class T> void choisenSequenceShape(){
    bool choiceSequence = true;
    int a = 0;
    a = dialog(SEQ, SEQ_SIZE);
    switch(a) {
        case 0:
            break;
        case 1:
            {
                createTypeShape <T, ArraySequence> ();
            }
            break;
        case 2:
            {
                createTypeShape <T, LinkedListSequence> ();
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

template <class T, template <class> class Sequence> void createTypeShape(){
    LinearShape <T, Sequence> *shapeType = new LinearShape <T, Sequence> ();
    createShape <T, Sequence> (*shapeType);
    shapeType -> printLinearShape();
    functionForShape <T, Sequence> (shapeType);
    delete shapeType;
};

template <class T, template <class> class Sequence> void createStack(Stack <T, Sequence> &stack){
    std::cout << "Сколько элементов Вы хотите добавить в стек?" << std::endl;
    int len = 0;
    while(len <= 0){
        std::cin >> len;
    };
    for(int i = 0; i < len; i++){
        std::cout << "Введите элемент" << std::endl;
        T n;
        std::cin >> n;
        stack.push(n);
    };
};

template <class T, template <class> class Sequence> void createShape(LinearShape <T, Sequence> &shape){
    std::cout << "Скольк элементов будет в линейной форме?" << std::endl;
    int len = 0;
    while(len <= 0){
        std::cin >> len;
    };
    for(int i = 0; i < len; i++){
        std::cout << "Введите элемент" << std::endl;
        T n;
        std::cin >> n;
        shape.addRatio(n);
    };
};

template <class T, template <class> class Sequence> void functionForStack(Stack <T, Sequence> *stack){
    bool choiceFunction = true;
    int a = 0;
    while(choiceFunction){
        a = dialog(FUNCTION, FUNCTION_SIZE);
        switch (a) {
            case 0:
                std::cout << "Exit" << std::endl;
                choiceFunction = false;
                break;
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
                    try{
                        stack -> concatStack(newStack, *concatStack);
                        concatStack -> printStack();
                        delete stack -> list;
                        stack -> list = new Sequence <T> (*(concatStack -> list));
                    }
                    catch (Error &error){
                        std::cout << "Error: " << error.getError() << std::endl;
                    }
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
                    try{
                        stack -> subStack(start, end,*newStack);
                        newStack -> printStack();
                    }
                    catch (Error &error){
                        std::cout << "Error: " << error.getError() << std::endl;
                    }
                    delete newStack;
                }
                break;
            case 6:
                std::cout << "Find SubSequence" << std::endl;
                {
                    Stack <T, Sequence> *newStack = new Stack <T, Sequence> ();
                    createStack <T, Sequence> (*newStack);
                    newStack -> printStack();
                    try{
                        int index = stack -> findSubStack(newStack);
                        if(index >= 0){
                            std::cout << "Начальная позиция - " << stack -> findSubStack(newStack) << std::endl;
                        } else {
                            std::cout << "Не найдено" << std::endl;
                        };
                    }
                    catch (Error &error){
                        std::cout << "Error: " << error.getError() << std::endl;
                    }
                    delete newStack;
                }
                break;
            default:
                std::cout << "Error" << std::endl;
                choiceFunction = false;
                break;
        };
    };
};

template <class T, template <class> class Sequence> void functionForMapReduce
(Stack <T, Sequence> *stack, void functionChoisen(Stack <T, Sequence> *stack,  T function(T, T))){
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

template <class T, template <class> class Sequence> void functionChoisenMap(Stack <T, Sequence> *stack,  T function(T, T)){
    std::cout << "Введите элемент для выполнения дейсвий со стеком" << std::endl;
    T n;
    std::cin >> n;
    try{
        stack -> map(function, n);
        stack -> printStack();
    }
    catch (Error &error){
        std::cout << "Error: " << error.getError() << std::endl;
    }
};

template <class T, template <class> class Sequence> void functionChoisenReduce(Stack <T, Sequence> *stack,  T function(T, T)){
    std::cout << "Введите элемент для выполнения дейсвий со стеком" << std::endl;
    T n;
    std::cin >> n;
    try{
        std::cout << stack -> reduce(function, n) << std::endl;
    }
    catch (Error &error){
        std::cout << "Error: " << error.getError() << std::endl;
    }
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

template <class T, template <class> class Sequence> void functionChoisenWhere(Stack <T, Sequence> *stack,  bool function(T, T)){
    std::cout << "Введите элемент для сравнения" << std::endl;
    T n;
    std::cin >> n;
    try{
        stack -> where(function, n);
        stack -> printStack();
    }
    catch (Error &error){
        std::cout << "Error: " << error.getError() << std::endl;
    }
};

template <class T, template <class> class Sequence> void functionForShape(LinearShape <T, Sequence> *shape){
    bool choiceFunction = true;
    int a = 0;
    while(choiceFunction){
        a = dialog(SHAPE_FUNC, SHAPE_FUNC_SIZE);
        switch (a) {
            case 0:
                std::cout << "Exit" << std::endl;
                choiceFunction = false;
                break;
            case 1:
                std::cout << "Addition" << std::endl;
                functionShape(shape, addition);
                break;
            case 2:
                std::cout << "Substraction" << std::endl;
                functionShape(shape, subtraction);
                break;
            case 3:
                std::cout << "Multiplication" << std::endl;
                functionForScalar(shape, multiply);
                break;
            case 4:
                std::cout << "Solve" << std::endl;
                {
                    T solution = shape -> solve();
                    shape -> printLinearShape();
                    std::cout << " = " << std::endl;
                    std::cout << solution << std::endl;
                };
                break;
             default:
                std::cout << "Error" << std::endl;
                choiceFunction = false;
                break;
         };
    };
};

template <class T, template <class> class Sequence> void functionShape(LinearShape <T, Sequence> *shape,  T function(T, T)){
    std::cout << "Введите вторую линейную форму" << std::endl;
    LinearShape <T, Sequence> *shapeTwo = new LinearShape <T, Sequence> ();
    createShape(*shapeTwo);
    shape -> printLinearShape();
    shapeTwo -> printLinearShape();
    shape -> changeShape(*shapeTwo, function);
    shape -> printLinearShape();
    delete shapeTwo;
};

template <class T, template <class> class Sequence> void functionForScalar(LinearShape <T, Sequence> *shape,  T function(T, T)){
    std::cout << "Введите элемент для изменения линейной формы" << std::endl;
    T n;
    std::cin >> n;
    shape -> printLinearShape();
    shape -> changeRatio(function, n);
    shape -> printLinearShape();
};

#endif //LABA_2_MENU_CPP
