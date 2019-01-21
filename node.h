/**
 * ListNode baded on Deitel, but not templatized
 *
 * */

#ifndef NODE_H
#define NODE_H

// forward declaration of class List required to announce that class
// List exists so it can be used in the friend declaration
class List;

class Node {
  friend class List; // make List a friend

 public:
  // constructor
  explicit Node(int value);

  // return data in node
  int getData() const;

 private:
  // data
  int data;

  // next node in list
  Node *nextPtr;
};

#endif

