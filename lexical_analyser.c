#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[]){
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue",
                             "default", "do", "double", "else", "enum", "extern",
                             "float", "for", "if", "int", "long",
                             "return", "short", "sizeof", "static", 
                             "struct", "switch", "void", "while"};
    int flag = 0;
    for(int i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0)
            flag=1;
            break;
    }
    return flag;
}

int main(){
    char ch, buff[15], operators[] = "+-*/%=";
    FILE *fp;
    int i,j=0;

    fp = fopen("prog.txt", "r");
    if(fp == NULL){
        printf("Error opening file\n");
        exit(0);
    }
    while((ch = fgetc(fp)) != EOF){
        for(i = 0; i < 6; ++i){
            if(ch == operators[i])
                printf("%c is an operator\n", ch);
        }
        if(isalnum(ch)){
            buff[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n') && (j != 0)){
            buff[j] = '\0';
            j = 0;
            if(isKeyword(buff) == 1)
                printf("%s is a keyword\n", buff);
            else
                printf("%s is an identifier\n", buff);
        }
    }
    fclose(fp);
    return 0;
}