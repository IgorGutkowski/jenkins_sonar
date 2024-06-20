#include "pyramid.h"
#include <gtest/gtest.h>
#include <sstream>
#include <string>

TEST(PyramidTests, DrawPyramidHeight5) {
    std::stringstream ss;
    std::streambuf* old_buf = std::cout.rdbuf(ss.rdbuf());

    draw_pyramid(5);

    std::cout.rdbuf(old_buf); // Przywracanie standardowego bufora
    std::string expected =
        "    *\n"
        "   ***\n"
        "  *****\n"
        " *******\n"
        "*********\n";
    ASSERT_EQ(ss.str(), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
