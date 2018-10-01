#include <stdio.h>
#include <string.h>
#include "stringfunc.h"

int mystrlen(char *s) {
    int size;
    for (size = 0; *(s+size) != '\0'; size++);
    return size;
}

char * mystrncpy(char *dest, char *source, int n) {
    int i;
    for (i = 0; i < n && *(source+i) != '\0'; i++) {
        *(dest+i) = *(source+i);
    }
    return dest;
}

char * mystrncat(char *dest, char *source, int n) {
    char *original = dest;
    while(*(dest++) != '\0');
    dest--;
    int i;
    for (i = 0; i < n && *(source+i) != '\0'; i++) {
        *(dest+i) = *(source+i);
    }
    *(dest+n) = '\0';
    return original;
}

int mystrcmp(char *s1, char *s2) {
    int i;
    char * max;
    if (strlen(s1) > strlen(s2)){
        max = s1;
    } else {
        max = s2;
    }
    for (i = 0; i < strlen(max) + 1; i++){
        if(s1[i] == s2[i]) {
            if (s1[i] == 0) {
                return 0;
            }
        } else if (s1[i] > s2[i]) {
            return 1;
        } else { //this is if s2 is greater than s1
            return -1;
        }
    }
}

char * mystrchr(char *s, char c){
    int size;
    for (size = 0; *s != '\0'; size++){
        //printf("comparing %s and %c\n", s, c);
        if(c == *s) {
            return s;
        } else {
            s++;
        }
    }
}

