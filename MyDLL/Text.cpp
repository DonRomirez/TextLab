#include "Text.h"
C_Text::C_Text(std::string _head) {
	head = new Node;
	head->str = " ";
	head->next = NULL;
	head->down = NULL;
	t = head;
	head->str = _head;
}
std::string C_Text::getHead() {
	return head->str;
}
void C_Text::Next() {
	if (t == NULL)
		throw - 1;
	if (t->next == NULL)
		throw - 2;
	path.push(t);
	t = t->next;
}
void C_Text::Previous() {
	if (path.IsEmpty())
		throw - 3;
	t = path.pop();
}
void C_Text::CreateSection(std::string str) {
	Node* p;
	p = new Node;
	p->down = NULL;
	p->next = NULL;
	p->str = str;
	if (head == NULL) {
		head = p;
		t = p;
		return;
	}
	p->next = t->next;
	t->next = p;
	path.push(t);
	t = t->next;
}
void C_Text::SubSection(std::string str) {
	if (t == NULL)
		throw - 1;
	Node* p = new Node;
	p->down = NULL;
	//p->next = t->down;
	p->next = NULL;
	p->str = str;
	t->down = p;
	
}
void C_Text::setHead(std::string str) {
	head->str = str;
}
void C_Text::DeleteTree(Node* curr) {
	if (curr == NULL)
		return;
	DeleteTree(curr->next);
	DeleteTree(curr->down);
	delete curr;
}
void C_Text::popSection() {
	if (t == NULL)
		return;
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
void C_Text::String_Text(Node* curr, std::string& str) {
	if (curr == NULL) {
		return;
	}
	if (curr == this->t) {
		if (t == head)
			str += "*...\n ";
		else
		str += "*";
	}
	if (curr != this->head) {
		str += curr->str;
		str += "\n";
	}
	String_Text(curr->down, str);
	String_Text(curr->next, str);
}
std::string C_Text::Print_t() {
	std::string res;
	String_Text(head, res);
	return res;
}