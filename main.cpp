#include <iostream>
#include <vector>

#include "DataPoint.h"

int main()
{
    std::cout << "Starting KNN CPP" << std::endl;

    std::vector<DataPoint> dataPoints;

    auto dataPoint1 = new DataPoint({1.0f, 2.0f}, "movie");
    auto dataPoint2 = new DataPoint({3.0f, 4.0f}, "game");
    auto dataPoint3 = new DataPoint({-1.0f, -2.0f}, "game");
    auto dataPoint4 = new DataPoint({-2.0f, 0.0f}, "game");
    auto dataPoint5 = new DataPoint({-1.0f, -0.5f}, "movie");
    dataPoints.push_back(*dataPoint1);
    dataPoints.push_back(*dataPoint2);
    dataPoints.push_back(*dataPoint3);
    dataPoints.push_back(*dataPoint4);
    dataPoints.push_back(*dataPoint5);

    auto dataPoint = new DataPoint({0.0f, 0.0f}, "movie");
    auto closestNeighbours = DataPoint::findKClosestPoints(*dataPoint, dataPoints, 3);
    std::cout << "Printing closest neighbours" << std::endl;
    for (const auto& neighbour : closestNeighbours)
    {
        std::cout << neighbour.toString() << std::endl;
    }

    auto majorityLabel = DataPoint::findMajorityLabel(closestNeighbours);
    std::cout << "New point to have label: " << majorityLabel << std::endl;

    return 0;
}
