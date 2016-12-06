#include "Angle.h"
#include <cmath>

using namespace Geometry;

Angle Angle::m_EPSILON = Angle(ANGLE_EPSILON);

Angle::Angle():m_value(0.0) {}

Angle::Angle(Angle const & angle):m_value(angle.m_value) {}

Angle::Angle(double const value):m_value(value) {}

double Angle::GetNormalizedValue(double const aValue, double const aRangeMin)
{
    double normalizedValue;
    double offsetValue = aValue - aRangeMin;
    if(offsetValue >= 0.0)
    {
        normalizedValue = fmod(offsetValue, TWO_PI);
    }
    else
    {
        normalizedValue = -fmod(-offsetValue, TWO_PI);
        if(normalizedValue < -ANGLE_EPSILON)
        {
            normalizedValue += TWO_PI;
        }
    }

    return normalizedValue +  aRangeMin;
}
