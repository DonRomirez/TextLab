#include "Text.h"
C_Text::C_Text(std::string _head) {
	head = new Node;
	head->next = NULL;
	head->down = NULL;
	head->str = _head;
}
 std::string C_Text::getHead() {
	return head->str;
}
void C_Text::Next() {
	if (t == NULL)
		throw - 1;
	if (t->next == 0)
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
void C_Text::SubSection(std::string str) {
	if (t = NULL)
		throw - 1;
	Node* p = new Node;
	p->down = NULL;
	p->next = t->down;
	p->str = str;
	t->down = p;
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