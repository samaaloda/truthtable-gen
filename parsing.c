#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

char * wrapExpression(char *expr){

    int counter = 0;
    int n = strlen(expr);

    for (int i = 0; i < n; i++){
        if (expr[i] == '('){
            counter++;
        }
        else if (expr[i] == ')'){
            counter--;
        }

        if (counter == 0 && i != n-1){

            char *newExpr = (char *)malloc(n+3); // allocate space for '(', ')', and '\0'
            newExpr[0] = '(';
            strcpy(newExpr+1, expr);
            newExpr[n+1] = ')';
            newExpr[n+2] = '\0';

            return newExpr;

        }
    }

    char *newExpr = (char *)malloc(n + 1);
    strcpy(newExpr, expr);
    return newExpr;
}

char * wrapVariables(char *expr){

    int n = strlen(expr);
    
    char *newExpr = (char *)malloc(n+1);
    strcpy(newExpr, expr);

    for (int i = 0; i < n; i++){
        int ascii = (int)newExpr[i];
        if ((ascii >= 'A' && ascii <= 'Z') || (ascii >= 'a' && ascii <= 'z')){
            if (newExpr[i-1] != '(' || newExpr[i+1] != ')'){

                char *temp = (char *)malloc(n+3); // allocate space for '(', and ')'
                strncpy(temp, newExpr, i);
                temp[i] = '(';
                temp[i+1] = newExpr[i];
                temp[i+2] = ')';
                strcpy(temp+i+3, newExpr+i+1);

                n+=2;
                i++;

                free(newExpr);
                newExpr = temp;
            }
        }
    }

    return newExpr;
}


bool balancedbrack(char* expr){
    int count = 0 ;
    bool paren = true ; 
    for(int i=0;i<strlen(expr);i++){
        if(*(expr+i)=='('){
            count++;
    }
        else if(*(expr+i)==')'){
            count--;
	}else {
	    paren = false; 
    }
    }
    
    if ( count != 0){
	  return false;
    } 
    return true;
}

int num_op(char* exp){
    int count=0;
    for(int i=0;i<strlen(exp);i++){
        if(*(exp+i)=='&'||(*(exp+i)=='|'||*(exp+i)=='~'))
            count++;
    }
    return count;
}

bool enoughBrack(char* exp){
    int count=0;
    for(int i=0;i<strlen(exp);i++){
        if(*(exp+i)==')'||*(exp+i)=='(')
            count++;
    }    
    return (count>=(2*(num_op(exp)-1)));
}

bool checkChars(char *expr){
    for(int i=0;i<strlen(expr);i++){
        if(!(*(expr+i)=='~' ||*(expr+i)=='&'||*(expr+i)=='|'||(*(expr+i)>='a'&&*(expr+i)<='z')||*(expr+i)<='('||*(expr+i)<=')')){
			return false;
			}
    }
    return true;
}

char * strip(char * expr){
    char * newexp=malloc(strlen(expr));
    int len=0;
    for(int i=0;i<strlen(expr);i++){
        if(*(expr+i)!=' '&&*(expr+i)!='\n'&&*(expr+i)!='\t'){
            *(newexp+len)=*(expr+i);
            len++;
        }
    }
    *(newexp+len)='\0';
    return newexp;
}

int num_binary_op(char *exp){
    int count=0;
    for(int i=0;i<strlen(exp);i++){
        if(*(exp+i)=='&'||(*(exp+i)=='|'))
            count++;
    }
    return count;
}

char* only_alpha(char *exp){
    char* new = malloc(strlen(exp));
    int count=0;
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]>='a'&&exp[i]<='z'){
            new[count]=exp[i];
            count++;
        }
    }
    new[count]='\0';
}

bool checkInput(char *expr){
    if(strlen(only_alpha(expr))==num_binary_op(expr))
        return 0;
    return ( checkChars(expr) && balancedbrack(expr) &&enoughBrack(expr));
}



