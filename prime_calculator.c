// Takes in an integer greater than 0 

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>

int next_prime (int number);
// If input <= 47, test_n and test_d is assigned but
// does not enter the while loop meaning isdigit(number)
// returns false. However,

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
	int number = 1;
	while (number < 99999){
		int next_prime_number = next_prime(number);
//		int next_prime_number = prime_detect(number);
		number++;
//		printf("main check: %d\n", next_prime_number);
	}

}

int next_prime (int number){
	int test_n = number;
	int test_d = number-1;
//	printf("test_n and test_d\n");


	if (number == 1) {
		printf("%d\n", number);
//		printf("if number == 1\n");
		return number;
	}


	while (number > 0){
//		printf("entered while loop\n");
		// if divisible and divisor > 1, not prime number
		if (test_n%test_d == 0 && test_d > 1){
			test_n++;
			test_d = test_n-1;
//			printf("A1\n");
		}
		// if divisible and divisor == 1, prime number
		else if(test_n%test_d == 0 && test_d == 1) {
			printf("%d\n", test_n);
//			printf("A2\n");
			return test_n;
		}
		// if not divisible, try reduce denominator by 1
		else {
			test_d--;
//			printf("A3\n");
		}
	}
}

int prime_detect (int number) {
	int test_n = number;
	int test_d = number-1;

	while (isdigit(number)) {
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