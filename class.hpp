#pragma once
#include "header.hpp"

class Layer {
public:
    int layerNum;
    int weiNum;
    float* Neural;
    float** weight;
    float* bias;

    Layer(int preNum, int Num);   // 构造函数声明
    ~Layer();                     // 析构函数声明

    float activate(float input);  
    void fullconnection(Layer& Prelayer);  
};
