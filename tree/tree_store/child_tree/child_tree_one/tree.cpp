#include "Tree.h"
#include <iostream>

//RootCreate函数,创建根节点
//int key 根节点的数据
//记得更新m_Size的大小
void Tree::RootCreate(int key)
{
	m_List[m_Size] = GetNewList(key);
	//GetNewList返回的不会是nullptr,不用判断
	++m_Size;
	return;
}

//GetNewNode(int key)函数创建一个新的List结点
//int key 待插入到新节点的数据
List* Tree::GetNewList(int key)
{
	List* newlist = new List(key);
	if (newlist == nullptr)
	{
		std::cout << "新数据节点内存申请失败,准备退出" << std::endl;
	}
	return newlist;
}

//ChildInsert函数,孩子节点的插入
//int parent 待寻找的父亲节点
//int key待插入到新节点的数据
//记得更新m_Size的大小
void Tree::ChildInsert(int parent, int key)
{
	//判断存放树的数组是否满
	if (m_Size >= m_MaxSize)
	{
		std::cout << "树已满,插入失败,准备返回" << std::endl;
		return;
	}
	//判断是否有此父亲节点
	int index = FindParent(parent);
	if (index == -1)
	{
		std::cout << "没有此父节点,插入失败,准备返回" << std::endl;
		return;
	}

	//先把数据存到数组
	List* newlist = GetNewList(key);
	m_List[m_Size] = newlist;
	
	//再将子节点的下标信息链到父节点的链表中
	Node* newnode = GetNewNode(m_Size);
	
	newnode->m_Next = m_List[index]->m_Next;
	m_List[index]->m_Next = newnode;

	//更新m_Size的大小
	++m_Size;
	std::cout << "插入成功" << std::endl;
	return;

}


//GetNewNode函数,创建一个新的Node节点
//int key待插入节点的数据(孩子节点的下标)
Node* Tree::GetNewNode(int key)
{
	Node* newnode = new Node(key);
	if (newnode == nullptr)
	{
		std::cout << "新下标节点内存申请失败,准备退出" << std::endl;
	}
	return newnode;
}

//FindParent函数,查询树中的父节点信息
//int parent 待查询的父节点信息
int Tree::FindParent(int parent)
{
	int i = 0;
	while (i < m_Size)
	{
		if (m_List[i]->m_Data == parent)
		{
			return i;
		}
		++i;
	}
	return -1;
}

//Tree默认构造函数,初始化数据
Tree::Tree()
	:m_List(), m_Size(0), m_MaxSize(20)
{
	std::cout << "Tree默认构造函数的调用" << std::endl;
}

//Tree析构函数,释放所有申请的内存节点
Tree::~Tree()
{
	int i = 0;		//i用来记录释放的List内存块
	int index = 0;	//index 用来记录释放的Node内存块
	for (i; i < m_Size; i++)
	{
		//temp和del_node指针,用来释放List对象所指的所有Node内存
		Node* temp = m_List[i]->m_Next;
		Node* del_node = temp;       
		while (temp != nullptr)
		{
			temp = temp->m_Next;
			delete del_node;
			del_node = temp;
			++index;
		}
		//del_list指针, 用来释放m_List[]对象所指的所有List内存
		List* del_list = m_List[i];
		delete del_list;
	}
	//打印信息,判断是否正确释放所有的内存块
	std::cout << "m_Size的大小是: " << m_Size << std::endl;
	std::cout << "释放:" << i << " 块List内存" << std::endl;
	std::cout << "释放:" << index << " 块Node内存" << std::endl;

	std::cout << "Tree析构函数的调用" << std::endl;
}
