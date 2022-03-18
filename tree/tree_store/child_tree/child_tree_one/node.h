#pragma once>
//申请创建Node节点
class Node
{
public:
	Node();
	Node(int key);
	~Node();
public:
	int data;
	Node* m_Next;  //Node链表
};

