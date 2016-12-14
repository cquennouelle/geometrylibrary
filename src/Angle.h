#ifndef __ANGLE_H__
#define __ANGLE_H__
#include "Constants.h"
#include <iostream>
#include <cmath>

/**
 * \file Angle.h
 * \brief Creation of a type Angle.
 * \author Cyril Quennouelle
 * \version 0.1
 * \date 06/12/2016
 * \brief Contains the definition of class Angle
 *
 * \details The main objectives of this class is to remove units problems and to manage periodicity
 *
 */

namespace Geometry
{

/**
 * \brief The Angle class
 */
class Angle
{
public:
    /**
     * \brief Default empty constructor (Value of the angle is zero rad.)
     */
    Angle();

    /**
     * \brief Copy constructor
     */
    Angle(Angle const & angle);

    ~Angle() {}

    /**
     * \brief Get the angle value in radian
     * \return double
     */
    double Rad() const;

    /**
     * \brief Get the angle value in degree.
     * \return double
     */
    double Deg() const;

    /**
     * \brief Get the angle value in 1/100 of degree.
     * \return double
     */
    double Deg100th() const;

    /**
     * \brief Get the angle of neglectible value.
     * \return Angle close to zero.
     */
    static Angle const EPSILON();

    Angle & operator=(Angle const & angle);

    /**
     * \brief IsEqual operator.
     * \remark Angles are equal if difference is smaller than Angle::EPSILON()
     * \return bool
     */
    bool const operator==(Geometry::Angle const & angle) const;

    /**
     * \brief IsNotEqual operator.
     * \remark Angles are equal if difference is smaller than Angle::EPSILON()
     * \return bool
     */
    bool const operator!=(Geometry::Angle const & angle) const;

    Angle const operator-() const;
    Angle & operator+=(Angle const & angle);
    Angle & operator-=(Angle const & angle);
    Angle & operator*=(double const & value);
    Angle & operator/=(double const & value);

    /**
     * @brief Factory method to create an angle.
     * @param value of the angle in radian.
     * @return New angle.
     */
    static Angle RAD(double const value);

    /**
     * @brief Factory method to create an angle.
     * @param Value of the angle in degree.
     * @return New angle.
     */
    static Angle DEG(double const value);

    /**
     * @brief Factory method to create an angle.
     * @param Value of the angle in 1/100 degree.
     * @return New angle.
     */
    static Angle DEG100th(double const value);

    /**
     * @brief Get the equivalent angle in a 2-PI period
     * @param Min value of the period
     * @return Equivalent angle between [offset, offset+2PI[
     */
    Angle Modulo2PI(double const offset = 0.0) const;

private:
    /**
     * @brief Constructor form a double
     * @remark Use forbidden. Use factory method RAD, DEG, etc.
     * @param Angle with a value in radian
     */
    Angle(double const value);

    static double GetNormalizedValue(double const value, double const offset);

private:
    double m_value; //!< Internal value of the angle in Radian.
    static Angle m_EPSILON; //!< Value for comparison between angles
};

inline Angle RAD(double const value) { return Angle::RAD(value); }

inline Angle DEG(double const value) { return Angle::DEG(value); }

inline Angle DEG100th(double const value) { return Angle::DEG100th(value); }

}

inline Geometry::Angle const operator+(Geometry::Angle const & angle, Geometry::Angle const & angle2) {
    return Geometry::Angle(angle)+=angle2;
}

inline Geometry::Angle const operator-(Geometry::Angle const & angle, Geometry::Angle const & angle2) {
    return Geometry::Angle(angle)-=angle2;
}

inline Geometry::Angle const operator*(Geometry::Angle const & angle, double const & value) {
    return Geometry::Angle(angle)*=value;
}
inline Geometry::Angle const operator/(Geometry::Angle const & angle, double const & value) {
    return Geometry::Angle(angle)/=value;
}

inline bool const operator>(Geometry::Angle const & aAngle, Geometry::Angle const & aAngle2) {
    return aAngle.Rad() > aAngle2.Rad();
}

inline bool const operator<(Geometry::Angle const & angle, Geometry::Angle const & angle2) {
    return angle.Rad() < angle2.Rad();
}

inline bool const operator>=(Geometry::Angle const & angle, Geometry::Angle const & angle2) {
    return angle.Rad() >= angle2.Rad();
}

inline bool const operator<=(Geometry::Angle const & angle, Geometry::Angle const & angle2) {
    return angle.Rad() <= angle2.Rad();
}

inline Geometry::Angle operator*(double const value, Geometry::Angle const & angle) {
    return angle * value;
}

/**
 * @brief Overload of cosinus
 * @param Angle
 * @return cos
 */
inline double cos(Geometry::Angle const & angle) {
    return cos(angle.Rad()); }

/**
 * @brief Overload of sinus
 * @param Angle
 * @return sin
 */
inline double sin(Geometry::Angle const & aAngle) {
    return sin(aAngle.Rad()); }

/**
 * @brief Overload of tangent
 * @param Angle
 * @return tan
 */
inline double tan(Geometry::Angle const & angle) {
    return tan(angle.Rad()); }

/**
 * @brief Overload of absolute value
 * @param Angle
 * @return Angle with positive value
 */
inline Geometry::Angle fabs(Geometry::Angle const & angle) {
    return Geometry::RAD(fabs(angle.Rad()));
}

/**
 * @brief Overload of acos to get an angle
 * @param Value of the cosinus
 * @return Angle
 */
inline Geometry::Angle arccos(double const cosinus) {
    return Geometry::RAD(acos(cosinus)); }

/**
 * @brief Overload of asin to get an angle
 * @param Value of the sinus
 * @return Angle
 */
inline Geometry::Angle arcsin(double const sinus) {
    return Geometry::RAD(asin(sinus)); }

/**
 * @brief Overload of atan to get an angle
 * @param Value of the tangent
 * @return Angle
 */
inline Geometry::Angle arctan(double const tangent) {
    return Geometry::RAD(atan(tangent)); }

/**
 * @brief Overload of atan2 to get an angle
 * @param Value of the cosinus
 * @return Angle
 */
inline Geometry::Angle arctan2(double const sinus, double const cosinus) {
    return Geometry::RAD(atan2(sinus, cosinus)); }

/**
 * @brief Overload operator <<
 * @param Ostream out
 * @param Angle aAngle
 * @return Ostream
 */
inline std::ostream & operator<<(std::ostream & out, Geometry::Angle const & angle) {
    out << angle.Rad();
    return out;
}

#endif //__ANGLE_H__
