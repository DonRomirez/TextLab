#pragma once
#include<iostream>
#include<string.h>
#include "Stack.h"
struct Node {
	std::string str;
	Node* next;
	Node* down;
};
class C_Text {
	Node* head;
	Node* t = NULL;
	Stack<Node*>path;
public:
	
	C_Text(std::string head = "Head");
	std::string getHead();
	void Next();
	void Previous();
	void CreateSection(std::string str);
	void SubSection(std::string str);
	void DeleteTree(Node* curr);
	void popSection();
};