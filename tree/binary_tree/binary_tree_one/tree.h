#pragma once
#include "Node.h"

class Tree
{
public:
	Tree();
	~Tree();
public:
	void  InsertAvlNode(int key);
	void  DeleteAvlNode(int key);
	void  PrintTree();
private:
	//这个命名规范 快找一个标准把
	Node* DeleteAvlNode(Node* root, int key);
	Node* InsertAvlNode(Node* root, int key);
	Node* get_new_node (int key);
	Node* LLrotation   (Node* root);
	Node* RRrotation   (Node* root);
	Node* LRrotation   (Node* root);
	Node* RLrotation   (Node* root);
	int   height(Node* root);
	int  Max(int a, int b);
	void Del_ALL(Node* root);
	void PrintTree(Node* root);

private:
	Node* m_Root;
};
