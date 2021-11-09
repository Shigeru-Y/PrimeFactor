// PrimeFactor.cpp : Defines the entry point for the console application.
//
// Console application to find prime factor of integer value.
// Usage $PrimeFactor [number]
//
// Code history:
// 2021/Nov/09 S.Yamamoto Original.
//

#include "stdafx.h"

// Test routine.
// If found any prime, return false.
//    return true otherwise.
bool PrimeTest(long long number)
{
	bool ret = true;
	long long prime, quotient;
	for (long long l = 2; l < number / 2; l++) {
		if (number % l == 0) {
			// Find prime.
			prime = l;
			quotient = number / l;
			printf("prime=%lld, quotient=%lld\n", prime, quotient);
			PrimeTest(quotient);	// Recartive call.
			ret = false;
			break;	// No more test for remainings.
		}
	}
	return ret;
}

//
// Main routine.
//
int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("...Use PrimeFactor [number]\n");
		exit(0);
	}

	// Recarsive call for PrimeTest()
	long long testNumber = atoll(argv[1]);

	printf("Test for %lld\n", testNumber);
	if (PrimeTest(testNumber)) {
		printf("%lld is a prime number.\n", testNumber );
	}

    return 0;
}
