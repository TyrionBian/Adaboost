cmake_minimum_required(VERSION 3.8)
project(Adaboost)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AdaBooster.h FeatureVector.h FeatureVector.cpp TrainingData.h TrainingData.cpp)
add_executable(Adaboost ${SOURCE_FILES})