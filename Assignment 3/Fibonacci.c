/**
*	ALBRIT BENDO
*	ADS HW3
*	QUESTION 3.1
*	FIBONACCI IMPLEMENTATION
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// Naive algorithm function
int naive_alg(int a)
{
    if(a <= 1)
        return a;
    else
        return naive_alg(a-1)+naive_alg(a-2);
}
// Bottom Up algorithm function
int bottomup_alg(int n)
{
	int fib[n+1];
	fib[0] = 0;
	fib[1] = 1;

	for(int i=2; i<=n; i++)
	{
		fib[i] = fib[i-1]+fib[i-2];
	}
	return fib[n];
}
// Closed Form algorithm function
int closed_alg(int n)
{
	double phi = (1+sqrt(5))/2;
	return round(pow(phi, n)/sqrt(5));
}
// Matrix algorithm function
// power raising of matrix
// implementing a matrix multiplication so we can use in power
void multiply_matrix(int m1[2][2], int m2[2][2])
{
	int x1 = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
	int x2 = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
	int x3 = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
	int x4 = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];

	m1[0][0] = x1;
	m1[0][1] = x2;
	m1[1][0] = x3;
	m1[1][1] = x4;
}
void power_matrix(int m1[2][2], int n)
{
	if(n == 0 || n == 1)
	{
		return;
	}
	int m2[2][2] = {{1, 1}, {1, 0}};

	power_matrix(m1, n/2);
	multiply_matrix(m1, m1);

	if(n%2 != 0)
		multiply_matrix(m1, m2);
}
int matrix_alg(int n)
{
	int f[2][2] = {{1, 1}, {1, 0}};
	if(n == 0)
	{
		return 0;
	} 
	power_matrix(f, n-1);
	return f[0][0];
}

int main()
{
	int n;

	for(int i=0; i<100; i++)
	{
		printf("Scan Fibonacci n'th number: ");
		scanf("%d", &n);

		double start = clock();

		//printf("fib(%d) = %d\n", n, naive_alg(n));
		//printf("fib(%d) = %d\n", n, matrix_alg(n));
		//printf("fib(%d) = %d\n", n, bottomup_alg(n));
		printf("fib(%d) = %d\n", n, closed_alg(n));

		getchar();
	double end = clock();
	double time_taken = ((double)end-start)/CLOCKS_PER_SEC;
        printf("%f sec\n", time_taken);
	}
	return 0;
}