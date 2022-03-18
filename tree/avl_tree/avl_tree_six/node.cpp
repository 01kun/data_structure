#include "Node.h"
#include <iostream>

Node::Node() : data_(0), height_(0), left_(nullptr), right_(nullptr) {
	std::cout<<"Node默认构造函数的调用" <<std::endl;
}

Node::Node(int key) : data_(0), height_(0), left_(nullptr), right_(nullptr) {
	std::cout <<"Node有参构造函数的调用" <<std::endl;
}

Node::Node(int key, Node* left, Node* right) : data_(0), height_(0), left_(nullptr), right_(nullptr) {
	std::cout << "Node有参构造函数的调用" << std::endl;
}

