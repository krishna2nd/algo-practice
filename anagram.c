#include <stdio.h>

char *sort(char *str) {
    int len = strlen(str);
    char tmp = NULL;
    for (int i =0; i< len; i++) {
        for(int j=0;j<len;j++) {
            if (str[i] < str[j]) {
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
    return str;
}

int isAnagram(char *str1, char *str2) {
    if (strlen(str1) != strlen(str2)) return 0;
    char* ptr1 = str1;
    char* ptr2 = str2;
    while(*ptr1) {
        if (*ptr1 != *ptr2) return 0;
        ptr1++;ptr2++;
    }
    return 1;
}


int main() {
    char str[2][100] = {{"brainy"}, {"binary"}};
    fprintf(stderr, "%s %s\n" , str[0], str[1]);
    sort(str[0]);
    sort(str[1]);
    printf("%d", isAnagram(str[0], str[1]));
}
