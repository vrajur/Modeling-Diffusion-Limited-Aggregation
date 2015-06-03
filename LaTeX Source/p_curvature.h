//-----------------------------------------------------------
/*
Header File: p_curvature.h

Function P:
    Return the probability of the particle sticking to the aggregate
    probability is a function of the local curvature at the point of contact
*/

double P(int ind, double tx, double ty){
    int i,n;
    double A, B, L, p, C, nl, n0;

    A = 10.0;                   // Parameter for probability function
    B = 0.50;                   // Parameter for probability function

    L = 5.0*diameter;           // Sample Cell size
    n = 0;                      // Particle Count (inside cell)
    n0 = (L - 1)/2/L;           // Particle count for straight line of particles
    C = 0.01;                   // Min bound on probability p

    for(i = 0; i < ind; i++){
        if( fabs(x(i,0) - tx) < L && fabs(x(i,1)- ty) < L){
            n++;                // count particles within surrounding L x L cell
        }
    }

    nl = n/L/L;
    p = A*(nl - n0) - B;        // evaluate p
    //p = ran.doub();
    if(p < C){ p = C; }         // ensure p > C

    return p;
}
//-----------------------------------------------------------
