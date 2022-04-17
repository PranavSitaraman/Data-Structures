#include<stdio.h>
#include<stdlib.h>
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
	int height;
};
struct AVLTree
{
	Node* root;
	AVLTree() { root = NULL; }
	int height(struct Node* N) { if (N == NULL) return 0; return N->height; }
	struct Node* newNode(int key)
	{
		struct Node* node = (struct Node*)malloc(sizeof(struct Node));
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		node->height = 1;
		return(node);
	}
	struct Node* rightRotate(struct Node* node)
	{
		struct Node* x = node->left;
		struct Node* y = x->right;
		x->right = node;
		node->left = y;
		node->height = max(height(node->left), height(node->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;
		return x;
	}
	struct Node* leftRotate(struct Node* node)
	{
		struct Node* x = node->right;
		struct Node* y = x->left;
		x->left = node;
		node->right = y;
		node->height = max(height(node->left), height(node->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;
		return x;
	}
	int getBalance(struct Node* N) { if (N == NULL) return 0; return height(N->left) - height(N->right); }
	struct Node* insert(struct Node* node, int key)
	{
		if (node == NULL) return(newNode(key));
		if (key < node->key) node->left = insert(node->left, key);
		else if (key > node->key) node->right = insert(node->right, key);
		else return node;
		node->height = 1 + max(height(node->left), height(node->right));
		int bal = getBalance(node);
		if (bal > 1 && key < node->left->key) return rightRotate(node);
		if (bal < -1 && key > node->right->key) return leftRotate(node);
		if (bal > 1 && key > node->left->key) { node->left = leftRotate(node->left); return rightRotate(node); }
		if (bal < -1 && key < node->right->key) { node->right = rightRotate(node->right); return leftRotate(node); }
		return node;
	}
	void insert(int key)
	{
		if (root == NULL) { root = newNode(key); return; }
		if (key < root->key) root->left = insert(root->left, key);
		else if (key > root->key) root->right = insert(root->right, key);
		else return;
		root->height = 1 + max(height(root->left), height(root->right));
		int bal = getBalance(root);
		if (bal > 1 && key < root->left->key) { root = rightRotate(root); return; }
		if (bal < -1 && key > root->right->key) { root = leftRotate(root); return; }
		if (bal > 1 && key > root->left->key) { root->left = leftRotate(root->left); root = rightRotate(root); return; }
		if (bal < -1 && key < root->right->key) { root->right = rightRotate(root->right); root = leftRotate(root); return; }
		return;
	}
	struct Node* minValueNode(struct Node* node) { struct Node* current = node; while (current->left != NULL) current = current->left; return current; }
	struct Node* deleteNode(struct Node* root, int key)
	{
		if (root == NULL) return root;
		if (key < root->key) root->left = deleteNode(root->left, key);
		else if (key > root->key) root->right = deleteNode(root->right, key);
		else
		{
			if ((root->left == NULL) || (root->right == NULL))
			{
				struct Node* x = root->left ? root->left : root->right;
				if (x == NULL) { x = root; root = NULL; }
				else *root = *x;
				free(x);
			}
			else
			{
				struct Node* y = minValueNode(root->right);
				root->key = y->key;
				root->right = deleteNode(root->right, y->key);
			}
		}
		if (root == NULL) return root;
		root->height = 1 + max(height(root->left), height(root->right));
		int bal = getBalance(root);
		if (bal > 1 && getBalance(root->left) >= 0) return rightRotate(root);
		if (bal > 1 && getBalance(root->left) < 0) { root->left = leftRotate(root->left); return rightRotate(root); }
		if (bal < -1 && getBalance(root->right) <= 0) return leftRotate(root);
		if (bal < -1 && getBalance(root->right) > 0) { root->right = rightRotate(root->right); return leftRotate(root); }
		return root;
	}
	void deleteNode(int key)
	{
		if (root == NULL) return;
		if (key < root->key) root->left = deleteNode(root->left, key);
		else if (key > root->key) root->right = deleteNode(root->right, key);
		else
		{
			if ((root->left == NULL) || (root->right == NULL))
			{
				struct Node* x = root->left ? root->left : root->right;
				if (x == NULL) { x = root; root = NULL; }
				else *root = *x;
				free(x);
			}
			else
			{
				struct Node* y = minValueNode(root->right);
				root->key = y->key;
				root->right = deleteNode(root->right, y->key);
			}
		}
		if (root == NULL) return;
		root->height = 1 + max(height(root->left), height(root->right));
		int bal = getBalance(root);
		if (bal > 1 && getBalance(root->left) >= 0) { root = rightRotate(root); return; }
		if (bal > 1 && getBalance(root->left) < 0) { root->left = leftRotate(root->left); root = rightRotate(root); return; }
		if (bal < -1 && getBalance(root->right) <= 0) { root = leftRotate(root); return; }
		if (bal < -1 && getBalance(root->right) > 0) { root->right = rightRotate(root->right); root = leftRotate(root); return; }
		return;
	}
	void preOrder(struct Node* root)
	{
		if (root != NULL) { printf("%d ", root->key); preOrder(root->left); preOrder(root->right); }
	}
	void preOrder()
	{
		if (root != NULL) { printf("%d ", root->key); preOrder(root->left); preOrder(root->right); printf("\n"); }
	}
	void destroy(struct Node* node)
	{
		if (node != NULL)
		{
			destroy(node->left);
			free(node->left);
			destroy(node->right);
			free(node->right);
		}
	}
	~AVLTree()
	{
		if (root != NULL)
		{
			destroy(root->left);
			free(root->left);
			destroy(root->right);
			free(root->right);
		}
	}
};
int main()
{
	AVLTree hello;
	hello.insert(9);
	hello.insert(5);
	hello.insert(10);
	hello.insert(0);
	hello.insert(6);
	hello.insert(11);
	hello.insert(-1);
	hello.insert(1);
	hello.insert(2);
	hello.preOrder();
	hello.deleteNode(10);
	hello.deleteNode(6);
	hello.preOrder();
}
