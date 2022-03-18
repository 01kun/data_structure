#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}Node;


Node* GetNewNode(int key);
Node* InsertNode(Node* root, int key);
Node* DeleteNode(Node* root, int key);
void  DelNode(Node* root, int key);

Node* GetNewNode(int key)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		printf("新节点内存申请失败, 准备退出");
		exit(0);
	}
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;

}

Node* InsertNode(Node* root, int key)
{
	if (root == NULL)
	{
		root = GetNewNode(key);
		return root;
	}
	else if (key < root->data)
 	{
		root->left = InsertNode(root->left, key);
	}
	else if (key > root->data)
	{
		root->right = InsertNode(root->right, key);
	}
}

//假定插入不存在相等的情况
void  InsertChildNode(Node* root, int key)
{
	Node* prev = NULL;
	
	if (root == NULL)
	{
		root = GetNewNode(key);
		return;
	}
	while (root != NULL)
	{
		prev = root;
		if (key < root->data)
		{
			root = root->left;
		}
		else if (key > root->data)
		{
			root = root->right;
		}
	}
	if (key < prev->data)
	{
		prev->left = GetNewNode(key);
	}
	else if (key > prev->data)
	{
		prev->right = GetNewNode(key);
	}
	
}

Node* DeleteNode(Node* root, int key)
{
	if (root == NULL)
	{
		return root;
	}
	else if (key < root->data)
	{
		root->left = DeleteNode(root->left, key);
		return root;
	}
	else if (key > root->data)
	{
		root->right = DeleteNode(root->right, key);
		return root;
	}
	else if (key == root->data)
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
			return root;
		}
		else if (root->left == NULL)
		{
			Node* temp = root;
			root = root->right;
			free(temp);
			return root;
		}
		else if (root->right == NULL)
		{
			Node* temp = root;
			root = root->left;
			free(temp);
			return root;
		}
		else
		{
			Node* temp = root->right;
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			root->data = temp->data;
			root->right = DeleteNode(root->right, temp->data);
			return root;
		}
	}
}



int main()
{

}
