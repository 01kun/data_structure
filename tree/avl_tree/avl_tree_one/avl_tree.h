#pragma once
#include "Node.h"

class Tree
{
public:
	Tree();	  //构造函数	
	~Tree();  //析构函数
public:
	//展示给用户看的
	void Delete_avlnode(int key);
	void Insert_avlnode(int key);
	void Print_avlnode();
private:
	//
	Node* Insert_avlnode(Node* root, int key);	//插入节点
	Node* Delete_avlnode(Node* root, int key); //删除节点

	Node* LLrotation(Node* root);	//LL插入失衡进行旋转
	Node* RRrotation(Node* root);	//RR插入失衡进行旋转
	Node* LRrotation(Node* root);	//LR插入失衡进行旋转
	Node* RLrotation(Node* root);   //RL插入失衡进行旋转

	void Del_ALL(Node* root);       //析构函数相关,释放内存
	void Print_avlnode(Node* root); //打印树中的所有函数
	
	Node* GetNewNode(int key, Node* l, Node* r);   //获取新节点内存
	
	int Max(int a, int b);          //更新树的高度
	int height(Node* root);		    //获取树的高度

private:
	Node* m_Tree;
};

