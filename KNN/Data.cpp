#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <ostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Data.h"
using namespace std;

static int i = 0;
Data::Data(const string& n,int &K,int &sample,int &numbers):name(n),k(K),sample_(sample),number(numbers)
{
    randomKNNCalculator();      
}
void Data::randomKNNCalculator()
{
    setCategory();
    setXYCategory();
}
//
void Data::setXYCategory()
{
    srand(time(NULL));
    P temp[30];
    for(int i = 0; i<30; ++i){
        temp[i].x = (double)rand()/(RAND_MAX) +(rand()%10)-5;
        temp[i].y = (double)rand()/(RAND_MAX) +(rand()%10)-5;
        temp[i].category = getCategory(i);
        Point.insert(make_pair(i,temp[i]));
    }
}
void Data::setCategory()
{
    vector<int>temp(30,0);
    generate(temp.begin(),temp.end(),gTCategory);
    indexCategory = temp;
}
int Data::getCategory(int i)
{
    return indexCategory[i];
}
//generate category
int Data::gTCategory(void)
{
    static int i = 0;
	int hold;
	if (i<10)
		hold=0;
	else if (i<20)
		hold=1;
	else 
		hold=2;
  	i++; 
	return hold; 
}
Data::~Data()
{
    //empty body
}
void Data::setDistance(int i,double d)
{
    Point[i].distance = d;
}
double Data::getXPoint(int i)
{
    return Point[i].x;
}
double Data::getYPoint(int i)
{
    return Point[i].y;
}
void Data::sortDistance()
{
    map<int, P> :: iterator it2;
    for (it2=Point.begin(); it2!=Point.end(); it2++)
        vec.push_back(make_pair(it2->first, it2->second));
    sort(vec.begin(),vec.end(),comparison);   
    printSortVec();
    vec.clear();
}
bool Data::comparison(const pair<int, P> &a, 
               const pair<int, P> &b)
{
    return (a.second.distance < b.second.distance);
}
int Data::getPoint(int i)
{
    cout<<vec[i].second.category<<endl;
    return 0;
}
void Data::printPoint()
{
    for(int i = 0; i<30;i++)
        cout<<i<<" x: "<<Point[i].x<<"   y: "<<Point[i].y<<"    Category: "<<Point[i].category
                <<" Distance: "<<Point[i].distance<<endl;
}
void Data::changingVecIndex()
{
    for(int i = 0; i<30;i++)
        vec[i].first = i;
}
void Data::printSortVec()
{
    changingVecIndex();
    for(int i = 0; i<30;i++)
        cout<<vec[i].first<<" x: "<<vec[i].second.x<<"   y: "<<vec[i].second.y<<"    Category: "
                <<vec[i].second.category<<" d: "<<vec[i].second.distance<<endl;
}
int Data::selectCategory()
{
    int freq1 = 0;     // Frequency of group 0
    int freq2 = 0;     // Frequency of group 1
    int freq3 = 0;     // Frequency of group 2
    if(vecSort.size()>0)
        vecSort.clear();
    for(int i=0;i<k;i++)vecSort.push_back(make_pair(vec[i].second.x,vec[i].second.y));

    for (int i = 0; i < getK(); i++)
    {
        if (vec[i].second.category == 0)
            freq1++;
        else if (vec[i].second.category  == 1)
            freq2++;
        else if (vec[i].second.category  == 2)
            freq3++;
    }  
    cout<<"Category 0: "<<freq1<<"\nCategory 1: "<<freq2<<"\nCategory 2:"<<freq3;
    int enbuyuk = freq1;
    int c;
    if(enbuyuk<=freq2 && freq2>=freq3)
        c = 1;
    else if(enbuyuk<=freq3 && freq3>=freq2)
        c = 2;
    else 
        c = 0;
    sampleCategory = c;
    return c;
}
double Data::vecSecondX(int i)
{
    return vecSort[i].first; 
}
double Data::vecSecondY(int i)
{
    return vecSort[i].second; 
}
void Data::vecSortClear()
{
    vecSort.clear();
}
int Data::getSampleCategory()
{
    return sampleCategory;
}
int Data::getK()const
{
    return k;
}
int Data::getSample()const
{
    return sample_;
}
ostream &operator<<(ostream &output ,const Data &nodeObje)
{
    output << "********************************************\n\nThe points of the KNN Result"<<endl;
    for(int i = 0; i<nodeObje.getK();i++)
        output<<i<<" x: "<<nodeObje.vec[i].second.x<<"   y: "<<nodeObje.vec[i].second.y<<"    Category: "<<nodeObje.vec[i].second.category
                <<" Distance: "<<nodeObje.vec[i].second.distance<<endl;
    return output;
}
