#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../RequiredFiles/SinglyLinkedList.hpp"


using namespace testing;

class SinglyLinkedListTests: public Test{
    public:
	SinglyLinkedList List;
        
};

TEST_F(SinglyLinkedListTests, notANullAfterInsertingFirstNode){
    List.insert_node(5);
    ASSERT_THAT(List.head->data, Eq(5));
}

TEST_F(SinglyLinkedListTests, notANullAfterInsertingFirstNode){
    List.insert_node(5);
    ASSERT_THAT(List.head->data, Eq(5));
}



int main(int argc, char **argv){
    //in the book, the line below is 
    //testing::InitGoolgeMock(&argc, argv)
    //but this is deprecated
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
