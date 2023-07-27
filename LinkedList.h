#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

//Linked list class

struct Node {
	int data;
	Node* nextPtr;
};

class LinkList
{
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int num_items = 0;

public:
	//LinkList()
	//{
	//	head = nullptr;
	//	tail = nullptr;
	//}
	void push_front(int n);
	void push_back(int n);
	void pop_front();
	void pop_back();
	int front();
	int back();
	bool empty();
	void display();
	void insert(size_t index, const int &value);
	bool remove(size_t index);
	size_t find(const int& value);
};


void LinkList::push_front(int n) {
	Node* tempNode = new Node;
	tempNode->data = n;
	tempNode->nextPtr = nullptr;
	if (head == nullptr) {
		head = tempNode;
		tail = tempNode;
	}
	else {
		tempNode->nextPtr = head;
		head = tempNode;
	}

	num_items += 1;
}

void LinkList::push_back(int n) {
	Node* tempNode = new Node;
	tempNode->data = n;
	tempNode->nextPtr = nullptr;
	if (head == nullptr) {
		head = tempNode;
		tail = tempNode;
	}
	else {
		tail->nextPtr = tempNode;
		tail = tempNode;
	}

	num_items += 1;
}

void LinkList::pop_front() {
	Node* tempNode = new Node;
	
	if (head == nullptr) {
		cout << "The list is empty";
		return;
	}
	else {
		tempNode = head;
		head = head->nextPtr;
		delete tempNode;
		tempNode = nullptr;
	}

	num_items -= 1;
}

void LinkList::pop_back() {
	Node* tempNode = new Node;

	if (head == nullptr) {
		cout << "The list is empty";
		return;
	}
	if (head->nextPtr == nullptr) {
		delete head;
		head = nullptr;
		return;
	}
	
	tempNode = head;

	while (tempNode->nextPtr->nextPtr != nullptr) {
		tempNode = tempNode->nextPtr;
	}

	delete tempNode->nextPtr;
	tempNode->nextPtr = nullptr;
	tail = tempNode;

	num_items -= 1;
	return;

}


int LinkList::front() {
	Node* tempNode = new Node;
	
	if (head == nullptr) {
		cout << "This list is empty";
	}
	else {
		tempNode = head;
		return tempNode->data;
	}
}

int LinkList::back() {
	Node* tempNode = new Node;
	
	if (head == nullptr) {
		cout << "This list is empty";
	}
	else {
		tempNode = head;

		while (tempNode->nextPtr != nullptr) {
			tempNode = tempNode->nextPtr;
		}

		return tempNode->data;

	}
}

bool LinkList::empty() {
	return (head == nullptr);
}


void LinkList::insert(size_t index, const int &value) {
	if (index > (num_items - 1)) {
		cout << "Index out of range. Item has been added to back of list\n";
		push_back(value);
	}

	else if (index == 0) {
		push_front(value);
	}

	else {
		Node* currNode = head;
		Node* insertNode = new Node;
		insertNode->data = value;
		insertNode->nextPtr = nullptr;
		Node* prevNode = new Node;

		int count = 0;
		while (count < index) {
			prevNode = currNode;
			currNode = currNode->nextPtr;
			count += 1;
		}
		
		prevNode->nextPtr = insertNode;
		insertNode->nextPtr = currNode;
		
		num_items += 1;
	}
	return;
}

bool LinkList::remove(size_t index) {
	if (index > (num_items - 1)) {
		cout << "Index out of range.\n";
		return false;
	}

	else if (index == (num_items - 1)) {
		pop_front();
		return true;
	}

	else {
		Node* delNode = head;
		Node* prevNode = new Node;

		int count = 0;
		while (count < index) {
			prevNode = delNode;
			delNode = delNode->nextPtr;
			count += 1;
		}

		prevNode->nextPtr = delNode->nextPtr;
		delete delNode;
		delNode = nullptr;

		num_items -= 1;
		return true;
	}
}

size_t LinkList::find(const int& value) {
	Node* tempNode = head;
	int count = 0;
	while (tempNode != nullptr) {
		if (tempNode->data == value) {
			return count;
		}
		tempNode = tempNode->nextPtr;
		count += 1;
	}
	return count;
}

void LinkList::display() {
	Node* tempNode = head;
	
	while (tempNode != nullptr) {
		cout << tempNode->data << endl;
		tempNode = tempNode->nextPtr;
	}
	cout << " TOT ----- " << num_items << endl;
}