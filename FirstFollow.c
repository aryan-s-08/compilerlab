#include <stdio.h>
#include <string.h>

char productions[6][20] ={
    "S=aAb",
    "S=bA",
    "S=#",
    "A=aAb",
    "A=#",
    "B=bB"
};

char first[3][20];
char follow[3][20];

int n = 6;
void add(char result[], char c){
    int i;
    for (i = 0; result[i] != '\0'; i++){
        if (result[i] == c){
            return;
        }
    }
    i = strlen(result);
    result[i] = c;
    result[i + 1] = '\0';
}

int indexOf(char c){
    if (c == 'S')
        return 0;
    if (c == 'A')
        return 1;
    if (c == 'B')
        return 2;
    return -1;
}

void findFirst(char symbol){
    int i;
    int index = indexOf(symbol);

    for (i = 0; i < n; i++){
        if (productions[i][0] == symbol){
            char c = productions[i][2];

            if (c >= 'a' && c <= 'z'){
                add(first[index], c);
            }
            else if (c == '#'){
                add(first[index], '#');
            }
            else{
                int j;
                int other = indexOf(c);
                findFirst(c);
                for (j = 0; first[other][j] != '\0'; j++){
                    add(first[index], first[other][j]);
                }
            }
        }
    }
}

void findFollow(char symbol){
    int i, j;
    int index = indexOf(symbol);

    if (symbol == 'S')
        add(follow[index], '$');

    for (i = 0; i < n; i++){
        for (j = 2; productions[i][j] != '\0'; j++){
            if (productions[i][j] == symbol){
                if (productions[i][j + 1] != '\0'){
                    char next = productions[i][j + 1];

                    if (next >= 'a' && next <= 'z'){
                        add(follow[index], next);
                    }
                }
                else{
                    char lhs = productions[i][0];

                    if (lhs != symbol){
                        int lhsIndex = indexOf(lhs);

                        findFollow(lhs);

                        for (int k = 0;
                             follow[lhsIndex][k] != '\0';
                             k++)
                        {
                            add(follow[index],
                                 follow[lhsIndex][k]);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int i;

    for (i = 0; i < 3; i++){
        first[i][0] = '\0';
        follow[i][0] = '\0';
    }

    findFirst('S');
    findFirst('A');
    findFirst('B');

    findFollow('S');
    findFollow('A');
    findFollow('B');

    printf("Grammar:\n");

    for (i = 0; i < n; i++){
        printf("%s\n", productions[i]);
    }

    printf("\nFIRST:\n");

    printf("FIRST(S) = { ");
    for (i = 0; first[0][i] != '\0'; i++)
        printf("%c ", first[0][i]);
    printf("}\n");

    printf("FIRST(A) = { ");
    for (i = 0; first[1][i] != '\0'; i++)
        printf("%c ", first[1][i]);
    printf("}\n");

    printf("FIRST(B) = { ");
    for (i = 0; first[2][i] != '\0'; i++)
        printf("%c ", first[2][i]);
    printf("}\n");

    printf("\nFOLLOW:\n");

    printf("FOLLOW(S) = { ");
    for (i = 0; follow[0][i] != '\0'; i++)
        printf("%c ", follow[0][i]);
    printf("}\n");

    printf("FOLLOW(A) = { ");
    for (i = 0; follow[1][i] != '\0'; i++)
        printf("%c ", follow[1][i]);
    printf("}\n");

    printf("FOLLOW(B) = { ");
    for (i = 0; follow[2][i] != '\0'; i++)
        printf("%c ", follow[2][i]);
    printf("}\n");

    return 0;
}