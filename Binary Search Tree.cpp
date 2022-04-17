#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
struct node
{
	int key;
	struct node* left, * right;
};
struct bsTree
{
	struct node* root;
	bsTree()
	{
		root = NULL;
	};
	struct node* newNode(int item)
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->key = item;
		temp->left = temp->right = NULL;
		return temp;
	}
	void inorder()
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
	void inorder(struct node* root)
	{
		if (root != NULL)
		{
			inorder(root->left);
			printf("%d ", root->key);
			inorder(root->right);
		}
	}
	void insert(int key)
	{
		if (root == NULL) { root = newNode(key); return; }
		if (key < root->key) root->left = insert(root->left, key);
		else root->right = insert(root->right, key);
		return;
	}
	struct node* insert(struct node* node, int key)
	{
		if (node == NULL) return newNode(key);
		if (key < node->key) node->left = insert(node->left, key);
		else node->right = insert(node->right, key);
		return node;
	}
	struct node* minValueNode(struct node* node)
	{
		struct node* current = node;
		while (current && current->left != NULL) current = current->left;
		return current;
	}
	void deleteNode(int key)
	{
		if (root == NULL) return;
		if (key < root->key) root->left = deleteNode(root->left, key);
		else if (key > root->key) root->right = deleteNode(root->right, key);
		else
		{
			if (root->left == NULL)
			{
				struct node* temp = root->right;
				root = temp;
				return;
			}
			else if (root->right == NULL)
			{
				struct node* temp = root->left;
				root = temp;
				return;
			}
			struct node* temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
		return;
	}
	struct node* deleteNode(struct node* root, int key)
	{
		if (root == NULL) return root;
		if (key < root->key) root->left = deleteNode(root->left, key);
		else if (key > root->key) root->right = deleteNode(root->right, key);
		else
		{
			if (root->left == NULL)
			{
				struct node* temp = root->right;
				free(root);
				return temp;
			}
			else if (root->right == NULL)
			{
				struct node* temp = root->left;
				free(root);
				return temp;
			}
			struct node* temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
		return root;
	}
};
int main()
{
	bsTree hi;
	hi.insert(50);
	hi.insert(30);
	hi.insert(20);
	hi.insert(40);
	hi.insert(70);
	hi.insert(60);
	hi.insert(80);
	hi.inorder();
	cout << endl;
	hi.deleteNode(20);
	hi.inorder();
	cout << endl;
	hi.deleteNode(30);
	hi.inorder();
	cout << endl;
	hi.deleteNode(50);
	hi.inorder();
}
