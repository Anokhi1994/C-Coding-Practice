#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../northeria.hpp"
using namespace testing;




TEST(NortheriaFemale, TestingFemaleInput){
		try{
		Northeria north("F",27,9 ,1994);
		EXPECT_THAT(north.get_sex_type() , "F");
		}
		catch(std::string& error){
		std::cout << error;	
		}
		
}

TEST(NortheriaMale, TestingMaleInput){
		try{
		Northeria north("M", 27, 9, 1994);
		EXPECT_THAT(north.get_sex_type() , "M");
		}
		catch(std::string& error){
		std::cout << error;	
		}
		
}




int main(int argc, char **argv){
    //in the book, the line below is 
    //testing::InitGoolgeMock(&argc, argv)
    //but this is deprecated
	testing::InitGoogleTest();
   // InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
