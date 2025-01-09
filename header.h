#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct treenode {
    char value;
    struct treenode* left;
    struct treenode* right;
} treenode;

void formatHelp();

//Eval
int and(int a,int b);
int or(int a, int b);
int not(int a);
int evaluate_tree(treenode *root);
void update_leaf_value(treenode *root, char var, char newValue);
//Truth Table
int power(int b, int e);
int* truth_table_gen(int n);
bool foundIn(char* arr, char key);
char* findUniq(char* str);

//Parsing
bool balancedbrack(char* expr);
bool checkChars(char *expr);
bool checkInput(char *expr);
char* wrapExpression (char *expr);
char* wrapVariables (char *expr);
char* strip(char *expr);

//Build Tree
int find_operator(char* expr);
char* partOfStr(char* str, int start, int end);
void build(char* expr, treenode** tree);
//void main();

//Data
void formatHelp();
void usage();
