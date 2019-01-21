/**
 * ListNode implementation
 */
 
#include "node.h"

// constructor
Node::Node(int value)
    : data{value}, nextPtr{nullptr} {}

// return data in node
int Node::getData() const {
  return data;
}

