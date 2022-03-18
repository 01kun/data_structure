#pragma once
class Node
{
public:
	Node();
	Node(int key);
	Node(int key, Node* left, Node* right);
	~Node();
public:
	int data;
	Node* left;
	Node* right;
	int height;
};

