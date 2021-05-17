#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_str();
int find_smile(char *str, int index);
char *substr(char *str, int start, int length);

int main() {
    char *s = NULL;
    do {
        s = get_str();
        if (s) {
            printf("%s\n", s);
            find_smile(s, 0);
            printf("'%s'\n", s);
            free(s);
        }
    } while (s);
    return 0;
}

char *get_str() {
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

int find_smile(char *str, int index){
    char *buf = ":-)";
    while(str[index] != '\0'){
        if(str[index] == ':'){
            if(str[index + 1] == ':'){
                find_smile(str, index + 1);
            }
            int i = 0, flag = 1, len = 0, pred_index = index;
            while((len < 3) && (flag == 1)){
                if(str[index] != buf[i]){
                    flag = 0;
                }
                index++;
                len++;
                i++;
            }
            if(flag == 1){
                int j = index - 3;
                while(str[j] != '\0'){
                     str[j] = str[index];
                     j++;
                     index++;
                }
                index = pred_index;
            }
        }
        index++;
    }
}