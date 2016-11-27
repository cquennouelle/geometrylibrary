#include "Angle.h"
#include <cmath>

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

Angle Angle::Modulo2PI() const
{
    double angleNormalized = fmod(m_value, TWO_PI);
    if (angleNormalized < 0.0)
    {
        angleNormalized += TWO_PI;
    }
    return Angle(angleNormalized);
}
