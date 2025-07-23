#include <string>
#include <cmath>

using std::string;

// 글자 수: 60점
// 알파벳 : 40점
class StringDiffChecker {
public:
	int check(string str1, string str2) {
		int str1_len = str1.length();
		int str2_len = str2.length();
		if (str1_len == str2_len) return 60;
		else {
			int gap = abs(str1_len - str2_len);
			int short_len = std::min(str1_len, str2_len);
			double ratio = 1.0 - (static_cast<double>(gap) / short_len);
			int last_score = static_cast<int>(std::round(ratio * 60));
			return last_score;
		}
	}
};