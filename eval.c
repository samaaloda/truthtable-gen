/* Team 40: Luna Almoayad, Tasnim Ayderus, Sama Al-Oda, Kristian Diana, December 2024
 *
 * A program that evaluates a binary tree that has been built using a user-inputted binary expression. 
 * The evaluation is done through boolean logic. 
 */

#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <stdbool.h>
#include "header.h"


/* and
 *
 * Parameters:
 * - a: first integer input 
 * - b: second integer input
 * 
 * This function performs a logical AND operation on two integers.
 *
 * Returns:
 * - 1 if both a and b are non-zero
 * - 0 otherwise
 */
int and(int a,int b){
 
    if( a&& b)
        return 1;
    return 0; 
}
 


/* or
 *
 * Parameters:
 * - a: first integer input
 * - b: second integer input
 *
 * This function performs a logical OR operation on two integers.
 *
 * Returns:
 * - 1 if either a or b (or both) are non-zero
 * - 0 otherwise
 */
int or(int a, int b){
    if(a || b)
        return 1;
    return 0;   
}
 
/* not
 *
 * Parameters:
 * - a: an integer input
 *
 * This function performs a logical NOT operation on an integer.
 *
 * Returns:
 * - 1 if a is 0
 * - 0 if a is non-zero
 */ 
int not(int a){
    if (a)
        return 0;
    return 1;                                   
    }      

/* update_leaf_value
 *
 * Parameters:
 * - root: pointer to the root node of the binary tree
 * - var: the character value of the variable to search for
 * - newValue: the new character value to assign to the leaf node
 *
 * This function updates the value of a leaf node in a binary tree if it matches
 * the specified variable. The function traverses the tree recursively
 * to locate and update the appropriate node of the tree.
 *
 * Returns: None
 */
void update_leaf_value(treenode *root, char var, char newValue)
{
    if( root ==NULL)
        return;

    if( root-> value == var)
        root->value = newValue;
	
 	
	if(root->left !=NULL && root->right ==NULL)
		update_leaf_value(root->left, var, newValue);
	else
    {	update_leaf_value(root->left, var, newValue);
    	update_leaf_value(root->right, var, newValue);
	}
}

/* evaluate_tree
 *
 * Parameters:
 * - root: pointer to the root node of the binary tree
 *
 * This function evaluates a binary expression tree. For leaf nodes, it returns
 * the integer value stored in the node. For non-leaf nodes, it recursively
 * evaluates the left and right subtrees and applies the operation stored in
 * the current node.
 *
 * Returns:
 * - The evaluated integer result of the binary tree.
 */
int evaluate_tree(treenode *root)
{
    int left_value=0;
    int right_value=0;
    if( root->left == NULL && root->right ==NULL)
     {   
        // return int of string var
           return (int) root->value -'0';
      
     }
    else if(root ->right ==NULL && root->left !=NULL)
	{
		left_value=evaluate_tree(root->left);
	}
    else if(root->right!=NULL &&root->left==NULL){//only happens when ~ing an expr
        right_value=evaluate_tree(root->right);

    }
    else{
        left_value = evaluate_tree(root->left);
        right_value=evaluate_tree(root->right);
    }
    if( root->value=='&')
        return and(left_value, right_value);
    
	else if(root->value=='|')
        return or(left_value,right_value);
    
    else if(root->value=='~') {
        if(left_value!=0)
            return not(left_value); 
        else
            return not(right_value);
    }
}
