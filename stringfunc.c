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

int main() {
  char s1[10] ="HELLO!";
  char s2[] = "hello?";
  char *s3 = "hello";
  char s4[] = "";

  printf("S! %s\n", s1);
  printf("S2 %s\n", s2);
  printf("S3 %s\n", s3);
  printf("S4 %s\n", s4);
  
  
  printf("LEN TESTING\n");

  printf("standard %ld\n", strlen(s1));
  printf("homemade %d\n", mystrlen(s1));

  printf("standard %ld\n", strlen(s3));
  printf("homemade %d\n", mystrlen(s3));

  printf("standard %ld\n", strlen(s4));
  printf("homemade %d\n", mystrlen(s4));

  printf("Testing strncpy (s1, s3, 3)\n");
  printf("standard %s\n", strncpy(s1, s3, 6));
  printf("homemade %s\n", strncpy(s1, s3, 6));

  
  
  return 0;
}
