#include "Tree.h"
#include <iostream>

Tree::Tree()
	:m_Tree(nullptr)
{
	std::cout << "Tree构造函数的调用" << std::endl;
}

Tree::~Tree()
{
	//析构函数的实现,释放所有的内存块
	std::cout << "Tree析构函数的调用" << std::endl;
}
void Tree::Del_ALL(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	else if (root->left == nullptr && root->right == nullptr)
	{
		delete root;
		root = nullptr;
		return;
	}
	Del_ALL(root->left);
	Del_ALL(root->right);
}

//LL降低左树高度
Node* Tree::LLrotation(Node* root)
{
	Node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	return temp;
}

//RR降低右树高度
Node* Tree::RRrotation(Node* root)
{
	Node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	return temp;
}

Node* Tree::LRrotation(Node* root)
{
	root->left = RRrotation(root->left);
	root = LLrotation(root);
	return root;
}

Node* Tree::RLrotation(Node* root)
{
	root->right = LLrotation(root->right);
	root = RRrotation(root);
	return root;
}

Node* Tree::GetNewNode(int key, Node* l, Node* r)
{
	Node* newnode = new Node(key, l, r);
	if (newnode == nullptr)
	{
		std::cout << "申请新节点内存失败,准备退出" << std::endl;
		exit(0);
	}
	return newnode;

}


int Tree::Max(int a, int b)
{
	return (a > b) ? a : b;
}

int Tree::height(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return root->height;
}

void Tree::Print_avlnode()
{
	Print_avlnode(this->m_Tree);
	std::cout << std::endl;
	std::cout << "打印函数执行完成" << std::endl;
	return;
}
void Tree::Print_avlnode(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	Print_avlnode(root->left);
	std::cout << root->data << " ";
	Print_avlnode(root->right);
}


void Tree::Insert_avlnode(int key)
{
	this->m_Tree = Insert_avlnode(this->m_Tree, key);
	return;
}

Node* Tree::Insert_avlnode(Node* root, int key)
{
	if (root == nullptr)
	{
		root = GetNewNode(key, nullptr, nullptr);
	}
	else if (key < root->data)
	{
		//这个展示的是插入操作完成
		root->left = Insert_avlnode(root->left, key);
		//这个判断此根节点是否失衡
		if (height(root->left) - height(root->right) == 2)
		{
			if (key < root->left->data)
			{
				root = LLrotation(root);
			}
			else if (key > root->left->data)
			{
				root = LRrotation(root);
			}
		}
	}
	else if (key > root->data)
	{
		root->right = Insert_avlnode(root->right, key);
		if (height(root->right) - height(root->left) == 2)
		{
			if (key > root->right->data)
			{
				root = RRrotation(root);
			}
			else if (key < root->right->data)
			{
				root == RLrotation(root);
			}
		}
	}
	
	root->height = Max(height(root->right), height(root->left)) + 1;
	return root;
}


void Tree::Delete_avlnode(int key)
{
	Delete_avlnode(this->m_Tree, key);
	return;
}

Node* Tree::Delete_avlnode(Node* root, int key)
{
	if (root == nullptr)
	{
		return root;
	}
	else if (key < root->data)
	{
		//删除操作
		root->left = Delete_avlnode(root->left, key);
		//进行删除失衡判断
		if (height(root->right) - height(root->left) == 2)
		{
			if (root->right->right != nullptr)
			{
				root = RRrotation(root);
			}
			else if (root->right->left != nullptr)
			{
				root = RLrotation(root);
			}
		}
	}
	else if (key > root->data)
	{
		root->right = Delete_avlnode(root->right, key);
		if (height(root->left) - height(root->right) == 2)
		{
			if (root->left->left != nullptr)
			{
				root = LLrotation(root);
			}
			else if (root->left->right != nullptr)
			{
				root = LRrotation(root);
			}
		}
	}
	root->height = Max(height(root->left),height(root->right)) + 1;
	return root;
}
