#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>

int next_prime (int number);

int prime_detect (int number);

/*
int main (int argc, char* argv[]) {
	if (isdigit(argv[1])){;
		int number = atoi(argv[1]);
		int next_prime_number = next_prime(number);
		return 1;
	}
	return 0;
}
*/

// for testing 
int main (void) {
	int number = 3;
	while (number < 99999){
//		int next_prime_number = next_prime(number);
		int next_prime_number = prime_detect(number);
		number++;
	}

}

int next_prime (int number){
	int test_n = number;
	int test_d = number-1;

	while (number > -1){
		// if divisible and divisor > 1, not prime number
		if (test_n%test_d == 0 && test_d > 1){
			test_n++;
			test_d = test_n-1;
		}
		// if divisible and divisor == 1, prime number
		else if(test_n%test_d == 0 && test_d == 1) {
			printf("%d\n", test_n);
			return test_n;
		}
		// if not divisible, try reduce denominator by 1
		else {
			test_d--;
		}
	}
}

int prime_detect (int number) {
	int test_n = number;
	int test_d = number-1;

	while (number > -1) {
		if (test_n%test_d == 0 && test_d > 1){
			test_n++;
			test_d = test_n-1;
		}
		else if (test_n%test_d == 0 && test_d == 1 && test_n == number) {
			printf("%d\n", test_n);
			return test_n;
		}
		else if (test_n%test_d == 0 && test_d == 1 && test_n != number) {
			return test_n;
		}
		else {
			test_d--;
		}
	}
}