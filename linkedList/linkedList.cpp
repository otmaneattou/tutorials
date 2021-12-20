#include <iostream>

class List
{

private:
    typedef struct node
    {
        int data;
        node *next;
    } * nodePtr;
    nodePtr head;
    nodePtr curr;
    nodePtr temp;

public:
    List();
    void addNode(int data);
    void deleteNode(int data);
    void printList();
};

List::List()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void List::addNode(int data)
{
    nodePtr newNode = new node;
    newNode->next = NULL;
    newNode->data = data;
    if (head != NULL)
    {
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    else
    {
        head = newNode;
    }
}

void List::deleteNode(int data)
{
    nodePtr nodeToBeDeleted = NULL;
    temp = head;
    curr = head;
    while (curr->next != NULL && curr->data != data)
    {
        temp = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        std::cout << data << " was not in the linkedlist" << std::endl;
        delete nodeToBeDeleted;
    }
    if (curr->data == data)
    {
        nodeToBeDeleted = curr;
        curr = curr->next;
        temp->next = curr;
        delete nodeToBeDeleted;
        std::cout << "The value  " << data << " was deleted" << std::endl;
    }
}

void List::printList()
{
    curr = head;
    while (curr != NULL)
    {
        std::cout << curr->data << std::endl;
        curr = curr->next;
    }
}

int main()
{
    List test;
    test.addNode(3);
    test.addNode(5);
    test.addNode(6);
    test.addNode(7);
    test.printList();
    std::cout << "------------" << std::endl;
    test.deleteNode(1);
    test.printList();
    return 0;
}
