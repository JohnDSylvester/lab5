#ifndef NODE_H
#define NODE_H
#include <string>
#include <cstddef>
// Use this file to declare your Node type.
// Implement Node member functions and helper functions in Node.cpp.
class Node {
	public:
  std::string data;
  Node*       left;
  Node*	      right;

  Node(std::string value);
  Node* copy(Node* origin);
  size_t betterInsert(const std::string& value, Node* &head);
  bool betterSwivel(const std::string& value, Node* &head, Node* &prev);
  std::string printBetter(Node* head);
  Node* printLeft(Node* head);
  void deleteSelf(Node* head);
};


#endif
