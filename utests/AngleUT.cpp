#include "gtest/gtest.h"
#include "../src/Angle.h"
#include <cmath>

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
    double range_min = -5.0*PI;
    double range = 10.0*PI;
    double nb = 100;
    double increment = range / nb;
    for(int i=0; i<nb; ++i)
    {
        Angle angle = RAD(range_min + increment);
        Angle angle1 = RAD(angle.Rad() + TWO_PI);
        Angle angle2 = RAD(angle1.Rad() + TWO_PI);

        EXPECT_TRUE(angle.Modulo2PI().Rad() >= -ANGLE_EPSILON);
        EXPECT_TRUE(angle1.Modulo2PI().Rad() >= -ANGLE_EPSILON);
        EXPECT_TRUE(angle2.Modulo2PI().Rad() >= -ANGLE_EPSILON);
        EXPECT_TRUE(angle.Modulo2PI().Rad() < TWO_PI - ANGLE_EPSILON);
        EXPECT_TRUE(angle1.Modulo2PI().Rad() < TWO_PI - ANGLE_EPSILON);
        EXPECT_TRUE(angle2.Modulo2PI().Rad() < TWO_PI - ANGLE_EPSILON);

        EXPECT_TRUE(angle.Modulo2PI() == angle1.Modulo2PI());
        EXPECT_TRUE(angle.Modulo2PI() == angle2.Modulo2PI());
        EXPECT_TRUE(angle1.Modulo2PI() == angle2.Modulo2PI());
    }
}

TEST_F(Angle_Test, Modulo2PI_0)
{
    double range_min = -5.0*PI;
    double range = 10.0*PI;
    double nb = 133;
    double increment = range / nb;
    for(int i=0; i<nb; ++i)
    {
        Angle angle = RAD(range_min + increment);
        Angle angle1 = RAD(angle.Rad() + TWO_PI);
        Angle angle2 = RAD(angle1.Rad() + TWO_PI);

        EXPECT_TRUE(angle.Module2PI_0().Rad() >= -PI);
        EXPECT_TRUE(angle1.Module2PI_0().Rad() >= -PI);
        EXPECT_TRUE(angle2.Module2PI_0().Rad() >= -PI);
        EXPECT_TRUE(angle.Module2PI_0().Rad() < PI);
        EXPECT_TRUE(angle1.Module2PI_0().Rad() < PI);
        EXPECT_TRUE(angle2.Module2PI_0().Rad() < PI);

        EXPECT_TRUE(angle.Module2PI_0() == angle1.Module2PI_0());
        EXPECT_TRUE(angle.Module2PI_0() == angle2.Module2PI_0());
        EXPECT_TRUE(angle1.Module2PI_0() == angle2.Module2PI_0());
    }
}
