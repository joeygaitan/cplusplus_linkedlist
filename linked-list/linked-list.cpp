// linked-list.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include "Node.h"
#include "Linkedlist.h"

int main()
{
    std::vector<Node<int>*> vectorNodes{ new Node<int>(5), new Node<int>(10), new Node<int>(15), new Node<int>(20) };

    Linkedlist<int> list(vectorNodes);

    list.PrintBackward();

    std::cout << "\n\n";

    //Node<int>* pNewNode = new Node<int>(35);

    //list.AddNode(pNewNode,4);

    //list.PrintBackward();

    list.RemoveNode(2);

    list.PrintBackward();

    std::cout << "\n\n";

    list.RemoveNode(2);

    list.PrintBackward();
    

    for (Node<int>* node : vectorNodes)
    {
        delete node;
    }

    /*delete pNewNode;*/
}