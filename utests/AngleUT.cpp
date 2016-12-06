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
    EXPECT_DOUBLE_EQ(angleZero1.Rad(), 0.0);
    EXPECT_DOUBLE_EQ(angleOneRad1.Rad(), 1.0);
}

TEST_F(Angle_Test, Deg)
{
    Angle angleOneDeg = DEG(1.0);

    EXPECT_DOUBLE_EQ(angleOneDeg.Rad(), DEG_TO_RAD);
    EXPECT_DOUBLE_EQ(angleOneDeg.Deg(), 1.0);
    EXPECT_DOUBLE_EQ(angleZero1.Deg(), 0.0);
    EXPECT_DOUBLE_EQ(angleOneRad1.Deg(), RAD_TO_DEG);
}

TEST_F(Angle_Test, Deg100th)
{
    Angle angleOneDeg100th = DEG100th(1.0);

    EXPECT_DOUBLE_EQ(angleOneDeg100th.Rad(), DEG100TH_TO_RAD);
    EXPECT_DOUBLE_EQ(angleOneDeg100th.Deg100th(), 1.0);
    EXPECT_DOUBLE_EQ(angleOneDeg100th.Deg(), 0.01);
    EXPECT_DOUBLE_EQ(angleOneRad1.Deg100th(), RAD_TO_DEG100TH);
}

TEST_F(Angle_Test, Modulo2PI_0)
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

        EXPECT_GE(angle.Modulo2PI().Rad(), 0.0);
        EXPECT_GE(angle1.Modulo2PI().Rad(), 0.0);
        EXPECT_GE(angle2.Modulo2PI().Rad(), 0.0);
        EXPECT_LT(angle.Modulo2PI().Rad(), TWO_PI);
        EXPECT_LT(angle1.Modulo2PI().Rad(), TWO_PI);
        EXPECT_LT(angle2.Modulo2PI().Rad(), TWO_PI);
        EXPECT_EQ(angle.Modulo2PI(), angle1.Modulo2PI());
        EXPECT_EQ(angle.Modulo2PI(), angle2.Modulo2PI());
        EXPECT_EQ(angle1.Modulo2PI(), angle2.Modulo2PI());
    }
}

TEST_F(Angle_Test, Modulo2PI_mPI)
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

        EXPECT_GE(angle.Modulo2PI(-PI).Rad(), -PI);
        EXPECT_GE(angle1.Modulo2PI(-PI).Rad(), -PI);
        EXPECT_GE(angle2.Modulo2PI(-PI).Rad(), -PI);
        EXPECT_LT(angle.Modulo2PI(-PI).Rad(), PI);
        EXPECT_LT(angle1.Modulo2PI(-PI).Rad(), PI);
        EXPECT_LT(angle2.Modulo2PI(-PI).Rad(), PI);

        EXPECT_EQ(angle.Modulo2PI(-PI), angle1.Modulo2PI(-PI));
        EXPECT_EQ(angle.Modulo2PI(-PI), angle2.Modulo2PI(-PI));
        EXPECT_EQ(angle1.Modulo2PI(-PI), angle2.Modulo2PI(-PI));
    }
}

TEST_F(Angle_Test, Modulo2PI_m11dot5)
{
    double minmod = -11.5;
    double range_min = -5.0*PI;
    double range = 10.0*PI;
    double nb = 133;
    double increment = range / nb;
    for(int i=0; i<nb; ++i)
    {
        Angle angle = RAD(range_min + increment);
        Angle angle1 = RAD(angle.Rad() + TWO_PI);
        Angle angle2 = RAD(angle1.Rad() + TWO_PI);

        EXPECT_GE(angle.Modulo2PI(minmod).Rad(), minmod);
        EXPECT_GE(angle1.Modulo2PI(minmod).Rad(), minmod);
        EXPECT_GE(angle2.Modulo2PI(minmod).Rad(), minmod);
        EXPECT_LT(angle.Modulo2PI(minmod).Rad(), minmod+TWO_PI);
        EXPECT_LT(angle1.Modulo2PI(minmod).Rad(), minmod+TWO_PI);
        EXPECT_LT(angle2.Modulo2PI(minmod).Rad(), minmod+TWO_PI);

        EXPECT_EQ(angle.Modulo2PI(minmod), angle1.Modulo2PI(minmod));
        EXPECT_EQ(angle.Modulo2PI(minmod), angle2.Modulo2PI(minmod));
        EXPECT_EQ(angle1.Modulo2PI(minmod), angle2.Modulo2PI(minmod));
    }
}

TEST_F(Angle_Test, Modulo2PI_11dot5)
{
    double minmod = 11.5;
    double range_min = -5.0*PI;
    double range = 10.0*PI;
    double nb = 133;
    double increment = range / nb;
    for(int i=0; i<nb; ++i)
    {
        Angle angle = RAD(range_min + increment);
        Angle angle1 = RAD(angle.Rad() + TWO_PI);
        Angle angle2 = RAD(angle1.Rad() + TWO_PI);

        EXPECT_GE(angle.Modulo2PI(minmod).Rad(), minmod);
        EXPECT_GE(angle1.Modulo2PI(minmod).Rad(), minmod);
        EXPECT_GE(angle2.Modulo2PI(minmod).Rad(), minmod);
        EXPECT_LT(angle.Modulo2PI(minmod).Rad(), minmod+TWO_PI);
        EXPECT_LT(angle1.Modulo2PI(minmod).Rad(), minmod+TWO_PI);
        EXPECT_LT(angle2.Modulo2PI(minmod).Rad(), minmod+TWO_PI);

        EXPECT_EQ(angle.Modulo2PI(minmod), angle1.Modulo2PI(minmod));
        EXPECT_EQ(angle.Modulo2PI(minmod), angle2.Modulo2PI(minmod));
        EXPECT_EQ(angle1.Modulo2PI(minmod), angle2.Modulo2PI(minmod));
    }
}

TEST_F(Angle_Test, Operator_Greater)
{
    EXPECT_TRUE(RAD(1.0) > RAD(0.0));
    EXPECT_GT(RAD(1.0), RAD(0.0));

    EXPECT_FALSE(RAD(0.0) > RAD(1.0));
    EXPECT_FALSE(RAD(0.0) > RAD(0.0));

    Angle angle1 = RAD(-10.0);
    Angle angle2 = DEG(-10.0);
    EXPECT_TRUE(angle2 > angle1);
    EXPECT_FALSE(angle1 > angle2);
    EXPECT_GT(angle2, angle1);
}

TEST_F(Angle_Test, Operator_Less)
{
    EXPECT_FALSE(RAD(1.0) < RAD(0.0));
    EXPECT_TRUE(RAD(0.0) < RAD(1.0));
    EXPECT_LT(RAD(0.0), RAD(1.0));
    EXPECT_FALSE(RAD(0.0) < angleZero1);

    Angle angle1 = RAD(-10.0);
    Angle angle2 = DEG(-10.0);
    EXPECT_FALSE(angle2 < angle1);
    EXPECT_TRUE(angle1 < angle2);
}

TEST_F(Angle_Test, Operator_GreaterEq)
{
    EXPECT_TRUE(RAD(1.0) >= RAD(0.0));
    EXPECT_GE(RAD(1.0), RAD(0.0));
    EXPECT_FALSE(RAD(0.0) >= RAD(1.0));
    EXPECT_TRUE(RAD(0.0) >= RAD(0.0));

    Angle angle1 = RAD(-10.0);
    Angle angle2 = DEG(-10.0);
    EXPECT_TRUE(angle2 >= angle1);
    EXPECT_GE(angle2, angle1);
    EXPECT_GE(angle2, angle2);
    EXPECT_FALSE(angle1 >= angle2);
}

TEST_F(Angle_Test, Operator_LessEq)
{
    EXPECT_FALSE(RAD(1.0) <= RAD(0.0));
    EXPECT_TRUE(RAD(0.0) <= RAD(1.0));
    EXPECT_LE(RAD(0.0), RAD(1.0));
    EXPECT_TRUE(RAD(0.0) <= RAD(0.0));

    Angle angle1 = RAD(-10.0);
    Angle angle2 = DEG(-10.0);
    EXPECT_FALSE(angle2 <= angle1);
    EXPECT_TRUE(angle1 <= angle2);
    EXPECT_LE(angle1, angle2);
    EXPECT_LE(angle1, angle1);
}

TEST_F(Angle_Test, OperatorMinus)
{
    Angle angle_m1 = -RAD(1.0);
    EXPECT_DOUBLE_EQ(angle_m1.Rad(), -1.0);
    Angle angle_1 = -angle_m1;
    EXPECT_EQ(angle_1, RAD(1.0));
}

TEST_F(Angle_Test, OperatorAddSelf)
{
    Angle angle = RAD(0.0);
    EXPECT_EQ(angle, RAD(0.0));
    angle+=RAD(1.0);
    EXPECT_EQ(angle, RAD(1.0));
    angle+=RAD(1.0);
    EXPECT_EQ(angle, RAD(2.0));
    angle+= -RAD(1.0);
    angle+= -RAD(1.0);
    EXPECT_EQ(angle, RAD(0.0));
}

TEST_F(Angle_Test, OperatorSubstractSelf)
{
    Angle angle = RAD(1.0);
    EXPECT_EQ(angle, RAD(1.0));
    angle-=RAD(1.0);
    EXPECT_EQ(angle, RAD(0.0));
    angle-=RAD(1.0);
    EXPECT_EQ(angle, RAD(-1.0));
    angle-= -RAD(1.0);
    angle-= -RAD(1.0);
    EXPECT_EQ(angle, RAD(1.0));
}

TEST_F(Angle_Test, OperatorMultiplySelf)
{
    Angle angle = RAD(1.0);
    EXPECT_EQ(angle, RAD(1.0));
    angle*=2.0;
    EXPECT_EQ(angle, RAD(2.0));
    angle*=5;
    EXPECT_EQ(angle, RAD(10));
    angle*= 0.0;
    EXPECT_EQ(angle, RAD(0.0));
}

TEST_F(Angle_Test, OperatorDivideSelf)
{
    Angle angle = RAD(1.0);
    EXPECT_EQ(angle, RAD(1.0));
    angle/=2.0;
    EXPECT_EQ(angle, RAD(0.5));
}

TEST_F(Angle_Test, OperatorAdd)
{
    Angle angle = RAD(0.0);
    EXPECT_EQ(angle, RAD(0.0));
    Angle angle1 = angle+RAD(1.0);
    EXPECT_EQ(angle1, RAD(1.0));
    Angle angle2 = angle1+RAD(1.0);
    EXPECT_EQ(angle2, RAD(2.0));
    Angle angle3 = angle2+(-(RAD(1.0)+RAD(1.0)));
    EXPECT_EQ(angle3, RAD(0.0));
}

TEST_F(Angle_Test, OperatorSubstract)
{
    Angle angle = RAD(1.0);
    EXPECT_EQ(angle, RAD(1.0));
    Angle angle1 = angle-RAD(1.0);
    EXPECT_EQ(angle1, RAD(0.0));
    Angle angle2 = angle1-RAD(1.0);
    EXPECT_EQ(angle2, -RAD(1.0));
    Angle angle3 = angle2-(RAD(1.0)+RAD(1.0));
    EXPECT_EQ(angle3, RAD(-3.0));
}

TEST_F(Angle_Test, OperatorMultiply)
{
    Angle angle = RAD(1.0);
    EXPECT_EQ(angle, RAD(1.0));
    Angle angle1 = angle*2.0;
    EXPECT_EQ(angle1, RAD(2.0));
    Angle angle2 = angle1*5;
    EXPECT_EQ(angle2, RAD(10));
    Angle angle3 = 10.0*angle2;
    EXPECT_EQ(angle3, RAD(100.0));
    Angle angle4 = 0.0*angle3;
    EXPECT_EQ(angle4, RAD(0.0));
}

TEST_F(Angle_Test, OperatorDivide)
{
    Angle angle = RAD(1.0);
    EXPECT_EQ(angle, RAD(1.0));
    Angle angle1 = angle/2.0;
    EXPECT_EQ(angle1, RAD(0.5));
    Angle angle2 = angle1/0.05;
    EXPECT_EQ(angle2, RAD(10));
}

TEST_F(Angle_Test, Sin)
{
    double range_min = -PI;
    double range = 3.0*PI;
    double nb = 133;
    double increment = range / nb;
    for(int i=0; i<nb; ++i)
    {
        double val = range_min + increment;
        EXPECT_DOUBLE_EQ(sin(RAD(val)), sin(val));
    }
}

TEST_F(Angle_Test, Cos)
{
    double range_min = -PI;
    double range = 3.0*PI;
    double nb = 133;
    double increment = range / nb;
    for(int i=0; i<nb; ++i)
    {
        double val = range_min + increment;
        EXPECT_DOUBLE_EQ(cos(RAD(val)), cos(val));
    }
}

TEST_F(Angle_Test, Tan)
{
    double range_min = -PI;
    double range = 3.0*PI;
    double nb = 133;
    double increment = range / nb;
    for(int i=0; i<nb; ++i)
    {
        double val = range_min + increment;
        EXPECT_DOUBLE_EQ(tan(RAD(val)), tan(val));
    }
}

TEST_F(Angle_Test, Fabs)
{
    double range_min = -PI;
    double range = 3.0*PI;
    double nb = 133;
    double increment = range / nb;
    for(int i=0; i<nb; ++i)
    {
        double val = range_min + increment;
        EXPECT_EQ(fabs(RAD(val)), RAD(fabs(val)));
        EXPECT_EQ(fabs(RAD(-val)), RAD(fabs(val)));
    }
}

TEST_F(Angle_Test, Arccos)
{
    double range_min = -1.0;
    double range = 2.0;
    double nb = 133;
    double increment = range / nb;
    for(int i=0; i<nb; ++i)
    {
        double val = range_min + increment;
        Angle angle = arccos(val);
        EXPECT_EQ(angle, RAD(acos(val)));
        EXPECT_DOUBLE_EQ(cos(angle), val);
    }
}

TEST_F(Angle_Test, Arcsin)
{
    double range_min = -1.0;
    double range = 2.0;
    double nb = 133;
    double increment = range / nb;
    for(int i=0; i<nb; ++i)
    {
        double val = range_min + increment;
        Angle angle = arcsin(val);
        EXPECT_EQ(angle, RAD(asin(val)));
        EXPECT_DOUBLE_EQ(sin(angle), val);
    }
}

TEST_F(Angle_Test, Arctan)
{
    double range_min = -1000.0;
    double range = 2000.0;
    double nb = 133;
    double increment = range / nb;
    for(int i=0; i<nb; ++i)
    {
        double val = range_min + increment;
        Angle angle = arctan(val);
        EXPECT_EQ(angle, RAD(atan(val)));
        EXPECT_LT(fabs(tan(angle) - val), 1e-10);
    }
}

TEST_F(Angle_Test, Arctan2)
{
    Angle angle1 = arctan2(0.0, 0.0);
    EXPECT_EQ(angle1, RAD(0.0));

    Angle angle2 = arctan2(sin(1.0), cos(1.0));
    EXPECT_EQ(angle2, RAD(1.0));

    double range_min = -1000.0;
    double range = 2000.0;
    double nb = 133;
    double increment = range / nb;
    for(int i=0; i<nb; ++i)
    {
        double val = range_min + increment;
        Angle angle = arctan2(sin(val), cos(val));
        EXPECT_LT(fabs(angle - RAD(val).Modulo2PI()), RAD(1e-10));
    }
}
