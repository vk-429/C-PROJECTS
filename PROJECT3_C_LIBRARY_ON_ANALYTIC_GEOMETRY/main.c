
// main.c to check if library is working accurately and efficiently

#include<stdio.h>
#include "Library.h"

int main()
{
    struct midPoint p1;
    p1=find_mid_point(1,2,3,4);
    printf("%lf %lf \n",p1.x_coordinate,p1.y_coordinate);
    struct Slope s1;
    s1=find_slope(-5,44);
    if(!s1.error)
        printf("Slope is %lf\n",s1.slope);
    else
        printf("slope is undefined\n");

    bool isperpendicular=is_perpendicular(1,4,-4,1);
    printf("%d \n",isperpendicular);

    bool isparallel=is_parallel(1,4,-1,4);
    printf("%d \n",isparallel);

    double angle=find_angle(1,4,-4,1);
    printf("%lf \n",angle);
    angle=find_angle(1,4,-3,2);
    printf("%lf \n",angle);

    double distance=find_distance(0,2,0,4);
    printf("%lf\n",distance);

    struct Centroid c1;
    c1=centroid_triangle(1,2,3,4,5,6);
    printf("x : %lf y : %lf\n",c1.x_coordinate,c1.y_coordinate);

    double area=area_triangle(0,0,0,2,2,0);
    printf("area : %lf\n",area);

    struct Cartesian c2;
    c2=polar_to_cartesian(1,3.14);
    printf("x : %lf y : %lf\n",c2.x_coordinate,c2.y_coordinate);
    
    struct Polar p2;
    p2=cartesian_to_polar(1,2);
    printf("r : %lf theta : %lf \n",p2.r,p2.angle_radians);
    return 0;
}