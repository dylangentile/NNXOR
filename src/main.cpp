#include <iostream>
#include <vector>
#include "network.h"
#include "function.h"
using namespace std;

typedef struct{
    double x,y,z;
} Answers;


int main(int argc, char const *argv[])
{
    bool done = false;
    while(!done)
    {
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


        vector<double> loc0, loc1, loc2, loc3;
        
        int nodearray[4] = {2,2,1,-1}; //for now max of 3 layers.
        double *inputarray;
        double target;
        inputarray = new double[nodearray[0]];
        
    	Network *myNeuralNetwork = new Network;
    	
    	int zz = 0;
    	while(nodearray[zz] != -1){
    		zz++;
    	}
    	int cycles = 25000;
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

                if(zz == 0)
                {
                    loc0.push_back(result);
                }
                else if(zz == 1)
                {
                    loc1.push_back(result);
                }
                else if(zz == 2)
                {
                    loc2.push_back(result);
                }
                else if(zz == 3)
                {
                    loc3.push_back(result);
                }

               // cout << "\n\n" << result << '\n';
                //cout << "\n\nResult: "<< myNeuralNetwork->results[0] << "\n\n\n" << "Aeon: " << h+1 << '\n';
                myNeuralNetwork->learn(target, 0.2);
                if(w == h * zz)
                {
                    if(loc0.back() <= 0.2 && loc1.back() >= 0.8 && loc2.back() >= 0.8 && loc3.back() <= 0.2)
                    {
                        done = true;
                    }
                }

                /*
                if(w%20 == 0){
                	cout << "\nAeon: " << w;
                	cout << "\nResult: f(" <<loc[zz].x <<", " << loc[zz].y << ") = " << result << "\n\n\n";
                }
                w++;
                */
            }
        }
        //cout << "\n\n\nResult: " << result << "\n\n";
        cleanup();
    }
    cout << "\n\nworking model!\n\n";
	return 0;
}

