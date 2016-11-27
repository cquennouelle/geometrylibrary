#ifndef __ANGLE_H__
#define __ANGLE_H__
#include "Constants.h"

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
    Angle & operator=(Angle const & aAngle) { m_value = aAngle.m_value; return *this; }

    bool operator==(Angle const aAngle) const;

    static Angle RAD(double const aValue);
    static Angle DEG(double const aValue);
    static Angle DEG100th(double const aValue);

private:
    Angle(double const aValue):m_value(aValue) {}

private:
    double m_value;

};

inline Angle RAD(double const aValue) { return Angle::RAD(aValue); }
inline Angle DEG(double const aValue) { return Angle::DEG(aValue); }
inline Angle DEG100th(double const aValue) { return Angle::DEG100th(aValue); }

}
#endif //__ANGLE_H__
