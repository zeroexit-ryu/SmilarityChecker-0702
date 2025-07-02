#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

TEST(TS1, TC1)
{
	EXPECT_EQ(1, 1);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}