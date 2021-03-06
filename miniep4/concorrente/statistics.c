#include "statistics.h"

#include <stdio.h>
#include <math.h>

void statistics_print_array(int n, const int v[])
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d, ", v[i]);
	putchar('\n');
}

double statistics_average(int n, const int v[])
{
	double sum = 0.;
	int i;
	for (i = 0; i < n; ++i)
		sum += v[i]; /*Ignore overflows*/
	return sum/n;
}

double statistics_stddev(int n, const int v[], const double* avg)
{
	double sum = 0;
	double my_avg;
	int i;

	if (avg != NULL)
		my_avg = *avg;
	else
		my_avg = statistics_average(n, v);

	for (i = 0; i < n; ++i)
		sum += (v[i] - my_avg)*(v[i] - my_avg); /*Ignore overflow*/
	return sqrt(sum/n); /*idk if the sample stddev is better here*/
}

void statistics_print(int n, const int v[])
{
	double avg, stddev;
	avg = statistics_average(n, v);
	stddev = statistics_stddev(n, v, &avg);

	printf("Average of accesses: %f\n", avg);
	printf("Standard Deviation of accesses: %f\n", stddev);
	printf("Number of times that each thread accessed the CS:\n");
	statistics_print_array(n, v);
}

double statistics_stddev_double(int n, const double v[], const double* avg)
{
	double sum = 0;
	double my_avg;
	int i;

	if (avg != NULL)
		my_avg = *avg;
	else
		my_avg = statistics_average_double(n, v);

	for (i = 0; i < n; ++i)
		sum += (v[i] - my_avg)*(v[i] - my_avg); /*Ignore overflow*/
	return sqrt(sum/n); /*idk if the sample stddev is better here*/
}

double statistics_average_double(int n, const double v[])
{
	double sum = 0.;
	int i;
	for (i = 0; i < n; ++i)
		sum += v[i]; /*Ignore overflows*/
	return sum/n;
}


void statistics_avg_print(int n, const double v[])
{
	double avg, stddev;
	avg = statistics_average_double(n, v);
	stddev = statistics_stddev_double(n, v, &avg);

	printf("Average of averages accesses: %lf\n", avg);
	printf("Average of Standard Deviations of accesses: %lf\n", stddev);
	printf("Averages of each test:\n");
	statistics_print_array_double(n, v);
}


void statistics_print_array_double(int n, const double v[])
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%lf, ", v[i]);
	putchar('\n');
}
