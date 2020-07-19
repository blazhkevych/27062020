#include <iostream>
using namespace std;

class Node {
	int val;
public:
	Node* next;
	Node(int v) :val(v) { next = nullptr; }
	int GetValue() const { return val; }
	void SetValue(int v) { val = v; }
};

class FList {
	Node* head;
	Node* tail;
	Node* PrevNode(Node*);
	Node* AddressNode(int p);
public:
	FList() :head(0), tail(0) {}
	~FList();
	void Print();
	void push_head(int v);
	void insert(int v, int p);
	void push_tail(int v);
	void del_head();
	void del(int p);
	void del_tail();
	void clear();
};
void FList::clear()
{
	while (head)
		del_head();
}
FList::~FList()
{
	clear();
}
void FList::push_tail(int v)
{
	Node* node = new Node(v);
	if (!head)
		head = node;
	else
		tail->next = node;
	tail = node;
}
void FList::push_head(int v)
{
	Node* node = new Node(v);
	if (!head)
		tail = node;
	else
		node->next = head;
	head = node;
}
void FList::insert(int v, int p)
{
	if (p == 0) {
		push_head(v);
		return;
	}
	Node* prev = AddressNode(p - 1);
	if (!prev)return;
	if (prev == tail) {
		push_tail(v);
		return;
	}
	Node* node = new Node(v);
	node->next = prev->next;
	prev->next = node;
}
void FList::del_head()
{
	Node* del = head;
	if (head)
		head = head->next;
	else
		tail = nullptr;
	delete del;
}
void FList::del(int p)
{
	if (p == 0) {
		del_head();
		return;
	}
	Node* prev = AddressNode(p - 1);
	if (prev == tail || !prev)return;
	Node* del = prev->next;
	prev->next = del->next;
	//prev->next = prev->next->next;
	if (del == tail) tail = prev;
	delete del;

}
void FList::del_tail()
{
	Node* prev = PrevNode(tail);
	if (prev) {
		prev->next = nullptr;
		delete tail;
		tail = prev;
	}
	else {
		del_head();
	}
}
Node* FList::PrevNode(Node* cur)
{
	Node* prev = head;
	while (prev)
	{
		if (prev->next == cur) break;
		prev = prev->next;
	}
	return prev;
}
Node* FList::AddressNode(int p)
{
	Node* prev = head;
	int k = 0;
	while (prev)
	{
		if (p == k++) break;
		prev = prev->next;
	}
	return prev;
}
void FList::Print()
{
	Node* temp = head;
	while (temp)
	{
		cout << temp->GetValue() << "\t";
		temp = temp->next;
	}
	cout << endl;

}


int main()
{
	FList list;
	list.push_tail(10);
	list.push_tail(20);
	list.push_tail(30);
	list.push_tail(40);
	list.Print();
	list.del(3);
	list.push_tail(666);
	list.Print();

	/*list.del_head();
	for (size_t i = 0; i < 5; i++)
		list.push_tail(i * 10);
	list.Print();
	for (size_t i = 0; i < 10; i++)
		list.del_head();

	for (size_t i = 0; i < 5; i++)
		list.push_tail(i * 10);
	list.Print();*/


	std::cout << "\nThe end!\n";
}