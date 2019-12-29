#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP

#include "singlyLinkedListNode.hpp"

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList();

        void insert_node(int node_data);
};

#endif
