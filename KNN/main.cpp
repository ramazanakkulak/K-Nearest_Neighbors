#include <iostream>
#include <string>
#include <ctime>
#include "Data.h"
#include "KNN.h"
#include "Graph.h"
using namespace std;

int main()
{
    srand(time(0));
    int sample;
    int k;
    int number = 30;/**<data set const is not changed.*/
    cout<<"Enter the number of samples to be tried --> sample: ";
    cin>>sample;
    cout<<"Enter the neighborhood level of KNN --> k: ";
    cin>>k;
    KNN knn("KNN",k,sample,number,k);
    for(int i = 0;i<sample;i++)
    {
        knn.KNNTestSample();
        Graph g("k-nearest neighbors",knn);
        cout<<knn;
        g.drawPoint();
        
    }
    return 0;
}