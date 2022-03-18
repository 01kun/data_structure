#ifndef cppavltree_Node_H_
#define cppavltree_Node_H_
class Node {
public:
	Node();
	Node(int key);
	Node(int key, Node* left, Node* right);
	~Node();
 
 public:
	int data_;
	int height_;
	Node* left_;
	Node* right_;
};
#endif 



