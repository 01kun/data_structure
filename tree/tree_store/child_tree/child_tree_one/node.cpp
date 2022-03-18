#include "Node.h"
#include <iostream>
Node::Node()
	:data(0), m_Next(nullptr)
{
	std::cout << "Node默认构造函数的调用" << std::endl;
}

Node::Node(int key)
	: data(key), m_Next(nullptr)
{
	std::cout << "Node有参构造函数的调用" << std::endl;
}

Node::~Node()
{
	std::cout << "Node析构函数的调用" << std::endl;
}
