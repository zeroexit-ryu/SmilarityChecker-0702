#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

TEST(TS1, TC1)
{
	SimilarityChecker sc;
	int actual = sc.getSimilarity("ASD", "DSA");
	
	EXPECT_EQ(60, actual);
}

TEST(TS1, TC2)
{
	SimilarityChecker sc;
	int actual = sc.getSimilarity("A", "BB");

	EXPECT_EQ(0, actual);
}

TEST(TS1, TC3)
{
	SimilarityChecker sc;
	int actual = sc.getSimilarity("AAABB", "BAA");

	EXPECT_EQ(20, actual);
}

TEST(TS1, TC4)
{
	SimilarityChecker sc;
	int actual = sc.getSimilarity("AA", "AAE");

	EXPECT_EQ(30, actual);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}