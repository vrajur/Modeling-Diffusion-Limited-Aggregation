//-----------------------------------------------------------
/*
Header File: p_curvature.h

Function P:
    Return the probability of the particle sticking to the aggregate
    probability is a function number of neighbors
*/


double P(int ind, double tx, double ty){
    int i, n1, n2;
    double A,B,L, p, C;

    L = 5.0*diameter;           // Sampling cell size
    n1 = 0;                     // Particle count 1
    n2 = 0;                     // Particle count 2

    A = 1.0;                    // Probability intercept
    B = -1.0;                   // Proabability dependence (slope)

    C = 0.01;                   // Min probability

    for(i = 0; i < ind; i++){
        if( fabs(x(i,0) - tx) < L/2 && fabs(x(i,1)- ty) < L/2){
            n1++;                // count particles within L/2 x L/2 cell surrounding ind
        }

        if( fabs(x(i,0) - tx) < L && fabs(x(i,1)- ty) < L){
            n2++;                // count particles within L x L cell surrounding ind
        }
    }


    p = A + B*n1/n2;            // evaluate probability
    if(p < C){ p = C; }

    return p;
}
//-----------------------------------------------------------
