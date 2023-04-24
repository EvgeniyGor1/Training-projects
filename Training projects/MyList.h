#pragma once

#ifndef _MyList_H
#define _MyList_H


#include <iostream>

template<class T>
class MyList
{
public:
	MyList();
	~MyList();

	void push_back(T data);
	int GetSize();
	T& operator[](const int index);
	void pop_front();
	void clear();
	void ShowElements();
	void push_front(T data);
	void insert(T value, int index);
	void removeAt(int index);
	void pop_back();

private:
	template<class T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr) {
			this->pNext = pNext;
			this->data = data;
		}
	};

	int Size;
	Node<T>* head;

};


#endif _MyList_H
