a#include <stdio.h>
#include <stdlib.h>
int uset[100];//并查集数组

//并查集的简单写法
//并查集解决的问题:
//只关心这一个问题对于给定的元素,快速找到这个元素给定的集合
//下标代表的是真实数据元素
//下标对应的值代表数据对应的父节点
//相当于孩子表示发

//并查集的
void MakeSet(int size) {
	for (int i = 0; i < size; i++) {
		uset[i] = i;
	}
}

//查询操作
int Find(int i) {
	if (uset[i] == i) {
		return i;
	}
	else {
		return Find(uset[i]);
	}
}
//并操作
void Unite(int x, int y) {  //把x接到y上面
	int a = Find(x);
	int b = Find(y);
	if (x == y) {
		return ;//这两个集合本身就在
	}
	uset[x] = y;

}W
