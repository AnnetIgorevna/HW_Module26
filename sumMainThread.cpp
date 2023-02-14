
#include "sumMainThread.h"

void sumOfNumbersInMainThread(const std::vector<int>& vector)
{
	long long sum = 0;
	auto start = std::chrono::high_resolution_clock::now();	// start of time
	for (auto& elem : vector)
		sum += elem;
	auto stop = std::chrono::high_resolution_clock::now();	// stop of time
	auto duration = std::chrono::duration_cast<std::chrono::microseconds> (stop - start);	// duration may be in nanoseconds, microseconds, milliseconds,seconds

	std::cout << "**************************************************************************************\n";
	std::cout << "\nN = " << vector.size();
	std::cout << "\nSum of vector v elements = " << sum;
	std::cout << "\nTime spent counting the sum of the numbers in the MAIN stream: " << duration.count() << " microseconds" << "\n";
}