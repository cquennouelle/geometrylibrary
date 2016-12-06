namespace Geometry
{
    // Fundamental constant
    static double const PI = 3.141592653589793238462643383279;
    static double const ANGLE_EPSILON = 1e-14;

    // Variations of fundamental constants
    static double const TWO_PI = 2.0 * PI;

    // Conversions
    static double const DEG_TO_RAD = PI / 180.0;
    static double const RAD_TO_DEG = 180.0 / PI;
    static double const DEG100TH_TO_RAD = DEG_TO_RAD * 0.01;
    static double const RAD_TO_DEG100TH = RAD_TO_DEG * 100.0;
}
