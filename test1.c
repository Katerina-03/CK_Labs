#include include "pch.h"
#include <stdio.h>
#include <conio.h>

int flag = 1;

TEST(TestCaseName, TestName) {
EXPECT_TRUE(flag);
}

int main(int argc, char* argv[])
{
    float a;
    char b;
    scanf("%f %c", &a, &b);
    printf("%f %c", a, b);

    if (a == 0)
        flag = 0;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
