#include "SinglyLinkedList.hpp"  

using namespace std;


int main()
{
    
  
    int tests;
    std::cout << "\nnumber of tests : " ;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        std::cout << "\nnumbers of elements in list 1 "  << " : " ;
        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::cout << "\nenter " << llist1_count << " number of elements : " ;
        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;

            llist1->insert_node(llist1_item);
        }
	
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();
	int llist2_count;
	std::cout << "\nnumbers of elements in list 2 "  << " : " ;
        
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::cout << "\nenter " << llist1_count << " number of elements : " ;

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;

            llist2->insert_node(llist2_item);
        }

        bool result = compare_lists(llist1->head, llist2->head);

        std::cout << result << "\n";
    }

    

    return 0;
}

