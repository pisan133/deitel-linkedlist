/**
 * Example on using Linked List based on Deitel
 * Fig. 19.3
 *
 */

#include <iostream>

#include <iostream>
#include <string>
#include "list.h" // List class definition

using namespace std;

// display program instructions to user
void instructions() {
  cout << "Enter one of the following:\n"
       << "  1 to insert at beginning of list\n"
       << "  2 to insert at end of list\n"
       << "  3 to delete from beginning of list\n"
       << "  4 to delete from end of list\n"
       << "  5 to end list processing\n";
}

// function to test a List
void testList(List &listObject) {
  cout << "Testing a List of integer values\n";
  instructions(); // display instructions

  int choice; // store user choice
  int value; // store input value

  do { // perform user-selected actions
    cout << "? ";
    cin >> choice;

    switch (choice) {
      case 1: // insert at beginning
        cout << "Enter an integer: ";
        cin >> value;
        listObject.insertAtFront(value);
        listObject.print();
        break;
      case 2: // insert at end
        cout << "Enter an integer: ";
        cin >> value;
        listObject.insertAtBack(value);
        listObject.print();
        break;
      case 3: // remove from beginning
        // value will be assigned once deleted
        if (listObject.removeFromFront(value)) {
          cout << value << " removed from list\n";
        }

        listObject.print();
        break;
      case 4: // remove from end
        // value will be assigned once deleted
        if (listObject.removeFromBack(value)) {
          cout << value << " removed from list\n";
        }

        listObject.print();
        break;
      case 5:  // ending loop
        break;
      default:  // unexpected
        cout << "Unexpected input " << choice << endl;
    }
  } while (choice < 5);

  cout << "End list test\n\n";
}

/**
 * Adding values from another list
 * Initial list
 * The list is: 0 10 20
 * List to be added
 * The list is: 3 5 7 9 11 13 15 17 19
 * Result is:
 * The list is: 0 10 20 3 5 7 9 11 13 15 17 19
 */
void testInsertAtBack() {
  List a;
  List b;
  for (int i = 0; i < 30; i += 10) {
    a.insertAtBack(i);
  }
  for (int i = 3; i < 20; i += 2) {
    b.insertAtBack(i);
  }
  cout << "Adding values from another list" << endl;
  cout << "Initial list" << endl;
  a.print();
  cout << "List to be added" << endl;
  b.print();
  cout << "Result is: " << endl;
  a.insertAtBack(b);
  a.print();
}

/**
 * Merging two sorted lists
 * The list is: 0 5 10 15 20 25
 * The list is: 3 5 7 9 11 13 15 17 19
 * Result is:
 * The list is: 0 3 5 5 7 9 10 11 13 15 15 17 19 20 25
 */
void testMerge() {
  List a;
  List b;
  for (int i = 0; i < 30; i += 5) {
    a.insertAtBack(i);
  }
  for (int i = 3; i < 20; i += 2) {
    b.insertAtBack(i);
  }
  cout << "Merging two sorted lists" << endl;
  a.print();
  b.print();
  cout << "Result is: " << endl;
  List out;
  out.mergeOrdered(a, b);
  out.print();
}

int main() {
  // test List of int values
  List integerList;
  testList(integerList);
  // testInsertAtBack();
  // testMerge();
  return 0;
}
