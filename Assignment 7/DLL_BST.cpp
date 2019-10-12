/**
 * ALBRIT BENDO 
 * ADS HW 7
 * PROBLEM 7.2
 * LINKED LIST TO BINARY SEARCH TREE
 **/
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int data;
	Node *prev, *next;

	Node(int data)
	{
		this->data = data;
		this->prev = this->next = nullptr;
	}
};

// function to insert a new node at the beginning of the Doubly Linked List
void push(Node* &headRef, int data)
{
	Node* node = new Node(data);
	node->next = headRef;
	// change prev of the existing head node to point to the new node
	if (headRef)
		headRef->prev = node ;
	// update head pointer
	headRef = node;
}

// function to push nodes of a given Linked List in a vector
void push_vector(Node* node, vector<Node*> &nodes)
{
	while (node)
	{
		nodes.push_back(node);
		node = node->next;
	}
}

// fecursive function to construct a BST
Node* build_BST(vector<Node*> &nodes, int start, int end)
{
	// base case
	if (start > end)
		return nullptr;

	// find the middle index
	int mid = (start + end) / 2;

	Node* root = nodes[mid];

	// recursively construct left and right subtree
	root->prev = build_BST(nodes, start, mid - 1);
	root->next = build_BST(nodes, mid + 1, end);
	return root;
}

// function to construct a BST from a sorted Linked List
Node* convert(Node*& headRef)
{
	// push nodes of a given Doubly Linked List in a vector
	vector<Node*> nodes;
	push_vector(headRef, nodes);
	return build_BST(nodes, 0, nodes.size() - 1);
}

// function to print BST
void print(Node* root)
{
	if (root == nullptr)
		return;

	cout << root->data << "\n";
	print(root->prev);
	print(root->next);

}

int main(int argv, char** argc)
{
	Node* head = nullptr;

	// construct a Doubly Linked List from sorted keys
	int keys[] = { 25, 20, 18, 15, 12, 10, 8 };
	for (int key: keys)
		push(head, key);

	// construct a height-balanced BST from a sorted Doubly Linked List
	Node* root = convert(head);

	cout << "Binary Search Tree: \n";
	print(root);

	return 0;
}

/* References: https://www.geeksforgeeks.org/given-linked-list-representation-of-complete-tree-convert-it-to-linked-representation/ 
                https://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/ 

	Time Complexity: O(n)
	Space Complexity: O(n)
*/