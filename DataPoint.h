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

    DataPoint()
    {
        this->features = std::vector<float>();
        this->label = "";
    }
    DataPoint(std::vector<float> features, std::string label)
    {
        this->features = std::move(features);
        this->label = std::move(label);
    }
    std::string toString() const;
    static double calculateEuclideanDistance(const DataPoint &a, const DataPoint &b);
    static std::vector<DataPoint> findKClosestPoints(const DataPoint& datapoint, const std::vector<DataPoint> &dataPoints, int k);
    static std::string findMajorityLabel(const std::vector<DataPoint> &neighbours);
};


#endif //DATAPOINT_H
