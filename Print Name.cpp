
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
}*first = nullptr, *second = nullptr, *third = nullptr;


int count(Node* p)
{
    int count = 0;
    while (p != nullptr)
    {
        count++;
        p = p->next;
    }

    return count;
}


void Display(Node* p) 
{
    while (p != nullptr)
    {
        cout << p->data <<" -> "<< flush;
        p = p->next;
    }
    cout << endl;
}

void Create(int A[], int n)
{
    int i;
    Node* t, * last;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void Create2(int A[], int n)
{
    int i;
    Node* t, * last;
    second = new Node;
    second->data = A[0];
    second->next = nullptr;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void Merge(Node* p, Node* q)
{
    Node* last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = nullptr;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = nullptr;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = nullptr;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = nullptr;
        }
    }
    if (p)last->next = p;
    if (q)last->next = q;

}

void Insert(Node*p, int index, int x)
{
    Node* t;
    int i;

    if (index < 0 || index > count(p))
        return;
    t = new Node;
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void SortedInsert(Node*p, int x)
{
    Node* t;
    Node* q = nullptr;


    t = new Node;
    t->data = x;
    t->next = nullptr;

    if (first == nullptr)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            if (q !=nullptr)
            {
                t->next = q->next;
                q->next = t;
            }

        }
    }
}

int Delete(Node* p, int index) 
{
    Node* q = nullptr;
    int x = -1;

    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }

    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }

}

void DeleteLin(Node * p) 
{
    if (p->next != nullptr){

        DeleteLin(p->next);
        p->next = nullptr;
    }

    if(p->next == nullptr)
    {
        cout << p->data << " is deleted successfully" << endl;
        delete p;
    }

    
    
}

int IsSorted(Node* p)
{
    int x = -65536;
    while (p != nullptr)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }

    return 1;
}

void RemoveDuplicates(Node* p)
{
    Node* q = p->next;
    while (q != nullptr)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void Reverse1(Node* p)
{
    int* A, i = 0;
    Node* q = p;
    A = new int[count(p)+1];

    while (q != nullptr)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != nullptr)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }

    delete[]A;
}

void Reverse2(Node*p)
{
    Node *q = nullptr;
    Node* r = nullptr;
    while (p!=nullptr)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    first = q;
}

void Reverse3(Node* p, Node*q)
{
    if (p)
    {
        Reverse3(p->next, p);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int isLoop(Node* p)
{
    Node* q, *r;
    q = r = p;

    do
    {
        q = q->next;
        r = r->next;
        r = r ? r->next : nullptr;

    } while (q && r && q != r);

        if (q == r)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

int main()
{
    struct Node* t1, * t2;

    int A[] = { 10,20,30,40,50 };
    Create(A, 5);

    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    cout << isLoop(first);
    t2->next = nullptr;
    cout << isLoop(first);
    DeleteLin(first);
    return 0;
}