/**
 * ALBRIT BENDO
 * ADS HW 7
 * PROBLEM 7.2
 * BINARY SEARCH TREE TO LINKED LIST
 **/
#include <iostream>

using namespace std;

typedef struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
}BinaryTreeNode;

void ConvertNode(BinaryTreeNode* root, BinaryTreeNode** head)
{
    if(root == NULL) // if empty
        return;

    BinaryTreeNode *current = root;

    if (current->left != NULL) // convert left side
        ConvertNode(current->left, head);

    current->left = *head; // convert the node
    if(*head != NULL)
        (*head)->right = current;

    *head = current;

    if (current->right != NULL)
        ConvertNode(current->right, head); // convert right side
}

BinaryTreeNode* new_node(int data) 
{ 
    BinaryTreeNode* new_node = new BinaryTreeNode; 
    new_node->value = data; 
    new_node->left = new_node->right = NULL; 
    return (new_node); 
} 

void print(BinaryTreeNode* node) 
{ 
    while (node!=NULL) 
    { 
        cout << node->value << endl; 
        node = node->right; 
    } 
} 
  

int main(int argv, char** argc) 
{ 
    // creating the tree
    BinaryTreeNode *root = new_node(10); 
    root->left = new_node(12); 
    root->right = new_node(15); 
    root->left->left = new_node(25); 
    root->left->right = new_node(30); 
    root->right->left = new_node(36); 
  
    
    BinaryTreeNode *head = NULL; 
    ConvertNode(root, &head);
  
    print(head); 
  
    return 0; 
} 

/* References: https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/ 
    
    Time Complexit: O(n)
*/

// Couldn't make it sorted