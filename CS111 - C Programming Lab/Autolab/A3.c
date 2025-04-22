#include <stdio.h>

/* do not modify the next 5 lines*/
int main() {
	int T;
    int dollars;
    int cents;
	scanf("%d", &T);

    /* do not modify the next 3 lines*/
	while(T--) {
		scanf("%d", &dollars);
        scanf("%d", &cents);

        /*  --- Start your solution here --- */
        double totalAmount = (double)dollars + (double)cents / 100.0;

        // Print the amount with a dollar sign and two decimal places
        printf("$%.2lf\n", totalAmount);

        /* Only print the amount with a dollar sign and two decimal places (e.g., $45.08) for 45 dollars and 9 cents. */

        /*  --- End of the solution --- */
    /* do not modify the next 3 lines*/
	}
	return 0;
}