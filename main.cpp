#include "header.hpp"
#include "class.hpp"

int main(int argc, char* argv[]) {
    Layer inputlayer(0, 3);
    Layer hiddenlayer(3, 3);
    Layer outputlayer(3, 1);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hiddenlayer.weight[i][j] = 1;
        }
    }

    hiddenlayer.bias[0] = -0.5;
    hiddenlayer.bias[1] = -1.5;
    hiddenlayer.bias[2] = -2.5;

    outputlayer.weight[0][0] = 1;
    outputlayer.weight[0][1] = -1;
    outputlayer.weight[0][2] = 1;

    inputlayer.Neural[0] = 1;
    inputlayer.Neural[1] = 1;
    inputlayer.Neural[2] = 1;

    hiddenlayer.fullconnection(inputlayer);
    outputlayer.fullconnection(hiddenlayer);

    std::cout << "hiddenlayer = ";
    for(int i = 0; i < 3; i++) {
        std::cout << hiddenlayer.Neural[i] << " ";
    }
    std::cout << "\n output = " << outputlayer.Neural[0] << "\n";

    return 0;
}