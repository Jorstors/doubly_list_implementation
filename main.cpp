#include "doublyList.hpp"

int main()
{
    doublyLinkedList list;
    while(printMenu(list) != 0){}

    return 0;
}

//list destructor is called once list is out of scope