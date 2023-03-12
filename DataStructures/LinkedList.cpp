#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    // every new node points to NULL
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    void pushNodeAtHead(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
    }

    void pushNode(int data)
    {
        Node *newNode = new Node(data);

        if (this->head == NULL)
        {
            this->head = newNode;
            return;
        }

        Node *temp = this->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteByData(int data)
    {
        if (this->head == NULL)
        {
            cout << "List already empty" << endl;
            return;
        }

        Node *current = this->head;
        Node *tracker = new Node;
        tracker->next = current;

        while (current->data != data)
        {
            tracker = current;
            current = current->next;
        }

        tracker->next = current->next;
        if (current == this->head)
        {
            this->head = this->head->next;
        }
        delete current;
    }

    void print()
    {
        cout << endl;
        if (this->head == NULL)
        {
            cout << "List empty";
            return;
        }

        Node *current = this->head;

        while (current != NULL)
        {
            cout << current->data << " - ";
            current = current->next;
        };
        cout << endl;
    }
};

int main()
{
    Node *nodeOne = new Node(420);
    // cout << nodeOne->data;
    LinkedList *listOne = new LinkedList;
    listOne->pushNode(1);
    listOne->pushNode(1);
    listOne->pushNode(1);
    listOne->pushNodeAtHead(1);
    listOne->pushNodeAtHead(2);
    listOne->pushNodeAtHead(3);
    listOne->deleteByData(3);
    listOne->print();
    return 0;
}
