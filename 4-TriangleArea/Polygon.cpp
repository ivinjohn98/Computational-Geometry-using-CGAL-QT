#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <iostream>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;
typedef CGAL::Triangle_2<K> Triangle;
using namespace std;

int main()
{
    Point P1(0, 0), P2(0, 4), P3(4, 0);
    Triangle T(P1,P2,P3);
    double Area = T.area();
    if(Area<0)
        Area = (-1)*Area;
    cout<<Area;
    return 0;
}
