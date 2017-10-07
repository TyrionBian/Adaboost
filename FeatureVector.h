//
// Created by vist on 17-10-7.
//

#ifndef ADABOOST_FEATUREVECTOR_H
#define ADABOOST_FEATUREVECTOR_H

#include <vector>

static const int POS=1;
static const int NEG=-1;

/*
 *
 */
class FeatureVector {
public:
    FeatureVector(const std::vector<float> &in_vec,
    int in_val);    //constructor

    FeatureVector(const FeatureVector &other);

    unsigned  int size() const;
    int val() const;
    float weight() const;
    float at(unsigned int i) const;

    void setWeight(float weight);

    void printFeature() const;

private:
    std::vector <float> fvec;   //feature vector
    int value;  //value (POS or NEG)
    float wt;   //weight;
};
#endif //ADABOOST_FEATUREVECTOR_H
