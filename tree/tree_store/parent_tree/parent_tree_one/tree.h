#pragma once
#include "Node.h"

//双亲表示法,结构体数组,存储树
//根节点创建和孩子节点插入
class Tree
{
public:
	Tree();							        //Tree默认构造函数	
	~Tree();					            //Tree析构函数
public:
	void   RootCreate (int key);            //根节点的创建
	void   ChildInsert(int parent, int key);//节点的插入
private:
	Node*  GetNewList (int key);            //申请新节点
	int    FindParent (int parent);         //寻找父亲节点
private:
	Node* m_Node[20];
	int   m_Size;
	int   m_MaxSize;
};



