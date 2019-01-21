/**
 * List based on Deitel, but not templatized
 *
 */

#ifndef LIST_H
#define LIST_H

// Node class definition
#include "node.h"

class List {
 public:

  // use default constructor, private variables set to default values
  List() = default;

  // destructor
  ~List();

  // insert node at front of list
  void insertAtFront(int value);

  // insert node at back of list
  void insertAtBack(int value);

  // delete node from front of list
  bool removeFromFront(int &value);

  // delete node from back of list

  bool removeFromBack(int &value);

  // is List empty?
  bool isEmpty() const;

  // display contents of List
  void print() const;

  // insert all the values from given list to the back of this one
  void insertAtBack(const List &other);

  // add all elements of two sorted lists into this list in a sorted way
  // this list must be empty at start
  void mergeOrdered(const List& first, const List& second);

 private:
  // pointer to first node
  Node *firstPtr{nullptr};

  // pointer to last node
  Node *lastPtr{nullptr};

  // utility function to allocate new node
  Node *getNewNode(int value);
};

#endif

