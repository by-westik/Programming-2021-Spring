#include <stdlib.h>
#include <stdio.h>

const char *MSGS[] = {"0. Quit", "1. Display list items on screen", "2. Display list items in reverse order", "3. Reverse list", "4. Checking a list for a palindrome","5. Add item to the end of the list"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

typedef struct List {
    int data;
    struct List *next;
} List;

List *list_new(){
    return (List*)calloc(1,sizeof(List));
}

int dialog(const char *msgs[], int n);
void fill_list(int len, List *list);
void print_list(List *list);
void print_reverse(List *list);
void reverse(List **list);
void put_end(int value, List *list);
int list_palindrom(List *list, int len);
void delete_list(List *list);

int main(){
    List *list = list_new();
    int c = 0, len = 0, p, value;
    printf("Enter the number of items in the list\n");
    scanf("%d", &len);
    while(len <= 0){
        printf("You're wrong. Try again!\n");
         scanf("%d", &len);
    }
    fill_list(len, list);
    scanf("%*c");
    do {
        c = dialog(MSGS, MSGS_SIZE);
        switch(c) {
        case 0:
            break;
        case 1:
            print_list(list);
            break;
        case 2:
            print_reverse(list);
            break;
        case 3:
            printf("Source List\n");
            print_list(list);
            reverse(&list);
            printf("\nModified list\n");
            print_list(list);
            break;
        case 4:
            p = list_palindrom(list, len);
            if(p == 1){
                printf("The list is a palindrom\n");
            } else {
                printf("The list isn't a palindrome\n");
            }
            break;
        case 5:
            printf("Enter the value of the new item\n");
            scanf("%d", &value);
            printf("Source List\n");
            print_list(list);
            put_end(value, list);
            printf("\nModified list\n");
            print_list(list);
            len++;
            scanf("%*c");
            break;
        }
    } while (c != 0);
    delete_list(list);
   return 0;
}

int dialog(const char *msgs[], int n) {
    char *error = "";
    int choice;
    do {
        puts(error);
        error = "You're wrong. Try again!";
        for (int i = 0; i < n; ++i) {
            puts(msgs[i]);
        }
        puts("Make your choice: ");
        choice = getchar() - '0';
        while (getchar() != '\n') {}
    } while (choice < 0 || choice >= n);
    return choice;
}

void fill_list(int len, List *list){
    List *ptr = list;
    printf("Below enter the values ​​of the list items\n");
    scanf("%d", &(ptr -> data));
    for(int i = 0; i < len - 1; i++){
        List *element = list_new();
        scanf("%d", &(element -> data));
        ptr -> next = element;
        ptr = ptr -> next;
    }
     ptr = NULL;
}

void print_list(List *list){
    List *ptr = list;
    while(ptr){
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

void print_reverse(List *list){
    List *ptr = list;
    if(!ptr){
        return;
    }
    print_reverse(ptr -> next);
    printf("%d ", ptr -> data);
}

void reverse(List **list){
    List *ptr = *list, *next = NULL, *previous = NULL;
    while(ptr){
        next = ptr -> next;
        ptr -> next = previous;
        previous = ptr;
        ptr = next;
    }
    *list = previous;
}

void put_end(int value, List *list){
    List *ptr = list;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }
    ptr -> next = list_new();
    ptr = ptr -> next;
    ptr -> data = value;
    ptr -> next = NULL;
}

int list_palindrom(List *list, int len){
    int i = 0;
    while(i != len / 2){
        List *start = list;
        List *end = list;
        for(int j = 0; j < i; j++){
            start = start -> next;
        }
        for(int j = 0; j < len - (i + 1); j++){
            end = end -> next;
        }
        if(start -> data != end -> data){
            return 0;
        } else {
            i++;
        }
    }
    return 1;
}

void delete_list(List *list){
    List *ptr = list, *ptr_previous;
    while(ptr){
        ptr_previous = ptr;
        ptr = ptr -> next;
        free(ptr_previous);
    }
}