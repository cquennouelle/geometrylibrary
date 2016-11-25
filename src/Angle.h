#ifndef __ANGLE_H__
#define __ANGLE_H__

class Angle
{
public:
	Angle():m_value(0.0) { }
	~Angle() {}

private:
	Angle(double const aValue):m_value(aValue) {}

private:
	double const m_value;

};
#endif //__ANGLE_H__
