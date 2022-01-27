#ifndef KNN_H
#define KNN_H
#include <string>
#include <map>
#include <vector>
#include "Data.h"
using namespace std;
/** @brief This class is the class in which the KNN calculation is made. This class is inherited from Data class.
    @author RAMAZAN AKKULAK
    @date January 2022
*/

class KNN:public Data{
private:
    struct attempt/**<The sample is the struct that will hold the x,y and k values.*/
    {
       double x;/**<trySample x data*/
       double y;/**<trySample y data*/
       int k;/**<trySample k data*/
    };
    attempt tryPoint;/**<tryPoint is holding x,y,k values*/
    int K;/**<KNN neighborhood degree*/
    int randomNumber;
    vector<attempt> v_Point;/**<v_Point vector*/

public:
/** KNN class constructor.
* @param string-KNN class name 
* @param int-k = neighborly relations for data point
* @param int-How many points will be produced and tested for the KNN algorithm
* @param int-k = neighborly relations for data point
* @param int-k = neighborly relations for data point
*/
    KNN(const string&, int &,int &, int &, int &);
/** This function writes the generated point x,y and k values into the struct and pushes them to the v_Point vector.
* @param double a
* @param double b
*/
    void setAttemptPoint(double,double);
/** This function calculates the distance between 2 points and processes the set_Distance function.
* @param vector
*/
    void classifyAPoint(vector<attempt> p);

/** This function returns the x value of the tested value.
* @return double
*/
    double getTryPointX()const;
/** This function returns the y value of the tested value.
* @return double
*/
    double getTryPointY()const;
/** This function returns the k value of the tested value.
* @return double
*/
    int getTryPointK()const;
/** This function is the part where the functions required for the sample to be tried are run sequentially.
*/
    void KNNTestSample();
/** This function returns the k value of the KNN class.
*/
    int getK();
/** KNN class destructor.
*/
    ~KNN();
};
#endif