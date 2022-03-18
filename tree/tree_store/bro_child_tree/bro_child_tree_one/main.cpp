#include "Tree.h"
#include <iostream>

void test()
{
	Tree a;
	a.RootCreate(3);
	a.ChildInsert(3, 1);
	a.PrintTree();
}
int main()
{
	test();
	std::cin.get();
}
