//
// Created by admin on 09.03.2024.
//

#ifndef CALCULATOR_LIST_H
#define CALCULATOR_LIST_H

//structures

struct Node {
	char element;
	Node* next = nullptr;
};

struct INode {
	int number = 0;
	INode* next = nullptr;
};

//
//My lists
//


//list for char input
class List {

private:

	Node* head;

public:

	List();

	void append(char newValue);

	void pushFront(char newValue);

	char getFirst(){
		return head->element;
	}

	void removeFirst();

	void nextElement(){
		Node* tmp = head->next;
		delete head;
		head = tmp;
	}

	char getLast();

	void removeLast();

	void print();

	bool isEmpty();

	void clear();

	~List();

};


//list for int input
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
