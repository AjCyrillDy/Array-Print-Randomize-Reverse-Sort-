#include <stdio.h>

/* Print the array*/
void printArray(int **array, int rowSize, int columnSize) {
    int i, j;
    for (i = 0; i < rowSize; i++) { /*Loop through each element of the row array*/
    
    printf("\n"); /*Print a new line before each row. Separates each of the rows so that it does not stay one line*/
    
    for (j = 0; j < columnSize; j++) { /*Loop through each element of column array*/
    printf("%d ", array[i][j]); /*Print the current element of array*/
    }
    }
    printf("\n");
    }