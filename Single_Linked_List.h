#pragma once
#include <iostream>
#include <iomanip>

template<typename T>
class Single_linked_List {
private:
	struct Node {
		T value;
		Node<T>* next;
	};

	Node* head, tail;
	int num_items;

public:
	Single_linked_List();
	Single_linked_List(T value, Node<T>* next);
};
