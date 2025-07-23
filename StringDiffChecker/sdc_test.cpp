#include <gmock/gmock.h>
#include "sdc.cpp"

using namespace testing;

class SdcFixture : public Test {
public:
	StringLengthChecker slc;
	StringAlphabetChecker sac;
	StringDiffChecker sdc;
	void checkLength(const string& str1, const string& str2, int expected_score) {
		int actual_score = slc.check(str1, str2);
		EXPECT_EQ(actual_score, expected_score);
	}

	void checkAlphabet(const string& str1, const string& str2, int expected_score) {
		int actual_score = sac.check(str1, str2);
		EXPECT_EQ(actual_score, expected_score);
	}

	void checkScore(const string& str1, const string& str2, int expected_score) {
		int actual_score = sdc.check(str1, str2);
		EXPECT_EQ(actual_score, expected_score);
	}
};

TEST_F(SdcFixture, checkLengthScoreCase) {
	checkLength("ASD", "DSA", 60);
	checkLength("A", "BB", 0);
	checkLength("AAABB", "BAA", 20);
	checkLength("AA", "AAE", 30);
	checkLength("AAAAAAAAAAAAA", "ASGB", 0);
}

TEST_F(SdcFixture, checkAlphabetScoreCase) {
	checkAlphabet("ASD", "DSA", 40);
	checkAlphabet("A", "BB", 0);
	checkAlphabet("AAABB", "BAA", 40);
	checkAlphabet("AA", "AAE", 32);
	checkAlphabet("AAAAAAAAAAAAA", "ASGB", 33);
}

TEST_F(SdcFixture, checkScoreCase) {
	checkScore("ASD", "DSA", 100);
	checkScore("A", "BB", 0);
	checkScore("AAABB", "BAA", 60);
	checkScore("AA", "AAE", 62);
	checkScore("AAAAAAAAAAAAA", "ASGB", 33);
}
