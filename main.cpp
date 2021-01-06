#include "node.hpp"

int main (int argc, char** argv)
{
    std::vector<int> arr1 {1,2,3,4,5,6,7,8,9,10};

    int arr2[10] = {2,4,6,8,10,12,14,16,18,20};

    LinkedList list = LinkedList(5);
    list.addArrToPos(arr2, 10, 3);
    list.print();

    return EXIT_SUCCESS;
}