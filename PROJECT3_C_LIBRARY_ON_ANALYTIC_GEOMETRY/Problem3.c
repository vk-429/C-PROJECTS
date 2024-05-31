// Refer Problem3.png for image of this problem
// Looking at an above image, actually that image is zoomed up version of pdf file.
// As we see there is ‘A’ shaped character, it has three vertices which has coordinates 
// (20.077, 11.598) , (26.526, 90.138) , (23.674, 32.579).
// We have to cover the area under ‘A’ shaped character and colour it black. 
// Calculate area under ‘A’ shaped character

#include<stdio.h>
#include "Library.h"

int main()
{
    double x1,y1,x2,y2,x3,y3;
    double area_under_A;
    printf("Enter coordinates of 1st vertex : ");
    scanf("%lf %lf",&x1,&y1);
    printf("Enter coordinates of 2nd vertex : ");
    scanf("%lf %lf",&x2,&y2);
    printf("Enter coordinates of 3rd vertex : ");
    scanf("%lf %lf",&x3,&y3);
    area_under_A=area_triangle(x1,y1,x2,y2,x3,y3);
    printf("Area to be coloured black : %lf Units\n",area_under_A);
    return 0;
}