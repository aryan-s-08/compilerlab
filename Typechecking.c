#include <stdio.h>
#include <string.h>

int main()
{
    char var1[20], var2[20], op;
    char type1[10], type2[10];

    printf("Enter first variable name: ");
    scanf("%s", var1);

    printf("Enter type of %s (int/float): ", var1);
    scanf("%s", type1);

    printf("Enter operator (+,-,*,/): ");
    scanf(" %c", &op);

    printf("Enter second variable name: ");
    scanf("%s", var2);

    printf("Enter type of %s (int/float): ", var2);
    scanf("%s", type2);

    if (strcmp(type1, type2) == 0)
    {
        printf("\nType Checking Successful\n");
        printf("Result type: %s\n", type1);
    }
    else if ((strcmp(type1, "int") == 0 && strcmp(type2, "float") == 0) ||
             (strcmp(type1, "float") == 0 && strcmp(type2, "int") == 0))
    {
        printf("\nType Checking Successful\n");
        printf("Result type: float\n");
    }
    else
    {
        printf("\nType Error\n");
    }

    return 0;
}