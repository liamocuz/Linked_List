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
    int length;

    struct NodeTuple {
        Node* front;
        Node* back;
    };

    template <typename Array>
    NodeTuple createNodesFromArray(const Array arr, const int len)
    {
        Node* front = new Node(arr[0]);
        Node* back = nullptr;
        Node* temp = front;
        for (int i = 1; i < len; i++)
        {
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
        back = temp;

        NodeTuple tuple;
        tuple.front = front;
        tuple.back = back;

        return tuple;
    }

public:
    LinkedList()
    {
        head = new Node();
        tail = head;
        length = 1;
    }

    LinkedList(const int len)
    {
        if (len < 1)
        {
            std::cout << "Cannot create a list of length < 1." << std::endl;
            return;
        }

        head = new Node();
        Node* temp = head;
        int i = 1;
        while (i < len)
        {
            temp->next = new Node();
            temp = temp->next;
            i++;
        }
        tail = temp;
        length = len;
    }

    LinkedList(const std::vector<int> arr)
    {
        head = new Node(arr[0]);
        Node* temp = head;
        int size = arr.size();
        int i = 1;
        for (i = 1; i < size; i++)
        {
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
        tail = temp;
        length = i;
    }

    void addToFront(const int val)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        length++;
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
        length++;
        return;
    }

    void addToPos(const int val, const int pos)
    {
        // pos is 0 indexed
        if (pos > length)
        {
            std::cout << "The length of the list is shorter than the input position." << std::endl;
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }

    template <typename Array>
    void addArrToBack(const Array arr, const int len)
    {
        NodeTuple tuple = createNodesFromArray(arr, len);
        tail->next = tuple.front;
        tail = tuple.back;
        length += len;

        return;
    }

    template <typename Array>
    void addArrToFront(const Array arr, const int len)
    {
        NodeTuple tuple = createNodesFromArray(arr, len);
        tuple.back->next = head;
        head = tuple.front;
        length += len;

        return;
    }

    template <typename Array>
    void addArrToPos(const Array arr, const int len, const int pos)
    {
        NodeTuple tuple = createNodesFromArray(arr, len);
        // pos is 0 indexed
        if (pos > length)
        {
            std::cout << "The length of the list is shorter than the input position." << std::endl;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        tuple.back->next = temp->next;
        temp->next = tuple.front;

        if (pos == length)
            tail = tuple.back;

        length += len;

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
        std::cout << "Length of list: " << length << std::endl;
        
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