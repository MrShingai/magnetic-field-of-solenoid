#include <stdio.h>
#include <math.h>
#include <stdlib.h>/*
 * Magnetic Field of a Finite Solenoid
 * Author: Tshepo Shingai Kgangetsile
 * Neptun: QA9158
 *
 * This program computes the magnetic field B(z) along the axis
 * of a finite solenoid from z = 0 to z = L, and writes the results
 * to data.txt, then plots them using Gnuplot.
 */


#define MU0 (4.0 * M_PI * 1e-7)  // Permeability of free space (H/m)

// Function to compute magnetic field along the axis of a finite solenoid
double magnetic_field(double z, double N, double L, double R, double I) {
    double term1 = z / sqrt(R * R + z * z);
    double term2 = (L - z) / sqrt(R * R + (L - z) * (L - z));
    return (MU0 * N * I / (2.0 * L)) * (term1 + term2);
}

int main(void) {
    double N, L, R, I;
    double dz;   // step size for z
    double z;    // position along solenoid
    double B;    // magnetic field at position z

    printf("=== Magnetic Field Along a Finite Solenoid ===\n\n");

    printf("Enter number of turns N: ");
    scanf("%lf", &N);

    printf("Enter solenoid length L (meters): ");
    scanf("%lf", &L);

    printf("Enter solenoid radius R (meters): ");
    scanf("%lf", &R);

    printf("Enter current I (amperes): ");
    scanf("%lf", &I);

    if (L <= 0.0 || R <= 0.0) {
        printf("Error: Length and radius must be greater than 0.\n");
        return 1;
    }

    printf("Enter step size for z (meters, e.g. 0.01): ");
    scanf("%lf", &dz);

    if (dz <= 0.0) {
        printf("Error: Step size must be greater than 0.\n");
        return 1;
    }

    // Open file to store data for graphing
    FILE *f = fopen("data.txt", "w");
    if (!f) {
        printf("Error: Unable to create data.txt\n");
        return 1;
    }

    printf("\nz (m)\t\tB(z) (T)\n");
    printf("-----------------------------\n");

    for (z = 0.0; z <= L + 1e-9; z += dz) {
        B = magnetic_field(z, N, L, R, I);
        printf("%8.4f\t% .6e\n", z, B);
        fprintf(f, "%lf %e\n", z, B);
    }

    fclose(f);

    // Create gnuplot script
    FILE *gp = fopen("plot_script.gp", "w");
    fprintf(gp,
        "set title 'Magnetic Field Along Solenoid Axis'\n"
        "set xlabel 'z (meters)'\n"
        "set ylabel 'B(z) (Tesla)'\n"
        "set grid\n"
        "plot 'data.txt' using 1:2 with linespoints lw 2 title 'B(z)'\n"
        "pause -1 'Press enter to exit.'\n"
    );
    fclose(gp);

    // Run gnuplot
    system("gnuplot plot_script.gp");

    return 0;
}
