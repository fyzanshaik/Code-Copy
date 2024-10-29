#include<stdio.h>
struct distance
{
    float inch;
    float feet;
}d1,d2,res;
struct distance add_distance( struct distance n1 , struct distance n2 ) {
    res.inch = n1.inch+n2.inch;
    res.feet = n1.feet+n2.feet;
    while ( res.inch >=12 ) {
        res.feet++;
        res.inch -= 12;
    }
    return res;
}
void main() {
    printf("Enter 1st Distance (feet,inch[<12]) : ");
    scanf("%f %f",&d1.feet,&d1.inch);
    printf("Enter 2nd Distance (feet,inch[<12]) : ");
    scanf("%f %f",&d2.feet,&d2.inch);
    add_distance(d1,d2);
    printf("Total Distance is : %f feet , %f inch\n",res.feet,res.inch);
}