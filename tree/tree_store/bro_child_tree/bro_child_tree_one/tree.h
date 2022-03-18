#pragma once
#include "Node.h"

class Tree
{
public:
	Tree ();
	~Tree();
public:
	void  RootCreate (int key);
	void  ChildInsert(int parent, int key);
	void  PrintTree();
private:
	Node* GetNewNode (int key);
	Node* FindParent (Node* root, int parent);
	void  Print(Node* root);
	void  Del_All(Node* root);
private:
	Node* m_Root;
	int   m_Size;
};

