//-----------------------------------------------------------
/*
Final.cpp
Final Project: Diffusion Limited Aggregation

    Simulate the DLA Model and grow aggregates from seed
    particle(s). Release walker particles individually
    and model with random walk using Monte Carlo Methods.

    Observe aggregate properties for different sticking
    probabilities (input from header files) and
    additionally test the average behavior of Brownian
    motion for several different time intervals.


    Run on Core I2 with g++ 4.8.1 on Windows 7

    Vinay Rajur             18-Dec-2013
*/

#include<cstdlib>
#include<cstdio>
#include<cmath>

#include<fstream>
#include<iostream>

//Define the following symbol to enable bounds checking:
#define ARRAYT_BOUNDS_CHECK

#include "arrayt.hpp"
#include "nr3.h"
#include "ran.h"

using namespace std;

//-----------------------------------------
//PARAMETER INITIALIZATIONS:

const int N = 1000;                  // Number of Particles in Aggregate
const float bias = 0.0;              // Central tendency of random walkers (increase to speed up simulation)

Ullong seed = time(NULL);          // Seed for Random Number Generator
//Ullong seed = 17;                    // Seed for Random Number Generator


//OTHER INITIALIZATIONS:
double diameter = 1.0;          // Particle Diameter
double r_step = .50*diameter;   // Step size
double r_bind = .5*diameter;    // Distance to bind particle

Ullong counts = 0;              //Counting steps (as a measure of time)
arrayt<double> x(N,3);          // Particle Array
Ran ran(seed);                  // Random Number Generator

//OTHER CONSTANTS:
const double PI = 4.0*atan(1.0);

//#include "p_coeff.h"
//#include "p_neighbors.h"
#include "p_curvature.h"

#include "r_walk.h"
//#define RWALKTEST       // run random walk simulation:

//-----------------------------------------
// MAIN LOOP:
int main(){

#ifdef RWALKTEST
    // Simuate Random Walks
    rwalktest();

#else

    clock_t start = clock();

    int i,n0;
    double tx,ty,r,rmax,r_kill,r_spawn,maxx,maxy,theta;
    bool bound;

    bool bindcheck(int, double, double);

    ofstream fppos;
    fppos.open("pos.dat");

    //-------------------------------------
    // Initializations:

    n0 = 1;                         //Number of initial particles

    // Create Distribution of Initial Particles:
    for(i = 0; i < n0; i++){
        x(i,0) = 0;
        x(i,1) = 0;
    }
    maxx = 0; maxy = 0;
    rmax = 2.0*r_step;

    //-------------------------------------
    // DLA Start:

    for(i = n0; i < N; i++){
        rmax = sqrt(maxx*maxx + maxy*maxy);
        r_spawn = rmax + 2.0*diameter;
        r_kill = r_spawn + 2.0*diameter;

        // Initialize Particle i:

        theta = 2*PI*ran.doub();
        tx = r_spawn*cos(theta);
        ty = r_spawn*sin(theta);
        r = sqrt(tx*tx + ty*ty);
        bound = false;

        // Simulate Brownian Motion Until Particle is Bound:
        while(!bound){
            //Random Walk:
            theta = 2*PI*ran.doub();
            tx += r_step*cos(theta) - bias*tx/r;
            ty += r_step*sin(theta) - bias*ty/r;
            r = sqrt(tx*tx + ty*ty);
            counts++;

            if(r > r_kill){
                //Reinitialize Particle

                theta = 2*PI*ran.doub();
                tx = r_spawn*cos(theta);
                ty = r_spawn*sin(theta);
                r = sqrt(tx*tx + ty*ty);
                bound = false;
            }

            bound = bindcheck(i,tx,ty);
        }

        if(x(i,0) > maxx){ maxx = x(i,0); }
        if(x(i,1) > maxy){ maxy = x(i,1); }

        cout << i << ":\t" << bound << endl;
    }

    // Print Array to File
    for(i = 0; i < N; i++){
        fppos << x(i,0) << "\t" << x(i,1) << "\t" << x(i,2) << "\t";
        fppos << sqrt(x(i,0)*x(i,0) + x(i,1)*x(i,1)) << "\t" << atan2(x(i,1), x(i,0)) + PI << endl;
    }

    cout << "Number of Steps Taken: " << counts << endl;
    fppos.close();

    clock_t end = clock();
    double time = (double)(end - start)/CLOCKS_PER_SEC;

    cout << "Processing Time: " << time << endl;

#endif // RWALKTEST

    cout << "DONE" << endl;
    return 0;
}

//-----------------------------------------
/*
Function bindcheck:
    Return a random theta value between 0 and 2PI (uniform distribution of random variable)
*/
bool bindcheck(int ind, double tx, double ty){
    bool bound = false;
    double dx, dy, dr, R;
    double P(int, double, double);

    for(int i = 0; i < ind; i++){
        dx = tx - x(i,0);
        dy = ty - x(i,1);
        dr = sqrt(dx*dx + dy*dy);       // Distance between particles

        if(dr < r_bind){
            R = ran.doub();
            if(P(ind, tx, ty) > R){
                //Bind the particle
                x(ind,0) = tx;
                x(ind,1) = ty;
                x(ind,2) = counts;
                bound = true;
            }
        }
    }

    return bound;
}
//-----------------------------------------------------------
