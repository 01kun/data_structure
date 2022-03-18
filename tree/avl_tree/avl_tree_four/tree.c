#include <stdio.h>
#include <stdlib.h>

typedef struct AvlTree
{
	int data;
	struct AvlTree* left;
	struct AvlTree* right;
	int height;
}avlnode, *avltree;

avltree left_left_rotation(avltree tree);
avltree right_right_rotation(avltree tree);
avltree right_left_rotation(avltree tree);
avltree left_right_rotation(avltree tree);
avltree GetNewNode(int key);
int height(avlnode* root);
int Max(int a, int b);
avltree InsertAvlNode(avltree root, int key);
avltree search(avltree root, int key);
avltree DelAvlNode(avltree root, int key);
void InOrderPrint(avltree root);
void PreOrderPrint(avltree root);

//LL插入操作  降低左树的高度(右旋)
avltree left_left_rotation(avltree tree)
{
	avlnode* temp = tree->left;
	tree->left = temp->right;
	temp->right = tree;
	//记得更新树的高度
}
//RR插入操作  降低右树的高度(左旋)
avltree right_right_rotation(avltree tree)
{
	avlnode* temp = tree->right;
	tree->right = temp->left;
	temp->left = tree;
	//记得更新树的高度
}
//LR插入操作
avltree left_right_rotation(avltree tree)
{
	tree->left = right_right_rotation(tree->left);
	tree = left_left_rotation(tree);
	//记得更新树的高度
}
//RL插入操作
avltree right_left_rotation(avltree tree)
{
	tree->right = left_left_rotation(tree->right);
	tree = right_right_rotation(tree);
	//记得更新树的高度
}

//如果是普通的插入操作 就按普通的插入操作来
//如果插入之后导致树失衡,就进行旋转操作

avltree GetNewNode(int key)
{
	avlnode* newnode = (avlnode*)malloc(sizeof(avlnode));
	if (newnode == NULL)
	{
		printf("新节点内存申请失败,准备退出\n");
		exit(0);
	}
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->height = 0;
	return newnode;
}

int height(avlnode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->height;
}
int Max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
avltree InsertAvlNode(avltree root, int key)
{
	if (root == NULL)
	{
		root = GetNewNode(key);
	}
	else if (key < root->data)
	{
		root->left = InsertAvlNode(root->left, key);
		if(height(root->left) - height(root->right) == 2)
		{
			if (key < root->left->data)
			{
				root = left_left_rotation(root);
			}
			if (key > root->left->data)
			{
				root = left_right_rotation(root);
			}
		}
	}
	else if (key > root->data)
	{
		root->right = InsertAvlNode(root->right, key);
		if (height(root->right) - height(root->left) == 2)
		{
			if (key < root->left->data)
			{
				root = right_left_rotation(root);
			}
			if (key > root->left->data)
			{
				root = right_right_rotation(root);
			}
		}
	}
	root->height = Max(height(root->left), height(root->right)) + 1;
	//更新树的高度
	return root;
}


avltree search(avltree root, int key)
{
	if (root == NULL || root->data == key)
	{
		return root;
	}
	else if (key < root->data)
	{
		root->left = search(root->left, key);
	}
	else if (key > root->data)
	{
		root->right = search(root->right, key);
	}
}

avltree DelAvlNode(avltree root, int key)
{
	if (root == NULL)
	{
		return root;
	}
	else if (key < root->data)
	{
		root->left = DelAvlNode(root->left, key);
		if (height(root->right) - height(root->left) == 2)
		{
			if (root->right->right != NULL)
			{
				root = right_right_rotation(root);
			}
			else
			{
				root = right_left_rotation(root);
			}
		}
	}
	else if (key > root->data)
	{
		root->right = DelAvlNode(root->right, key);
		if (height(root->left) - height(root->right) == 2)
		{
			if (root->left->left != NULL)
			{
				root = left_left_rotation(root);
			}
			else
			{
				root = left_right_rotation(root);
			}
		} 
	}
	//找到待删除的节点
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			avlnode* node = root;
			free(node);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			avlnode* node = root;
			root = root->right;
			free(node);
		}
		else if (root->right == NULL)
		{
			avlnode* node = root;
			root = root->left;
			free(node);
		}
		else
		{
			avlnode* node = root->right;
			while (node->left != NULL)
			{
				node = node->left;
			}
			root->data = node->data;
			root->right = DelAvlNode(root->right, key);
		}
	}
	if (root)
	{
		root->height = Max(height(root->left), height(root->right));
	}
	return root;
}

void InOrderPrint(avltree root)
{
	if (root == NULL)
	{
		return;
	}
	InOrderPrint(root->left);
	printf("%d ", root->data);
	InOrderPrint(root->right);
	printf("\n");
}

void PreOrderPrint(avltree root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	InOrderPrint(root->left);
	InOrderPrint(root->right);
	printf("\n");
}
int main()
{
	avltree root = NULL;
	root = InsertAvlNode(root, 3);
	root = InsertAvlNode(root, 5);
	root = InsertAvlNode(root, 7);
	
	PreOrderPrint(root);
	InOrderPrint(root);

	int b = 0;
}
