// Takes in an integer greater than 0 

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>

int next_prime (int number);
// takes in integer, returns if prime, else return 
// next prime

int prime_detect (int number);
// takes in integer, if number is prime, return number


// make error message for wrong input
int main (int argc, char* argv[]) {
/*
	if (isdigit(argv[1])){
		int number = atoi(argv[1]);
		int next_prime_number = next_prime(number);
		return 1;
	}
*/
	char* input_ptr;
	int test_int;
	test_int = strtol(argv[1], &input_ptr, 10);
	printf("%d\n", test_int);
	int next_prime_number = next_prime(test_int);
	return 0;
}

/*
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
*/

int next_prime (int number){
	int test_n = number;
	int test_d = number-1;

	if (number == 1) {
		printf("%d\n", number);
		return number;
	}

	while (number > 0){

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
// if not divisible, reduce denominator every iteration
		else {
			test_d--;
		}
	}
}

int prime_detect (int number) {
	int test_n = number;
	int test_d = number-1;
// if number is 1, then denominator cannot be 0
// we know 1 == prime to be true
	if (number == 1) {
		printf("%d\n", number);
		return number;
	}
// if number is positive integer larger than 0 and is not 1
// use while loop to attempt to divide by integers (1, number-1)
	while (number > 0) {
// if divisible and divisor > 1, not a prime number 
		if (test_n%test_d == 0 && test_d > 1){
			test_n++;
			test_d = test_n-1;
		}
// if divisable and divisor == 1 and test_n is unchanged, number is prime
		else if (test_n%test_d == 0 && test_d == 1 && test_n == number) {
			printf("%d\n", test_n);
			return test_n;
		}
// if divisable and divisor == 1 and test_n is changed, test_n is prime
// but number is not prime
		else if (test_n%test_d == 0 && test_d == 1 && test_n != number) {
			return test_n;
		}
// if not divisible, reduce denominator every iteration
		else {
			test_d--;
		}
	}
}