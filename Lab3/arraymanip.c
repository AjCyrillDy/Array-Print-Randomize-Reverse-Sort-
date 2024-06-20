/**
 * Name: Aj Cyrill Dy
 * Student #: 041113696
 * Course: CST8234 - C Language
 * Lab Section: 311
 * Lab Professor: Daniel Cormier
 * Title: Lab3 - arraymanip.c
*/

/*gcc -g -ansi -pedantic -Wall arraymanip.c -o arraym*/

/*Also use "make"*/

#include <stdio.h>
#include <stdlib.h>

#include "Functions.h"

int main() {

/**
 * declarations
*/
int inputRow = 0;
int inputColumn = 0;
int i, j;
int **array; /*Use an pointer to pointer*/
int validInput = 0;
int inputLength;
int option; /*used for switch case*/

do {
    validInput = 1; /*Assume valid input at the beginnning of each loop*/

/*Scanf uses format specifier %d. So if user enters a string (or non integer), scanf will not read
as an integer and return a value other than 1. So if validInput != 1, scanf failed.*/

/*Prompt the user to enter row size*/
printf("Enter the row size of 2D array: \n");
if (scanf("%d", &inputRow) != 1 || inputRow <= 0) {
    printf("Invalid input.\n");
    /*Clear the input buffer*/
    while(getchar() != '\n');
    validInput = 0;
    }

/*Prompt the user to enter column size*/
printf("Enter the column size of 2D array: \n");
if (scanf("%d", &inputColumn) != 1 || inputColumn <= 0) {
    printf("Invalid input.\n");
    /*Clear the input buffer*/
    while(getchar() != '\n');
    validInput = 0;
    }
} while (!validInput); /*Repeat loop until input is valid*/

inputLength = inputRow * inputColumn; /*Calculate the number of elements in the array*/

/*Dynamically allocate memory for the array using malloc. Uses memory allocation*/

/*Here, 'malloc' is a function that dynamically allocates a block of memory of size equal to 'inputLength' times the size of an integer. 
'inputLength' is the number of elements in the array and 'sizeof(int)' gives the size of an integer in bytes. 
The pointer to the first byte of the allocated block is assigned to 'array'. */

/*Whatever input is given, it automatically takes the size it was given instead of using the variable array length with a preset value*/
/*Allocating memory for rows*/
array = (int**) malloc(inputRow * sizeof(int*)); /*Dynamically allocate memory for 'inputRow' number of pointers to int*/
if (array == NULL) { /*Check if memory allocation failed*/
    printf("Memory allocation failed.\n");
    return 1; /*Exit if failed*/
    }
    
    /*Allocating memory for columns in each row*/
    for(i = 0; i < inputRow; i++) { /*Iterate over each row*/
        array[i] = (int*)malloc(inputColumn * sizeof(int)); /*Dynamically allocate memory for 'inputColumn' integers per row*/
        if (array[i] == NULL) { /*Check if memory allocation failed*/
            printf("Memory allocation failed.\n");
            for (j = 0; j < i; j++) { /*Iterate previously allocated rows to free memory*/
            free(array[j]); /*Free the memory allocated for the array. Related to malloc*/
        }
        free(array); /*Free memory for the row pointer*/
        return 1; /*Exit if failed*/
        }
    }

/*Prompt the user to enter the numbers*/
printf("Enter %d numbers (spaces separated): \n", inputLength);
for (i = 0; i < inputRow; i++) { /*Loop through each element in rows*/
    for (j = 0; j < inputColumn; j++) { /*Loop thorugh each element in columns*/
        if (scanf("%d", &array[i][j]) != 1) {
            printf("Invalid input.\n");
            /*Clear the input buffer*/
            while(getchar() != '\n');
            j--; /*Decrement j to repeat the loop for the same element*/
        }
    }
}

do {
    int switchRead;

/*Prompt the user to choose an operation*/
printf("Choose an operation:\n");
printf("(0) : exit\n");
printf("(1) : reverse array\n");
printf("(2) : randomize array\n");
printf("(3) : sort array\n");
printf("(4) : print array\n");
switchRead = scanf("%d", &option); /*read is used for input checking while also taking input of the options*/

/*Input checking in case any non-integer numbers are type in*/
    if (!switchRead) {
        printf("Invalid input. Please enter a number.\n");
        /*Clear input buffer*/
        while(getchar() != '\n');
        continue; /*Continue loop until the user puts valid input*/
    }

/*Switch case to choose the operation*/
switch (option) {
    case 0: 
    printf("Exiting program...\n");
    break;

    case 1:
    printf("Reversing array...\n");
    reverseArray(array, inputRow, inputColumn);
    break;

    case 2:
    printf("Randomizing array...\n");
    randomizeArray(array, inputRow, inputColumn);
    break;

    case 3:
    printf("Sorting array...\n");
    sortArray(array, inputRow, inputColumn);
    break;

    case 4:
    printf("Printing array...\n");
    printArray(array, inputRow, inputColumn);
    break;

    default:
    printf("Invalid option. Please try again\n");
    break;
    
    } 
} while (option != 0); /* Moved the closing brace here*/

/*Free the memory allocated for the array*/
for (i = 0; i < inputRow; i++) {
    free(array[i]);
}
free(array);

return 0; /* Added return statement*/

} /* End of main function*/