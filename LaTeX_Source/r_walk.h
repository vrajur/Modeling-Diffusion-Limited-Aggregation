//-----------------------------------------------------------
/*
Header File: r_walk.h

    Function rwalktest:
        test the properties of the random walk model for
        the conditions specified in Final.cpp

        Print array of n1 average r^2 for n2 particles after n3 steps
*/

void rwalktest(){
    int i,s,t;
    double theta, tx, ty, sum;

    int n_sim = 50;               // Number of calculations of mean r^2 (n1)
    int n_particles = 100;       // Number of particles simulated each simulation (n2)
    int n_steps = 111973;          // Number of time steps for particles to move (n3)


    Ullong seed2 = time(NULL);

    Ran myran(seed2);

    ofstream fpwalks;
    fpwalks.open("walks.dat");

    for(i = 0; i < n_sim; i++){
        //Run n_sim simulations

        sum = 0;
        for(s = 0; s < n_particles; s++){
            //Simulate n_particles particles:
            tx = 0; ty = 0;

            for(t = 0; t < n_steps; t++){
                // Random Walk for 1 Particle
                theta = 2*PI*myran.doub();
                tx += r_step*cos(theta);
                ty += r_step*sin(theta);
            } // END STEPS

            sum += tx*tx + ty*ty;
        } // END PARTICLES

        // Print average r^2 for 1 simulation (to file)
        fpwalks << sum/n_particles << endl;

        // Print average r^2 for 1 simulation (to output)
        cout << sum/n_particles << endl;
    } // END TIMES

    fpwalks.close();
}
//-----------------------------------------------------------
