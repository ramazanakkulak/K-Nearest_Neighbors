# K-Nearest-Neighbors-

How does the K-Means algorithm work?

K-NN study can be explained on the basis of the following algorithm:

Step-1: Choose the K number of neighbors

Step-2: Calculate the Euclidean distance of K neighbors

Step-3: According to the calculated Euclidean distance, get the K nearest neighbors.

Step-4: Count the number of data points in each category among these k neighbors.

Step-5: Assign the new data points to the category with the maximum number of neighbors.

Step-6: Our model is ready.


K-Nearest Neighbors C++

The KNN algorithm I designed consists of 2 classes and one inherit class. These classes are as follows:

1.	Data Class (base)
2.	KNN Class (inherit)
3.	Graph	Class (base)
4.	MatPlotLib.cpp

The study was developed on VS code ide. There is also the matplotlib.cpp function developed for plotting over the matplotlib library developed for python. The installation of this file is simple. This file can be accessed via github specified in table 2 step 1[3]. This should be copied to the part where the project files are.The following guidelines should be followed to run this run.

Installing the matplotlib package required for Graph:
MatPlotLib setups steps. (1)Github link (2) Python lib setup, (3) Example run
(1)	https://github.com/lava/matplotlib-cpp

(2)	sudo apt-get install python-matplotlib pythonX-numpy pythonX.X-dev

(3)	g++ example.cpp -I/usr/include/pythonX.X -lpythonX.X

The above 2 steps are performed. Before this process is performed, the python version installed on the Linux (ubuntu) operating system is important in places marked as X in bold. The work was run on python3.8. Then run one of the examples in the file installed from github to test the accuracy of this process. After doing this process, you can go to the directory where you are working via the terminal on the visual code or via the ubuntu terminal with the help of the "cd" command. After navigating to the required directory:


Terminal complier CMake:
(1) g++ main.cpp Data.cpp KNN.cpp Graph.cpp Prim.cpp -std=c++11 -I/usr/include/python3.8 -lpython3.8

This command is typed into the terminal to view the results. The video of the study is given in
(2) ./a.out
