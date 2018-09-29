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
  for (i = 0; i < n && *(dest+i) != '\0'; i++) {
    *(dest+i) = *(source+i);
  }
  return dest;
}

char * mystrncat(char *dest, char *source, int n) {
  char *original = dest;
  while(*(dest++) != '\0');
  int i;
  for (i = 0; i < n && *(dest+i) != '\0'; i++) {
    *(dest+i) = *(source+1);
  }
  *dest = '\0';
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

int main() {
  char s1[8] ="HELLO!";
  char s2[] = "hello?";
  char *s3 = "world";
  char s4[] = "";

  printf("S1 %s\n", s1);
  printf("S2 %s\n", s2);
  printf("S3 %s\n", s3);
  printf("S4 %s\n", s4);
  
  
  printf("============================\nLEN TESTING\n");

  printf("Length of s1");
  printf("[standard]: %ld\n", strlen(s1));
  printf("[mine]: %d\n", mystrlen(s1));
  
  printf("Length of s2");
  printf("[standard]: %ld\n", strlen(s2));
  printf("[mine]: %d\n", mystrlen(s2));
  

  printf("Length of s3");
  printf("[standard]: %ld\n", strlen(s3));
  printf("[mine]: %d\n", mystrlen(s3));

  printf("Length of s4");
  printf("[standard]: %ld\n", strlen(s4));
  printf("[mine]: %d\n", mystrlen(s4));

  printf("============================\nTesting strncpy\n");
  
  printf("Standard\n strncpy(s2,s3,3) \n");
  printf("[standard]: %s\n", strncpy(s2, s3, 3));
  printf("[mine]: %s\n", mystrncpy(s2, s3, 3));
  printf("s2: %s\n", s2);
  
  
  printf("Copy char array into a smaller char array\n strncpy(s1, s2, 4)\n");
  printf("[standard]: %s\n", strncpy(s1, s2, 4));
  printf("[mine]: %s\n", mystrncpy(s1, s2, 4));
  printf("s1: %s\n", s1);
  
  // need to look into this 
  // why does strncpy return "worrlo?"
  printf("CONFUSED +++++++++++++++++++++++++++++++++++++++++++++++\n");
  printf("Copy char array into an empty char arrray\n strncpy(s4, s2, 3)\n");
  printf("s4: %s\n", s4);
  printf("s2: %s\n", s2);
  printf("[standard]: %s\n", strncpy(s4, s2, 3)); // returns "worllo?"
  printf("[mine]: %s\n", mystrncpy(s4, s2, 3)); // returns ""
  printf("s4: %s\n", s4);

  // Segmentation fault
  //printf("Copy char array into a string literal\n strncpy("abcd", s2, 3)\n");
  //printf("[standard]: %s\n", strncpy("abcd", s2, 3));
  //printf("[mine]: %s\n", mystrncpy("abcd", s2, 3));
  
  
  printf("Copy a string literal into char array\n strncpy(s1, abcd, 3)\n");
  printf("[standard]: %s\n", strncpy(s1, "abcd", 3));
  printf("[mine]: %s\n", mystrncpy(s1, "abcd", 3));
  printf("s1: %s\n", s1);
  
  // Segmentation fault 
  //printf("Copy a string literal into a string literal\n strncpy(abcd, wxyz, 3)\n");
  //printf("[standard]: %s\n", strncpy("abcd", "wxyz", 3));
  //printf("[mine]: %s\n", mystrncpy("abcd", "wxyz", 3));
  
  // STACK SMASHING 
  /*
  printf("============================\nTesting strncat\n");
  printf("[standard]: %s\n", strncat(s1, s3, 3));
  printf("[mine]: %s\n", mystrncat(s1, s3, 3));
  */
  printf("============================\nTesting strcmp\n");
  printf("Testing abcd vs abcd\n");
  printf("[standard]: %i\n", strcmp("abcd", "abcd"));
  printf("[mine]: %i\n", mystrcmp("abcd", "abcd"));
  printf("Testing abc vs abcd\n");
  printf("[standard]: %i\n", strcmp("abc", "abcd"));
  printf("[mine]: %i\n", mystrcmp("abc", "abcd"));
  printf("Testing abcd vs abc\n");
  printf("[standard]: %i\n", strcmp("abcd", "abc"));
  printf("[mine]: %i\n", mystrcmp("abcd", "abc"));
  
  printf("============================\nTesting strchr \n");
  printf("Testing abcd and a\n");
  printf("[standard]: %s\n", strchr("abcd", 'a'));
  printf("[mine]: %s\n", mystrchr("abcd", 'a'));
  printf("Testing abc and b\n");
  printf("[standard]: %s\n", strchr("abc", 'b'));
  printf("[mine]: %s\n", mystrchr("abc", 'b'));
  printf("Testing abcd and c\n");
  printf("[standard]: %s\n", strchr("abcd", 'c'));
  printf("[mine]: %s\n", mystrchr("abcd", 'c'));
  printf("Testing hello world and e\n");
  printf("[standard]: %s\n", strchr("hello world", 'e'));
  printf("[mine]: %s\n", mystrchr("hello world", 'e'));
  
  return 0;
}
