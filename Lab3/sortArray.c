#include <stdio.h>

/*
Reference for insertion sort:
https://stackoverflow.com/questions/36084752/2d-arrays-in-bubble-sorting
*/

 /*Sort the array*/
 void sortArray(int **array, int rowSize, int columnSize) { 
    int i, j, k, l, temp;

/*Sorts in ascending order. */
/*i used for rows, j for columns, 
k and l used for iteration and used for comparisons (ensures compared only once)*/

/* Bubble sort */
/*Used to compare each element array[i][j] with every other element array[k][l]*/
    for (i = 0; i < rowSize; i++) { /* Loop through each row */
        for (j = 0; j < columnSize; j++) { /* Loop through each column */
            for (k = 0; k < rowSize; k++) { /* Loop through each row again. Used to select comparison element (array[k][l]).*/
                for (l = 0; l < columnSize; l++) { /* Loop through each column again within row k. Used to select comparison element (array[k][l]) for (array[i][j])*/
                    
                    /* Compare each element array[i][j] with every other element in array array[k][l] that hasn't been compared yet. */
                    if ((k > i) || (k == i && l > j)) { /* Ensure we don't compare elements with themselves or with elements they've already been compared with */
                        if (array[i][j] > array[k][l]) { /* If the current element is greater than the comparison element */
                            /* Swap elements if they are out of order */
                            temp = array[i][j]; /* Store the current element in a temporary variable */
                            array[i][j] = array[k][l]; /* Replace the current element with the comparison element */
                            array[k][l] = temp; /* Replace the comparison element with the value of the temporary variable (original current element) */
                        }
                    }
                }
            }
        }
    }
}