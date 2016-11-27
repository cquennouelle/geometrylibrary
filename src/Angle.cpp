#include "Angle.h"
#include <cmath>

using namespace Geometry;

Angle Angle::m_EPSILON = Angle(ANGLE_EPSILON);

Angle &Angle::operator=(Angle const &aAngle)
{
    m_value = aAngle.m_value;
    return *this;
}

Angle Angle::operator-() const
{
    return Angle(-m_value);
}

Angle & Angle::operator+=(Angle const & aAngle)
{
    m_value += aAngle.m_value;
    return *this;
}

Angle & Angle::operator-=(Angle const & aAngle)
{
    m_value -= aAngle.m_value;
    return *this;
}

Angle & Angle::operator*=(const double &aValue)
{
    m_value *= aValue;
    return *this;
}

Angle & Angle::operator/=(const double &aValue)
{
    m_value /= aValue;
    return *this;
}

Angle Angle::operator+(const Angle &aAngle) const
{
    return Angle(*this)+=aAngle;
}

Angle Angle::operator-(const Angle &aAngle) const
{
    return Angle(*this)-=aAngle;
}

Angle Angle::operator*(const double &aValue) const
{
    return Angle(*this)*=aValue;
}

Angle Angle::operator/(const double &aValue) const
{
    return Angle(*this)/=aValue;
}

bool Angle::operator==(Angle const & aAngle) const
{
    double const diff = fabs(m_value-aAngle.m_value);
    return diff < ANGLE_EPSILON;
}

bool Angle::operator>(Angle const & aAngle) const
{
    return m_value > aAngle.m_value;
}

bool Angle::operator<(Angle const & aAngle) const
{
    return m_value < aAngle.m_value;
}

bool Angle::operator>=(Angle const & aAngle) const
{
    return m_value >= aAngle.m_value;
}

bool Angle::operator<=(Angle const & aAngle) const
{
    return m_value <= aAngle.m_value;
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

double Angle::GetNormalizedValue(double const aValue)
{
    double normalizedValue;
    if(aValue >= 0.0)
    {
        normalizedValue = fmod(aValue, TWO_PI);
    }
    else
    {
        normalizedValue = -fmod(-aValue, TWO_PI);
        if(normalizedValue < -ANGLE_EPSILON)
        {
            normalizedValue += TWO_PI;
        }
    }

    return normalizedValue;
}

Angle Angle::Modulo2PI() const
{
    double normalizedValue = GetNormalizedValue(m_value);
    return Angle(normalizedValue);
}

Angle Angle::Module2PI_0() const
{
    double normalizedValue = GetNormalizedValue(m_value + PI);
    return Angle(normalizedValue-PI);
}
