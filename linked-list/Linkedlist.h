#pragma once
#include <iostream>
#include <vector>
#include "Node.h"


template <typename DataType>
class Linkedlist
{
private:
	Node<DataType>* m_pHead;
	size_t m_length;
public:
	Linkedlist(std::vector<Node<DataType>*> nodes)
	{
		m_pHead = nodes[0];
		Node<DataType>* pNextNode = m_pHead;
		m_length++;
		for (size_t i = 1; i < nodes.size(); ++i)
		{
			pNextNode->SetNextNode(nodes[i]);
			pNextNode = pNextNode->GetNextNode();
			m_length++;
		}
	}

	Linkedlist(Node<DataType>* node)
		: m_pHead(node)
		, m_length(1)
	{}

	const size_t& GetLength() const
	{
		return m_length;
	}

	void PrintList()
	{
		Node<DataType>* pNextNode = m_pHead;
		int nodeIndex = 0;

		if (m_length == 0)
		{
			std::cout << "Please add a node to display nodes....\n";
			return;
		}

		while (pNextNode != nullptr)
		{
			std::cout << "node number: " << nodeIndex << ": " << pNextNode->GetData() << "\n";
			nodeIndex++;
			pNextNode = pNextNode->GetNextNode();
		}
	}

	void AddNode(Node<DataType>* node)
	{
		Node<DataType>* pNextNode = m_pHead;

		while (pNextNode->GetNextNode() != nullptr)
		{
			pNextNode = pNextNode->GetNextNode();
		}
		pNextNode->SetNextNode(node);
		++m_length;
	}

	void RemoveNode(int index)
	{
		Node<DataType>* pPrevNode = nullptr;
		Node<DataType>* pCurrentNode = m_pHead;
		Node<DataType>* pNextNode = m_pHead->GetNextNode();
		int nodeIndex = 0;

		if (index == 0)
		{
			// Will I still need to delete if I delete it somewhere else?
			m_pHead = m_pHead->GetNextNode();
			return;
		}
		while (currentNode != nullptr)
		{
			pPrevNode = pCurrentNode;
			if (index == nodeIndex)
			{
				 
			}
		}
	}
};

