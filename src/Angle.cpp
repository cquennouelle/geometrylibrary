#include "Angle.h"
#include <cmath>

using namespace Geometry;

Angle Angle::m_EPSILON = Angle(ANGLE_EPSILON);

Angle::Angle():m_value(0.0) {}

Angle::Angle(Angle const & angle):m_value(angle.m_value) {}

Angle::Angle(double const value):m_value(value) {}

double Angle::Rad() const { return m_value; }

double Angle::Deg() const { return m_value * RAD_TO_DEG; }

double Angle::Deg100th() const { return m_value * RAD_TO_DEG100TH; }

Angle const Angle::EPSILON() { return Angle::m_EPSILON; }

bool const Angle::operator==(Angle const & angle) const {
    double const diff = fabs(Rad()-angle.Rad());
    return diff < ANGLE_EPSILON;
}

bool const Angle::operator!=(Angle const & angle) const {
    return !((*this)==angle);
}

Angle & Angle::operator=(Angle const &angle) {
    m_value = angle.m_value;
    return *this;
}

Angle const Angle::operator-() const { return Angle(-m_value); }

Angle & Angle::operator+=(Angle const & angle) {
    m_value += angle.m_value;
    return *this;
}

Angle & Angle::operator-=(Angle const & angle) {
    m_value -= angle.m_value;
    return *this;
}

Angle & Angle::operator*=(const double &value) {
    m_value *= value;
    return *this;
}

Angle & Angle::operator/=(const double &value) {
    m_value /= value;
    return *this;
}

Angle Angle::RAD(double const value) { return Angle(value); }

Angle Angle::DEG(double const value) { return Angle(value*DEG_TO_RAD); }

Angle Angle::DEG100th(double const value) { return Angle(value*DEG100TH_TO_RAD); }

Angle Angle::Modulo2PI(double const offset) const
{
    double normalizedValue = GetNormalizedValue(m_value, offset);
    return Angle(normalizedValue);
}

double Angle::GetNormalizedValue(double const value, double const offset)
{
    double normalizedValue;
    double offsetValue = value - offset;
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

    return normalizedValue + offset;
}
