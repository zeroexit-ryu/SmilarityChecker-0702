#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>

class SimilarityChecker {
public:
	int getSimilarity(const std::string& a, const std::string& b) {
		if (a.length() == b.length()) return 60;
 		if (a.length() >= b.length() * 2) return 0;
		if (a.length() * 2 <= b.length()) return 0;

		int shortStringLength = -1;
		if (a.length() > b.length()) shortStringLength = b.length();
		else shortStringLength = a.length();

		int gap = ::abs((int)(a.length() - b.length()));		
		int score = static_cast<int>((1.0 - (static_cast<double>(gap) / static_cast<double>(shortStringLength))) * 60.0);
		return score;
	}
};

