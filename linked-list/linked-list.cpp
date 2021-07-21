// linked-list.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include "Node.h"
#include "LinkedList.h"

using pNodeType = Node<int>*;

// Displays reversed list if false and from head to tail if true.
void DisplayDirection(bool selection, LinkedList<int>& list, const char* text)
{
    if (selection)
    {
        std::cout << text << "\n";
        list.PrintForward();
        std::cout << "\n\n";
    }
    else
    {
        std::cout << text << "\n";
        list.PrintBackward();
        std::cout << "\n\n";
    }
}

// Intializes the linked list with a vector. It then does some tests to show the changes made by different functions.
//void LinkedListVectorTest()
//{
//    std::vector<pNodeType> vectorNodes{ new Node<int>(5), new Node<int>(10), new Node<int>(15), new Node<int>(20) };
//
//    LinkedList<int> list(vectorNodes);
//
//    // Print Intialized List.
//    DisplayDirection(true, list, "Intialized List from vector {*Node(5), *Node(10), *Node(15), *Node(20)}");
//
//    pNodeType pNewNodeHead = new Node<int>(35);
//
//    list.Insert(pNewNodeHead, 0);
//
//
//    // Print list with new head.
//    DisplayDirection(false, list, "Inserted Node(35) at the head (Displayed Backward)");
//
//    DisplayDirection(true, list, "Displayed Frontward");
//
//    list.RemoveNode(2);
//
//
//    // Prints out list with removed node.
//    DisplayDirection(false , list, "Removed the third element from the list (displayed backward)");
//    
//    list.RemoveNode(3);
//
//    // Prints list with removed tail.
//    DisplayDirection(true, list, "Removed the last Node of the list (displayed frontward)");
//
//    DisplayDirection(true, list, "(displayed backward)");
//
//
//    for (Node<int>* node : vectorNodes)
//    {
//        delete node;
//    }
//
//    delete pNewNodeHead;
//}

void SingleIntialNodeTest()
{
    pNodeType head = new Node<int>(5);
    LinkedList<int> list(head);

    pNodeType pNewNode = new Node<int>(10);
    list.Append(pNewNode);

    // Appending a Node test.
    DisplayDirection(false, list, "Intialized list with one node. Additional appended node (displayed backwards)");

    pNodeType pMiddleNode = new Node<int>(7);
    list.Insert(pMiddleNode, 1);

    // Inserting a Node test.

    DisplayDirection(false, list, "Inserted a Node in between the head and the tail (displayed backward)");

    list.RemoveNode(1);

    // Remove one Node test.
    DisplayDirection(false, list, "Removed newly inserted Node (displayed backward)");

    DisplayDirection(true, list, "(displayed forward)");

    delete head;
    delete pNewNode;
    delete pMiddleNode;
}

// Allows the user to pick what tests runs they wish to display or quit.
void SelectTest()
{
    char userChoice = '0';
    while (userChoice != 'q')
    {
        std::cout << "Linked List Testing\n";
        std::cout << "2. Test single Node inserted Data\n";
        std::cout << "q. Quit\n";

        std::cout << "input: ";
        std::cin >> userChoice;

        switch (userChoice)
        {
            case '2':
                system("cls");
                SingleIntialNodeTest();
                system("pause");
                break;
            case 'q':
                return;
            default:
                std::cout << "Wrong input...." << std::endl;
                break;
        }
    }
}


int main()
{
    SelectTest();
}