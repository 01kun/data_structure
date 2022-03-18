#include "Tree.h"
#include <iostream>
//二叉排序树的实现

Tree::Tree()
	:m_Head(nullptr), m_Size(0)
{
	std::cout << "Tree默认构造函数的实现" << std::endl;
}
Tree::Tree(int key)
	: m_Head(nullptr), m_Size(0)
{
	m_Head = GetNewNode(key);
	if (m_Head == nullptr)
	{
		std::cout << "根节点内存申请失败,准备退出" << std::endl;
	}
	++m_Size;
	std::cout << "根节点创建成功" << std::endl;
	std::cout << "Tree有参构造函数的实现" << std::endl;
}

//RootCreate(int key)函数
//创建根节点
//int key待插入根节点的数据
void Tree::RootCreate(int key)
{
	if (m_Head != nullptr)
	{
		std::cout << "已有根节点,根节点创建操作失败,准备退出" << std::endl;
		return;
	}
	m_Head = GetNewNode(key);
	if (m_Head == nullptr)
	{
		std::cout << "根节点内存申请失败,准备退出" << std::endl;
	}
	++m_Size;
	std::cout << "根节点创建成功" << std::endl;
	return;

}

Node* Tree::GetNewNode(int key)
{
	Node* newnode = new Node(key);
	if (newnode == nullptr)
	{
		std::cout << "新节点内存申请失败,准备退出" << std::endl;
	}
	return newnode; 
}

//FindParent(int parent)函数 
//再树中寻找parent代表的父节点
Node* Tree::FindParent(int parent)
{
	Node* temp = FindParent(m_Head, parent);
	if (temp == nullptr)
	{
		std::cout << "没有找到此父节点" << std::endl;
		return temp;
	}
	std::cout << "找到此父节点" << std::endl;
	return temp;
}
//FindParent(Node*root, int parent)函数
//遍历整棵树对比树中的数据和parent是否相等
// root 将要判断的根节点
// int parent 将要判断的数据
//!!!注意!!!这个遍历没有利用到二叉树的性质!!!
Node* Tree::FindParent(Node* root, int parent)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->data == parent)
	{
		return root;
	}
	if (parent < root->data)
	{
		FindParent(root->left, parent);
	}
	else if (parent > root->data)
	{
		FindParent(root->right, parent);
	}
}


//PrintTree函数,打印树中的数据
//index =1, 前序遍历打印
//index =2, 中序遍历打印
//index =3, 后序遍历打印
void Tree::PrintTree(int index)
{
	if (index == 1)
	{
		PrevPrint(m_Head);
		std::cout << std::endl;
		return;
	}
	else if (index == 2)
	{
		InPrint(m_Head);
		std::cout << std::endl;
		return;
	}
	else if (index == 3)
	{
		PostPrint(m_Head);
		std::cout << std::endl;
		return;
	}
}
//打印树的三种方式
//前序遍历打印
void Tree::PrevPrint(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	std::cout << root->data << " ";
	PrevPrint(root->left);
	PrevPrint(root->right);
}
//中序遍历打印
void Tree::InPrint(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	InPrint(root->left);
	std::cout << root->data << " ";
	InPrint(root->right);
}
//后序遍历打印
void Tree::PostPrint(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	PostPrint(root->left);
	PostPrint(root->right);
	std::cout << root->data << " ";
}


//ChildInsert(int key)函数,给用户看的函数
// 进行数据的插入
//int key待插入的数据
void Tree::ChildInsert(int key)
{
	ChildInsert(this->m_Head, key);

	return;
}
//ChildInsert(Node*root ,int key)
//一种插入的方式, 使用递归和返回值更新
//进行节点的插入操作 
void Tree::ChildInsert(Node* root, int key)
{
	if (root == nullptr)
	{
		root = GetNewNode(key);
		std::cout << "(根节点)插入操作完成" << std::endl;
		return;
	}
	Node* prev = nullptr;
	Node* temp = root;
	while (temp != nullptr)
	{
		prev = temp;
		if (key > temp->data)
		{
			temp = temp->right;
		}
		else if (key < temp->data)
		{
			temp = temp->left;
		}
	}

	if (key < prev->data)
	{
		prev->left = GetNewNode(key);
		std::cout << "(孩子节点)插入操作完成" << std::endl;
	}
	else if (key > prev->data)
	{
		prev->right = GetNewNode(key);
		std::cout << "(孩子节点)插入操作完成" << std::endl;
	}
	return;
}

// 这个是给用户看的函数
void Tree::Del(int key)
{
	DelNode(m_Head, key);
	return;
}

Node* DelNode(Node* root, int key)
{
	if (root == NULL)
	{
		return root;
	}
	else
	{
		if (key < root->data)
		{
			root->left=  DelNode(root->left, key);
			return root;
		}
		else if (key > root->data)
		{
			root->right= DelNode(root->right, key);
			return root;
		}
		else if (key == root->data)
		{
			if (root->left == nullptr && root->right == nullptr)
			{
				delete root;
				root = nullptr;
				std::cout << "叶子节点的删除" << std::endl;
				return root;
			}
			else if (root->left == nullptr)
			{
				Node* temp = root;
				root = root->right;
				delete temp;
				return root;
			}
			else if (root->right == nullptr)
			{
				Node* temp = root;
				root = root->left;
				delete temp;
				return root;
			}
			else
			{
				Node* temp = root->right;
				while (temp->left != nullptr)
				{
					temp = temp->left;
				}
				root->data = temp->data;
				root->right = DelNode(root->right, temp->data);
				return root;
			}
		}
	}
}
