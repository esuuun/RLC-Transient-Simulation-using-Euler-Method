#include <stdio.h>
#include <math.h>

#define L 1.0
#define R 0.0
#define C 0.25
#define E0 1.0
#define W 3.5 // omega
#define P 2.0 // p

// Tegangan sumber E(t) = E0 * sin(W*t)
double E(double t)
{
    return E0 * sin(W * t);
}

// Sistem ODE: y[0]=q, y[1]=i
// Output: dydt[0]=dq/dt, dydt[1]=di/dt
void f(double t, double y[], double dydt[])
{
    dydt[0] = y[1];
    dydt[1] = (1.0 / L) * (E(t) - R * y[1] - y[0] / C);
}

// Satu langkah Euler eksplisit: y_out = y + h * f(t,y)
void euler_step(double t, double y[], double h, double y_out[])
{
    double dydt[2];
    f(t, y, dydt);
    y_out[0] = y[0] + h * dydt[0];
    y_out[1] = y[1] + h * dydt[1];
}

// Solusi analitik q(t) dari Eq. (28.11)
double q_analytic(double t)
{
    double term1 = (-E0 / (L * (P * P - W * W))) * (W / P) * sin(P * t);
    double term2 = (E0 / (L * (P * P - W * W))) * sin(W * t);
    return term1 + term2;
}

int main()
{
    double t0 = 0.0, tf = 20.0, h = 0.01;
    int N = (int)((tf - t0) / h);
    double t = t0;
    double y[2] = {0.0, 0.0}; // kondisi awal: q(0)=0, i(0)=0
    double y_next[2];

    printf("   t      q_Euler      q_Analytic      Error\n");
    printf("-------------------------------------------------\n");
    for (int n = 0; n <= N; n++)
    {
        double q_eu = y[0];
        double q_an = q_analytic(t);
        double err = fabs(q_eu - q_an);
        // t empat digit, q dengan 9 desimal, error dalam notasi ilmiah
        printf("%6.3f   % .9f   % .9f   % .3e\n",
               t, q_eu, q_an, err);

        // lakukan satu langkah Euler
        euler_step(t, y, h, y_next);
        // update
        t += h;
        y[0] = y_next[0];
        y[1] = y_next[1];
    }

    return 0;
}
