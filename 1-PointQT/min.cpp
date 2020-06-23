#include <iostream>
#include <boost/format.hpp>
// Qt headers
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QLineF>
#include <QRectF>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
// CGAL headers
#include <CGAL/Qt/PointsGraphicsItem.h>
#include <CGAL/Qt/GraphicsViewPolylineInput.h>
#include <CGAL/Qt/utility.h>
// GraphicsView items and event filters (input classes)
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/point_generators_2.h>
#include <CGAL/Largest_empty_iso_rectangle_2.h>
// the two base classes
#include <QString>
#include <QFileDialog>
#include <QInputDialog>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef K::Vector_2 Vector_2;
typedef K::Segment_2 Segment_2;
#include <string.h>
#include <fstream>
using namespace std;
int main(int argc, char **argv)
{
	CGAL::Qt::PointsGraphicsItem<std::vector<Point_2> > * pgi;
	std::vector<Point_2> points;
	ifstream fin;
	string strline;
	ofstream fout;
	int j = 1, ar[2],i,flag =0;
	char str[100];
	fin.open("input.txt");
	QApplication app(argc, argv);
	QGraphicsScene scene;
	while (fin)
    {
		for (i=0;i<2;i++)
		{
			getline(fin, strline);
			if (fin.eof())
            {
                flag = 1;
				break;
            }
			ar[i] = atoi(strline.c_str());
		}
        if(flag ==1)
            break;
		Point_2 Q(ar[0], ar[1]);
		points.push_back(Q);
	}
	fin.close();
	 pgi = new CGAL::Qt::PointsGraphicsItem<std::vector<Point_2> >(&points);
	pgi->setVerticesPen(QPen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin));
    scene.setSceneRect(0,0, 100, 100);
	scene.addItem(pgi);
    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);
    view->show();
    return app.exec();
}
