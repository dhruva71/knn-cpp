#include <iostream>
#include <vector>

#include "DataPoint.h"
#include "loadcsv.h"

int main()
{
    std::cout << "Starting KNN CPP" << std::endl;

    std::vector<DataPoint> dataPoints = loadCSV();

    auto dataPoint = new DataPoint({0.0f, 0.5f, -0.2f}, "");
    auto closestNeighbours = DataPoint::findKClosestPoints(*dataPoint, dataPoints, 5);
    std::cout << "Printing closest neighbours" << std::endl;
    for (const auto& neighbour : closestNeighbours)
    {
        std::cout << neighbour.toString() << std::endl;
    }

    auto majorityLabel = DataPoint::findMajorityLabel(closestNeighbours);
    std::cout << "New point to have label: " << majorityLabel << std::endl;

    return 0;
}
