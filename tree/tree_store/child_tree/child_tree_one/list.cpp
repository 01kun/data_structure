#include "List.h"
#include <iostream>

List::List()
	:m_Data(0), m_Next(nullptr) 
{
	std::cout << "List默认构造函数的调用" << std::endl;
}

List::List(int key)
	: m_Data(key), m_Next(nullptr) 
{
	std::cout << "List有参构造函数的调用" << std::endl;
}
List::~List()
{
	std::cout << "List析构函数的调用" << std::endl;
}
