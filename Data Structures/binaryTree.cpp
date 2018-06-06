#include <bits/stdc++.h>
using namespace std;

struct node {
	int key;
	struct node* left;
	struct node* right;
};

struct node* newNode(int key) {
	struct node* temp = new node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node* temp){
	if(!temp)
		return;

	inorder(temp->left);
	cout<<temp->key<<" ";
	inorder(temp->right);
}

void insert(struct node* temp, int key){

	queue<struct node*> q;
	q.push(temp);

	while(!q.empty()){
		struct node* temp = q.front();
		q.pop();

		if(!temp->left){
			temp->left = newNode(key);
			break;
		}
		else {
			q.push(temp->left);
		}

		if(!temp->right){
			temp->right = newNode(key);
			break;
		}
		else{
			q.push(temp->right);
		}
	}
}


void deleteRightmost(struct node* root, struct node* rightmost){
	queue<struct node*> q;
	q.push(root);

	while(!q.empty()){
		struct node* temp = q.front();
		q.pop();


		if(temp->left){
			if(temp->left == rightmost){
				temp->left = NULL;
				delete(rightmost);
				return;
			}
			else
				q.push(temp->left);
		}

		if(temp->right){
			if(temp->right == rightmost){
				temp->right = NULL;
				delete(rightmost);
				return;
			}
			else
				q.push(temp->right);
		}

	}
}

void deleteNode(struct node* root, int key){
	queue<struct node*> q;
	q.push(root);

	struct node* key_node;
	struct node* temp;

	while(!q.empty()){
		temp = q.front();
		q.pop();

		if(temp->key == key){
			key_node = temp; 
		}

		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}

	}

	int x = temp->key;
	deleteRightmost(root, temp);
	key_node->key = x; 
}

int main ()
{
    struct node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    cout<<"before insertion";
    inorder(root);

    int key = 12;
    insert(root, key);

    cout<<"after insertion";
    inorder(root);

    deleteNode(root, key);

    cout<<"after deletion";
    inorder(root);

    return 0;

}