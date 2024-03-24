//
// Created by admin on 09.03.2024.
//

#include "List.h"
#include "iostream"
using namespace std;


//char list funkcje ----->


// huh stworzylam calą liste zeby zrobic pusty obiekt,
//bardzo przydatna metoda
List::List() {
	head = nullptr;
	tail = nullptr;
}

// dodajemy na koniec, nie na początek to nie chiny
void List::append(char newValue) {
	Node* NewElement = new Node;
	NewElement->element = newValue;
	if (head == nullptr){
		head = NewElement;
		tail = NewElement;
	}
	else{
		Node* tmp = tail;
//		while (tmp->next != nullptr){
//			tmp = tmp->next;
//		}
		tmp->next = NewElement;
		tail = NewElement;
	}
}

void List::pushFront(char newValue){
	Node* newVal = new Node;
	newVal->element = newValue;
	if (head == nullptr){
	head = newVal;
	tail = newVal;
	newVal->next = nullptr;
	} else{
		Node* tmp = head;
		head=newVal;
		newVal->next = tmp;
	}
}

void List::removeFirst(){
	if (head == nullptr) return;
	else if (head->next == nullptr) clear();
	else{
		Node* tmp = head->next;
		delete head;
		head = tmp;
	}
}

// get lost, get fucked
char List::getLast(){
	if (tail == nullptr) return 0;
	return tail->element;
}

// dosłownie get fucked last element nobody likes you go away and die
void List::removeLast() {
	Node* tmp = head;
	if (tmp->next == nullptr) {
		head = nullptr;
		tail = nullptr;
		return;
	}
	while (tmp->next->next != nullptr){
		tmp = tmp->next;
	}
	delete tmp->next;
	tmp->next = nullptr;
	tail = tmp;
}

void List::print() {
	Node* tmp = head;
	if (tmp == nullptr){
		cout << "empty list";
		return;
	}
	while (tmp->next != nullptr){
		cout << tmp->element;
		tmp = tmp->next;
	}
	//commented cause it prints '.' hope it doesn't break anything
	//cout << tmp->element << " ";
}

// destruktor
void List::clear() {
	Node* tmp = head;
	if (tmp == nullptr) return;
	Node* helper;
	while (tmp->next != nullptr){
		helper = tmp->next;
		delete tmp;
		tmp = helper;
	}
	delete tmp;
	head = nullptr;
	tail = nullptr;
}

bool List::isEmpty() {
	if (head == nullptr) return true;
	else return false;
}

// wannabe destruktor/ copy cat
List::~List() {
	clear();
	// ja pierdole technologia

}

// koniec char list funkcji teraz int lista funkcje

IntList::IntList() {
	head = nullptr;
}

void IntList::append(int newValue) {
	INode* NewElement = new INode;
	NewElement->number = newValue;
	if (head == nullptr){
		head = NewElement;
	}
	else{
		INode* tmp = head;
		while (tmp->next != nullptr){
			tmp = tmp->next;
		}
		tmp->next = NewElement;
	}
}
void IntList::pushFront(int newValue) {
	INode* NewElement = new INode;
	NewElement->number = newValue;
	if (head == nullptr){
		head = NewElement;
		NewElement->next = nullptr;
	} else{
		INode* tmp = head;
		head=NewElement;
		NewElement->next = tmp;
	}
}

void IntList::removeFirst() {
	if (head == nullptr) return;
	else if (head->next == nullptr) clear();
	else{
		INode* tmp = head->next;
		delete head;
		head = tmp;
	}

}


int IntList::getLast() {
	INode* tmp = head;
	if (tmp->next == nullptr) return head->number;
	while (tmp->next != nullptr){
		tmp = tmp->next;
	}
	return tmp->number;
}

void IntList::removeLast() {
	INode* tmp = head;
	if (tmp->next == nullptr) {
		head = nullptr;
		return;
	}
	while (tmp->next->next != nullptr){
		tmp = tmp->next;
	}
	delete tmp->next;
	tmp->next = nullptr;
}

void IntList::print() {
	INode* tmp = head;
	if (tmp == nullptr){
		cout << "empty list";
		return;
	}
	while (tmp->next != nullptr){
		cout << tmp->number << " ";
		tmp = tmp->next;
	}
	cout << tmp->number << " ";
}

void IntList::clear() {
	INode* tmp = head;
	if (tmp == nullptr) return;
	INode* helper;
	while (tmp->next != nullptr){
		helper = tmp->next;
		delete tmp;
		tmp = helper;
	}
	delete tmp;
	head = nullptr;
}

IntList::~IntList() {
	clear();
}