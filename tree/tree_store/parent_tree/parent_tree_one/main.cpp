#include <iostream>
#include "Tree.h"

void test() 
{
	Tree t;
	t.RootCreate(3);
	t.ChildInsert(3, 1);

}


int main()
{
	test();
	std::cin.get();
}
