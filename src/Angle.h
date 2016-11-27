#ifndef __ANGLE_H__
#define __ANGLE_H__
#include "Constants.h"
#include <iostream>
#include <cmath>

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

    Angle & operator=(Angle const & aAngle);

    Angle operator-() const;
    Angle & operator+=(Angle const & aAngle);
    Angle & operator-=(Angle const & aAngle);
    Angle & operator*=(double const & aValue);
    Angle & operator/=(double const & aValue);

    Angle operator+(Angle const & aAngle) const;
    Angle operator-(Angle const & aAngle) const;
    Angle operator*(double const & aValue) const;
    Angle operator/(double const & aValue) const;

    bool operator==(Angle const & aAngle) const;
    bool operator!=(Angle const & aAngle) const;
    bool operator>(Angle const & aAngle) const;
    bool operator<(Angle const & aAngle) const;
    bool operator>=(Angle const & aAngle) const;
    bool operator<=(Angle const & aAngle) const;

    static Angle RAD(double const aValue);
    static Angle DEG(double const aValue);
    static Angle DEG100th(double const aValue);

    Angle Modulo2PI() const;
    Angle Module2PI_0() const;

private:
    Angle(double const aValue):m_value(aValue) {}

    static double GetNormalizedValue(double const aValue);

private:
    double m_value;
    static Angle m_EPSILON;

};

inline Angle RAD(double const aValue) { return Angle::RAD(aValue); }
inline Angle DEG(double const aValue) { return Angle::DEG(aValue); }
inline Angle DEG100th(double const aValue) { return Angle::DEG100th(aValue); }

}

inline Geometry::Angle operator*(double const aValue, Geometry::Angle const & aAngle)
{
    return aAngle*aValue;
}

inline double cos(Geometry::Angle const & aAngle)
{
    double const value = aAngle.Rad();
    return cos(value);
}

inline double sin(Geometry::Angle const & aAngle)
{
    double const value = aAngle.Rad();
    return sin(value);
}

inline double tan(Geometry::Angle const & aAngle)
{
    double const value = aAngle.Rad();
    return tan(value);
}

inline Geometry::Angle fabs(Geometry::Angle const & aAngle)
{
    double const value = aAngle.Rad();
    return Geometry::RAD(fabs(value));
}

inline Geometry::Angle arccos(double const aValue)
{
    double const value = acos(aValue);
    return Geometry::RAD(fabs(value));
}

inline Geometry::Angle arcsin(double const aValue)
{
    double const value = asin(aValue);
    return Geometry::RAD(value);
}

inline Geometry::Angle arctan(double const aValue)
{
    double const value = atan(aValue);
    return Geometry::RAD(value);
}

inline Geometry::Angle arctan2(double const aY, double const aX)
{
    double const value = atan2(aY, aX);
    return Geometry::RAD(value);
}

inline std::ostream & operator<<(std::ostream & out, Geometry::Angle const & aAngle)
{
    out << aAngle.Rad();
    return out;
}
#endif //__ANGLE_H__
