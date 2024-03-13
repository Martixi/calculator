//
// Created by admin on 09.03.2024.
//

#ifndef CALCULATOR_LIST_H
#define CALCULATOR_LIST_H

struct Node {
	char element;
	Node* next = nullptr;
};

struct INode {
	int number = 0;
	INode* next = nullptr;
};

class List {

private:

	Node* head;

public:

	List();

	void append(char newValue);

	char getFirst(){
		return head->element;
	}

	void nextElement(){
		Node* tmp = head->next;
		delete head;
		head = tmp;
	}

	char getLast();

	void removeLast();

	void print();

	void clear();

	~List();

};

class IntList {
private:

	INode* head;

public:
	IntList();

	void append(int newValue);

	void pushFront(int newValue);

	int getFirst(){
		return head->number;
	}
	void removeFirst();

//	void nextElement(){
//		Node* tmp = head->next;
//		delete head;
//		head = tmp;
//	}

	int getLast();

	void removeLast();

	void print();

	void clear();

	~IntList();

};

#endif //CALCULATOR_LIST_H
