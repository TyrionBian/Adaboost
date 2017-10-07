//
// Created by vist on 17-10-7.
//

#include <cstdio>
#include "FeatureVector.h"

using namespace std;

// constructor
FeatureVector::FeatureVector(const std::vector<float> &in_vec,
                             int in_val) : value(in_val),wt(-1) {
    for (unsigned int i = 0; i<in_vec.size(); ++i) {
        fvec.push_back(in_vec[i]);
    }
}

FeatureVector::FeatureVector(const FeatureVector &other) {
    this->fvec = other.fvec;
    this->value = other.value;
    this->wt = other.wt;
}

// return size of feature vector (useful in addFeature in training data
unsigned int FeatureVector::size() const {
    return fvec.size();
}

// more getter methods
int FeatureVector::val() const { return value; }
float FeatureVector::weight() const { return wt; }
float FeatureVector::at(unsigned int i) const { return fvec[i]; }

// sets weight to given value
void FeatureVector::setWeight(float weight) {wt = weight; }

// print out all instance fields of a feature
void FeatureVector::printFeature() const {
    for (unsigned int i = 0; i < fvec.size(); ++i) {
        printf("[%d]: %.3f ",i, fvec[i]);
    }
    printf("\n \t val: %d, wight: %f\n", value, wt);
}