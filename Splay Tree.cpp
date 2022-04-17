#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node* left, * right;
};
struct SplayTree
{
	struct node* root;
	SplayTree()
	{
		root = NULL;
	}
	struct node* newNode(int key)
	{
		struct node* node = (struct node*)malloc(sizeof(struct node));
		node->key = key;
		node->left = node->right = NULL;
		return node;
	}
	struct node* rightRotate(struct node* x)
	{
		struct node* y = x->left;
		x->left = y->right;
		y->right = x;
		return y;
	}
	struct node* leftRotate(struct node* x)
	{
		struct node* y = x->right;
		x->right = y->left;
		y->left = x;
		return y;
	}
	struct node* splay(struct node* root, int key)
	{
		if (root == NULL || root->key == key) return root;
		if (root->key > key)
		{
			if (root->left == NULL) return root;
			if (root->left->key > key)
			{
				root->left->left = splay(root->left->left, key);
				root = rightRotate(root);
			}
			else if (root->left->key < key)
			{
				root->left->right = splay(root->left->right, key);
				if (root->left->right != NULL) root->left = leftRotate(root->left);
			}
			return (root->left == NULL) ? root : rightRotate(root);
		}
		else
		{
			if (root->right == NULL) return root;
			if (root->right->key > key)
			{
				root->right->left = splay(root->right->left, key);
				if (root->right->left != NULL) root->right = rightRotate(root->right);
			}
			else if (root->right->key < key)
			{
				root->right->right = splay(root->right->right, key);
				root = leftRotate(root);
			}
			return (root->right == NULL) ? root : leftRotate(root);
		}
	}
	struct node* insert(struct node* root, int k)
	{
		if (root == NULL) return newNode(k);
		root = splay(root, k);
		if (root->key == k) return root;
		struct node* newnode = newNode(k);
		if (root->key > k)
		{
			newnode->right = root;
			newnode->left = root->left;
			root->left = NULL;
		}
		else
		{
			newnode->left = root;
			newnode->right = root->right;
			root->right = NULL;
		}
		return newnode;
	}
	void insert(int k)
	{
		if (root == NULL)
		{
			root = newNode(k);
			return;
		}
		root = splay(root, k);
		if (root->key == k) return;
		struct node* newnode = newNode(k);
		if (root->key > k)
		{
			newnode->right = root;
			newnode->left = root->left;
			root->left = NULL;
		}
		else
		{
			newnode->left = root;
			newnode->right = root->right;
			root->right = NULL;
		}
		root = newnode;
	}
	struct node* delete_key(struct node* root, int key)
	{
		struct node* temp;
		if (!root) return NULL;  
		root = splay(root, key);
		if (key != root->key) return root;
		if (!root->left)
		{
			temp = root;
			root = root->right;
		}
		else
		{
			temp = root;
			root = splay(root->left, key);
			root->right = temp->right;
		}
		free(temp);
		return root;
	}
	void delete_key(int key)
	{
		struct node* temp;
		if (!root) return;
		root = splay(root, key);
		if (key != root->key) return; 
		if (!root->left)
		{
			temp = root;
			root = root->right;
		}
		else
		{
			temp = root;
			root = splay(root->left, key);
			root->right = temp->right;
		}
		free(temp);
	}
	void search(int key)
	{
		root = splay(root, key);
	}
	void preOrder(struct node* root)
	{
		if (root != NULL)
		{
			printf("%d ", root->key);
			preOrder(root->left);
			preOrder(root->right);
		}
	}
	void preOrder()
	{
		if (root != NULL)
		{
			printf("%d ", root->key);
			preOrder(root->left);
			preOrder(root->right);
		}
	}
};
int main()
{
	SplayTree a;
	a.root = a.newNode(100);
	a.root->left = a.newNode(50);
	a.root->right = a.newNode(200);
	a.root->left->left = a.newNode(40);
	a.root->left->left->left = a.newNode(30);
	a.root->left->left->left->left = a.newNode(20);
	printf("Preorder traversal of the modified Splay tree is \n");
	a.preOrder();
	a.insert(25);
	a.delete_key(200);
	a.search(20);
	printf("\nPreorder traversal of the modified Splay tree is \n");
	a.preOrder();
}
