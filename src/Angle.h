#ifndef __ANGLE_H__
#define __ANGLE_H__
#include "Constants.h"
#include <iostream>

namespace Geometry
{
class Angle
{
public:
    Angle():m_value(0.0) {}
    ~Angle() {}

    double Rad() const { return m_value; }
    double Deg() const { return m_value * RAD_TO_DEG; }
    double Deg100th() const { return m_value * RAD_TO_DEG * 100.0; }
    static Angle const EPSILON() { return m_EPSILON; }

    Angle & operator=(Angle const & aAngle);

    bool operator==(Angle const & aAngle) const;
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

inline std::ostream & operator<<(std::ostream & out, Angle const & aAngle)
{
    out << aAngle.Rad();
    return out;
}
}
#endif //__ANGLE_H__
