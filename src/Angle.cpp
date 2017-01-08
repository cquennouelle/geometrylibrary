#include "Angle.h"

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

/////////////////////////////////////////////////////////////////////////////////
// function definitions
/////////////////////////////////////////////////////////////////////////////////

Geometry::Angle const operator+(Geometry::Angle const & angle, Geometry::Angle const & angle2) {
    return Geometry::Angle(angle)+=angle2;
}

Geometry::Angle const operator-(Geometry::Angle const & angle, Geometry::Angle const & angle2) {
    return Geometry::Angle(angle)-=angle2;
}

Geometry::Angle const operator*(Geometry::Angle const & angle, double const & value) {
    return Geometry::Angle(angle)*=value;
}

Geometry::Angle const operator/(Geometry::Angle const & angle, double const & value) {
    return Geometry::Angle(angle)/=value;
}

bool const operator>(Geometry::Angle const & aAngle, Geometry::Angle const & aAngle2) {
    return aAngle.Rad() > aAngle2.Rad();
}

bool const operator<(Geometry::Angle const & angle, Geometry::Angle const & angle2) {
    return angle.Rad() < angle2.Rad();
}

bool const operator>=(Geometry::Angle const & angle, Geometry::Angle const & angle2) {
    return angle.Rad() >= angle2.Rad();
}

bool const operator<=(Geometry::Angle const & angle, Geometry::Angle const & angle2) {
    return angle.Rad() <= angle2.Rad();
}

Geometry::Angle operator*(double const value, Geometry::Angle const & angle) {
    return angle * value;
}

double cos(Geometry::Angle const & angle) {
    return cos(angle.Rad()); }

double sin(Geometry::Angle const & aAngle) {
    return sin(aAngle.Rad()); }

double tan(Geometry::Angle const & angle) {
    return tan(angle.Rad()); }

Geometry::Angle fabs(Geometry::Angle const & angle) {
    return Geometry::RAD(fabs(angle.Rad()));
}

Geometry::Angle arccos(double const cosinus) {
    return Geometry::RAD(acos(cosinus)); }

Geometry::Angle arcsin(double const sinus) {
    return Geometry::RAD(asin(sinus)); }

Geometry::Angle arctan(double const tangent) {
    return Geometry::RAD(atan(tangent)); }

Geometry::Angle arctan2(double const sinus, double const cosinus) {
    return Geometry::RAD(atan2(sinus, cosinus)); }

std::ostream & operator<<(std::ostream & out, Geometry::Angle const & angle) {
    out << angle.Rad();
    return out;
}
