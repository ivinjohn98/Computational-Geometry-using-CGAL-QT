#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <iostream>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;
typedef  CGAL::Segment_2 <K> Segment;
using std::cout; using std::endl;


int main()
{
  Point P1(0, 0), P2(4, 4), P3(5, 5),P4(0, 0);
  Segment  S1(P1, P2), S2(P3, P4);
  CGAL::Object result = CGAL::intersection(S1, S2);
  Point point;
  Segment segment;
  if (CGAL::assign(point, result))
    cout << "point intersect" << endl;
  else
if(CGAL::assign(segment, result))
    cout << "segment intersect" << endl;
  return 0;
}
