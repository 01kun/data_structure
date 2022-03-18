#include "Tree.h"
#include <iostream>

//Tree构造函数
Tree::Tree()
	:m_Root(nullptr), m_Size(0)
{
	std::cout << "Tree默认构造函数的调用" << std::endl;
}
//RootCreate函数创建根节点
//int key根节点的数据
void Tree::RootCreate(int key)
{
	m_Root = GetNewNode(key);
	++m_Size;
	return;
}

//GetNewNode(int key)函数,申请新Node节点内存
//int key,待插入新节点的数据
Node* Tree::GetNewNode(int key)
{
	Node* newnode = new Node(key);
	if (newnode == nullptr)
	{
		std::cout << "没有申请到新节点内存,准备退出" << std::endl;
		exit(0);
	}
	return newnode;
}

//FindParent(Node* root, int parent)查询父节点
//Node* root带查询的树的根节点
//int parent待查询节点的数据
Node* Tree::FindParent(Node* root , int parent)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->m_Data == parent)
	{
		return root;
	}
	FindParent(root->m_Son, parent);
	FindParent(root->m_Bro, parent);
}

//ChildInsert孩子节点的插入
//int parent父亲节点
//int key待插入节点的数据
void Tree::ChildInsert(int parent, int key)
{	
	//查询是否存在此父节点
	Node* temp = FindParent(this->m_Root, parent);
	if (temp == nullptr)
	{
		std::cout << "没有此父节点,准备退出" << std::endl;
		return;
	}
	//判断父亲节点是否有孩子
	Node* newnode = GetNewNode(key);
	if (temp->m_Son == nullptr)
	{
		temp->m_Son = newnode;
	}
	//判断父亲节点是否有兄弟(叔叔)
	else if(temp->m_Bro == nullptr) 
	{
		temp->m_Bro = newnode;
	}
	else if (temp->m_Bro != nullptr)
	{
		newnode->m_Bro = temp->m_Bro;
		temp->m_Bro = newnode;
	}
	std::cout << "节点插入成功" << std::endl;
	++m_Size;
	return;
}

//打印树中的数据
void Tree::PrintTree() 
{
	std::cout <<"开始打印树中的数据" <<std::endl;
	Print(m_Root);
	std::cout << std::endl;
}

//树的打印
void Tree::Print(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	std::cout << root->m_Data << " ";
	Print(root->m_Son);
	Print(root->m_Bro);
}

//析构函数,释放所有Node内存块
Tree::~Tree()
{
	Del_All(m_Root); //释放所有子节点内存
	delete m_Root;	 //释放根节点内存
	std::cout << "Tree析构函数的调用" << std::endl;
}

//Del_All函数,释放所有的子节点内存块
//Node* root传入的根节点
void Tree::Del_All(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->m_Bro == nullptr && root->m_Son == nullptr)
	{
		delete root;
		root = nullptr;
		return;
	}
	Del_All(root->m_Son);
	Del_All(root->m_Bro);
}

