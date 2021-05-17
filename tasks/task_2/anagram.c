#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enter_array(char ***array, int len);
char *enter_str();
void sort_str(char *str);
void n_anagram(char **array, int len);

int main() {
    int len;
    char **array = NULL;
    scanf("%d", &len);
    enter_array(&array, len);
    n_anagram(array, len);
    return 0;
}

void enter_array(char ***array, int len){
    char **new_array = (char**) calloc(len + 1, sizeof(char*));
    char *str = NULL;
    for(int i = 0; i <= len; i++){
        str = enter_str();
        sort_str(str);
        new_array[i] = str;
    }
    *array = new_array;
}

char *enter_str() {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);


    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }

    return res;
}
void sort_str(char *str){
    int n = strlen(str);
    char temp;
    for (int i = 0; i < n - 1; i++) {
	    for (int j = i + 1; j < n; j++) {
		    if (str[i] > str[j]) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
		    }
	    }
    }
}

void n_anagram(char **array, int len){
    int counter = 0, max = 0;
    for(int i = 0; i <= len; i++){
        counter = 0;
        for(int j = i  ; j <= len; j++){
            if(strcmp(array[i], array[j]) == 0){
                counter++;
            }
        }
        if(counter >= max){
            max = counter;
        }
    }
    printf("%d", max);
}
