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

	const DataType& GetData() const
	{
		return m_data;
	}

	void SetData(DataType data)
	{
		m_data = data;
	}

	Node* GetNextNode()
	{
		return m_pNextNode;
	}

	void SetNextNode(Node* node)
	{
		m_pNextNode = node;
	}
};

