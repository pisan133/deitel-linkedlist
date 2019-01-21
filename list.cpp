/**
 * List based on Deitel, but not templatized
 *
 */


#include <iostream>
#include <cassert>
#include "list.h"

using namespace std;

// destructor
List::~List() {
  if (!isEmpty()) { // List is not empty
    cout << "Destroying nodes ...\n";

    Node *currentPtr{firstPtr};
    Node *tempPtr{nullptr};

    while (currentPtr != nullptr) { // delete remaining nodes
      tempPtr = currentPtr;
      cout << tempPtr->data << '\n';
      currentPtr = currentPtr->nextPtr;
      delete tempPtr;
    }
  }

  cout << "All nodes destroyed\n\n";
}

// insert node at front of list
void List::insertAtFront(int value) {
  Node *newPtr{getNewNode(value)}; // new node

  if (isEmpty()) { // List is empty
    firstPtr = lastPtr = newPtr; // new list has only one node
  } else { // List is not empty
    newPtr->nextPtr = firstPtr; // point new node to old 1st node
    firstPtr = newPtr; // aim firstPtr at new node
  }
}

// insert node at back of list
void List::insertAtBack(int value) {
  Node *newPtr{getNewNode(value)}; // new node

  if (isEmpty()) { // List is empty
    firstPtr = lastPtr = newPtr; // new list has only one node
  } else { // List is not empty
    lastPtr->nextPtr = newPtr; // update previous last node
    lastPtr = newPtr; // new last node
  }
}

// delete node from front of list
bool List::removeFromFront(int &value) {
  if (isEmpty()) { // List is empty
    return false; // delete unsuccessful
  } else {
    Node *tempPtr{firstPtr}; // hold item to delete

    if (firstPtr == lastPtr) {
      firstPtr = lastPtr = nullptr; // no nodes remain after removal
    } else {
      firstPtr = firstPtr->nextPtr; // point to previous 2nd node
    }

    value = tempPtr->data; // return data being removed
    delete tempPtr; // reclaim previous front node
    return true; // delete successful
  }
}

// delete node from back of list
bool List::removeFromBack(int &value) {
  if (isEmpty()) { // List is empty
    return false; // delete unsuccessful
  } else {
    Node *tempPtr{lastPtr}; // hold item to delete

    if (firstPtr == lastPtr) { // List has one element
      firstPtr = lastPtr = nullptr; // no nodes remain after removal
    } else {
      Node *currentPtr{firstPtr};

      // locate second-to-last element
      while (currentPtr->nextPtr != lastPtr) {
        currentPtr = currentPtr->nextPtr; // move to next node
      }

      lastPtr = currentPtr; // remove last node
      currentPtr->nextPtr = nullptr; // this is now the last node
    }

    value = tempPtr->data; // return value from old last node
    delete tempPtr; // reclaim former last node
    return true; // delete successful
  }
}

// is List empty?

bool List::isEmpty() const {
  return firstPtr == nullptr;
}

// display contents of List
void List::print() const {
  if (isEmpty()) { // List is empty
    cout << "The list is empty\n\n";
    return;
  }

  Node *currentPtr{firstPtr};

  cout << "The list is: ";

  while (currentPtr != nullptr) { // get element data
    cout << currentPtr->data << ' ';
    currentPtr = currentPtr->nextPtr;
  }

  cout << "\n\n";
}

// utility function to allocate new node
Node *List::getNewNode(int value) {
  return new Node{value};
}

// insert all the values from given list to the back of this one
void List::insertAtBack(const List &other) {
  // TODO
}

// add all elements of two sorted lists into this list in a sorted way
// this list must be empty at start
void List::mergeOrdered(const List &first, const List &second) {
  assert(isEmpty());

  // TODO
}