// Complete the compare_lists function below.

/*
 * For your reference:
 *compare_lists is a function that 
 *Compares two heads, if they are not null pointer and if their data is same
it goes to the next node and returns true. 
 *
 */
#ifndef COMPAREHEADS_HPP
#define COMPAREHEADS_HPP
#include <numeric>
#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <memory>
#include <fstream> 

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data);
};



void print_singly_linked_list(SinglyLinkedListNode* node, std::string sep, std::ofstream& fout) ;

void free_singly_linked_list(SinglyLinkedListNode* node);
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) ;

#endif
