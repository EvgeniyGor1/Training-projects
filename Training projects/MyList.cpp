#include "MyList.h"


using namespace std;

template<class T>
MyList<T>::MyList()
{
	Size = 0;
	head = nullptr;

}

template<class T>
MyList<T>::~MyList()
{
	clear();
}

template<class T>
void MyList<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;

		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<class T>
int MyList<T>::GetSize()
{
	return Size;
}

template<class T>
T& MyList<T>::operator[](int index)
{
	Node<T>* current = this->head;
	int counter = 0;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

}

template<class T>
void MyList<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<class T>
void MyList<T>::clear()
{
	while (Size) {
		pop_front();
	}
}

template<class T>
void MyList<T>::ShowElements()
{
	Node<T>* current = head;
	for (int i = 0; i < Size;) {
		cout << "Element number:" << i << "\t" << current->data << endl;
		current = current->pNext;
		i++;
	}
	cout << "\nTotal elements:" << Size << endl;
}

template<class T>
void MyList<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<class T>
void MyList<T>::insert(T data, int index)
{
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<T>* previous = head;
		int counter = 0;

		while (counter < index - 1) {
			previous = previous->pNext;
			counter++;
			if (counter == Size) {
				previous = head;
			}
		}

		previous->pNext = new Node<T>(data, previous->pNext);
		Size++;
	}


}

template<class T>
void MyList<T>::removeAt(int index)
{
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previous = head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;

		delete toDelete;
		Size--;

	}
}

template<class T>
void MyList<T>::pop_back()
{
	removeAt(Size - 1);
}



