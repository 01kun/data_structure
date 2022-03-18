#pragma once
class Node
{
public:
	Node();
	Node(int key);
	Node(int key, Node* a, Node* b);
	~Node();
public:
	int data;
	int height;
	Node* left;
	Node* right;
};

