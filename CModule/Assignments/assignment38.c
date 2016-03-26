/*  
 *  Q. Read n & n floats in a float array ’store’. 
 *  Print the values in sorted order without modifying or 
 *      copying ’store’.
 *
 *  a. Read the float elements from user and 
 *      store them into an array.
 *  b. Run a loop for printing the float elements in sorted order.
 *
 *  Note: Dont change the existing array.
 *  Dont copy the elements in any other array.
 *
 *  Hint: Store the last printed float value in a float variable.
 *      So that you can compare each float element in the array 
 *      by the variable value.
 *
 *  Concepts to apply:
 *  -----------------
 *  Array concepts
 *
 *  Sample Execution:
 *  -----------------
 *
 *  Enter the count of float elements need to store: 5
 *
 *  [0] = 10.0
 *  [1] = 1.2
 *  [2] = 3.2
 *  [3] = 8.2
 *  [4] = -1.4
 *
 *  After sorting: -1.4   1.2   3.2   8.2   10.0
 *
 */

#include <stdio.h>

#define MAXLEN 256
#define MAXVAL 20000000
#define MINVAL -20000000

#define FLOATBITS 32

void sortFloatNumbers(float array[], int floatCount);
void swap_generic(void * aptr, void * bptr, int size);

int main()
{
    int floatCount, i, j;
    float store[MAXLEN];
    float lastElem;
    
    
    printf("Enter the count of float elements need to store: ");
    scanf("%d", &floatCount);
    
    if ((floatCount < 0) || (floatCount > MAXLEN))
    {
        printf("Error: Size is Out of range. Retry\n");
        return 1;
    }
    
    for (i = 0; i < floatCount; i++)
    {
        printf("[%d] -> ", i);
        scanf("%f", &store[i]);
        
        /* Error Check for limit */
        if (((store[i]) < MINVAL) || ((store[i]) > MAXVAL))
        {
            printf("Error: Element value is Out of range. Retry\n");
            return 1;
        }
        
    }
    
    /* Printing the float elements in sorted order. */
    printf("After sorting: ");
    sortFloatNumbers(store, floatCount);
    
    for (i = 0; i < floatCount; i++)
    {
        printf("%f ", store[i]);
    }
    
    printf("\n");
    return 0;
}


/* Sorting floating numbers - Bubble sort using generic swap */
void sortFloatNumbers(float array[], int floatCount)
{
    int i, j;
    
    for (i = 0; i < floatCount; i++)
    {
        for (j = 0; j < floatCount - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                swap_generic((array+j), (array+j+1), sizeof(float));
            }
        }
    }
    

}

void swap_generic(void * aptr, void * bptr, int size)
{
    int i;
    char temp;
    
    for ( i = 0; i < size; i++ )
    {
        temp = * (char *) aptr;
        * (char *) aptr++ = * (char *) bptr;
        * (char *) bptr++ = temp;
    }
}