#include <gmock/gmock.h>
#include "sdc.cpp"

using namespace testing;

class SdcFixture : public Test {
public:
	StringDiffChecker sdc;

	void checkScore(const string& str1, const string& str2, int expected_score) {
		int actual_score = sdc.check(str1, str2);
		EXPECT_EQ(actual_score, expected_score);
	}
};

TEST_F(SdcFixture, checkScoreCase) {
	checkScore("ASD", "DSA", 100);
	checkScore("A", "BB", 0);
	checkScore("AAABB", "BAA", 60);
	checkScore("AA", "AAE", 62);
	checkScore("AAAAAAAAAAAAA", "ASGB", 33);
}

TEST_F(SdcFixture, checkScoreEmpty) {
	checkScore("", "", 60);
	checkScore("A", "", 0);
	checkScore("", "B", 0);
}