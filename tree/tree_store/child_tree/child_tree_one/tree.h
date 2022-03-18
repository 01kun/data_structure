#pragma once
#include "List.h"
//树的存储  孩子表示法
//主要功能  孩子节点的创建, 根节点的创建 
class Tree
{
public:
	Tree();							        //Tree默认构造函数	
	~Tree();					            //Tree析构函数
public:
	void   RootCreate(int key);             //根节点的创建
	void   ChildInsert(int parent, int key);//节点的插入
private:
	List*  GetNewList(int key);             //申请新数据节点
	Node*  GetNewNode(int key);             //申请新下标节点
	int    FindParent(int parent);          //寻找父亲节点
private:
	List*  m_List[20];						//存放树节点信息的数组
	int    m_Size;							//当前数组的大小.树的大小
	int    m_MaxSize;						//数组的最大值
};



