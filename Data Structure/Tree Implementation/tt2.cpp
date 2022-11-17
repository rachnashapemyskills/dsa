// Binary Search Tree operations in C++
#include <iostream>
using namespace std;
struct node {
 int data;
 struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {

 struct node *temp = new node;
 temp->data = item;
 temp->left = temp->right = NULL;
 return temp;
}
// Inorder Traversal
void inorder(struct node *root) 
{
 if (root != NULL) {
	 inorder(root->left);
	 cout << root->data << " -> ";
	 inorder(root->right);
	 }
}
 
struct node *insert(struct node *node, int data) {
 if (node == NULL) {
 	return newNode(data);
 }

 if (data < node->data)
 {
 		node->left = insert(node->left, data);
 } 
 else
 {
 		node->right = insert(node->right, data);
 }
 
 return node;
}


// Find the inorder successor
struct node *minValueNode(struct node *node) {
 struct node *current = node;
 // Find the leftmost leaf
 while (current && current->left != NULL)
 current = current->left;
 return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int data) 
{
 // Return if the tree is empty
 if (root == NULL)
 {
 	return root;
  } 
 // Find the node to be deleted
 if (data < root->data)
 {
 	root->left = deleteNode(root->left, data);
 }
 
 else if (data > root->data)
 {
 	root->right = deleteNode(root->right, data);	
 }
 
 else {
 
	 if (root->left == NULL) 
	 {
	 	struct node *temp = root->right;
	 	delete root;
	 return temp;
	 } 
	 else if (root->right == NULL) 
	 {
	 	struct node *temp = root->left;
	 	delete root;
	 return temp;
	 }
	 
 // If the node has two children
 	struct node *temp = minValueNode(root->right);
 // Place the inorder successor in position of the node to be deleted
 	root->data = temp->data;
 // Delete the inorder successor
 	root->right = deleteNode(root->right, temp->data);
 }
 return root;
}



// Driver code
int main() {
 struct node *root = NULL;
 root = insert(root, 8);
 root = insert(root, 3);
 root = insert(root, 1);
 root = insert(root, 6);
 root = insert(root, 7);
 root = insert(root, 10);
 root = insert(root, 14);
 root = insert(root, 4);
 cout << "Inorder traversal: ";
 inorder(root);
 deleteNode(root, 7);
 cout<<"\n After Deletion \n";
 inorder(root);
 
}
