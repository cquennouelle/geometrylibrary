#include "gtest/gtest.h"
#include "../src/Angle.h"

using namespace Geometry;

class Angle_Test : public ::testing::Test
{
public:
    void SetUp()
    {
        angleOneRad1 = Angle::RAD(1.0);
    }

public:
    Angle angleZero1;
    Angle angleOneRad1;
};

TEST_F(Angle_Test,  ConstructionAndAssignation)
{
    Angle angleZero2;
    Angle angleOneRad2 = RAD(1.0);
    Angle angleOneRad3, angleOneRad4;
    angleOneRad3 = angleOneRad4 = Angle::RAD(1.0);

    Angle angleZeroAssigned = angleZero1;
    Angle angleOneRadAssigned = angleOneRad1;

    EXPECT_TRUE(angleZero1==angleZero2);
    EXPECT_TRUE(angleZero1==angleZeroAssigned);
    EXPECT_FALSE(angleZero1==angleOneRad1);
    EXPECT_FALSE(angleZero1==angleOneRadAssigned);

    EXPECT_TRUE(angleOneRad1==angleOneRad2);
    EXPECT_TRUE(angleOneRad1==angleOneRad3);
    EXPECT_TRUE(angleOneRad1==angleOneRad4);
    EXPECT_TRUE(angleOneRad1==angleOneRadAssigned);
    EXPECT_FALSE(angleOneRad1==angleZero1);
    EXPECT_FALSE(angleOneRad1==angleZeroAssigned);
}

TEST_F(Angle_Test, Rad)
{
    EXPECT_EQ(angleZero1.Rad(), 0.0);
    EXPECT_EQ(angleOneRad1.Rad(), 1.0);
}

TEST_F(Angle_Test, Deg)
{
    Angle angleOneDeg = DEG(1.0);

    EXPECT_EQ(angleOneDeg.Rad(), DEG_TO_RAD);
    EXPECT_EQ(angleOneDeg.Deg(), 1.0);
    EXPECT_EQ(angleZero1.Deg(), 0.0);
    EXPECT_EQ(angleOneRad1.Deg(), RAD_TO_DEG);
}

TEST_F(Angle_Test, Deg100th)
{
    Angle angleOneDeg100th = DEG100th(1.0);

    EXPECT_EQ(angleOneDeg100th.Rad(), DEG100TH_TO_RAD);
    EXPECT_EQ(angleOneDeg100th.Deg100th(), 1.0);
    EXPECT_EQ(angleOneDeg100th.Deg(), 0.01);
    EXPECT_EQ(angleOneRad1.Deg100th(), RAD_TO_DEG100TH);
}

TEST_F(Angle_Test, Modulo2PI)
{
    Angle angle2pi = RAD(2.0*PI);
    Angle angle2pi_one = RAD(2.0*PI+1.0);
    EXPECT_FALSE(angleZero1 == angle2pi);
    EXPECT_TRUE(angleZero1 == angle2pi.Modulo2PI());
    EXPECT_FALSE(angleOneRad1 == angle2pi_one);
    EXPECT_TRUE(angleOneRad1 == angle2pi_one.Modulo2PI());
}
