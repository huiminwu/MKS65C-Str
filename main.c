#include <stdio.h>
#include <string.h>
#include "stringfunc.h"


int main() {
  char s1[] ="HELLO!";
  char s2[256] = "hello?";
  char *s3 = "world";
  char s4[] = "";
  
  char r1[] ="HELLO!";
  char r2[256] = "hello?";
  char *r3 = "world";
  char r4[] = "";
  
  printf("============================\nLEN TESTING\n");

  printf("S1 %s\n", s1);
  printf("S2 %s\n", s2);
  printf("S3 %s\n", s3);
  printf("S4 %s\n", s4);
  
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
  
  printf("S1 %s\n", s1);
  printf("S2 %s\n", s2);
  printf("S3 %s\n", s3);
  printf("S4 %s\n", s4);
  
  printf("Standard\n strncpy(s2,s3,3) \n");
  printf("[standard]: %s\n", strncpy(s2, s3, 3));
  printf("[mine]: %s\n", mystrncpy(r2, r3, 3));
  printf("s2: %s\n", s2);
  printf("r2: %s\n", r2);
  
  
  printf("Copy char array into a smaller char array\n strncpy(s1, s2, 4)\n");
  printf("[standard]: %s\n", strncpy(s1, s2, 4));
  printf("[mine]: %s\n", mystrncpy(r1, r2, 4));
  printf("s1: %s\n", s1);
  printf("r1: %s\n", r1);
  
  // need to look into this 
  // why does strncpy return "worrlo?"
  
  /*
  printf("CONFUSED +++++++++++++++++++++++++++++++++++++++++++++++\n");
  printf("Copy char array into an empty char arrray\n strncpy(s4, s2, 3)\n");
  printf("s4: %s\n", s4);
  printf("s2: %s\n", s2);
  printf("[standard]: %s\n", strncpy(s4, s2, 3)); // returns "worllo?"
  printf("[mine]: %s\n", mystrncpy(s4, s2, 3)); // returns ""
  printf("s4: %s\n", s4);
   */
  
  
  // Segmentation fault
  //printf("Copy char array into a string literal\n strncpy(abcd, s2, 3)\n");
  //printf("[standard]: %s\n", strncpy("abcd", s2, 3));
  //printf("[mine]: %s\n", mystrncpy("abcd", s2, 3));
  
  
  printf("Copy a string literal into char array\n strncpy(s1, abcd, 3)\n");
  printf("[standard]: %s\n", strncpy(s1, "abcd", 3));
  printf("[mine]: %s\n", mystrncpy(r1, "abcd", 3));
  printf("s1: %s\n", s1);
  printf("r1: %s\n", r1);
  
  // Segmentation fault 
  //printf("Copy a string literal into a string literal\n strncpy(abcd, wxyz, 3)\n");
  //printf("[standard]: %s\n", strncpy("abcd", "wxyz", 3));
  //printf("[mine]: %s\n", mystrncpy("abcd", "wxyz", 3));
  
  
  
  printf("============================\nTesting strncat\n");
  
  char s5[] ="BIRMAN";
  char s6[256] = "DEVON";
  char *s7 = "MANX";
  char s8[] = "";
  
  char r5[] ="BIRMAN";
  char r6[256] = "DEVON";
  char *r7 = "MANX";
  char r8[] = "";
  
  printf("S5 %s\n", s5);
  printf("S6 %s\n", s6);
  printf("S7 %s\n", s7);
  printf("S8 %s\n", s8);
  
  // STACK SMASHING 
  //printf("[standard]: %s\n", strncat(s1, s3, 3));
  //printf("[mine]: %s\n", mystrncat(s1, s3, 3));
  
  printf("Standard\n strncat(s6,s7,3) \n");
  printf("[standard]: %s\n", strncat(s6, s7, 10));
  printf("[mine]: %s\n", mystrncat(r6, r7, 10));
  printf("s6: %s\n", s6);
  printf("r6: %s\n", r6);
  
  // STACK SMASHING
  //printf("Cat char array into a smaller char array\n strncat(s5, s6, 4)\n");
  //printf("[standard]: %s\n", strncat(s5, s6, 4));
  //printf("[mine]: %s\n", mystrncat(s5, s6, 4));
  //printf("s5: %s\n", s5);
  
  /*
  printf("Cat char array into an empty char arrray\n strncat(s8, s6, 3)\n");
  printf("s8: %s\n", s8);
  printf("r8: %s\n", r8);
  printf("s6: %s\n", s6);
  printf("r6: %s\n", r6);
  printf("[standard]: %s\n", strncat(s8, s6, 3));
  printf("[mine]: %s\n", mystrncat(r8, r6, 3));
  printf("s8: %s\n", s8);  
  printf("r8: %s\n", r8);  
  */
  
  
  // Segmentation fault 
  //printf("Cat char array into a string literal\n strncat(abcd, s6, 3)\n");
  //printf("[standard]: %s\n", strncat("abcd", s6, 3));
  //printf("[mine]: %s\n", mystrncat("abcd", s6, 3));
  
  printf("Cat a string literal into char array\n strncat(s6, abcd, 3)\n");
  printf("[standard]: %s\n", strncat(s6, "abcd", 3));
  printf("[mine]: %s\n", mystrncat(r6, "abcd", 3));
  printf("s6: %s\n", s6);
  printf("r6: %s\n", r6);
  
  // Segmentation fault
  //printf("Cat a string literal into a string literal\n strncat(abcd, wxyz, 3)\n");
  //printf("[standard]: %s\n", strncat("abcd", "wxyz", 3));
  //printf("[mine]: %s\n", mystrncat("abcd", "wxyz", 3));
  
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