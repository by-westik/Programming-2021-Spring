
template <class T, template <class> class Sequence> void createStack(Stack <T, Sequence> &stack){
    std::cout << "Сколько элементов Вы хотите добавить в стек?" << std::endl;
    int len = 0;
    while(len <= 0){
        std::cin >> len;
    }
    for(int i = 0; i < len; i++){
        std::cout << "Введите элемент" << std::endl;
        T n = 0;
        std::cin >> n;
        stack.push(n);
    }
};
/*
template <> void createStack <Complex, LinkedListSequence> (Stack <Complex, LinkedListSequence> &stack){
    std::cout << "Сколько элементов Вы хотите добавить в стек?" << std::endl;
    int len = 0;
    while(len <= 0){
        std::cin >> len;
    }
    for(int i = 0; i < len; i++){
        std::cout << "Введите x" << std::endl;
        double r, im;
        std::cin >> r;
        std::cout << "Введите y" << std::endl;
        std::cin >> im;
        stack.push(Complex(r,im));
    }
}
*/
int main () {
    Stack <int, LinkedListSequence> n;
  //  n.createStack();
    createStack <int, LinkedListSequence> (n);
    n.printStack();
 }
