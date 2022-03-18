#ifndef CAVLTREETHREE_Node_H_
#define CAVLTREETHREE_Node_H_
class Node {
 public:
  Node();
  Node(int key);
  Node(int key,Node* left, Node* right);
 public:
  int data_;
  int height_;
  Node* left_;
  Node* right_;
};
#endif

