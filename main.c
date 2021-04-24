//Sorry for bad english

//Progam written in C and compiled for testing with clang-7 (also with gcc should works)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define LEN 1000

/*Prototypes of function --------------------------------------------------------------------------*/
void printArray(int* arrayInt, int len);
bool checkOrder(int* arrayInt, int len);

/*Beginning of MAIN --------------------------------------------------------------------------------*/
int main(void) {
  /* - just for test -
    Fill array[LEN] with random numbers and print it.
    (row 16-23)
  */
  srand(time(NULL));
  int arrayInt[LEN] = {0};
  int nRand;
  for (int i=0; i<LEN; i++) {
    nRand = 1 + (rand() % LEN);
    arrayInt[i] = nRand;
  }
  printArray(arrayInt, LEN);

  /* - Mirror Selection Sort -
    It simply works like a reflexed Selection Sort.
    For every loop the algorithm find the minimum and maximum value.
      and switch that values, for example with LEN=10, with array[0] and array[9] (the first
      and the last) and then the second loop itarate from 1 to i<9 (8) e do the same thing.
    That algorithm allows to have at the half (or less) of the operations in comparison 
      to a Selection Sort (the difference is more visible with large arrays).
    (row 36-61)
  */
  for (int i=0; i<(LEN-i); i++) {
    int min = i;
    int max = i;

    for (int j=i; j<(LEN-i); j++) {
      if (arrayInt[min] > arrayInt[j]) {
        min = j;
      }
      if (arrayInt[max] < arrayInt[j]) {
        max = j;
      }
    }

    int tmp;
    tmp = arrayInt[i];
    arrayInt[i] = arrayInt[min];
    arrayInt[min] = tmp;

    if (i==max) {
      max = min;
    }

    tmp = arrayInt[LEN-i-1];
    arrayInt[LEN-i-1] = arrayInt[max];
    arrayInt[max] = tmp;
  }

  ///*
  puts("\nSORTED ARRAY\n");
  printArray(arrayInt, LEN);
  checkOrder(arrayInt, LEN);
  ///*

  puts("");
  return 0;
}

/*Body of functions -------------------------------------------------------------------------------*/
void printArray(int* arrayInt, int len) {
  for (int i=0; i<len; i++) {
    printf("%3d =>", arrayInt[i]);
    if ((i+1)%10==0) {
      puts("");
    }
  }
}
bool checkOrder(int* arrayInt, int len) {
  int cont = 0;
  for (int i=0; i<(len-1); i++) {
    if (arrayInt[i]<=arrayInt[i+1]) {
      cont++;
    }
    else {
      puts("\nNOT ordered");
      return false;
    }
  }
  puts("\nOrdered");
  return true;
}
