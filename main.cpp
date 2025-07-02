#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

class SimilarityFixture : public testing::Test {
public:
	SimilarityChecker sc;
	int getLengthSimilarityScore(std::string a, std::string b) {
		return sc.getLengthSimilarity(a, b);
	}

	int getDigitSimilarityScore(std::string a, std::string b) {
		return sc.getDigitSimilarity(a, b);
	}

};

TEST_F(SimilarityFixture, SameLengthTest)
{	
	EXPECT_EQ(60, getLengthSimilarityScore("ASD", "DSA"));
}

TEST_F(SimilarityFixture, DoubleLenghtDiffTest)
{
	EXPECT_EQ(0, getLengthSimilarityScore("A", "BB"));
}

TEST_F(SimilarityFixture, SmallDiffTest1)
{
	EXPECT_EQ(20, getLengthSimilarityScore("AAABB", "BAA"));
}

TEST_F(SimilarityFixture, SmallDiffTest2)
{
	EXPECT_EQ(30, getLengthSimilarityScore("AA", "AAE"));
}

TEST_F(SimilarityFixture, SameDigitTest)
{
	EXPECT_EQ(40, getDigitSimilarityScore("ASD", "DSA"));
}

TEST_F(SimilarityFixture, NoSameDigitTest)
{
	EXPECT_EQ(0, getDigitSimilarityScore("ABCDE", "FGHIJ"));
}

TEST_F(SimilarityFixture, SomeDigitSameTest)
{
	EXPECT_EQ(26, getDigitSimilarityScore("ABCDEF", "ABF"));
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}