// linked-list.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include "Node.h"
#include "Linkedlist.h"


int main()
{
    std::vector<Node<int>*> vectorNodes{ new Node<int>(5), new Node<int>(10), new Node<int>(15), new Node<int>(20) };

    Linkedlist<int> list(vectorNodes);

    list.PrintList();

    std::cout << "\n\n";

    Node<int>* newNode = new Node<int>(25);

    list.AddNode(newNode);

    list.PrintList();

    for (Node<int>* node : vectorNodes)
    {
        delete node;
    }

    delete newNode;
}