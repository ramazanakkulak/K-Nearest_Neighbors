#define _USE_MATH_DEFINES
#include "matplotlibcpp.h"
#include <cmath>
#include <iostream>
#include <string>
#include "Graph.h"
#include <vector>
#include "KNN.h"
#include "Data.h"

namespace plt = matplotlibcpp;
using namespace std;

Graph::Graph(const string n,const KNN &ohm):
        name(n),
        points(ohm)
{
  
}
void Graph::drawPoint()
{
    int k = 0;
    for(int i = 0;i<30;i++)
    {   
        if(i==10)
            k++;
        else if(i==20)
            k++;
        choosePlotCluster(k,i);
    }
    vector<double> z;
    vector<double> x;
    plt::xlabel("Coordinate x");
    plt::ylabel("Coordinate y");
    plt::named_plot("Blue Category 0",x,z,"bs");
    plt::named_plot("Red Category 1",x,z,"r^");
    plt::named_plot("Cyan Category 2",x,z,"cP");
    plt::named_plot("Green Sample",x,z,"go");
    plt::legend();
    tryPointKNN();
    dashPointKNN();
    plt::show();
}
void Graph::tryPointKNN()
{
    vector<double> temp_x,temp_y;
    temp_x.push_back(points.getTryPointX());
    temp_y.push_back(points.getTryPointY());
    plt::plot(temp_x, temp_y, "go");
    temp_x.clear();
    temp_y.clear();
}
void Graph::choosePlotCluster(int number,int i)
{
  vector<double> y;
  vector<double> x;
  switch(number)
  {
    case 0:
      x.push_back(points.getXPoint(i));
      y.push_back(points.getYPoint(i));
      plt::plot(x, y, "bs");
      x.clear();
      y.clear();
      break;
    case 1:
      x.push_back(points.getXPoint(i));
      y.push_back(points.getYPoint(i));
      plt::plot(x, y, "r^");
      x.clear();
      y.clear();
      break;
    case 2:
      x.push_back(points.getXPoint(i));
      y.push_back(points.getYPoint(i));
      plt::plot(x, y, "cP");
      x.clear();
      y.clear();
      break;
    default:
      cout<<"KNN not possible."<<endl;
      break;
  }
}
void Graph::dashPointKNN()
{
    vector<double> tempx,tempy;
    for(int i=0;i<points.getK();i++)
    {
    tempx.push_back(points.vecSecondX(i));
    tempy.push_back(points.vecSecondY(i));
    tempx.push_back(points.getTryPointX());
    tempy.push_back(points.getTryPointY());
    plt::plot(tempx,tempy,"k--");
    tempx.clear();
    tempy.clear();
    }
    points.vecSortClear();
}

string Graph::getName()const
{
    return name;
}

