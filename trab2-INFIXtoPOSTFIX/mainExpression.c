#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "stack.c"

void InfixtoPostfix(Stack *stack, char source[], char target[]);
void askUser(char exp[]);
float evaluatePostfixExp(Stack *stack,char exp[]);
bool isOperador(char operador);
int prioridadeOperador(char operador);
bool tratamentoErro(char infix[]);

// cd "/Users/onatalia86/Desktop/" && gcc -lstdc++ mainExpression.c -o mainExpression && "/Users/onatalia86/Desktop/"mainExpression
int main(){
    Stack *stack= createStack();
    // Info *tempInfo;
    // tempInfo = createInfo('c');
    // if((push(stack,tempInfo))) printf("Funcionou");
    // tempInfo = createInfo('c');
    // if((push(stack,tempInfo))) printf("Funcionou");
    // tempInfo = createInfo('d');
    // if((push(stack,tempInfo))) printf("Funcionou");
    // printStack(stack);

    // if((pop(stack))) printf("\nPop");
    // printStack(stack);
    char infix[100], postfix[100];
    float value;
    int n = 0;
    // 9 - ((3 * 4) + 8) / 4
    while(n==0){
        printf("\nDigite a expressão infixa (números de 1 a 9; o algoritmo não suporta expressões como a+(-b)): ");
    // scanf("%s",infix);
        gets(infix);
        if(tratamentoErro(infix)) n++;
        else {
            // system("clear");
            printf("\nExpressão matematicamente errada. Por favor, tente novamente.\n");
        }
    }
    printf("\nExpressão INFIXA: %s\n",infix);
    char concat[] = ")";
    printf("%s",concat);
    strcat(infix, concat);
    // printf("Expressão INFIXA: %s\n",infix);
    InfixtoPostfix(stack,infix,postfix);
    printf("\nExpressão POSFIXA: %s\n",postfix);
    askUser(postfix);
    printf("\nExpressão POSFIXA com números: %s\n",postfix);
    freeStack(stack); 
    stack= createStack();
    value = evaluatePostfixExp(stack,postfix);
    printf("\nResultado: %f\n\n",value);
    return 0;
}

bool tratamentoErro(char infix[]){
    int i = 1, j, m=0, n=0, o=0;
    //nao pode começar com operador
    if(isOperador(infix[0])) return false;
    //nao pode terminar com operador
    if(isOperador(infix[strlen(infix)-1])) return false;
    //nao pode existir parenteses sem fechar (() && não pode existir expressão sem variavel
    for(j=0;j<strlen(infix);j++){
        if(infix[j] == '(') m++;
        if(infix[j] == ')') m--;
        if(m<0) return false;
        if(isalpha(infix[j]) || isdigit(infix[j])) n++;
        if(isalpha(infix[j]) || isdigit(infix[j]) || infix[j] == '(' || infix[j] == ')' || isOperador(infix[j])) o++;
    }
    if (m != 0) return false;
    if (n == 0) return false;
    if (o != strlen(infix)) return false;
    while (i<strlen(infix)){
        //nao pode ter numero/letra antes de parenteses
        if (infix[i] == '(' && (isalpha(infix[i-1]) || isdigit(infix[i-1]))) return false;
        //nao pode ter numero/letra antes de numero/letra
        if ((isalpha(infix[i]) || isdigit(infix[i])) && (isalpha(infix[i-1]) || isdigit(infix[i-1]))) return false;
        //nao pode ter operador antes de operador
        if(isOperador(infix[i]) && isOperador(infix[i-1])) return false;
        //não pode ter operador antes de fechar parenteses
        if(isOperador(infix[i-1]) && infix[i] == ')') return false;
        i++;
    }
    return true;
}

void InfixtoPostfix(Stack *stack, char source[], char target[]){
    Info *tempInfo;
    char aux;
    int i = 0,j = 0;
    tempInfo = createInfo('(');
    push(stack,tempInfo);
    // printStack(stack);
    // printf("Source[] : %s\n",source);
    for(i=0; i<strlen(source);i++){
        // printf("Source %d: %c",i,source[i]);
        if(source[i] == '('){
            tempInfo = createInfo(source[i]);
            push(stack,tempInfo);
        }else if(isalpha(source[i]) || isdigit(source[i])){
            target[j]=source[i];
            // printf("\n\nsource[i]: %c\n\n",source[i]);
            // printf("target[j]: %c\n",target[j]);
            j++;
        } else if(source[i] == ')'){
            while (getInfo(stack) != '('){
                target[j] = pop(stack);
                j++;
            }
            pop(stack);
        } else if(((isOperador(source[i])))){
            // printf("é operador. \n");
            // printf("getinfostack: %c \n",(getInfo(stack)));
            if((isOperador(getInfo(stack)))){
                if( (prioridadeOperador(source[i])) <= (prioridadeOperador(getInfo(stack)))){
                    while((isOperador(getInfo(stack)))){
                        target[j] = pop(stack);
                        j++;
                    }
                    tempInfo = createInfo(source[i]);
                    push(stack,tempInfo);
                } else {
                    tempInfo = createInfo(source[i]);
                    push(stack,tempInfo);
                }
            } else {
                tempInfo = createInfo(source[i]);
                push(stack,tempInfo);
            }
        } 
        // else printf("\nExpressão inválida!");
        // printf("\n stack: ");
        // printStack(stack);
        // printf("\n");
    }
    
    // printf("Target: %s\n",target);
    return;
}

void askUser(char exp[]){
    int i=0;
    int valor;
    while(i<strlen(exp)){
        if((isalpha(exp[i]))){
            int j = 0;
            while (j == 0){
                printf("\n Insira um valor inteiro (0 a 9) da variável %c: ",exp[i]);
                scanf("%d",&valor);
                if(valor>=0 && valor <10){
                    exp[i] = valor + '0';
                    j++;
                } else printf("Valor não permitido.");
            }
        }
        i++;
    }
}

//a+c*r+u
float evaluatePostfixExp(Stack *stack,char exp[]){
    char valueChar[2];
    Info *tempInfo;
    float A, B, value;
    int i=0;
    while(i<strlen(exp)){
        if(!((isOperador(exp[i])))){
            tempInfo = createInfo(exp[i]);
            push(stack,tempInfo);
        } else if (((isOperador(exp[i])))){
            A = pop(stack)-48; // A
             printf("\nA: %f",A);
            B = pop(stack)-48; //B
             printf("\nB: %f",B);
            if(exp[i]== '+'){
                value = B+A;
            } else if (exp[i]=='-'){
                value = B-A;
            } else if (exp[i]=='/'){
                value = B/A;
            } else if (exp[i]=='*'){
                value = B*A;
            } else if (exp[i]=='\%'){
                value = (int)B%(int)A;
            }
            valueChar[0] = value+48;
            tempInfo = createInfo(valueChar[0]);
            push(stack,tempInfo);
        }

        i++;
    }
    value = pop(stack)-48;
    return value;
}

bool isOperador (char operador){
    if (operador=='\%' || operador== '*' || operador== '/' || operador== '+' || operador== '-' ) return true;
    else return false;
}
// return 1 prioridade maior ou igual
// return 0 prioridade menor
int prioridadeOperador (char operador){
    if (operador== '\%' || operador== '*' || operador== '/') return 1;
    else return 0;
}