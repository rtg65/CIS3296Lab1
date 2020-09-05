#include "stdlib.h"
#include "stdio.h"
#include "time.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Error: Need argument!");
		return 1;
	}
	char* p;
	int n = 0;
	errno = 0;
	long conv = strtol(argv[1], &p, 10);

	// Check for errors: e.g., the string does not represent an integer
	// or the integer is larger than int
	if (errno != 0 || *p != '\0' || conv > INT_MAX) {
		// Put here the handling of the error, like exiting the program with
		// an error message
	}
	else {
		// No error
		n = conv;
		printf("%d\n", n);
	}

	srand(1101);

	//initialize Matrices
	int** A = malloc(n * sizeof(int*));

	int** B = malloc(n * sizeof(int*));

	int** C = malloc(n * sizeof(int*));
	if (A == NULL || B == NULL || C == NULL) {
		printf("Error: Out of Memory");
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		A[i] = malloc(n * sizeof(int));
		B[i] = malloc(n * sizeof(int));
		C[i] = calloc(n, sizeof(int));
		if (A[i] == NULL || B[i] == NULL || C[i] == NULL) {
			printf("Error: Out of Memory");
			return 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand();
			B[i][j] = rand();
		}
	}

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			printf("%d, ", A[i][j]);
		}
		printf("\n");
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			printf("%d, ", B[i][j]);
		}
		printf("\n");
	}/**/

	clock_t startTime = clock();
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++)
		{
			for (int j = 0; j < n; j++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	clock_t endTime = clock();
	int clockTotal = endTime - startTime;
	double totalTime = (double)clockTotal / CLOCKS_PER_SEC;
	printf("%d", clockTotal);

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			printf("%d, ", C[i][j]);
		}
		printf("\n");
	}/**/
	//Release Mem for Matrices
	for (int i = 0; i < n; i++)
	{
		free(A[i]);
		free(B[i]);
		free(C[i]);
	}/**/
	free(A);
	free(B);
	free(C);

	return(0);
}

