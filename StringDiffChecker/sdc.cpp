#include <string>
#include <cmath>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

// 글자 수: 60점
// 알파벳 : 40점
class StringLengthChecker {
public:
	int check(string str1, string str2) {
		int str1_len = str1.length();
		int str2_len = str2.length();
		if (str1_len == str2_len) return 60;
		else {
			return calculatePartScore(str1_len, str2_len);
		}
	}
private:
	int calculatePartScore(int str1_len, int str2_len) {
		int big_len = std::max(str1_len, str2_len);
		int short_len = std::min(str1_len, str2_len);
		if (big_len >= short_len * 2) return 0;
		double ratio = 1.0 - (static_cast<double>(big_len - short_len) / short_len);
		return static_cast<int>(std::round(ratio * 60));
	}
};

class StringAlphabetChecker {
public:
	int check(string str1, string str2) {
		int score = 0;
		int totalAlphabetCnt = str1.length() + str2.length();
		int sameCnt = 0;
		for (char c : str1) {
			if (str2.find(c) != string::npos) {
				++sameCnt;				
			}
		}
		
		for (char c : str2) {
			if (str1.find(c) != string::npos) {
				++sameCnt;				
			}			
		}
	
		if (sameCnt == 0) return 0;
		
		double ratio = static_cast<double>(sameCnt) / totalAlphabetCnt;
		score = static_cast<int>(std::round(ratio * 40));
		return score;		
	}	
};
