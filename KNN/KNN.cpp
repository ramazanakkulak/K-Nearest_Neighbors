#include <string>
#include <map>
#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>
#include "Data.h"
#include "KNN.h"
using namespace std;

KNN::KNN(const string& n, int &K_temp,int &s,int &number,int &K_):Data(n,K_temp,s,number)
{
    K = K_;
}
void KNN::setAttemptPoint(double a,double b)
{
    tryPoint.x = a;
    tryPoint.y = b;
    tryPoint.k = K;
    v_Point.push_back(tryPoint);
    classifyAPoint(v_Point);
    v_Point.clear();

}
void KNN::classifyAPoint(vector<attempt> p)
{

    for (int i = 0; i < 30; i++){
        //cout<<p[0].x<<" ";
        double temp_distance = sqrt((getXPoint(i) - p[0].x) * (getXPoint(i) -  p[0].x) +
                                     (getYPoint(i) -  p[0].y) * (getYPoint(i) -  p[0].y));
        //cout<<temp_distance<<" "<<endl;
        setDistance(i,temp_distance);
    } 
}
double KNN::getTryPointX()const
{
    return tryPoint.x;
}

double KNN::getTryPointY()const
{
    return tryPoint.y;
}

int KNN::getTryPointK()const
{
    return tryPoint.k;
}
void KNN::KNNTestSample()
{
    srand(time(NULL));
    printPoint();
    setAttemptPoint(((double)rand()/(RAND_MAX) +(rand()%10)-5),((double)rand()/(RAND_MAX) +(rand()%10)-5));
    cout<<endl<<endl;
    sortDistance();
    int category = selectCategory();
    cout<<"\nSELECTED CATEGORY --> "<<getSampleCategory()<<endl;
}
int KNN::getK()
{
    return K;
}

KNN::~KNN()
{
    //empty body
}

