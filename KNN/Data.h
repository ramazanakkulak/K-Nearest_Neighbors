#ifndef DATA_H
#define DATA_H
#include <string>
#include <map>
#include <ostream>
#include <vector>
using namespace std;
/** @brief The Data is a class that holds, reads or generates data points required for implementing the KNN algorithm.
    @author RAMAZAN AKKULAK
    @date January 2022
*/
class Data{
friend ostream &operator<<(ostream & ,const Data &);
private:
    struct P{
        double x;/**<Point x data*/
        double y;/**<Point y data*/
        int category;/**<Point category data*/
        double distance = 0;/**<Point distance data, default 0*/
    };struct P data/**<struct P,its holding x,y,category and distance*/;
    string name;/**<Data class name*/
    int number;/**<Data class point number*/
    int k;/**<k = neighborly relations for data points*/
    map<int,P> Point;/**< <index, Point(x,y),category and distance> , (P struct)*/
    int sample_;/**<How many points will be produced and tested for the KNN algorithm*/
    int sampleCategory;/**<It keeps the value of which cluster the sample points tried as a result of the KNN algorithm belong to.*/
    vector<int> indexCategory;/**<Category is the vector holding the values 0,1 and 2*/
    vector<pair<int, P>> vec;/**<Point vector is the vector that will keep the sorting process according 
                                to the distance results according to the sample value given.*/
    vector<pair<double,double> > vecSort;/**<Point vector is the vector that keeps how many points will be taken according to the
                                            k value after the distance sorting. It was used in the vector graph operation.*/

//
//
//

/** This function (hidden) should be used if we want to create a random dataset. Necessary settings should be made in Constructr.
*/
    void setXYCategory();
/** This function sets the required category of the (hidden) dataset.
*   category 0, category 1, category 2
*/
    void setCategory();

public:
/** Data class constructor.
* @param string-Data class name 
* @param k-k = neighborly relations for data point
* @param sample-How many points will be produced and tested for the KNN algorithm
* @param number-How many points 
*/
    Data(const string &,int &,int &,int &);
/** This function returns the desired x value of the generated Point data.
*@param int index for example; 1,2,3,4...
*@return double 
*/
    double getXPoint(int);
/** This function returns the desired y value of the generated Point data.
*@param int index for example; 1,2,3,4...
*@return double 
*/
    double getYPoint(int);
/** This function returns the desired category value of the generated Point data.
*@param int index for example; 1,2,3,4...
*@return int 
*/
    int getCategory(int);
/** This function performs a random KNN calculation designed for the user to run on data consisting of random values. 
 * This function executes setCategory() and setXYCategory() functions. This function does not perform a clustering operation, 
 * it only generates x,y points efficiently and obtains data.
*/
    void randomKNNCalculator();

/** This function is the function that updates the Point distance value after the distance calculation is made. 
 * The distance calculation between 2 points was made in the KNN class.
 *@param int index for example; Point[1],2,3,4
 *@param double distance = sqrt((x2-x1)^2 +(y2-y1)^2)
*/
    void setDistance(int,double);

/** This function is a function that will compare the algorithm "sort" function. Returns true and false.
 *@param pair const pair<int, P>
 *@param pair const pair<int, P>
 *@return bool 1 or 0
*/
    static bool comparison(const pair<int, P> &a,const pair<int, P> &b);
/** This function is the function that returns the category part of the algorithm generate function.
 *@param void
*/
    static int gTCategory(void);
/** This function is written for algorithm accuracy by performing the count function.
 *@param int cout<<vec[i].second.category<<endl;
 *@return 0
*/
    int getPoint(int);
/** This function is the part where the sort short function operations are made.
*/
    void sortDistance();
/** This function comes mixed after sorting, so it updates the index. map<int,P> Point --> (int value)
*/
    void changingVecIndex();
/** This function counts the lowest k values according to the given neighborhood level.
 *  This function results in a value of up to 0.1 or 2.
* @return int
*/
    int selectCategory();
/** This function prints all the values of the map<int,P> Point.
*/
    void printPoint();
/** This function displays the vector retained after the sort operation of the map<int,P> Point.
 *  This function prints all the values of the sort Point.
*/
    void printSortVec();
/** This function returns the first value of the sort vector.
 *@param int index for example 1,2,3,4...
 *@return double 
*/
    double vecSecondX(int);
/** This function returns the second (x,y,distance etc...) value of the sort vector.
 *@param int index for example 1,2,3,4...
 *@return double 
*/
    double vecSecondY(int);
/** This function clears the dating vector. Since values will be calculated for each different sample, 
 * 30 sample values of the vector need to be deleted.
*/    
    void vecSortClear();
/** This function returns the set after the set find operation (select Category()).
 *@return int
*/ 
    int getSampleCategory();
/** Data class destructor.
*/ 
    ~Data();
/** This function returns K value
 *@return int
*/ 
    int getK()const;
/** This function returns sample
 *@return int
*/ 
    int getSample()const;
};
#endif