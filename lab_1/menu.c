#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "function_for_void_str.h"
const char *MSGS[] = {"0. Выход", "1. Конкантенация строк", "2. Поиск подстроки по индексу", "3. Поиск введенной подстроки"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int menu(const char *msgs[], int n);
void function_1(struct void_str* void_str);
void function_2(struct void_str* void_str);
void function_3(struct void_str* void_str);

int main() {
    int c = 0;
    struct void_str* void_str = NULL;
    printf("Введите строку\nP.S. Строка типа char, другого все равно нет\n");
    do{
        void_str = create_void_str();
    } while (void_str -> size == 1);
    printf("Введенная строка - '%s'\n", (char*) void_str -> data);
    do {
        c = menu(MSGS, MSGS_SIZE);
        switch(c) {
        case 0:
            break;
        case 1:
            printf("\n******** Конкантенация строк ********\n");
            function_1(void_str);
            break;
        case 2:
            printf("********\nПоиск подстроки по индексу\n********\n");
            function_2(void_str);
            break;
        case 3:
            printf("********\nПоиск введенной подстроки\n********\n");
            function_3(void_str);
        }
    } while (c != 0);
    delete_void_str(*void_str);
    delete_void_ptr_str(void_str);
    return 0;
}

void function_1(struct void_str* void_str){
    printf("Для этой фунции требуется еще одна строка\nВведите её ниже\n");
    struct void_str* void_str_2 = NULL;
    do{
        void_str_2 = create_void_str();
    } while (void_str_2 -> size == 1);
    void_str = concatenation(void_str, void_str_2);
    printf("Результирующая строка - '%s'\n", (char*) void_str -> data);
}

void function_2(struct void_str* void_str){
    size_t start, end;
    printf("Введите номер индекса начала подстроки\n");
    scanf("%ld", &start);
    printf("Введите номер индекса конца подстроки\n");
    scanf("%ld", &end);
    struct void_str* sub_str = substring(void_str, start, end);
    printf("Подстрока - '%s'\n", (char*) sub_str -> data);
    delete_void_str(*sub_str);
    delete_void_ptr_str(sub_str);
}

void function_3(struct void_str* void_str){
    printf("Для этой фунции требуется еще одна строка\nВведите её ниже\n");
    struct void_str* void_str_2 = NULL;
    do{
        void_str_2 = create_void_str();
    } while (void_str_2 -> size == 1);
    int c = 0;
    printf("Выберите вариант поиска подстроки\n1. Чувствительный к регистру\n2. Не чувствительный к регистру\n");
    scanf("%d", &c);
    size_t index;
    if(c == 1){
        index = find_substr(void_str, void_str_2, funk);
    } else {
        index = find_substr(void_str, void_str_2, tolower);
    }
    printf("Первое вхождение строки 2 в строку 1 начинается по индексу - %ld\n", index);
    delete_void_str(*void_str_2);
    delete_void_ptr_str(void_str_2);
}

int menu(const char *msgs[], int n) {
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