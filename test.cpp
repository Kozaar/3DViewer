#include <gtest/gtest.h>
#include <iostream>

#include "3dviewer_v2_0/Model/data.h"
#include "3dviewer_v2_0/Model/affinitytransformation.h"
/*
v version 1.0
*/

s21::Data data("examples/cube_norm.obj");
s21::AffinityTransformation trans;

TEST(open, true) {
    ASSERT_TRUE(data.numberOfFacets() == 4);
    ASSERT_TRUE(data.numberOfDots() == 8);
}

TEST(open, false) {
    s21::Data kis("test.cpp");
    ASSERT_TRUE(kis.filenameWithParametres() == "Wrong file");
}

TEST(moveX, true) {
    trans.update(data.setDots());
    double x = data.setDots()->at(0)[0];
    trans.movingX(1);
    ASSERT_TRUE(x == data.setDots()->at(0)[0]-1);
}

TEST(moveY, true) {
    trans.update(data.setDots());
    double x = data.setDots()->at(0)[1];
    trans.movingY(1);
    ASSERT_TRUE(x == data.setDots()->at(0)[1]-1);
}

TEST(moveZ, true) {
    trans.update(data.setDots());
    double x = data.setDots()->at(0)[2];
    trans.movingZ(1);
    ASSERT_TRUE(x == data.setDots()->at(0)[2]-1);
}

TEST(move, true) {
    trans.update(data.setDots());
    double x = data.setDots()->at(0)[0];
    double y = data.setDots()->at(0)[1];
    double z = data.setDots()->at(0)[2];
    trans.moving(5, 5, 5);
    ASSERT_TRUE(x == data.setDots()->at(0)[0]-5);
    ASSERT_TRUE(y == data.setDots()->at(0)[1]-5);
    ASSERT_TRUE(z == data.setDots()->at(0)[2]-5);
}

TEST(scale, true) {
    trans.update(data.setDots());
    double x = data.setDots()->at(0)[0];
    double y = data.setDots()->at(0)[1];
    double z = data.setDots()->at(0)[2];
    trans.scale(2);
    ASSERT_TRUE(x == data.setDots()->at(0)[0]/2);
    ASSERT_TRUE(y == data.setDots()->at(0)[1]/2);
    ASSERT_TRUE(z == data.setDots()->at(0)[2]/2);
}

TEST(rotate, true) {
    trans.update(data.setDots());
    double x = data.setDots()->at(0)[0];
    double y = data.setDots()->at(0)[1];
    double z = data.setDots()->at(0)[2];
    trans.rotate(180, 0, 0);
    ASSERT_TRUE(x - data.setDots()->at(0)[0] < 0.0000007);
    ASSERT_TRUE(y + data.setDots()->at(0)[1] < 0.0000007);
    ASSERT_TRUE(z + data.setDots()->at(0)[2] < 0.0000007);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
