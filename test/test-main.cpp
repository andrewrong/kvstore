#include <iostream>
#include <gtest/gtest.h>

using std::iostream;

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
