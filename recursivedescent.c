#include <stdio.h>

char input[100];
int pos = 0;
int error = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

void E()
{
    T();
    Eprime();
}

void Eprime()
{
    if (input[pos] == '+')
    {
        pos++;
        T();
        Eprime();
    }
}

void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if (input[pos] == '*')
    {
        pos++;
        F();
        Tprime();
    }
}

void F()
{
    if (input[pos] == 'i' &&
        input[pos + 1] == 'd')
    {
        pos += 2;
    }
    else if (input[pos] == '(')
    {
        pos++;

        E();

        if (input[pos] == ')')
            pos++;
        else
            error = 1;
    }
    else
    {
        error = 1;
    }
}

int main()
{
    printf("Grammar:\n");
    printf("E  -> TE'\n");
    printf("E' -> +TE' | epsilon\n");
    printf("T  -> FT'\n");
    printf("T' -> *FT' | epsilon\n");
    printf("F  -> (E) | id\n\n");

    printf("Enter input string: ");
    scanf("%s", input);

    E();

    if (input[pos] != '\0')
        error = 1;

    if (error == 0)
        printf("Input Accepted\n");
    else
        printf("Input Rejected\n");

    return 0;
}