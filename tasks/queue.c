#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int data;
    int min;
    int max;
    struct Item *next;
} Item;

typedef struct Stack {
    Item *head;
} Stack;

Stack *stack_new(){
    return (Stack *) calloc(1, sizeof(Stack));
}

int push(Stack *stack, int data);
int pop(Stack *stack, Item *result);
void print_stack(Stack *stack);
void delete_stack(Stack *stack);
int find(Stack *stack_1, Stack *stack_2, Item *result);
void fill_stack(Stack *stack);

int main(){
    Stack *s_1 = stack_new();
    Stack *s_2 = stack_new();
    int y_n;
    fill_stack(s_1);
    printf("*****Stack_1*****\n");
    print_stack(s_1);
    Item value;
    find(s_1, s_2, &value);
    printf("*****Stack_2*****\n");
    print_stack(s_2);
    printf("Минимальный элемент = %d\nМаксимальный элемент = %d\n", value.min, value.max);
    printf("Хотите добавить элементы в очередь?\n");
    scanf("%d", &y_n);
    if(y_n == 1){
        fill_stack(s_1);
        printf("*****Stack_1*****\n");
        print_stack(s_1);
        find(s_1, s_2, &value);
        printf("*****Stack_2*****\n");
        print_stack(s_2);
        printf("Минимальный элемент = %d\nМаксимальный элемент = %d\n", value.min, value.max);
    }
    delete_stack(s_1);
    delete_stack(s_2);
    return 0;
}

int push(Stack *stack, int data) {
    Item *ptr = (Item *) malloc(sizeof(Item)), *head = stack -> head;
    if (!ptr) {
        return -1;
    }
    ptr->data = data;
    ptr->next = stack->head;
    stack->head = ptr;
    if(!(stack -> head -> next)){
       stack -> head -> min = data;
       stack -> head -> max = data;
    }else{
        if((head -> max) >= data){
            stack -> head -> max = head -> max;
        } else {
            stack -> head -> max = data;
        }
        if((head -> min) <= data){
            stack -> head -> min = head -> min;
        } else {
            stack -> head -> min = data;
        }
    }
    return 0;
}

void print_stack(Stack *stack) {
    Item *ptr = stack->head;
    while (ptr) {
        printf("[%d %d %d]", ptr->data, ptr -> min, ptr -> max);
        ptr = ptr->next;
        printf("\n");
    }
    printf("\n");
}

void fill_stack(Stack *stack){
    int len = 0;
    while(len <= 0){
        printf("Введите количество вводимых элементов\n");
           scanf("%d", &len);
    }
    for(int i = 0; i < len; i++){
        int n = 0 ;
        printf("Введите значение элемента\n");
        scanf("%d", &n);
        push(stack, n);
    }
}

void delete_stack(Stack *stack){
    Item *ptr = stack -> head, *ptr_prev;
    while(ptr){
        ptr_prev = ptr;
        ptr = ptr -> next;
        free(ptr_prev);
    }
    free(stack);
}

int pop(Stack *stack, Item *result) {
    if (!stack->head) {
        return -1;
    }
    result -> data = stack -> head -> data;
    result -> min = stack -> head -> min;
    result -> max = stack -> head -> max;
    Item *head = stack->head;
    stack->head = head->next;
    free(head);
    return 0;
}


int find(Stack *stack_1, Stack *stack_2, Item *result){
    Item *ptr = stack_1 -> head, value_1, value_2;
    int res;
    if(!stack_2 -> head){
       while((res = pop(stack_1, &value_2)) != -1){
           push(stack_2, value_2.data);
       }
       pop(stack_2, result);
    } else if ((stack_2 -> head) && (stack_1 -> head)){
       pop(stack_1, &value_1);
       pop(stack_2, &value_2);
       if(value_1.max >= value_2.max){
          result -> max = value_1.max;
       } else {
          result -> max = value_2.max;
       }
       if(value_1.min <= value_2.min){
          result -> min = value_1.min;
       } else {
          result -> min = value_2.min;
       }
       while((res = pop(stack_1, &value_2)) != -1){
           push(stack_2, value_2.data);
       }
    }
}