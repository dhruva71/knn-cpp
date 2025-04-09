//
// Created by dhruva on 4/9/25.
//

#include "DataPoint.h"

#include <iostream>
#include <cmath>
#include <ostream>
#include <valarray>

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
