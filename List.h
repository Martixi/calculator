//
// Created by admin on 09.03.2024.
//

#ifndef CALCULATOR_LIST_H
#define CALCULATOR_LIST_H

//structures

struct Node {
	char element = ' ';
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
	Node* tail;

public:

	List();

	void append(char newValue);

	void pushFront(char newValue);

	char getFirst();

	void removeFirst();

	void nextElement();

	char getLast();

	void print();

	void clear();

	~List();

};


//list for int input

class IntList {

private:

	INode* head;

public:
	IntList();

	void pushFront(int newValue);

	int getFirst();

	void removeFirst();

	void print();

	void clear();

	~IntList();

};

#endif //CALCULATOR_LIST_H
