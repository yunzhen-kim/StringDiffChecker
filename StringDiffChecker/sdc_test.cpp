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

TEST_F(SdcFixture, checkLengthScoreCase) {
	checkLength("ASD", "DSA", 60);
	checkLength("A", "BB", 0);
	checkLength("AAABB", "BAA", 20);
	checkLength("AA", "AAE", 30);
}


