/* Team 40: Luna Almoayad, Tasnim Ayderus, Sama Al-Oda, Kristian Dianna, December 2024
 *
 * A program that identifies unique characters from a given string to generate a truth table based on a user-inputted boolean expression.
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* power
 *
 * Parameters:
 * - b: the base value
 * - e: the exponent value
 *
 * This function calculates the result of raising the base `b` to the power `e`.
 * It iteratively multiplies the base `b` by itself `e` times.
 *
 * Returns:
 * - The result of b^e as an integer.
 */
int power(int b, int e)
{
	int r=1;

	for(int i=0; i<e; i++)
	{
		r= r*b;
	}

	return r;
}



/* truth_table_gen
 *
 * Parameters:
 * - n: the number of variables in the truth table
 *
 * This function generates a truth table for `n` variables. It uses binary representation
 * to create all possible combinations of truth values (0 and 1). The truth table is
 * stored in a dynamically allocated 2D array.
 *
 * Returns:
 * - A pointer to the dynamically allocated 2D array containing the truth table.
 */
int* truth_table_gen(int n)
{
	
	int rows = power(2,n);
	int cols= n;
	int (*truthTable)[cols]=malloc(cols*rows*sizeof(int));

	if( truthTable ==NULL)
	{
		fprintf(stderr, "Error. Memory allocation failed");
		exit(1);
	}
	for(int i =0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			int div = power(2,cols - j -1);
			truthTable[i][j]= (i/div)%2;
		}
	}

	
	return (int *) truthTable;
}

/* foundIn
 *
 * Parameters:
 * - arr: a character array to search
 * - key: the character to find in the array
 *
 * This function checks if the character `key` exists in the character array `arr`.
 *
 * Returns:
 * - true if the character is found
 * - false otherwise
 */
bool foundIn(char* arr, char key){
    for(int i=0;i<strlen(arr);i++){
        if(*(arr+i)==key){
            return true;
        }
    }
    return false;
}


/* findUniq
 *
 * Parameters:
 * - str: a string containing characters to analyze
 *
 * This function identifies all unique lowercase alphabetic characters in the input string `str`.
 * It filters out duplicates and non-lowercase characters, returning a new string with the unique characters.
 *
 * Returns:
 * - A dynamically allocated string containing unique lowercase alphabetic characters.
 */
char* findUniq(char* str){
    char* arr = (char*)malloc(strlen(str)+1);
    int count =0;
    for(int i=0;i<strlen(str);i++){
        if(!foundIn(arr, *(str+i))&&(*(str+i)>='a')&&(*(str+i)<='z')){
            *(arr+count)=*(str+i);
            count ++;
        }
    }
    *(arr+count)='\0';
    return arr;
}

