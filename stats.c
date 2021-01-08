/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Source code for week1 assignment
 *
 * This file contains a couple of functions that can analyze an array of unsigned char data 
 * items and report analytics on the maximum, minimum, mean, and median of the data set. 
 * In addition, this data set is reordered from large to small data. All statistics are  
 * rounded down to the nearest integer. After analysis and sorting is done, you will need 
 * to print that data to the screen in nicely formatted presentation. 
 *
 * @author Mohamed Faouzi ABI AYAD
 * @date 06 January 2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)



void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  
  unsigned char mean = 0, median = 0, maximum = 0, minimun = 0;
  
  
  /* Statistics and Printing Functions Go Here */
  
  printf("Array before sorting: ");
  print_array(test, SIZE);
  
  sort_array(test, SIZE);
  printf("\nArray after sorting: ");
  print_array(test, SIZE);
  
  mean = find_mean(test, SIZE);
  median = find_median(test, SIZE);
  maximum = find_maximum(test, SIZE);
  minimun = find_minimum(test, SIZE);
  
  print_statistics(mean, median, maximum, minimun);
}


/* print_statistics() - A function that prints the statistics of an array including minimum, maximum, mean, and median.*/
void print_statistics(unsigned char mean, unsigned char median, unsigned char maximum, unsigned char minimum){
  printf("\nMean: %d\nMedian: %d\nMaximum: %d\nMinimum: %d", mean, median, maximum, minimum);
}


/* print_array() - Given an array of data and a length, prints the array to the screen */
void print_array(unsigned char *arr, unsigned int size){

  printf("\nElements of the array: ");
  unsigned int i;
  for(int i = 0; i < size; ++i){
    printf("%d ", arr[i]);
  }
}


/*find_median() - Given an array of data and a length, returns the median value */
unsigned char find_median(unsigned char *arr, unsigned int size){

  unsigned char median;
  if(size % 2 == 0){
    median = (arr[(size/2)] + arr[(size-1)/2])/2;
  } else {
    median = arr[(size/2)];
  }
  return median;
}


/* find_mean() - Given an array of data and a length, returns the mean */
unsigned char find_mean(unsigned char *arr, unsigned int size){

  unsigned int sum = 0, i;
  for(i = 0; i < size; ++i){
    sum += arr[i];
  }
  //printf("\n\nMean: %d\t%f\n\n", sum, (float)sum/size);
  unsigned char mean = sum/size;
  return mean;
}



/* find_maximum() - Given an array of data and a length, returns the maximum */
unsigned char find_maximum(unsigned char *arr, unsigned int size){

  unsigned int i;
  unsigned char max = arr[0];
  for (i = 0; i < size; ++i){
    if (max < arr[i]){
      max = arr[i];
    }
  }
  return max;
}



/* find_minimum() - Given an array of data and a length, returns the minimum */
unsigned char find_minimum(unsigned char *arr, unsigned int size){

  unsigned int i;
  unsigned char min = arr[0];
  for (i = 0; i < size; ++i){
    if (min > arr[i]){
      min = arr[i];
    }
  }
  return min;
}



/* sort_array() - Given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. ) */
void sort_array(unsigned char *arr, unsigned int size){
  unsigned int i, j, temp;
  for(i = 0; i < size; ++i){
    for(j = 0; j < size-1-i; ++j){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}








