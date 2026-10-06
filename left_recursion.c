#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
if A->A alpha1 | beta1 | beta2
then
A-> beta1 A' | beta2 A'
A'-> alpha1 A' | epsilon
*/

int main(){
    char production[100];
    char nonTerminal;
    char alpha[50]="",beta[50]="";
    int i=0,j=0,k=0;

    printf("Enter the production rule (e.g., A->Aa|b): ");
    scanf("%s", production);

    nonTerminal = production[0];

    if(production[1] != '-' || production[2] != '>'){
        printf("Invalid production rule format.\n");
        return 1;
    }
    i=3; // Start after '->'
    if(production[i] == nonTerminal){
        // Left recursion detected
        i++; // Move past the non-terminal
        while(production[i] != '\0' && production[i] != '|'){
            alpha[j++] = production[i++];
        }
        alpha[j] = '\0'; // Null-terminate alpha
        
        if(production[i] == '|'){
            i++; // Move past '|'

            while(production[i] != '\0'){
                beta[k++] = production[i++];
            }
            beta[k] = '\0'; // Null-terminate beta
        }
    }
    else{
            printf("No beta production found.\n");
            return 1;
    }
    printf("Grammar after removing left recursion:\n");
    printf("%c -> %s%c'\n", nonTerminal, beta, nonTerminal);
    printf("%c' -> %s%c' | epsilon\n", nonTerminal, alpha, nonTerminal);
    
    return 0;



}

//e.g. E->E+T|T