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

char * strncat(char *dest, char *source, int n) {
  char *original = dest;
  while(*(dest++) != '\0');
  int i;
  for (i = 0; i < n && *(dest+i) != '\0'; i++) {
    *(dest+i) = *(source+1);
  }
  *dest = '\0';
  return original
}

