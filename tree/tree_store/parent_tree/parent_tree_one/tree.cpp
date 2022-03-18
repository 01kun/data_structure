#include "Tree.h"
#include <iostream>

//Tree默认构造函数,初始化根节点
//
Tree::Tree()
	:m_Node{ nullptr }, m_Size(0), m_MaxSize(20)
{
	std::cout << "Tree默认构造函数的调用" << std::endl;
}
//Tree析构函数
//释放申请的Node内存块
Tree::~Tree()
{
	int i = 0;
	while (i < m_Size)
	{
		delete m_Node[i];
		++i;
	}
	std::cout << "释放了: " << i << " 次Node内存块" << std::endl;
	std::cout << "Tree析构函数的调用" << std::endl;
}

//RootCreatre(int key)函数根节点的创建
//int key 根节点的数值
//记得更新m_Size的大小
void Tree::RootCreate(int key)
{
	Node* newnode = GetNewNode(key);
	m_Node[m_Size] = newnode;
	++m_Size;
	std::cout << "根节点创建成功" << std::endl;
	return;
}

//GetNewNode(int key)函数
//申请新节点内存
//int key待插入的数据
//新节点 data(key) parent(-1)
Node* Tree::GetNewNode(int key)
{
	Node* newnode = new Node(key);
	if (newnode == NULL)
	{
		std::cout << "新节点内存申请失败,准备退出" << std::endl;
		exit(0);
	}
	return newnode;
}

//FindParent(int parent)函数
//判断数组中是否存在这个父节点
int Tree::FindParent(int parent)
{
	for (int i = 0; i < m_Size; i++)
	{
		if (m_Node[i]->data = parent)
		{
			return i;
		}
	}
	return -1;
}

//ChildInsert(int key, int parent)函数,插入孩子节点
//int key  待插入的数据
//int parent 父亲的数据
//记得更新数组的大小
void Tree::ChildInsert(int parent, int key)
{
	if (m_Size >= m_MaxSize)
	{
		std::cout << "数组已满,插入操作失败" << std::endl;
		return;
	}
	int index = FindParent(parent);
	if (index == -1)
	{
		std::cout << "没有此父节点,插入操作失败" << std::endl;
		return;
	}
	Node* newnode = GetNewNode(key);
	newnode->parent = index;
	m_Node[m_Size] = newnode;
	++m_Size;
	std::cout << "插入操作成功" << std::endl;
	return;

}
