#include "pch.h"
#include <gtest/gtest.h>
#include <string.h>
using namespace std;

struct Project
{
	float var = 101;
	string greetings = "Hello,world!";
};

TEST(ProjectTest, StringTest)
{
	Project test;
	EXPECT_EQ("Hello,world!", test.greetings);
	EXPECT_EQ(101, test.var);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
