//
// Created by mbk on 18/08/2024.
//

#include "gtest/gtest.h"
#include "polynom.h"


class PoylnomTestSuite : public ::testing::Test{
    Polynom<double, 2> p1{ {1., 2., 3.} };
    Polynom<double, 3> p2{ {1., -2., 3., 4. } };
};