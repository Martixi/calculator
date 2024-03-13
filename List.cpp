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
}

// dodajemy na koniec, nie na początek to nie chiny
void List::append(char newValue) {
	Node* NewElement = new Node;
	NewElement->element = newValue;
	if (head == nullptr){
		head = NewElement;
	}
	else{
		Node* tmp = head;
		while (tmp->next != nullptr){
			tmp = tmp->next;
		}
		tmp->next = NewElement;
	}
}

// get lost, get fucked
char List::getLast(){
	Node* tmp = head;
	while (tmp->next != nullptr){
		tmp = tmp->next;
	}
	return tmp->element;
}

// dosłownie get fucked last element nobody likes you go away and die
void List::removeLast() {
	Node* tmp = head;
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
	cout << tmp->element << " ";
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