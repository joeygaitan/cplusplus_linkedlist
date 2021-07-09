#pragma once

template <typename DataType>
class Node
{
private:
	DataType m_data;
	Node* m_pNextNode;
public:
	
	Node(DataType data)
		: m_data(data)
		, m_pNextNode(nullptr)
	{}

	Node()
		: m_data()
		, m_pNextNode(nullptr)
	{}

	Node(DataType data, Node<DataType>* pNextNode)
		: m_data(data)
		, m_pNextNode(pNextNode)
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

	// Returns the Next Node.
	Node* GetNextNode()
	{
		return m_pNextNode;
	}

	// Sets the Next Node to the new given Node.
	void SetNextNode(Node* node)
	{
		if (m_pNextNode == nullptr)
		{
			m_pNextNode = node;
		}
	}
};

