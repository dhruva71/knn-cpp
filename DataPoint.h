//
// Created by dhruva on 4/9/25.
//

#ifndef DATAPOINT_H
#define DATAPOINT_H
#include <string>
#include <utility>
#include <vector>


struct DataPoint {
    std::vector<float> features;
    std::string label;

    DataPoint(std::vector<float> features, std::string label)
    {
        this->features = std::move(features);
        this->label = std::move(label);
    }

    static double calculateEuclideanDistance(const DataPoint &a, const DataPoint &b);
};


#endif //DATAPOINT_H
