#pragma once
#include "Node.h"

//申请创建List节点使用
class List
{
public:
	List();			//List构造函数
	List(int key);	//List有参构造函数
	~List();		//List析构函数
public:		
	int m_Data;
	Node* m_Next;  //指向Node节点的指针
};

