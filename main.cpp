#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

class SimilarityFixture : public testing::Test {
public:
	SimilarityChecker sc;
	int getSimilarityScore(std::string a, std::string b) {
		return sc.getSimilarity(a, b);
	}

};

TEST_F(SimilarityFixture, SameLengthTest)
{	
	EXPECT_EQ(60, getSimilarityScore("ASD", "DSA"));
}

TEST_F(SimilarityFixture, DoubleLenghtDiffTest)
{
	EXPECT_EQ(0, getSimilarityScore("A", "BB"));
}

TEST_F(SimilarityFixture, SmallDiffTest1)
{
	EXPECT_EQ(20, getSimilarityScore("AAABB", "BAA"));
}

TEST_F(SimilarityFixture, SmallDiffTest2)
{
	EXPECT_EQ(30, getSimilarityScore("AA", "AAE"));
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}