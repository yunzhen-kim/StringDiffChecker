#include <string>
#include <cmath>

using std::string;

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