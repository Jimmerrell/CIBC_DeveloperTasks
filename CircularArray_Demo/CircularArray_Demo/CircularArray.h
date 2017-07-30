#pragma once

////////////////////////////////////////////////////////
//  File			:	"CircularArray.h"
//  Author			:	Jim Merrell
//  Date Created	:	7/30/2017
//  Copyright		:	All rights reserved.
////////////////////////////////////////////////////////

template<class Type = int>
class CircularArray
{
public:
	//Constructor
	CircularArray();
	//Destructor
	~CircularArray();
	//Copy Constructor
	CircularArray(const CircularArray<Type>& circArray);

	//Operator Overloads
	CircularArray<Type>& operator=(const CircularArray<Type>& circArray);
	Type& operator[](const unsigned int index);
	const Type& operator[](const unsigned int index) const;

//********** class methods **************************
	// Emplaces the item at the currentIndex
	void AddElement(const Type& item);
	//returns the number of elements in the array
	unsigned int Size() const;
	//returns the number of slots in the array
	unsigned int Capacity() const;
	//Empties the array and resets the size to zero
	void Clear();
	//Adds a new element slot in the array and inserts the item
	void Append(const Type& item);
	//establishes the given amount of slots in the array
	void Reserve(const unsigned int& newCap = 0);

private:
	unsigned int m_currentIndex;
	unsigned int m_nSize;
	unsigned int m_nCapacity;
	Type* m_circArray;
};

//Constructor
template<class Type>
CircularArray<Type>::CircularArray()
{
	m_currentIndex = 0;
	m_nSize = 0;
	m_nCapacity = 0;
	m_circArray = nullptr;
}

//Destructor
template<class Type>
CircularArray<Type>::~CircularArray()
{
	delete[] m_circArray;
}

//Copy Constructor
template<class Type>
CircularArray<Type>::CircularArray(const CircularArray<Type>& circArray)
{
	m_nSize = circArray.Size();
	m_circArray = new Type[m_nSize];
	for (unsigned int i = 0; i < m_nSize; i++)
	{
		m_circArray[i] = circArray.m_circArray[i];
	}
}

//Operator Overloads
template<class Type>
CircularArray<Type>& CircularArray<Type>::operator=(const CircularArray<Type>& circArray)
{
	if (this != &circArray)
	{
		m_nSize = circArray.Size();
		delete[] m_circArray;
		m_circArray = new Type[m_nSize];
		for (unsigned int i = 0; i < m_nSize; i++)
		{
			m_circArray[i] = circArray.m_circArray[i];
		}
	}
	return *this;
}

template<class Type>
Type& CircularArray<Type>::operator[](const unsigned int index)
{
	return m_circArray[index];
}

template<class Type>
const Type& CircularArray<Type>::operator[](const unsigned int index) const
{
	return m_circArray[index];
}

//********** class methods **************************
// Emplaces the item at the currentIndex
template<class Type>
void CircularArray<Type>::AddElement(const Type& item)
{
	m_circArray[m_currentIndex] = item;
	m_currentIndex++;
	if (m_nSize < m_nCapacity)
	{
		m_nSize++;
	}

	if (m_currentIndex >= m_nCapacity)
	{
		m_currentIndex = 0;
	}
}

//returns the number of elements in the array
template<class Type>
unsigned int CircularArray<Type>::Size() const
{
	return m_nSize;
}

//returns the number of slots in the array
template<class Type>
unsigned int CircularArray<Type>::Capacity() const
{
	return m_nCapacity;
}

//Empties the array and resets the size to zero
template<class Type>
void CircularArray<Type>::Clear()
{
	if (m_circArray != nullptr)
	{
		delete[] m_circArray;
		m_circArray = nullptr;
	}
	m_nSize = 0;
}

//Increases the array size by adding a new element slot in the array and inserts the item 
template<class Type>
void CircularArray<Type>::Append(const Type& item)
{
	if(m_nSize == m_nCapacity)
	{
		m_nCapacity += 1;

		Type *temp = new Type[m_nCapacity];
		for (unsigned int i = 0; i < m_nSize; i++)
		{
			temp[i] = m_circArray[i];
		}

		delete[] m_circArray;
		m_circArray = temp;
	}

	m_circArray[m_nSize] = item;
	m_nCapacity++;
	m_nSize++;
	m_currentIndex = 0;
}

//establishes the given amount of slots in the array
template<class Type>
void CircularArray<Type>::Reserve(const unsigned int& newCap)
{
	if (newCap == 0)
	{
		if (m_nCapacity == 0)
		{
			m_nCapacity++;
			m_circArray = new Type[m_nCapacity];
		}
		//else
		//{
		//	m_nCapacity
		//}
	}
	else if (newCap > m_nCapacity)
	{
		m_nCapacity = newCap;
		Type* temp = new Type[m_nCapacity];
		for (unsigned int i = 0; i < m_nCapacity; i++)
		{
			temp[i] = NULL;
		}
		for (unsigned int i = 0; i < m_nSize; i++)
		{
			temp[i] = m_circArray[i];
		}
		delete[] m_circArray;
		m_circArray = temp;
	}
}

