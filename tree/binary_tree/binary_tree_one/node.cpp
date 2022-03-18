#include "Node.h"
#include <iostream>

Node::Node()
	:data(0), left(nullptr), right(nullptr), height(0)
{
	std::cout << "Node默认构造函数的调用" << std::endl;
}

Node::Node(int key)
	: data(key), left(nullptr), right(nullptr), height(0)
{
	std::cout << "Node有参构造函数的调用" << std::endl;
}
Node::Node(int key, Node* left, Node* right)
	: data(key), left(left), right(right), height(0)
{
	std::cout << "Node有参构造函数的调用" << std::endl;
}
Node::~Node()
{
	std::cout << "Node析构函数的调用" << std::endl;
}
