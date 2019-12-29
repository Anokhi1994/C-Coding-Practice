#include "singlyLinkedListNode.hpp"

SinglyLinkedListNode::SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }

void print_singly_linked_list(SinglyLinkedListNode* node, std::string sep, std::ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}


bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    while(head1!=NULL && head2!=NULL && head1->data==head2->data)
    head1=head1->next,head2=head2->next;    
    return head1==head2;
}

