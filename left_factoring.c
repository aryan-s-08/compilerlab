#include <stdio.h>
#include <string.h>

int main(){
    char production[100];
    char nonTerminal;
    char opt1[50]="",opt2[50]="";
    char prefix[50]="";
    int i=0,j=0,k=0;

    printf("Enter the production rule (e.g., A->alpha1|alpha2): ");
    scanf("%s", production);

    nonTerminal = production[0];
    i=3;

    while(production[i]!='|' && production[i]!='\0'){
        opt1[j++] = production[i++];
    }
    opt1[j] = '\0';

    if(production[i] == '|'){
        i++;
        while(production[i] != '\0'){
            opt2[k++] = production[i++];
        }
    }
    opt2[k] = '\0';

    int prefixLen = 0;
    while(opt1[prefixLen] != '\0' && opt2[prefixLen] != '\0' && opt1[prefixLen] == opt2[prefixLen]){
        prefix[prefixLen] = opt1[prefixLen];
        prefixLen++;
    }
    prefix[prefixLen] = '\0';

    if(prefixLen == 0){
        printf("No common prefix found.\n");
        return 0;
    }

    char* suffix1 = &opt1[prefixLen];
    char* suffix2 = &opt2[prefixLen];

    if(strlen(suffix1)==0) suffix1="e";
    if(strlen(suffix2)==0) suffix2="e";

    printf("Grammar after left factoring:\n");
    printf("%c -> %s%c'\n", nonTerminal, prefix, nonTerminal);
    printf("%c' -> %s | %s\n", nonTerminal, suffix1, suffix2);
    return 0;

}

//e.g. S->iEtS|iEtSeS|a