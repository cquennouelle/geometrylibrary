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

    Angle angleZeroCopy(angleZero1);
    Angle angleOneRadCopy(angleOneRad1);

    EXPECT_TRUE(angleZero1==angleZero2);
    EXPECT_FALSE(angleZero1==angleOneRad1);
    EXPECT_TRUE(angleOneRad1==angleOneRad2);
    EXPECT_TRUE(angleOneRad1==angleOneRad3);
    EXPECT_TRUE(angleOneRad1==angleOneRad4);
    EXPECT_FALSE(angleOneRad1==angleZero1);

    EXPECT_TRUE(angleZero1==angleZeroAssigned);
    EXPECT_FALSE(angleZero1==angleOneRadAssigned);
    EXPECT_TRUE(angleOneRad1==angleOneRadAssigned);
    EXPECT_FALSE(angleOneRad1==angleZeroAssigned);

    EXPECT_TRUE(angleZero1==angleZeroCopy);
    EXPECT_FALSE(angleZero1==angleOneRadCopy);
    EXPECT_TRUE(angleOneRad1==angleOneRadCopy);
    EXPECT_FALSE(angleOneRad1==angleZeroCopy);
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

TEST_F(Angle_Test, Operator_Greater)
{
    EXPECT_TRUE(angleOneRad1 > angleZero1);
    EXPECT_FALSE(angleZero1 > angleOneRad1);
    EXPECT_FALSE(angleZero1 > angleZero1);

    Angle angle1 = RAD(-10.0);
    Angle angle2 = DEG(-10.0);
    EXPECT_TRUE(angle2 > angle1);
    EXPECT_FALSE(angle1 > angle2);
}

TEST_F(Angle_Test, Operator_Less)
{
    EXPECT_FALSE(angleOneRad1 < angleZero1);
    EXPECT_TRUE(angleZero1 < angleOneRad1);
    EXPECT_FALSE(angleZero1 < angleZero1);

    Angle angle1 = RAD(-10.0);
    Angle angle2 = DEG(-10.0);
    EXPECT_FALSE(angle2 < angle1);
    EXPECT_TRUE(angle1 < angle2);
}

TEST_F(Angle_Test, Operator_GreaterEq)
{
    EXPECT_TRUE(angleOneRad1 >= angleZero1);
    EXPECT_FALSE(angleZero1 >= angleOneRad1);
    EXPECT_TRUE(angleZero1 >= angleZero1);

    Angle angle1 = RAD(-10.0);
    Angle angle2 = DEG(-10.0);
    EXPECT_TRUE(angle2 >= angle1);
    EXPECT_FALSE(angle1 >= angle2);
}

TEST_F(Angle_Test, Operator_LessEq)
{
    EXPECT_FALSE(angleOneRad1 <= angleZero1);
    EXPECT_TRUE(angleZero1 <= angleOneRad1);
    EXPECT_TRUE(angleZero1 <= angleZero1);

    Angle angle1 = RAD(-10.0);
    Angle angle2 = DEG(-10.0);
    EXPECT_FALSE(angle2 <= angle1);
    EXPECT_TRUE(angle1 <= angle2);
}

TEST_F(Angle_Test, OperatorMinus)
{
    Angle angle_m1 = -angleOneRad1;
    EXPECT_EQ(angle_m1.Rad(), -(angleOneRad1.Rad()));
    Angle angle_1 = -angle_m1;
    EXPECT_EQ(angle_1, angleOneRad1);
}

TEST_F(Angle_Test, OperatorAddSelf)
{
    Angle angle = angleZero1;
    EXPECT_EQ(angle, angleZero1);
    angle+=angleOneRad1;
    EXPECT_EQ(angle, angleOneRad1);
    angle+=angleOneRad1;
    EXPECT_EQ(angle, RAD(2.0));
    angle+= -angleOneRad1;
    angle+= -angleOneRad1;
    EXPECT_EQ(angle, angleZero1);
}

TEST_F(Angle_Test, OperatorSubstractSelf)
{
    Angle angle = angleOneRad1;
    EXPECT_EQ(angle, angleOneRad1);
    angle-=angleOneRad1;
    EXPECT_EQ(angle, angleZero1);
    angle-=angleOneRad1;
    EXPECT_EQ(angle, RAD(-1.0));
    angle-= -angleOneRad1;
    angle-= -angleOneRad1;
    EXPECT_EQ(angle, angleOneRad1);
}

TEST_F(Angle_Test, OperatorMultiplySelf)
{
    Angle angle = angleOneRad1;
    EXPECT_EQ(angle, angleOneRad1);
    angle*=2.0;
    EXPECT_EQ(angle, RAD(2.0));
    angle*=5;
    EXPECT_EQ(angle, RAD(10));
    angle*= 0.0;
    EXPECT_EQ(angle, angleZero1);
}

TEST_F(Angle_Test, OperatorDivideSelf)
{
    Angle angle = angleOneRad1;
    EXPECT_EQ(angle, angleOneRad1);
    angle/=2.0;
    EXPECT_EQ(angle, RAD(0.5));
}

TEST_F(Angle_Test, OperatorAdd)
{
    Angle angle = angleZero1;
    EXPECT_EQ(angle, angleZero1);
    Angle angle1 = angle+angleOneRad1;
    EXPECT_EQ(angle1, angleOneRad1);
    Angle angle2 = angle1+angleOneRad1;
    EXPECT_EQ(angle2, RAD(2.0));
    Angle angle3 = angle2+(-(angleOneRad1+angleOneRad1));
    EXPECT_EQ(angle3, angleZero1);
}

TEST_F(Angle_Test, OperatorSubstract)
{
    Angle angle = angleOneRad1;
    EXPECT_EQ(angle, angleOneRad1);
    Angle angle1 = angle-angleOneRad1;
    EXPECT_EQ(angle1, angleZero1);
    Angle angle2 = angle1-angleOneRad1;
    EXPECT_EQ(angle2, -angleOneRad1);
    Angle angle3 = angle2-(angleOneRad1+angleOneRad1);
    EXPECT_EQ(angle3, RAD(-3.0));
}

TEST_F(Angle_Test, OperatorMultiply)
{
    Angle angle = angleOneRad1;
    EXPECT_EQ(angle, angleOneRad1);
    Angle angle1 = angle*2.0;
    EXPECT_EQ(angle1, RAD(2.0));
    Angle angle2 = angle1*5;
    EXPECT_EQ(angle2, RAD(10));
    Angle angle3 = 10.0*angle2;
    EXPECT_EQ(angle3, RAD(100.0));
    Angle angle4 = 0.0*angle3;
    EXPECT_EQ(angle4, angleZero1);
}

TEST_F(Angle_Test, OperatorDivide)
{
    Angle angle = angleOneRad1;
    EXPECT_EQ(angle, angleOneRad1);
    Angle angle1 = angle/2.0;
    EXPECT_EQ(angle1, RAD(0.5));
    Angle angle2 = angle1/0.05;
    EXPECT_EQ(angle2, RAD(10));
}
