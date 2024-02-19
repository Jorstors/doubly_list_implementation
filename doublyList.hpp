#ifndef DOUBLYLIST
#define DOUBLYLIST

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int dataInput);
};

class doublyLinkedList
{
private:
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    ~doublyLinkedList(); // destructor that deletes the entire list from memory
    
    Node *frontNode(int data);

    Node *backNode(int data);

    int popFirst();

    int popLast();

    void printForward();

    void printBackward();
};

int printMenu(doublyLinkedList &list);

#endif