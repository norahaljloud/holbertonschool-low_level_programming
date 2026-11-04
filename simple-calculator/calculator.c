#include <stdio.h>

int main(void)
{
    int choice;
    double a;
    double b;
    double result;

    printf("Simple Calculator\n");

    while (1)
    {
        printf("1) Add\n");
        printf("2) Subtract\n");
        printf("3) Multiply\n");
        printf("4) Divide\n");
        printf("0) Quit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("Bye!\n");
            break;
        }
        else if (choice >= 1 && choice <= 4)
        {
            printf("A: ");
            scanf("%lf", &a);

            printf("B: ");
            scanf("%lf", &b);

            if (choice == 1)
                result = a + b;
            else if (choice == 2)
                result = a - b;
            else if (choice == 3)
                result = a * b;
            else
            {
                if (b == 0)
                {
                    printf("Error: division by zero\n");
                    continue;
                }
                result = a / b;
            }

            printf("Result: %g\n", result);
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return (0);
}
