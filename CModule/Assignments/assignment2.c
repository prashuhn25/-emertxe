/*
 * Read n and Print the greatest fibonacii no <= n
 */

#include <stdio.h>

int main()
{
	int givenNum;
    int fib1 = 0, fib2 = 1, temp;

	printf("Enter a number:\n");
	scanf("%d", &givenNum);

    /* Negative number check */
    if (givenNum < 0) {
        printf("Error: negative number\n");
        printf("Usage: Provide a positive number\n");
        return 0;
    }
    
    /* To get the greatest fibonacii number <= givenNum */
    printf("The greatest Fibonacii number <= %d is ", givenNum);
    /* generate the fibonacii numbers <= givenNum */
    while (fib1 <= givenNum)
    {
        /* take the first fib into temp */
        temp = fib1;
        /* fib1 will be sum of fib1 and fib2 */
        fib1 += fib2;
        /* fib2 will be the value of previous fib1 value */
        fib2 = temp;
    }
    printf("%d\n", fib2);
	return 0;
}	
