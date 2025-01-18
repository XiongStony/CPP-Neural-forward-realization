#include "class.hpp"

// 构造函数实现
Layer::Layer(int preNum, int Num) {
    this->layerNum = Num;
    this->weiNum = preNum;
    
    this->Neural = new float[layerNum];
    for (int i = 0; i < layerNum; i++) {
        this->Neural[i] = 0.0f;
    }
    
    this->weight = new float*[layerNum];
    for (int i = 0; i < layerNum; i++) {
        this->weight[i] = new float[weiNum];
        for (int j = 0; j < weiNum; j++) {
            this->weight[i][j] = 0.0f;
        }
    }

    this->bias = new float[layerNum];
    for (int i = 0; i < layerNum; i++) {
        this->bias[i] = 0.0f;
    }
}

// 激活函数实现
float Layer::activate(float input) {
    return (input > 0) ? 1.0f : 0.0f;
}

// 全连接函数实现
void Layer::fullconnection(Layer& Prelayer) {
    for (int i = 0; i < layerNum; i++) {
        float sum = 0.0f;
        for (int j = 0; j < weiNum; j++) {
            sum += this->weight[i][j] * Prelayer.Neural[j];
        }
        sum += bias[i];
        this->Neural[i] = activate(sum);
    }
}

// 析构函数实现
Layer::~Layer() {
    delete[] Neural;
    for (int i = 0; i < layerNum; i++) {
        delete[] weight[i];
    }
    delete[] weight;
    delete[] bias;
}