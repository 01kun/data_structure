#include "Node.h"
#include <iostream>
Node::Node()
	:data(0), parent(-1) 
{
	std::cout << "Node默认构造函数的调用" << std::endl;
}

Node::Node(int key)
	:data(key), parent(-1) 
{
	std::cout << "Node有参构造函数的调用" << std::endl;
}

Node::~Node()
{
	std::cout << "Node析构函数的调用" << std::endl;
}
