#include <bits/stdc++.h>

using namespace std;

struct node {
	int key;
	struct node* left, *right;
};

void inorder(struct node* root){
	if(!root)
		return;

	inorder(root->left);
	cout<<root->key<<" ";
	inorder(root->right);
}

struct node* newNode(int key)
{
	struct node* temp = new node;
	temp->key = key;
	temp->right = temp->left = NULL;
	return temp;
}

struct node* insert(struct node* root, int key){
	if(root == NULL)
	{
		return newNode(key);
	}

	if(key < root->key){
		root->left = insert(root->left, key);
	}
	if (key > root->key){
		root->right = insert(root->right, key);
	}
	return root; 
}

int main()
{

    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    // print inoder traversal of the BST
    inorder(root);
  
    return 0;
}