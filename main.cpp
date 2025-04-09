#include <iostream>
#include <vector>

#include "DataPoint.h"

int main()
{
    std::cout << "Starting KNN CPP" << std::endl;

    std::vector<DataPoint> dataPoints;

    auto dataPoint1 = new DataPoint({1.0f, 2.0f}, "movie");
    auto dataPoint2 = new DataPoint({3.0f, 4.0f}, "movie");
    dataPoints.push_back(*dataPoint1);
    dataPoints.push_back(*dataPoint2);

    auto dataPoint3 = new DataPoint({0.0f, 0.0f}, "movie");
    double distance = DataPoint::calculateEuclideanDistance(*dataPoint1, *dataPoint3);
    std::cout << "Euclidean distance is " << distance << std::endl;

    return 0;
}