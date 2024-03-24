//
// Created by admin on 09.03.2024.
//

#include "List.h"
#include "iostream"
using namespace std;

//
//char list
//

List::List() {
	head = nullptr;
	tail = nullptr;
}

void List::append(char newValue) {
	Node* NewElement = new Node;
	NewElement->element = newValue;
	if (head == nullptr){
		head = NewElement;
		tail = NewElement;
	}
	else{
		Node* tmp = tail;
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

char List::getFirst(){
	return head->element;
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

void List::nextElement(){
	Node* tmp = head->next;
	delete head;
	head = tmp;
}

char List::getLast(){
	if (tail == nullptr) return 0;
	return tail->element;
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
}

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

List::~List() {
	clear();
}

//
// int list
//

IntList::IntList() {
	head = nullptr;
}

void IntList::pushFront(int newValue) {
	auto * NewElement = new INode;
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

int IntList::getFirst(){
	return head->number;
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