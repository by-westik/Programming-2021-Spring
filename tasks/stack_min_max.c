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

int main(){
    Stack *s = stack_new();
    int len  = 0;
    printf("Введите количество вводимых элементов\n");
    scanf("%d", &len);
    for(int i = 0; i < len; i++){
        int n = 0;
        printf("Введите значение элемента\n");
        scanf("%d", &n);
        push(s, n);
    }
    print_stack(s);
    Item value;
    pop(s, &value);
    printf("Минимальный элемент = %d\nМаксимальный элемент = %d\n", value.min, value.max);
    delete_stack(s);
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

int pop(Stack *stack, Item *result) {
    if (!stack->head) {
        return -1;
    }
    result -> min = stack -> head -> min;
    result -> max = stack -> head -> max;
    Item *head = stack->head;
    stack->head = head->next;
    free(head);
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

void delete_stack(Stack *stack){
    Item *ptr = stack -> head, *ptr_prev;
    while(ptr){
        ptr_prev = ptr;
        ptr = ptr -> next;
        free(ptr_prev);
    }
    free(stack);
}