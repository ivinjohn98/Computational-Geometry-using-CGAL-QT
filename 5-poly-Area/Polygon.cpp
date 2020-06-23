#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <iostream>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;
typedef CGAL::Polygon_2<K> Polygon;
using namespace std;
int main()
{
  Polygon p;
  p.push_back(Point(0, 0));
  p.push_back(Point(0, 4));
  p.push_back(Point(4, 4));
  p.push_back(Point(4, 0));
  double Area = p.area();
  if(Area<0)
    Area = (-1)*Area;
  cout << Area;
  return 0;
}
