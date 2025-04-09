//
// Created by dhruva on 4/9/25.
//

#include "DataPoint.h"

#include <iostream>
#include <cmath>
#include <ostream>
#include <valarray>
#include <sstream>

std::string DataPoint::toString() const
{
    std::ostringstream oss;
    oss << "DataPoint(label: \"" << label << "\", features: [";
    for (size_t i = 0; i < features.size(); ++i)
    {
        oss << features[i];
        if (i != features.size() - 1)
        {
            oss << ", ";
        }
    }
    oss << "])";
    return oss.str();
}

// Calculates Euclidean distance between DataPoint a and Datapoint B
// throws an error if the number of dimensions of the features do not match
double DataPoint::calculateEuclideanDistance(const DataPoint& a, const DataPoint& b)
{
    const auto vector_a = a.features;
    const auto vector_b = b.features;

    // check dimensions
    if (vector_a.size() != vector_b.size())
    {
        std::cerr << "Vectors have different sizes" << std::endl;
        throw std::invalid_argument("Vectors have different sizes");
    }

    double sum_of_diff_square = 0;
    for (size_t i = 0; i < vector_a.size(); i++)
    {
        auto diff = vector_a[i] - vector_b[i];
        sum_of_diff_square += diff * diff;
    }
    return sqrt(sum_of_diff_square);
}

// Find the nearest k neighbours. Calculates distance to all points.
// TODO: optimize this further
std::vector<DataPoint> DataPoint::findKClosestPoints(const DataPoint& datapoint, const std::vector<DataPoint>& dataPoints, int k)
{
    using Neighbour = std::pair<DataPoint, double>;
    std::vector<Neighbour> neighbours;
    neighbours.reserve(dataPoints.size());

    for (const DataPoint& point : dataPoints)
    {
        double distance = calculateEuclideanDistance(datapoint, point);
        neighbours.emplace_back(point, distance);
    }

    // sort by distance
    std::ranges::sort(neighbours, [](const Neighbour& a, const Neighbour& b) {return a.second < b.second;});

    // pick only the first k entries and return them
    neighbours.resize(k);
    std::vector<DataPoint> closestPoints;
    for (size_t i = 0; i < k; i++)
    {
        closestPoints.push_back(neighbours[i].first);
    }
    return closestPoints;
}
