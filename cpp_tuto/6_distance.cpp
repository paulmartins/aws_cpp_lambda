#include <iostream>
#include <chrono> 
#include <math.h>
#include <vector>

double distance(double x1, double y1, double x2, double y2){
	return sqrt(pow((x2-x1),2) + pow((y2-y1),2));
}

int main()
{
    // Generate random points
    int size = 20000;

    double* x1 = new double[size];
    double* y1 = new double[size];
    double* x2 = new double[size];
    double* y2 = new double[size];
     
    for(unsigned int i=0; i<size; i++){ 
        x1[i] = (rand()%1000)+1; 
        x2[i] = (rand()%1000)+1; 
        y1[i] = (rand()%1000)+1; 
        y2[i] = (rand()%1000)+1; 
    } 
    //std::cout << "Finish generating random points : x1=" << x1[0] << ", y1=" << y1[0] << ", x2=" << x2[0] << ", y2=" << y2[0] << std::endl;

    double* dist_results = new double[size];

	auto start = std::chrono::high_resolution_clock::now();

    for(unsigned int i=0; i < size-1; i++){
    	for(int j=i+1; j<size; j++){
			dist_results[i] = (distance(x1[i], y1[i], x2[j], y2[j]));
    	}
    }

    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "Finish calculating distances: dist=" << dist_results[0] << std::endl;
	std::cout << "Elapsed time: " << elapsed.count() << " s\n";


    return 0;
}