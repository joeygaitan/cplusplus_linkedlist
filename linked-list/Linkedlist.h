#pragma once
#include <iostream>
#include <vector>


template <typename DataType>
class LinkedList
{
private:
	struct Node
	{
		DataType data;
		Node* pPrevNode;
		Node* pNextNode;
	};

	Node* m_pHead;
	Node* m_pTail;
	size_t m_length;
public:

	LinkedList()
		: m_pHead(nullptr)
		, m_pTail(nullptr)
		, m_length(0)
	{}

	~LinkedList()
	{
		Destroy();
	}

	// Who ever is calling
	//LinkedList(std::vector<Node<DataType>*> nodes)
	//{
	//	m_pHead = nodes[0];
	//	Node<DataType>* pNextNode = m_pHead;
	//	m_length = 1;
	//	for (size_t i = 1; i < nodes.size(); ++i)
	//	{
	//		pNextNode->SetNextNode(nodes[i]);
	//		nodes[i]->SetPrevNode(pNextNode);
	//		pNextNode = pNextNode->GetNextNode();
	//		m_length++;
	//	}
	//	m_pTail = pNextNode;
	//}

	LinkedList& operator=(LinkedList<DataType>&& right)
		: LinkedList()
	{
		if (this == &right)
			return *this;

		Destroy();

		for (Node* pNode = right.m_pHead; pNode != nullptr; pNode = pNode->pNextNode)
		{
			Append(pNode);
		}
	}

	LinkedList& operator=(LinkedList<DataType>&& right)
		: LinkedList()
	{
		if (this == &right)
			return *this;

		Destroy();

		for (Node* pNode = right.m_pHead; pNode != nullptr; pNode = pNode->pNextNode)
		{
			Append(pNode);
		}


	}

	LinkedList(Node* node)
		: m_pHead(node)
		, m_pTail(node)
		, m_length(1)
	{}

	void DisplayStats()
	{
		std::cout << "Head: " << m_pHead->GetData() << "\n";
		std::cout << "Tail: " << m_pTail->GetData() << "\n";
		std::cout << "Length: " << m_length << "\n";
		PrintForward();
		std::cout << "\n\n" << "Display Backwards" << "\n";
	}

	// Returns the count of how many nodes are in the Linked List.
	const size_t& GetLength() const
	{
		return m_length;
	}

	// Displays out of scope if you search out of scope.
	static void OutOfScope()
	{
		std::cout << "Out of Scope of Linked List.....\n";
		system("pause");
	}

	// Displays all the nodes of the Linked List from the head.
	void PrintForward()
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
			++nodeIndex;
			pNextNode = pNextNode->GetNextNode();
		}
	}

	// Display all the nodes from the tail.
	void PrintBackward()
	{
		Node<DataType>* pNextNode = m_pTail;
		// ptrdiff_t is exactly the same as size_t except it's signed.
		ptrdiff_t nodeIndex = static_cast<ptrdiff_t>(m_length) - 1;

		if (m_length == 0)
		{
			std::cout << "Please add a node to display nodes....\n";
			return;
		}

		while (pNextNode != nullptr)
		{
			std::cout << "node number: " << nodeIndex << ": " << pNextNode->GetData() << "\n";
			--nodeIndex;
			pNextNode = pNextNode->GetPrevNode();
		}
	}

	// Displays one Node from the linked list selected by index.
	void PrintOne(int index)
	{
		Node<DataType>* pNextNode = m_pHead;
		int nodeIndex = 0;

		while (pNextNode != nullptr)
		{
			if (nodeIndex == index)
			{
				std::cout << "node number: " << nodeIndex << ": " << pNextNode->GetData() << "\n";
				return;
			}
			++nodeIndex;
			pNextNode = pNextNode->GetNextNode();
		}
	}

	// Adds a new Node to the end of Linked List.
	void Append(Node<DataType>* node)
	{
		Node<DataType>* pNext = m_pHead;

		while (pNext->pNextNode != nullptr)
		{
			pNext = pNext->pNextNode;
		}
		pNextNode = node;
		node->pPrevNode = pNext;
		m_pTail = node;
		++m_length;
	}

	// Insert a new Node anywhere in the linked list by index.
	void Insert(Node<DataType>* node, int index)
	{
		Node<DataType>* pPrev = m_pHead;
		Node<DataType>* pCurrentNode = m_pHead;
		int nodeIndex = 0;

		// Check case if the index is at 0.
		if (index == 0)
		{
			pCurrentNode->pPrevNode = node;
			m_pHead = node;
			m_pHead->pNextNode = pCurrentNode;
			++m_length;
			return;
		}

		while (pCurrentNode != nullptr)
		{
			if (nodeIndex == index)
			{
				pPrev->SetNextNode(node);
				node->SetPrevNode(pPrevNode);
				node->SetNextNode(pCurrentNode);
				if (pCurrentNode != nullptr)
				{
					pCurrentNode->SetPrevNode(node);
				}
				++m_length;
				return;
			}
			pPrev = pCurrentNode;
			pCurrentNode = pCurrentNode->GetNextNode();
			++nodeIndex;
		}
		if (index == m_length)
		{
			Append(node);
			return;
		}
		OutOfScope();
	}

	// Removes a Node based on its location in the Linked List.
	void RemoveNode(int index)
	{
		Node<DataType>* pPrevNode = m_pHead;
		Node<DataType>* pCurrentNode = m_pHead;
		int nodeIndex = 0;

		// Check case if the Linked List is empty.
		if (m_pHead == nullptr)
		{
			std::cout << "Linked List is empty :(...\n";
			return;
		}

		// Check case if the index is at 0.
		if (index == 0)
		{
			m_pHead = m_pHead->GetNextNode();
			m_pHead->SetPrevNode(nullptr);
			return;
		}

		while (pCurrentNode != nullptr)
		{
			if (index == nodeIndex)
			{
				pPrevNode->SetNextNode(pCurrentNode->GetNextNode());
				// Checks if next node is not a nullptr. If it isn't then it will add it as a privous pointer.
				if (pPrevNode->GetNextNode() != nullptr)
				{
					pPrevNode->GetNextNode()->SetPrevNode(pPrevNode);
				}
				// check to see if you are at the end, which then resets the tail to the new end.
				if (index == m_length - 1)
				{
					m_pTail = pPrevNode;
				}
				--m_length;
				return;
			}
			pPrevNode = pCurrentNode;
			pCurrentNode = pCurrentNode->GetNextNode();
			++nodeIndex;
		}
		OutOfScope();
	}

	void Destroy()
	{
		if (!m_pHead)
			return;

		Node* pCurrentNode = m_pHead;
		Node* pNext = m_pHead->pNextNode;

		while (pCurrentNode != nullptr)
		{
			delete pCurrentNode;
			pCurrentNode = pNext;
		}

		m_pHead = m_pTail = nullptr;
	}
};

