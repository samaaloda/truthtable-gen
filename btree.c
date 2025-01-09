#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct treenode {
    char value;
    struct treenode* left;
    struct treenode* right;
} treenode;

void printtree_rec(treenode *, int);
void printtree(treenode *);
void printtabs(int);
treenode* createNode(char);
int find_operator(char*);
char* partOfStr(char *, int, int);
void build(char*, treenode**);
//Below defines a struct of type treenode, with character variable value, treenode pointer left, and treenode pointer right


void printtree_rec(treenode* root, int level) { //pass in a root to print it
    if(root==NULL) {
        printtabs(level);
        printf("---<empty>---\n");
        return;
    }
    printtabs(level);
    printf("value = %c\n", root-> value);
    printtabs(level);
    printf("left\n");


    printtree_rec(root->left,level+1);
    printtabs(level);
    printf("right\n");


    printtree_rec(root->right, level+1);
    printtabs(level);
    printf("done\n");
}


void printtree(treenode *root){
    printtree_rec(root,0);
}


void printtabs(int numtabs){
    for(int i=0;i<numtabs;i++){
        printf("\t");
    }
}


//Below creates a node by initializing all its values. It initializes value to the value given in parameters, and the left and right variables to NULL.
treenode* createNode(char value) {
    treenode* newNode = (treenode*)malloc(sizeof(treenode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Below finds the operator in a given expression. It does that by checking the brackets and returning the index of the operator.
//int variable count counts up for an open bracket, and counts down for a closed bracket. Once there is one more open bracket than a closed bracket,
//the index of the outmost operator should be the one found right after.
int find_operator(char* expr) {
    int count = 0;
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i]=='(')
            count++;
        else if (expr[i]==')')
            count--;
        if (count == 1 &&(expr[i]=='&'||expr[i]=='|'||expr[i]=='~'))
            return i; 
    }
    return -1;
}

//Below returns a substring of char* str from the start of index start until index end.
char* partOfStr(char* str, int start, int end) {
    int len = end-start+1;
    char* substr = (char*)malloc(len + 1);
    strncpy(substr, str+start,len);
    substr[len] = '\0';
    return substr;
}

//Below builds a binary tree using the char* expression expr and a treenode tree
void build(char* expr, treenode** tree) { 
    if (strlen(expr) <= 6){ //The smallest expressions would end once the expression is of size 6 or less, i.e. it should be either (~(q)) or (q)
		if(*(expr+1)=='~'){
			*tree=createNode(expr[1]);
			(*tree)->left=createNode(expr[3]); //the left value of the node corresponding to the negation is the variable
		}
		else
        	*tree = createNode(expr[1]);
	}
	else {
        int op_in = find_operator(expr);
        *tree = createNode(expr[op_in]); 
        char* leftS=partOfStr(expr, 1, op_in-1); 
        char* rightS=partOfStr(expr, op_in+1, strlen(expr)-2);
        //check for negation in front of an expression
        if(expr[op_in]=='~'&&expr[op_in+1]=='('&&expr[op_in+2]=='('){
            build(rightS, &((*tree)->right)); 
        }
        else{
            build(leftS, &((*tree)->left)); //recursively calls build
            build(rightS, &((*tree)->right)); //recursively calls build
        }
        free(leftS); 
        free(rightS);
    }
}

/*
void main(){
    char* expr="((~(p))&(q))";
    treenode *tree;
    build(expr, &tree);
    printtree(tree);
}*/

