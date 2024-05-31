#include<math.h> // Standard library for mathematical functions
#include<stdbool.h> // Standard library for boolean type and values
#include "Library.h" // Custom header file for the library (contains relevant definitions and declarations)

// MACRO definitions
#define PI 3.14159265
#define ORIGIN 0
#define FIRST_QUADRANT 1
#define SECOND_QUADRANT 2
#define THIRD_QUADRANT 3
#define FOURTH_QUADRANT 4 
#define POSITIVE_X_AXIS 5
#define NEGATIVE_X_AXIS 6
#define POSITIVE_Y_AXIS 7
#define NEGATIVE_Y_AXIS 8


// Function to find the slope of a line 
// General equation of line : ax + by +c = 0 
// a - coefficient of x in the general equation of line 
// b - coefficient of y in the general equation of line 

struct Slope find_slope(double a,double b)
{
    struct Slope s1;
    s1.error=0;
    if(a==0) s1.error=1; // Error if the line is vertical
    s1.slope=(-b/a);
    return s1;
}

// Function to check if two lines are perpendicular to each other 
// Line 1 : a1x + b1y + c1 = 0
// Line 2 : a2x + b2y + c2 = 0
// Product of slopes is -1 for perpendicular lines
bool is_perpendicular(double a1,double b1,double a2,double b2)
{
    struct Slope s1,s2;
    s1=find_slope(a1,b1);
    s2=find_slope(a2,b2);
    if(!s1.error && !s2.error)
        return (s1.slope*s2.slope == -1);
    else if((s1.error && s2.slope==0) || (s1.slope==0 && s2.error))
        return true; // Vertical and horizontal lines are perpendicular
    return false;
}

// Function to check if two lines are parallel to eah=ch other
// Slopes of two parallel lines is equal
bool is_parallel(double a1,double b1,double a2,double b2)
{
    struct Slope s1,s2;
    s1=find_slope(a1,b1);
    s2=find_slope(a2,b2);
    if(!s1.error && !s2.error)
        return (s1.slope == s2.slope);
    else if(s1.error && s2.error) return true; // Both lines are vertical
    return false;
}

// Funtion to find angle between two lines
// Formula to calculate acute angle between two lines : arctan((m2-m1)/(1+m1*m2))
// m1 - slope of line 1, m2 - slope of line 2
double find_angle(double a1,double b1,double a2,double b2)
{
    struct Slope s1,s2;
    double angle=0.0;
    s1=find_slope(a1,b1);
    s2=find_slope(a2,b2);
    if(is_perpendicular(a1,b1,a2,b2)) // Perpendicular
        return 90.00;
    else if(is_parallel(a1,b1,a2,b2)) // Parallel
        return 0.00;
    else
    {
        
        angle=atan((s2.slope-s1.slope)/(1+(s1.slope*s2.slope)));
        angle=(angle*180.0)/PI; // Convert to degrees
        return fabs(angle);
    }
}

// Function to find distance between two points (x1,y1) and (x2,y2)
double find_distance(double x1,double y1,double x2,double y2)
{
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

// Function to calculate mid point of two points (x1,y1) and (x2,y2) 
struct midPoint find_mid_point(double x1,double x2,double y1,double y2)
{
    struct midPoint p1;
    p1.x_coordinate=(x1+x2)/2;
    p1.y_coordinate=(y1+y2)/2;
    return p1;
}

// Function to locate a point (x,y) in cartesian plane
int find_quadrant(double x,double y)
{
    if(x>0 && y>0) return FIRST_QUADRANT;
    else if(x<0 && y>0) return SECOND_QUADRANT;
    else if(x<0 && y<0) return THIRD_QUADRANT;
    else if(x>0 && y<0) return FOURTH_QUADRANT;
    else if(x>0 && y==0) return POSITIVE_X_AXIS;
    else if(x<0 && y==0) return NEGATIVE_X_AXIS;
    else if(x==0 && y>0) return POSITIVE_Y_AXIS;
    else if(x==0 && y<0) return NEGATIVE_Y_AXIS;
    else return ORIGIN;
    
}

// Function to find centroid of a triangle with coordinates of vertices as (x1,y1), (x2,y2) and (x3,y3)
struct Centroid centroid_triangle(double x1,double y1,double x2,double y2,double x3,double y3)
{
    struct Centroid c1;
    c1.x_coordinate=(x1+x2+x3)/3;
    c1.y_coordinate=(y1+y2+y3)/3;
    return c1;
}

// Funtion to check whether three given points form a valid triangle 
bool is_triangle(double x1,double y1,double x2,double y2,double x3,double y3)
{
    double ab=find_distance(x1,y1,x2,y2);
    double bc=find_distance(x2,y2,x3,y3);
    double ca=find_distance(x3,y3,x1,y1);
    if((ab+bc>ca) && (bc+ca>ab) && (ca+ab>bc)) 
        return true;
    return false;
}

// Function to find the area of a trinagle, given it's vertices 
double area_triangle(double x1,double y1,double x2,double y2,double x3,double y3)
{
    if(is_triangle(x1,y1,x2,y2,x3,y3))
        return fabs((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2)))/2.0;
    return 0.0;
}

// Function to find area of rectangle
double area_rectangle(double length,double breadth)
{
    return length*breadth;
}

// Function to find area of sqare
double area_square(double side_length)
{
    return side_length*side_length;
}

// Function to find area of trapezium
// a, b - lengths of parallel sides of the triangle
// h - perpedicular distance between the parallel sides
double area_trapezium(double a,double b,double h)
{
    return ((a+b)*h)/2.0;
}

// Function to find the area of a parallelogram
// b - base length, h - height
double area_parallelogram(double b,double h)
{
    return b*h;
}

// Function to find the area of a rhombus
// d1 - length of main diagonal
// d2 - length of anti-diagonal
double area_rhombus(double d1,double d2)
{
    return (d1*d2)/2.0;
}

// Function to find the area of a regular polygon
// n - no. of sides, s - length of each side
double area_regular_polygon(int n,double s)
{
    return (double)(n*s*s)/(4*tan(PI/n));
}

// Function to find area of circle
double area_circle(double radius)
{
    return (PI*radius*radius);
}

// Function to find the area of a sector of a circle given its radius and central angle in radians
// r - radius of circle, angle_radians - central angle in radians 
double area_circle_sector(double r,double angle_radians)
{
    return (r*r*angle_radians)/2.0;
}

// Function to find area of an ellipse
// a - semi-major axis, b - semi-minor axis
double area_ellipse(double a,double b)
{
    return PI*a*b;
}

// Function two find perimeter of a triangle with coordinates of vertices as (x1,y1), (x2,y2), (x3,y3)
// Perimeter = sum of lengths of each side
double perimeter_triangle(double x1,double y1,double x2,double y2,double x3,double y3)
{
    if(is_triangle(x1,y1,x2,y2,x3,y3))
        return find_distance(x1,y1,x2,y2)+find_distance(x2,y2,x3,y3)+find_distance(x3,y3,x1,y1);
    return -1.0;
}

// Function to calculate perimeter of a rectangle
double perimeter_rectangle(double length,double breadth)
{
    return 2.0*(length+breadth);
}

// Function to calculate perimeter of a square
double perimeter_square(double side_length)
{
    return 4.0*side_length;
}

// Function to calculate circumference of a circle
double circumference_circle(double radius)
{
    return (2.0*PI*radius);
}

// Function to calculate perimeter of a regular polygon
double perimeter_regular_polygon(int n,double s)
{
    return (double)(n*s);
}

// Function to convert cartesian coordinates(x,y) of a point into polar coordinates(r,Θ)
struct Polar cartesian_to_polar(double x,double y)
{
    struct Polar p1;
    p1.r=sqrt((x*x)+(y*y));
    p1.angle_radians=atan(y/x);
    return p1;
}

// Function to convert polar coordinates(r,Θ) of a point into cartecian coordinates(x,y)
struct Cartesian polar_to_cartesian(double r,double angle)
{
    struct Cartesian c1;
    c1.x_coordinate=r*cos(angle);
    c1.y_coordinate=r*sin(angle);
    return c1;
}