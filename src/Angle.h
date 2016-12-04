#ifndef __ANGLE_H__
#define __ANGLE_H__
#include "Constants.h"
#include <iostream>
#include <cmath>

// Doxygen
// binary operators as function


namespace Geometry
{
class Angle
{
public:
    Angle():m_value(0.0) {}
    Angle(Angle const & aAngle):m_value(aAngle.m_value) {}
    ~Angle() {}

    double Rad() const { return m_value; }
    double Deg() const { return m_value * RAD_TO_DEG; }
    double Deg100th() const { return m_value * RAD_TO_DEG * 100.0; }
    static Angle const EPSILON() { return m_EPSILON; }

    inline Angle & operator=(Angle const & aAngle);
    inline bool const operator==(Geometry::Angle const & aAngle) const;
    inline bool const operator!=(Geometry::Angle const & aAngle) const;

    inline Angle const operator-() const;
    inline Angle & operator+=(Angle const & aAngle);
    inline Angle & operator-=(Angle const & aAngle);
    inline Angle & operator*=(double const & aValue);
    inline Angle & operator/=(double const & aValue);

    inline static Angle RAD(double const aValue);
    inline static Angle DEG(double const aValue);
    inline static Angle DEG100th(double const aValue);

    inline Angle Modulo2PI(double const aRangeMin = 0.0) const;

private:
    Angle(double const aValue):m_value(aValue) {}

    static double GetNormalizedValue(double const aValue, double const aRangeMin);

private:
    double m_value;
    static Angle m_EPSILON;

};

inline Angle RAD(double const aValue) { return Angle::RAD(aValue); }
inline Angle DEG(double const aValue) { return Angle::DEG(aValue); }
inline Angle DEG100th(double const aValue) { return Angle::DEG100th(aValue); }
}

inline Geometry::Angle const operator+(Geometry::Angle const & aAngle, Geometry::Angle const & aAngle2) {
    return Geometry::Angle(aAngle)+=aAngle2;
}

inline Geometry::Angle const operator-(Geometry::Angle const & aAngle, Geometry::Angle const & aAngle2) {
    return Geometry::Angle(aAngle)-=aAngle2;
}

inline Geometry::Angle const operator*(Geometry::Angle const & aAngle, double const & aValue) {
    return Geometry::Angle(aAngle)*=aValue;
}
inline Geometry::Angle const operator/(Geometry::Angle const & aAngle, double const & aValue) {
    return Geometry::Angle(aAngle)/=aValue;
}

inline bool const operator>(Geometry::Angle const & aAngle, Geometry::Angle const & aAngle2) {
    return aAngle.Rad() > aAngle2.Rad();
}

inline bool const operator<(Geometry::Angle const & aAngle, Geometry::Angle const & aAngle2) {
    return aAngle.Rad() < aAngle2.Rad();
}

inline bool const operator>=(Geometry::Angle const & aAngle, Geometry::Angle const & aAngle2) {
    return aAngle.Rad() >= aAngle2.Rad();
}

inline bool const operator<=(Geometry::Angle const & aAngle, Geometry::Angle const & aAngle2) {
    return aAngle.Rad() <= aAngle2.Rad();
}

inline Geometry::Angle operator*(double const aValue, Geometry::Angle const & aAngle) {
    return aAngle * aValue;
}

inline double cos(Geometry::Angle const & aAngle) { return cos(aAngle.Rad()); }

inline double sin(Geometry::Angle const & aAngle) { return sin(aAngle.Rad()); }

inline double tan(Geometry::Angle const & aAngle) { return tan(aAngle.Rad()); }

inline Geometry::Angle fabs(Geometry::Angle const & aAngle) {
    return Geometry::RAD(fabs(aAngle.Rad()));
}

inline Geometry::Angle arccos(double const aValue) { return Geometry::RAD(acos(aValue)); }

inline Geometry::Angle arcsin(double const aValue) { return Geometry::RAD(asin(aValue)); }

inline Geometry::Angle arctan(double const aValue) { return Geometry::RAD(atan(aValue)); }

inline Geometry::Angle arctan2(double const aY, double const aX) { return Geometry::RAD(atan2(aY, aX)); }

inline std::ostream & operator<<(std::ostream & out, Geometry::Angle const & aAngle) {
    out << aAngle.Rad();
    return out;
}

//////////////////////////////////////////////////////////////////////////////////////
// Inline member methods
//////////////////////////////////////////////////////////////////////////////////////

bool const Geometry::Angle::operator==(Geometry::Angle const & aAngle) const {
    double const diff = fabs(Rad()-aAngle.Rad());
    return diff < Geometry::ANGLE_EPSILON;
}

bool const Geometry::Angle::operator!=(Geometry::Angle const & aAngle) const {
    return !((*this)==aAngle);
}

Geometry::Angle & Geometry::Angle::operator=(Geometry::Angle const &aAngle) {
    m_value = aAngle.m_value;
    return *this;
}

Geometry::Angle const Geometry::Angle::operator-() const {
    return Angle(-m_value);
}

Geometry::Angle & Geometry::Angle::operator+=(Angle const & aAngle) {
    m_value += aAngle.m_value;
    return *this;
}

Geometry::Angle & Geometry::Angle::operator-=(Geometry::Angle const & aAngle) {
    m_value -= aAngle.m_value;
    return *this;
}

Geometry::Angle & Geometry::Angle::operator*=(const double &aValue) {
    m_value *= aValue;
    return *this;
}

Geometry::Angle & Geometry::Angle::operator/=(const double &aValue) {
    m_value /= aValue;
    return *this;
}

Geometry::Angle Geometry::Angle::RAD(double const aValue) {
    return Angle(aValue);
}

Geometry::Angle Geometry::Angle::DEG(double const aValue) {
    return Angle(aValue*DEG_TO_RAD);
}

Geometry::Angle Geometry::Angle::DEG100th(double const aValue) {
    return Angle(aValue*0.01*DEG_TO_RAD);
}

Geometry::Angle Geometry::Angle::Modulo2PI(double const aRangeMin) const
{
    double normalizedValue = GetNormalizedValue(m_value, aRangeMin);
    return Angle(normalizedValue);
}

#endif //__ANGLE_H__
