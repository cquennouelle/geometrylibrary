#include "Angle.h"

using namespace Geometry;

bool Angle::operator==(Angle const aAngle) const
{
    return m_value==aAngle.m_value;
}

Angle Angle::RAD(double const aValue)
{
    return Angle(aValue);
}

Angle Angle::DEG(double const aValue)
{
    return Angle(aValue*DEG_TO_RAD);
}

Angle Angle::DEG100th(double const aValue)
{
    return Angle(aValue*0.01*DEG_TO_RAD);
}


