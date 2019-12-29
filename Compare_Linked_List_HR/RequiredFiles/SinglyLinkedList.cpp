#include "SinglyLinkedList.hpp"


SinglyLinkedList::SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}


void SinglyLinkedList::insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

	if (!this->head) {
		this->head = node;
	} 
	else {
		this->tail->next = node;
	}

		this->tail = node;
} 

