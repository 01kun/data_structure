#pragma once
class Node
{
public:
	Node();
	Node(int key);
	~Node();
public:
	int   data;
	Node* left;
	Node* right;
};

