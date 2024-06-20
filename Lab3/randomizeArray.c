#include <stdio.h>
#include <stdlib.h>

/*Randomize the array*/
 void randomizeArray(int **array, int rowSize, int columnSize) { 
     int i, j, ranRow, ranColumn, temp;
    
     /*Seed the random number generator. To make it truly random, do srand(time(NULL)); and #include <time.h> at the top*/
     srand(1964); /*Seed the random number generator with constant value 1964. The "random" sequence of numbers will be the same.*/

     /*Randomize the array*/
     for (i = 0; i < rowSize; i++) { /*For each element in the array, swap it with a random element*/
        for (j = 0; j < columnSize; j++) { /*For each element in the array, swap it with a random element*/
            ranRow = rand() % rowSize; /*Random number between 0 and rowSize*/
            ranColumn = rand() % columnSize; /*Random number between 0 and columnSize*/
         
            temp = array[i][j]; /*Swap the array[i] with array[j]*/
            array[i][j] = array[ranRow][ranColumn]; /*Swap the array[i] with array[j]*/
            array[ranRow][ranColumn] = temp; /*Swap the array[i] with array[j]*/
         } 
    }
}