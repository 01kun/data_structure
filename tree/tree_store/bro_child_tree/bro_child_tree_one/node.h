#pragma once
class Node
{
public:
	Node();
	Node(int key);
	~Node();

public:
	int m_Data;
	Node* m_Son;
	Node* m_Bro;
};

