#include "Node.h"
#include <iostream>

Node::Node()
	:data(0), height(0), left(nullptr), right(nullptr)
{
	std::cout << "Node默认构造函数的调用" << std::endl;
}

Node::Node(int key)
	: data(key), height(0), left(nullptr), right(nullptr)
{
	std::cout << "Node(int key)构造函数的调用" << std::endl;
}

Node::Node(int key, Node*a, Node* b)
	: data(key), height(0), left(a), right(b)
{
	std::cout << "Node(key, left, right)构造函数的调用" << std::endl;
}
Node::~Node()
{
	std::cout << "Node析构函数的调用" << std::endl;
}
