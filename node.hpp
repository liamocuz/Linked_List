#include <iostream>
#include <vector>

class Node {
public:
    int data;
    Node* next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int data){
        data = data;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node head;

public:
    LinkedList()
    {
        head = Node();
    }

    LinkedList(int length)
    {
        head = Node();
        Node* temp = &head;
        for (int i = 0; i < length; i++)
        {
            temp->next = &Node();
            temp = temp->next;
        }
    }

    LinkedList(std::vector<int> arr)
    {
        Node* temp = &head;
        int size = arr.size();
        for (int i = 0; i < size; i++)
        {
            temp = &Node(arr[i]);
            temp = temp->next;
        }
    }

    void printList()
    {
        Node* tmp = &head;

        while (tmp != nullptr)
        {
            std::cout << tmp->data << ", ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
};