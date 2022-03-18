#pragma once
#include "Node.h"
//二叉排序树的实现
class Tree
{
public:
	//构造和析构函数
	Tree(int key);				//有参构造函数
	Tree();						//默认构造函数
	~Tree();					//析构函数
public:
	//给用户提供的服务
	void ChildInsert(int key);	//二叉排序树中节点的插入
	void RootCreate(int key);	//创建根节点
	void PrintTree(int index);	//打印数中所有元素的值,index代表遍历树的方式
	void Del(int key);
private:
	//为给用户提供服务,必备的函数
	void  ChildInsert(Node* root, int key);  //二叉排序树中节点的插入

	Node* DelNode(Node* root);
	Node* DelNode(Node* root, int key);

	Node* GetNewNode(int key);	                //申请一个新节点内存
	Node* FindParent(int parent);               //树中寻找一个树的值
	Node* FindParent(Node* root, int parent);   //寻找父亲节点的位置

	//三种遍历方式打印树中的节点
	void PrevPrint(Node* root); //前序遍历打印树节点
	void InPrint (Node* root);	//中序遍历打印树节点
	void PostPrint(Node* root);	//后序遍历打印树节点
private:
	Node* m_Head; //指向根节点的指针
	int m_Size;   //代表树的大小
};

