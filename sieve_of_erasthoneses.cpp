/*
-------------------------------------------------------
Info		: Sieve of eurosthenes implementation using
			  C++ vector container. Given upper limit,
			  this will list all the prime number upto
			  that range

Date		: 6th June 2017
Author		: Sarvesh Jayaraman
contact		: j.sarveshwaran@gmail.com
-------------------------------------------------------
*/




#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>


//timing operations

#define INIT_TIMER auto start=std::chrono::high_resolution_clock::now();
#define START_TIMER start=std::chrono::high_resolution_clock::now();
#define STOP_TIMER std::cout << "RUNTIME is "<< std::chrono::duration_cast <std::chrono::milliseconds> (\
	std::chrono::high_resolution_clock::now()-start).count() <<"ms\n" ;


void sieve_of_erasthoneses(int n){//,
	
	//initialize the sieve as vector of boolean!
	//initially assume all numbers are prime

	std::vector<bool> sieve(n,true);
	

	// numbers 0 and 1	
	sieve[0]=false;
	sieve[1]=false;
	
	for (int a=2;a<=std::sqrt(n);++a){
		//std::cout<<a<<"\n";
	
		// get the multiples of a and mark as not prime
		for (int i=2*a;i<=n;i+=a)
			sieve[i]=false;
	}

	
	std::cout <<"size of sieve is :" << sieve.size() <<"\n";
	std::cout <<"=======================\n"
		  <<"Numbers are as follows:\n" 
		  <<"=======================\n";
	
	// print sieve elements marked by true flag, which indicates 
	// they are prime numbers!

	for (int i=0;i<sieve.size();i++){
		if (sieve[i])
			std::cout <<i<<"\n";
	}
}


//main function
int main(){
	
	int n=1000000;

	//initialize and start timer
	INIT_TIMER
	START_TIMER


	// compute prime numbers using sieve of erasthoneses method!
	sieve_of_erasthoneses(n);


	STOP_TIMER
	return 0;
}
