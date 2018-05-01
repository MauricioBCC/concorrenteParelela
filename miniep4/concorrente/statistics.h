#ifndef STATISTICS_H
#define STATISTICS_H

void statistics_print_array(int n, const int v[]);

double statistics_average(int n, const int v[]);

/*Pass NULL to avg if you did not precalculate it*/
double statistics_stddev(int n, const int v[], const double* avg);

void statistics_print(int n, const int v[]);

void statistics_avg_print(int n, const double v[]);

double statistics_average_double(int n, const double v[]);

double statistics_stddev_double(int n, const double v[], const double* avg);

void statistics_print_array_double(int n, const double v[]);

#endif /*STATISTICS_H*/
