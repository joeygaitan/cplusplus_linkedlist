#pragma once

template <typename DataType>
class Node
{
private:
	DataType m_data;
	Node* m_pPrevNode;
	Node* m_pNextNode;
public:
	
	Node(DataType data)
		: m_data(data)
		, m_pPrevNode(nullptr)
		, m_pNextNode(nullptr)
	{}

	// Returns the data inside of the Node.
	const DataType& GetData() const
	{
		return m_data;
	}

	// Sets the Data of the Node.
	void SetData(DataType data)
	{
		m_data = data;
	}

	// Get the Previous linked list.
	Node* GetPrevNode()
	{
		return m_pPrevNode;
	}

	// Returns the Next Node.
	Node* GetNextNode()
	{
		return m_pNextNode;
	}

	// Set the previous node in the linked list.
	void SetPrevNode(Node<DataType>* node)
	{
		m_pPrevNode = node;
	}

	// Sets the Next Node to the new given Node.
	void SetNextNode(Node<DataType>* node)
	{
		m_pNextNode = node;
	}
};

