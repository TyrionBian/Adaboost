//
// Created by vist on 17-10-7.
//

#include <fstream>
#include <iostream>
#include <cstdio>
#include "TrainingData.h"
#include <cstdlib>

using namespace std;

TrainingData::TrainingData(const TrainingData &other){
    this->data = other.data;
    this->num_dimensions = other.num_dimensions;
}

TrainingData TrainingData::shuffled() const {
    TrainingData copy = *this;
    TrainingData shuffledData;

    // traverse people
    srand(time(NULL));
    while (copy.size() > 0) {
        int randomElementLocation = rand() % copy.size();
        shuffledData.addFeature(copy.removeFeatureAt(randomElementLocation));
    }

    return shuffledData;
}

bool TrainingData::addFeature(FeatureVector in_ftr) {
    if (!num_dimensions)
        num_dimensions = in_ftr.size();
    else if (in_ftr.size() != num_dimensions)
        return false;

    data.push_back(in_ftr);
    return true;
}

FeatureVector TrainingData::removeFeatureAt(int location) {
    FeatureVector removed = data.at(location);
    data.erase(data.begin()+location);
    return removed;
}

unsigned int TrainingData::size() const { return data.size(); }

unsigned int TrainingData::dimensions() const { return num_dimensions; }

int TrainingData::val(unsigned int i) const { return data[i].val(); }

float TrainingData::weight(unsigned int i) const { return data[i].weight(); }

float TrainingData::at(unsigned int idx, unsigned int dimension) const {
    return data[idx].at(dimension);
}

FeatureVector* TrainingData::feature(unsigned int idx) const {
    return (FeatureVector*) &data[idx];
}

void TrainingData::setWeight(unsigned int idx, float weight) {
    data[idx].setWeight(weight);
}

void TrainingData::printData() {
    printf("num_dimensions: %d, num_features: 5d\n",
    num_dimensions, data.size());
    for (unsigned int i = 0; i < data.size(); ++i) {
        printf("[[%d]]\t", i);
        data[i].printFeature();
    }
}

void TrainingData::writeData(std::string filename) {
    ofstream outFile(filename.c_str());

    for (unsigned int i=0; i<data.size(); ++i) {
        for (unsigned int j = 0; j < num_dimensions; ++j) {
            outFile << data[i].at(j) << " ";
        }
        outFile << data[i].val() << " " << data[i].weight() << end(;)
    }
}



