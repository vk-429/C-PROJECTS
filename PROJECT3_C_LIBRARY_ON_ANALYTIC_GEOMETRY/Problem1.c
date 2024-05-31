// Suppose there are two roads, 
// Road 1: ABC Road, represented by equation 5x + y - 3 = 0 
// Road 2: XYZ Road, represented by equation 2x + 3y + 1 = 0 
// These two roads meet each other at a chowk, called 123 Chowk. 
// Determine at which angle , these two roads meet each other at chowk. 
// What you have to do : 
// Create a Program which determines angle at which these roads meet at 123 Chowk.

#include<stdio.h>
#include "Library.h"

int main()
{
    double x1,y1,x2,y2;
    double angle_at_chowk;
    printf("Enter the x and y coefficients of the line, represents the Road ABC : ");
    scanf("%lf %lf",&x1,&y1);
    printf("Enter the x and y coefficients of the line, represents the Road XYZ : ");
    scanf("%lf %lf",&x2,&y2);
    angle_at_chowk=find_angle(x1,y1,x2,y2);
    printf("The angle at which both roads meet at chowk : %lf Degrees",angle_at_chowk);
    return 0;
}