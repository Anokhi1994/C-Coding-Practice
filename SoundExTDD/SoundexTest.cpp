#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Soundex.hpp"

using namespace testing;


class SoundexEncoding : public Test{
		public:
			Soundex soundex;
	};

TEST_F(SoundexEncoding, RetainsSoOneLetterofOneWord){
		EXPECT_THAT(soundex.encoded("Ab")  , Eq("A100"));
		EXPECT_THAT(soundex.encoded("Ac")  , Eq("A200"));
		EXPECT_THAT(soundex.encoded("Ad")  , Eq("A300"));
}

TEST_F(SoundexEncoding, PaddingWithZeroes){
		ASSERT_THAT(soundex.encoded("I")  , Eq("I000"));
}


TEST_F(SoundexEncoding, SecondLetterEncoding){
		ASSERT_THAT(soundex.encoded("Ab")  , Eq("A100"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
ASSERT_THAT(soundex.encoded("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
ASSERT_THAT(soundex.encoded("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, DISABLED_ReplacesMultipleConsonantsWithDigits) {
ASSERT_THAT(soundex.encoded("Acdl"), Eq("A234"));
}



int main(int argc, char **argv){
    //in the book, the line below is 
    //testing::InitGoolgeMock(&argc, argv)
    //but this is deprecated
	testing::InitGoogleTest();
   // InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
