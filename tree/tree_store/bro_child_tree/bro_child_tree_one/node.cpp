#include "Node.h"
#include <iostream>

Node::Node()
	:m_Data(0), m_Son(nullptr), m_Bro(nullptr)
{
	std::cout << "Node默认构造函数的调用" << std::endl;
}

Node::Node(int key)
	: m_Data(key), m_Son(nullptr), m_Bro(nullptr)
{
	std::cout << "Node有参构造函数的调用" << std::endl;
}

Node::~Node()
{
	std::cout << "Node析构函数的调用" << std::endl;
}
