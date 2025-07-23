#include <gmock/gmock.h>
#include "sdc.cpp"

using namespace testing;

class SdcFixture : public Test {
public:
	StringLengthChecker sdc;
	void checkLength(const string& str1, const string& str2, int expected_score) {
		int score = sdc.check(str1, str2);
		EXPECT_EQ(score, expected_score);
	}
};

TEST_F(SdcFixture, checkLength60ScoreCase) {
	checkLength("ASD", "DSA", 60);
}

TEST_F(SdcFixture, checkLength0ScoreCase) {
	checkLength("A", "BB", 0);
}

TEST_F(SdcFixture, checkLength20ScoreCase) {
	checkLength("AAABB", "BAA", 20);
}

TEST_F(SdcFixture, checkLength30ScoreCase) {
	checkLength("AA", "AAE", 30);
}


