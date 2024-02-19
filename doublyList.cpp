#include "doublyList.hpp"

Node::Node(int dataInput) : data(dataInput), // constructor that initializes data, and pointers to null
                      prev(nullptr),
                      next(nullptr) {}

int printMenu(doublyLinkedList &list)
{
    cout << "\n Please select 1 of 7:\n"
         << endl;
    cout << "1. Put data in front" << endl;
    cout << "2. Put data in the back" << endl;
    cout << "3. Pop first element" << endl;
    cout << "4. Pop last element" << endl;
    cout << "5. Print list" << endl;
    cout << "6. Print reversed list" << endl;
    cout << "7. EXIT." << endl;
    cout << "\n\n"
         << endl;

    int data = 0;
    int selection = 0;
    bool success = NULL;
    cin >> selection;

    if (!cin || selection < 1 || selection > 7)
    {
        cout << "Invalid selection" << endl;
        cin.clear();
        cin.ignore();
        return 1;
    }

    switch (selection)
    {
    case 1:
        cout << "What data do you want to input?:";
        cin >> data;
        list.frontNode(data);
        break;

    case 2:
        cout << "What data do you want to input?:";
        cin >> data;
        list.backNode(data);
        break;

    case 3:
        success = list.popFirst();
        if (!success)
            cout << "\nNo elements in the list" << endl;
        else
            cout << "\nData released." << endl;
        break;

    case 4:
        success = list.popLast();
        if (!success)
            cout << "\nNo elements in the list" << endl;
        else
            cout << "\nData released." << endl;
        break;

    case 5:
        cout << "Printing list..." << endl;
        list.printForward();
        break;

    case 6:
        cout << "Printing list..." << endl;
        list.printBackward();
        break;

    case 7:
        cout << "Goodybye!" << endl;
        return 0;
        break;
    }

    return 1;
}

doublyLinkedList:: ~doublyLinkedList() // destructor that deletes the entire list from memory
{
    Node *current = head;
    Node *temp = nullptr;
    while (current != nullptr)
    {
        temp = current->next;
        delete current;
        current = temp;
    }
}

Node *doublyLinkedList:: frontNode(int data)
{

    Node *n = new Node(data);
    if (head == nullptr) // if list isn't made yet
    {
        head = n;
        tail = n;
    }
    else
    {
        n->next = head;
        head->prev = n;
        head = n;
    }

    return n;
    }

Node *doublyLinkedList:: backNode(int data)
    {

        Node *n = new Node(data);
        if (tail == nullptr) // if list isn't made yet
        {
            head = n;
            tail = n;
        }
        else
        {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }

        return n;
    }

int doublyLinkedList:: popFirst()
    {

        if (head == nullptr) // if list isn't made yet
            return 0;

        else if (head == tail) // if there is one element
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else // list is > 1
        {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr; // updates new head that old prev link is gone
            delete temp;
        }

        return 1;
    }

int doublyLinkedList:: popLast()
    {

        if (tail == nullptr) // if list isn't made yet
            return 0;

        else if (tail == head) // if there is one element
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else // list is > 1
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr; // updates new tail that old next link is gone
            delete temp;
        }

        return 1;
    }

void doublyLinkedList:: printForward()
    {

        if (head == nullptr) // if list isn't made yet
            cout << "List does not contain any data" << endl;

        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << ", ";
            current = current->next;
        }
        cout << endl;
    }

void doublyLinkedList:: printBackward()
    {

        if (tail == nullptr) // if list isn't made yet
            cout << "List does not contain any data" << endl;

        Node *current = tail;
        while (current != nullptr)
        {
            cout << current->data << ", ";
            current = current->prev;
        }
        cout << endl;
    }