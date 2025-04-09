//
// Created by dhruva on 4/9/25.
//
#include <fstream>
#include <sstream>
#include "loadcsv.h"

#include <iostream>

std::vector<DataPoint> loadCSV()
{
    std::vector<DataPoint> datapoints;
    std::string line;

    std::ifstream file("datapoints.csv");
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string label;
            std::getline(ss, label, ',');

            std::vector<float> features;
            std::string feature;
            while (std::getline(ss, feature, ','))
            {
                features.push_back(std::stof(feature));
            }
            auto datapoint = new DataPoint(features, label);
            datapoints.push_back(*datapoint);
        }
    } else
    {
        std::cerr << "Could not open the file!" << std::endl;
    }
    file.close();
    return datapoints;
}
