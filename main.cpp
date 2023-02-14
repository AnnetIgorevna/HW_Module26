
#include "sumMainThread.h"
#include "sumMultipleThreads.h"
#include "utils.h"

int main()
{
	std::vector<int> v{}; // vector of numbers
	std::vector<long long> n{10000,100000,1000000,10000000}; // count of numbers in v
	std::vector<int> m{1,2,4,8,10}; // count of threads

	for (int i = 0; i < n.size(); i++)
	{
		v = randomGenerator(n[i]);	// create vector v with random generator
		
		/**** Counting the sum of vector numbers in Main stream ****/

		sumOfNumbersInMainThread(v);			// sum function for main thread

		/**** Counting the sum of vector numbers in multiple threads ****/

		countingSumWithThreads(v, n[i], m);	// sum function for multiple threads

		v.clear();
	}

	return 0;
}