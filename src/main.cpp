#include <iostream>
#include "network.h"
#include "function.h"
using namespace std;

typedef struct{
    double x,y,z;
} Answers;


int main(int argc, char const *argv[])
{
    
    Answers *loc = new Answers[4];
    loc[0].x = 0.0;
    loc[0].y = 0.0;
    loc[0].z = 1.0;
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
	
	int zz = 0;
	while(nodearray[zz] != -1){
		zz++;
	}
	int cycles = 500;
	double result;
	myNeuralNetwork->networkInit(nodearray);
	int w = 1;
    for(int h = 0; h < cycles; h++){
        for(int zz = 0; zz < 4; zz++){
            inputarray[0] = loc[zz].x;
            inputarray[1] = loc[zz].y;
            target = loc[zz].z;
            myNeuralNetwork->run(inputarray);
            result = myNeuralNetwork->results[0];
            //cout << "\n\nResult: "<< myNeuralNetwork->results[0] << "\n\n\n" << "Aeon: " << h+1 << '\n';
            myNeuralNetwork->learn(target, 0.8);
            if(w%1 == 0){
            	cout << "\nAeon: " << w;
            	cout << "\nResult: f(" <<loc[zz].x <<", " << loc[zz].y << ") = " << result << "\n\n\n";
            }
            w++;

        }
    }
    //cout << "\n\n\nResult: " << result << "\n\n";
    cleanup();
	return 0;
}

