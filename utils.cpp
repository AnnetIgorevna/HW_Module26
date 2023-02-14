
#include "utils.h"

std::vector<int> randomGenerator(long long n)
{
	std::vector<int> v;
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.
	std::uniform_int_distribution<int> dist(2, 4); // distribute results between 2-4
	for (long long i = 0; i < n; i++)
		v.push_back(dist(gen));

	return v;
}

void printVector(const std::vector<int>& v)
{
	for (auto& it : v)
		std::cout << it << ' ';
}

void printVectorOfVectors(const std::vector<std::vector<int>>& v)
{
	std::cout << "\n";
	for (auto& it : v) {
		printVector(it);
		std::cout << "\n";
	}
}