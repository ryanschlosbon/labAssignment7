#include <stdio.h>
#include <stdlib.h>

//Ryan Schlosbon - COP 3502C - Lab Assignment 7 - Selection and Bubble Sort

void bubbleSort(int arr[], int n, int s[], int* total_s) {
    int i, j, temp;
  //Loop throug the entire array
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
          //if array at the current index is greater than the index after it, swap
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                s[arr[j]]++; //increase swap count for the given number
                s[arr[j+1]]++; //increase swap count for the given number
                (*total_s)++; //increase total swap count
            }
        }
    }
}

void selectionSort(int arr[], int n, int s[], int* total_s) {
    int i, j, min, temp;
  //loop through the entire array.
    for (i = 0; i < n-1; i++) {
        min = i; //min is set as the current loop iteration
        for (j = i+1; j < n; j++) { //j is set as one ahead of i
            if (arr[j] < arr[min]) { //if arr at index of j is less than the arr at index of min, set j as the new min
                min = j;
            }
        }
        if (min != i) { //if the min idx does not equal the current loop iteration, swap the two variables at the array indexes
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            s[arr[i]]++;
            s[arr[min]]++;
            (*total_s)++;
        }
    }
}

int main() {
  //Declare variables and arrays
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr1copy[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int arr2copy[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int s1[101] = {0}; // Since the values in the arr are from 1 to 100
    int s2[101] = {0};
    int s3[101] = {0};
    int s4[101] = {0};
    int total_s1 = 0;
    int total_s2 = 0;
    int total_s3 = 0;
    int total_s4 = 0;
  
    // Bubble Sort
    bubbleSort(arr1, n1, s1, &total_s1);
    bubbleSort(arr2, n2, s2, &total_s2);

    printf("Using Bubble Sort: \n");

    // Output for arr1
    printf("arr1:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d times\n", arr1[i], s1[arr1[i]]);
    }
  
    printf("Total s: %d\n\n", total_s1); //Print total swaps

    // Output for arr2
    printf("arr2:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d times\n", arr2[i], s2[arr2[i]]);
    }

    printf("Total swaps: %d\n", total_s2); //Print total swaps

  // Selection Sort
  selectionSort(arr1copy, n1, s3,&total_s3);
  selectionSort(arr2copy, n2, s4,&total_s4);

  printf("\nUsing Selection Sort:\n");
  
  // Output for arr1
  printf("arr1:\n");
  for (int i = 0; i < n1; i++) {
      printf("%d: %d times\n", arr1copy[i], s3[arr1copy[i]]);
  }
  
  printf("Total swaps: %d\n\n", total_s3); //print total swaps

  // Output for arr2
  printf("arr2:\n");
  for (int i = 0; i < n2; i++) {
      printf("%d: %d times\n", arr2copy[i], s4[arr2copy[i]]);
  }

  printf("Total swaps: %d",total_s4); //Print total swaps
}