#include "node.hpp"

int main (int argc, char** argv)
{
    std::vector<int> arr {1,2,3,4,5,6,7,8,9,10};

    LinkedList list = LinkedList(arr);
    list.reverse();
    list.print();

    return EXIT_SUCCESS;
}