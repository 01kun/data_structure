#include "Node.h"
#include <iostream>

Node::~Node()
{
	std::cout << "Node析构函数的调用" << std::endl;
}

Node::Node()
	:data(0), left(nullptr), right(nullptr)
{
	std::cout << "Node默认构造函数的调用" << std::endl;
}

Node::Node(int key)
	:data(key), left(nullptr), right(nullptr)
{
	std::cout << "Node有参构造函数的调用" << std::endl;
}
