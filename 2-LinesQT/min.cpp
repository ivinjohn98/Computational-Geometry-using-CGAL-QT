#include <iostream>
#include <boost/format.hpp>
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QLineF>
#include <QRectF>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <string.h>
#include <fstream>
using namespace std;
int main(int argc, char **argv)
{
	ifstream fin;
	ofstream fout;
	string strline;
	int i,j = 1,arr[4],flag = 0;
	char str[100];
	fin.open("input.txt");
	QApplication app(argc, argv);
	QGraphicsScene scene;
	while (fin)
    {
		for(i=0;i<4;i++)
        {
			getline(fin, strline);
			if (fin.eof())
            {
                flag=1;
                break;
            }
			arr[i] = atoi(strline.c_str());
		}
		if(flag == 1)
            break;
		scene.addLine(QLineF(arr[0],arr[1],arr[2],arr[3]));
	}
	fin.close();
    scene.setSceneRect(0,0, 100, 100);
    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);
    view->show();
    return app.exec();
}
