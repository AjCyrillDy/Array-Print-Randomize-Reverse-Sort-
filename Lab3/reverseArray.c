#include <stdio.h>

/*
Reference for reversing array:
https://forum.code.org/t/u5l4-extra-practice-reversing-rows-and-columns-of-a-2d-array/37577
*/

/*Reverse the array*/
 void reverseArray(int **array, int rowSize, int columnSize) { 
     int i, j, temp; 
    
    /* Reverse each row */
    for (i = 0; i < rowSize; i++) { /* Loop through each row */
        for (j = 0; j < columnSize / 2; j++) { /* For each row, loop through the first half of the columns */
            temp = array[i][j]; /* Store the current element in a temporary variable */
            array[i][j] = array[i][columnSize - 1 - j]; /* Replace the current element with the element in the mirror position from the end of the row */
            array[i][columnSize - 1 - j] = temp; /* Replace the element in the mirror position from the end of the row with the value of the temporary variable (original current element) */
        }
    }

    /* Reverse the order of the rows */
    for (i = 0; i < rowSize / 2; i++) { /* Loop through the first half of the rows */
        for (j = 0; j < columnSize; j++) { /* For each row in the first half, loop through each column */
            temp = array[i][j]; /* Store the current element in a temporary variable */
            array[i][j] = array[rowSize - 1 - i][j]; /* Replace the current element with the element in the mirror position from the end of the array */
            array[rowSize - 1 - i][j] = temp; /* Replace the element in the mirror position from the end of the array with the value of the temporary variable (original current element) */
        }
    }
}