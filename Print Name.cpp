
#include <iostream>

using namespace std;

// Circular Linked list
class Node {
public:
	int data;
	Node* next;
};

class CircularLinkedList {
private:
	Node* head;
public:
	CircularLinkedList(int A[], int n);
	void Display();
	void recursiveDisplay(Node* p);
	Node* getHead() { return head; }
	void Insert(Node*p, int pos, int x);
	int Length(Node* p);
	int Delete(Node* p, int index);
	~CircularLinkedList();
};

int CircularLinkedList::Length(Node*p)
{
	int len = 0;
	do {
		len++;
		p = p->next;
	} while (p!=head);

	return len;
}

CircularLinkedList::CircularLinkedList(int A[], int n)
{
	Node* t;
	Node* tail;

	head = new Node;

	head->data = A[0];
	head->next = head;
	tail = head;

	for (int i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = tail->next;
		tail->next = t;
		tail = t;
	}
}

void CircularLinkedList::Display()
{
	Node* p = head;
	do {
		cout << p->data << " -> " << flush;
		p = p->next;
	} while (p != head);
	cout << endl;
}

void CircularLinkedList::recursiveDisplay(Node*p)
{
	static int flag = 0;
	if (p != head || flag == 0)
	{
		flag = 1;
		cout << p->data << " -> " << flush;
		recursiveDisplay(p->next);
	}
	flag = 0;
}

CircularLinkedList::~CircularLinkedList()
{
	Node* p = head;
	while (p->next != head)
	{
		p = p->next;
	}

	while (p != head)
	{
		p->next = head->next;
		delete head;
		head = p->next;
	}

	if (p == head)
	{
		delete head;
		head = nullptr;
	}
}

void CircularLinkedList::Insert(Node* p, int pos, int x)
{
	Node* t;
	int i;

	if (pos < 0 || pos > Length(p))
		return;

	if (pos == 0)
	{
		t = new Node;
		t->data = x;
		if (head == nullptr)
		{
			head = t;
			head->next = head;

		}
		else
		{
			p = head;
			while (p->next != head) p = p->next;
			p->next = t; 
			t->next = head;
			head = t;
		}
	}
	else
	{
		p = head;
		for (i = 0; i < pos - 1; i++)
		{
			p = p->next;
		}
		t = new Node;
		t->data = x;
		t->next = p->next;
		p->next = t;
	}
}

int CircularLinkedList::Delete(Node* p, int index)
{
	Node* q;
	int i; int x;
	if (index < 0 || index > Length(p))
		return -1;
	if (index == 1)
	{
		p = head;
		while (p->next != head)
			p = p->next;
		x = head->data;
		if (p == head)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			p->next = head->next;
			delete head;
			head = p->next;
		}
	}
	else
	{
		p = head;
		for (i = 0; i < (index - 2); i++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		x = q->data;
		delete q;

	}

	return x;
}


int main()
{
	int A[] = { 1, 3, 5, 7, 9 };

	CircularLinkedList cl(A, sizeof(A) / sizeof(A[0]));

	cl.Display();

	Node* h = cl.getHead();
	cl.Insert(h, 3, 10);
	cl.Display();
	cout<<cl.Delete(h, 4)<<endl;
	cl.Display();
	return 0;
}