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

    Node(const int val){
        data = val;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    LinkedList(const int length)
    {
        head = new Node();
        Node* temp = head;
        for (int i = 0; i < length; i++)
        {
            temp->next = new Node();
            temp = temp->next;
        }
        tail = temp;
    }

    LinkedList(const std::vector<int> arr)
    {
        head = new Node(arr[0]);
        Node* temp = head;
        int size = arr.size();
        for (int i = 1; i < size; i++)
        {
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
        tail = temp;
    }

    void addToFront(const int val)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }

    void addToBack(const int val)
    {
        if (tail == nullptr)
        {
            std::cout << "Cannot add node to end." << std::endl;
            return;
        }

        Node* newNode = new Node(val);
        tail->next = newNode;
        newNode->next = nullptr;
        return;
    }

    void reverse()
    {
        Node* curr = head;
        Node* prev = nullptr;
        Node* trueNext = nullptr;
        tail = head;

        while (curr != nullptr)
        {
            trueNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = trueNext;
        }
        head = prev;

        return;
    }

    void print()
    {
        Node* temp = head;

        while (temp != nullptr)
        {
            temp->next == nullptr ? std::cout << temp->data : std::cout << temp->data << ", ";
            temp = temp->next;
        }
        std::cout << std::endl;

        return;
    }
};