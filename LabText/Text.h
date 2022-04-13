#pragma once
#include<iostream>
#include<string.h>
#include "Stack.h"
using namespace std;
struct Node {
	string str;
	Node* next;
	Node* down;
};
class Text {
	Node* head;
	Node* t = NULL;
	Stack<Node*>path;
public:
	Text() : head(NULL) {}
	void Next() {
		if (t == NULL)
			throw - 1;
		if (t->next == 0)
			throw - 2;
		path.push(t);
		t = t->next;
	}
	void Previous() {
		if (path.IsEmpty())
			throw - 3;
		t = path.pop();
	}
	void CreateSection(string str) {
		Node* p;
		p = new Node;
		p->next = NULL;
		p->down = NULL;
		p->str = str;
		if (head == NULL) {
			head = p;
			return;
		}
		p->next = t->next;
		t->next = p;
	}
	void SubSection(string str) {
		if (t = NULL)
			throw - 1;
		Node* p = new Node;
		p->down = NULL;
		p->next = t->down;
		p->str = str;
		t->down = p;
	}
	void DeleteTree(Node* curr) {
		if (curr == NULL)
			return;
		DeleteTree(curr->next);
		DeleteTree(curr->down);
		delete curr;
	}
	void popSection() {
		if (t == NULL)
			throw - 1;
		Node* tmp = t;
		if (path.IsEmpty()) {
			head = head->next;
			DeleteTree(tmp);
			return;
		}
		t = path.pop();
		if (t->next == tmp)
			t->next = tmp->next;
		else
			t->down = tmp->next;
		tmp->next = NULL;
		DeleteTree(tmp);
	}
};