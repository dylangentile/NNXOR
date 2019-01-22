#include <iostream>
#include "network.h"
#include "function.h"
using namespace std;

typedef struct{
    double x,y,z;
} Answers;


int main(int argc, char const *argv[])
{
    int cycles = 2500000;
    int mod = 100000;

    char x[2];


    if(argc == 2){
        char x[2];
        x[0] = *argv[0];
        x[1] = *argv[1];
        cycles = (int)x[0] - 48;
        mod = (int)x[1] - 48;
    }

    Answers *loc = new Answers[4];
    loc[0].x = 0.0;
    loc[0].y = 0.0;
    loc[0].z = 0.0;
    
    loc[1].x = 1.0;
    loc[1].y = 0.0;
    loc[1].z = 1.0;
    
    loc[2].x = 0.0;
    loc[2].y = 1.0;
    loc[2].z = 1.0;
    
    loc[3].x = 1.0;
    loc[3].y = 1.0;
    loc[3].z = 0.0;
    
    int nodearray[4] = {2,2,1,-1}; //for now max of 3 layers.
    double *inputarray;
    double target;
    inputarray = new double[nodearray[0]];
	Network *myNeuralNetwork = new Network;
    myNeuralNetwork->initialize(nodearray);
	int w = 0;
    for(int h = 0; h < cycles; h++){
        for(int zz = 0; zz < 4; zz++){
            inputarray[0] = loc[zz].x;
            inputarray[1] = loc[zz].y;
            target = loc[zz].z;
            myNeuralNetwork->forwardPropagation(inputarray);
            myNeuralNetwork->backPropagation(target, 0.1);
            
            if(w > 9999994){
                cout << "\nAeon: " << w << "\nf(" << inputarray[0] << ", " << inputarray[1] << ") = " << myNeuralNetwork->finOut << "\n";
            }
            else if(w%mod == 0){
            cout << "\nAeon: " << w << "\nf(" << inputarray[0] << ", " << inputarray[1] << ") = " << myNeuralNetwork->finOut << "\n";
            }
            w++;

        }
    }
    //cout << "\n\n\nResult: " << result << "\n\n";
    
    cleanup();
	return 0;
}

