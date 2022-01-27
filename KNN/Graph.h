#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "KNN.h"
#include "Data.h"
using namespace std;
/** @brief This class is the part where graph operations are done.
    @author RAMAZAN AKKULAK
    @date January 2022
*/
class Graph{
private:
    KNN points;/**Object created from KNN class*/
    string name;/**<trySample x data*/
public:
/** Graph class constructor.
* @param string-Graph class name 
* @param KNN
*/
    Graph(const string,const KNN &);
/** This function is the main function where all operations are done. It first calls 
 * the tryPointKNN function and the dahsPointKNN functions after plotting the data data. 
 * It is the function that visually expresses the KNN algorithm.
*/
    void drawPoint();
/** This function is for separating the set operation and expressing it in different colors.
 * @param int category 0,1 and 2
 * @param int index Point i=0,1,2,3,4...
*/
    void choosePlotCluster(int,int);
/** This function is the function that visualizes the tested sample values as green.
*/
    void tryPointKNN();
/** This function is the function that visualizes the nearest neighbors 
 * with the dash line according to the degree of neighborhood after the sample values are visualized as green.
*/
    void dashPointKNN();
/** This function returns the name of the Graph class.
 *@return  string Graph obje name
*/
    string getName()const;
};

#endif
