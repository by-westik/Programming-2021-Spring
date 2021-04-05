#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "function_for_void_str.h"

const char *MSGS[] = {"0. Выход", "1. Конкантенация строк", "2. Поиск подстроки по индексу", "3. Поиск введенной подстроки", "4. Удаление всех подстрок из строки"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);
const char *CRGN[] = {"0. Ввести самостоятельно", "1. Сгенерировать"};
const int CRGN_SIZE = sizeof(CRGN) / sizeof(CRGN[0]);

int menu(const char *msgs[], int n);
void function_1(struct void_str* void_str);
void function_2(struct void_str* void_str);
void function_3(struct void_str* void_str);
void function_4(struct void_str* void_str);
void create_generate(struct void_str** void_str);

int main() {
    srand(time(NULL));
    int c = 0;
    struct void_str* void_str = NULL;
    create_generate(&void_str);
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
            break;
        case 4:
            printf("********\nУдаление всех подстрок из строки\n********\n");
            function_4(void_str);
            break;
        }
    } while (c != 0);
    delete_void_str(*void_str);
    delete_void_ptr_str(void_str);
    return 0;
}

void function_1(struct void_str* void_str){
    printf("Для этой фунции требуется еще одна строка\nВведите её ниже\n");
    struct void_str* void_str_2 = NULL;
    create_generate(&void_str_2);
    void_str = concatenation(void_str, void_str_2);
    printf("Результирующая строка - '%s'\n", (char*) void_str -> data);
    delete_void_str(*void_str_2);
    delete_void_ptr_str(void_str_2);
}

void function_2(struct void_str* void_str){
    int start, end;
    printf("Введите номер индекса начала подстроки\n");
    scanf("%d", &start);
    printf("Введите номер индекса конца подстроки\n");
    scanf("%d", &end);
    struct void_str* sub_str = substring(void_str, start, end);
    if(sub_str){
       printf("Подстрока - '%s'\n", (char*) sub_str -> data);
       delete_void_str(*sub_str);
       delete_void_ptr_str(sub_str);
    }
}

void function_3(struct void_str* void_str){
    printf("Для этой фунции требуется еще одна строка\nВведите её ниже\n");
    struct void_str* void_str_2 = NULL;
    create_generate(&void_str_2);
    int c = 0;
    printf("Выберите вариант поиска подстроки\n1. Чувствительный к регистру\n2. Не чувствительный к регистру\n");
    scanf("%d", &c);
    int index = 0;
    if(c == 1){
        index = find_substr(void_str, void_str_2, funk);
    } else {
        index = find_substr(void_str, void_str_2, tolower);
    }
    if(index >= 0){
        printf("Первое вхождение строки '%s' в строку '%s' начинается по индексу - %d\n", (char*) void_str_2 -> data, (char*) void_str -> data, index);
    } else {
        printf("Строка '%s' не входит в строку '%s'\n", (char*) void_str_2 -> data, (char*) void_str -> data);
    }
    delete_void_str(*void_str_2);
    delete_void_ptr_str(void_str_2);
}


void function_4(struct void_str* void_str){
    struct void_str* void_str_2 = NULL;
    create_generate(&void_str_2);
    if(delete_all_sub_str(void_str, void_str_2)){
        printf("В результате удаления подстроки '%s', получается строка '%s'\n", (char*) void_str_2 -> data, (char*) void_str -> data);
    }
    delete_void_str(*void_str_2);
    delete_void_ptr_str(void_str_2);
}

int menu(const char *msgs[], int n) {
    char *error = "";
    int choice;
    do {
        puts(error);
        error = "Попробуйте еще раз!";
        for (int i = 0; i < n; ++i) {
            puts(msgs[i]);
        }
        puts("Сделайте выбор: ");
        choice = getchar() - '0';
        while (getchar() != '\n') {}
    } while (choice < 0 || choice >= n);
    return choice;
}

void create_generate(struct void_str** void_str){
    printf("Вы хотите сгенерировать строку или ввести самостоятельно?\n");
    int c = 0, len = 0;
    do{
        c = menu(CRGN, CRGN_SIZE);
        switch(c){
        case 0:
            do{
                printf("Введите строку ниже\n");
                *void_str = create_void_str();
            } while ((*void_str) == NULL);
            printf("Введенная строка - '%s'\n", (char*) (*void_str) -> data);
            break;
        case 1:
            do{
                printf("Введите длину строки\n");
                scanf("%d", &len);
            } while (len <= 0);
            *void_str = random_void_str(len + 1, sizeof(void));
            printf("Сгенерированная строка - '%s'\n", (char*) (*void_str) -> data);
            break;
       }
    } while ((c == 0) && (c == 1));
}
