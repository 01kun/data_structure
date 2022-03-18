#include "Tree.h"
#include <iostream>

int Tree::height(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return root->height;
}
int Tree::Max(int a, int b)
{
	return (a > b) ? a : b;
}

//降低左树高度
Node* Tree::LLrotation(Node* root)
{
	Node* temp = root->left;
	root->right = temp->right;
	temp->right = root;
	root->height = Max(height(root->left), height(root->right))+ 1;
	temp->height = Max(height(temp->left), height(temp->right))+ 1;
	return temp;
}
//降低右树高度
Node* Tree::RRrotation(Node* root)
{
	Node* temp = root->right;
	root->right = temp->left;
	temp->left = root;

	root->height = Max(height(root->left), height(root->right)) + 1;
	temp->height = Max(height(temp->left), height(temp->right)) + 1;
	return temp;
}

//记得看看这俩函数的链接是怎么返回的
Node* Tree::LRrotation(Node* root)
{
	root->left = RRrotation (root->left);
	root = LLrotation(root);
	root->left->height = Max(height(root->left->left), height(root->left->right)) + 1;
	root->height       = Max(height(root->left), height(root->right)) + 1;
	
	return root;
}
Node* Tree::RLrotation(Node* root)
{
	root->right = LLrotation(root->right);
	root = RRrotation(root);
	root->right->height = Max(height(root->right->left), height(root->right->right)) + 1;
	root->height = Max(height(root->left), height(root->right)) + 1;
	return root;
}

Node* Tree::get_new_node(int key)
{
	Node* newnode = new  Node(key, nullptr, nullptr);
	if (newnode == nullptr)
	{
		std::cout << "新节点内存申请失败,准备退出" << std::endl;
		exit(0);
	}
	return newnode;
}

void  Tree::InsertAvlNode(int key)
{
	m_Root = InsertAvlNode(this->m_Root, key);
	return;
}
Node* Tree::InsertAvlNode(Node* root, int key)
{
	if (root == nullptr)
	{
		root = new Node(key, nullptr, nullptr);
	}
	else if (key <root->data)
	{
		root->left = InsertAvlNode(root->left, key);
		if (height(root->left) - height(root->right) == 2)
		{
			if (key < root->left->data)
			{
				root = LLrotation(root);
			}
			else if( key > root->left->data)
			{
				root = LRrotation(root);
			}
		}
	}
	else if (key > root->data)
	{
		root->right = InsertAvlNode(root->right, key);

		if (height(root->right) - height(root->left) == 2)
		{
			if (key > root->right->data)
			{
				root = RRrotation(root);
			}
			else if (key < root->right->data)
			{
				root = RLrotation(root);
			}
		}
	}

	root->height = Max(height(root->left), height(root->right)) + 1;
	return root;
}


void Tree::DeleteAvlNode(int key)
{
	DeleteAvlNode(this->m_Root, key);
	return;
}
Node* Tree::DeleteAvlNode(Node* root, int key)
{
	if (root == nullptr)
	{
		return root;
	}
	//要删除的节点是在左子树
	else if (key < root->data)
	{
		root->left = DeleteAvlNode(root->left, key);
		if (height(root->right) - height(root->left) == 2)
		{
			if (root->right->right != nullptr)
			{
				root = RRrotation(root);
			}
			else
			{
				root = RLrotation(root);
			}
		}
	}
	//要删除的节点是在右子树
	else if (key > root->data)
	{
		root->right = DeleteAvlNode(root->right, key);
		if (height(root->left) - height(root->right) == 2)
		{
			if (root->left->left != nullptr)
			{
				root = LLrotation(root);
			}
			else
			{
				root = LRrotation(root);
			}
		}
	}

	else
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr)
		{		
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else
		{
			Node* temp = root->right;
			while (temp->left != nullptr)
			{
				temp = temp->left;
			}
			root->data = temp->data;
			root->right = DeleteAvlNode(root->right, temp->data);

		}
	}
	root->height = Max(height(root->left), height(root->right)) + 1;
	return root;
}


Tree::Tree()
	:m_Root(nullptr)
{
	std::cout << "Tree默认构造函数的调用" << std::endl;
}
Tree::~Tree()
{
	Del_ALL(this->m_Root);
	delete this->m_Root;
	this->m_Root = nullptr;
	std::cout << "Tree析构函数的调用" << std::endl;
}
void Tree::Del_ALL(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->left == nullptr && root->right == nullptr)
	{
		delete root;
		root = nullptr;
		return;
	}
	Del_ALL(root->left);
	Del_ALL(root->right);
	
	return;
}


void Tree::PrintTree()
{
	PrintTree(this->m_Root);
	std::cout << std::endl;
	return;
}
void Tree::PrintTree(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	PrintTree(root->left);
	std::cout << root->data<<" ";
	PrintTree(root->right);
}
