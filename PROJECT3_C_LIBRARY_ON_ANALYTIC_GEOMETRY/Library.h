// Library.h
// Header guard to prevent multiple inclusions of the header file
#ifndef LIBRARY_H
#define LIBRARY_H
#include<math.h> // Standard library for mathematical functions
#include<stdbool.h> // Standard library for boolean type and values

// Structure to represent the slope of a line and an error flag
struct Slope
{
    double slope;
    int error;
};

// Structure to represent the midpoint of two given points
struct midPoint
{
    double x_coordinate;
    double y_coordinate;
};

// Structure to represent the centroid of a triangle
struct Centroid
{
    double x_coordinate;
    double y_coordinate;
};

// Structure to represent polar coordinates of a point
struct Polar
{
    double r;
    double angle_radians;
};

// Structure to represent Cartesian coordinates of a point
struct Cartesian
{
    double x_coordinate;
    double y_coordinate;
};


// Function prototypes for various geometric calculations
struct Slope find_slope(double a,double b);
bool is_perpendicular(double a1,double b1,double a2,double b2);
bool is_parallel(double a1,double b1,double a2,double b2);
double find_angle(double a1,double b1,double a2,double b2);
double find_distance(double x1,double y1,double x2,double y2);
struct midPoint find_mid_point(double x1,double x2,double y1,double y2);
int find_quadrant(double x,double y);
struct Centroid centroid_triangle(double x1,double y1,double x2,double y2,double x3,double y3);
bool is_triangle(double x1,double y1,double x2,double y2,double x3,double y3);
double area_triangle(double x1,double y1,double x2,double y2,double x3,double y3);
double area_rectangle(double length,double breadth);
double area_square(double side_length);
double area_trapezium(double a,double b,double h);
double area_parallelogram(double b,double h);
double area_rhombus(double d1,double d2);
double area_regular_polygon(int n,double s);
double area_circle(double radius);
double area_circle_sector(double r,double angle_radians);
double area_ellipse(double a,double b);
double perimeter_triangle(double x1,double y1,double x2,double y2,double x3,double y3);
double perimeter_rectangle(double length,double breadth);
double perimeter_square(double side_length);
double circumference_circle(double radius);
double perimeter_regular_polygon(int n,double s);
struct Polar cartesian_to_polar(double x,double y);
struct Cartesian polar_to_cartesian(double r,double angle);

#endif // LIBRARY_H
