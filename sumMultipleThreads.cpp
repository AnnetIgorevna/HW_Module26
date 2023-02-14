
#include "sumMultipleThreads.h"

long long totalAmount(std::vector<long long>& sumFromOneThread)
{
	long long totalAmount = 0;
	for (auto& s : sumFromOneThread)
		totalAmount += s;
	sumFromOneThread.clear();
	return totalAmount;
}

void sumOfNumbersInOneThread(const std::vector<int>& vector, std::vector<long long>& summ, int pos)
{
	int summOfElem = 0;
	for (auto& elem : vector)
		summOfElem += elem;
	summ[pos] += summOfElem;
}

long long countOfNumbersInTread(long long n, int m)
{
	return n / m;
}

std::vector<std::vector<int>> createVectorOfVectors(const std::vector<int>& v, int m, long long countOfNumbers, std::vector<long long>& sumFromOneThread)
{
	std::vector<std::vector<int>> vecOfVec{};
	sumFromOneThread.clear();
	for (size_t i = 0; i < m; i++)
	{
		std::vector<int> newVector(v.begin() + i * countOfNumbers, v.begin() + (i + 1) * countOfNumbers);
		vecOfVec.push_back(newVector);
		sumFromOneThread.push_back(0);
	}
	return vecOfVec;
}

void createAndRunThreads(const std::vector<std::vector<int>>& vecOfVec, std::vector<long long>& sumFromOneThread, int m, long long n)
{
	std::vector<std::thread> threads{}; // vector of threads

	auto start = std::chrono::high_resolution_clock::now();
	for (int k = 0; k < m; k++)
	{
		std::thread t(sumOfNumbersInOneThread, std::ref(vecOfVec[k]), std::ref(sumFromOneThread), k);
		threads.emplace_back(std::move(t));
	}
	for (auto& t : threads)
		t.join();

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration1 = std::chrono::duration_cast<std::chrono::microseconds> (stop - start);

	std::cout << "\nN = " << n << "\tTHREADS = " << m << "\tcountOfElements in vector = " << (n / m);
	std::cout << "\nTime counting: " << duration1.count() << " microseconds";
	std::cout << "\nSum of vector v elements = " << totalAmount(sumFromOneThread) << "\n";
}

void countingSumWithThreads(const std::vector<int>& v, long long n, const std::vector<int>& m)
{
	std::vector<std::vector<int>> vectorOfVectors{};
	std::vector<long long> sumFromOneThread{};

	for (int i = 0; i < m.size(); i++)
	{
		long long countOfNumbers; // count of numbers in one thread
		countOfNumbers = countOfNumbersInTread(n, m[i]); // count of vector elements for one thread

		vectorOfVectors = createVectorOfVectors(v, m[i], countOfNumbers, sumFromOneThread);

		createAndRunThreads(vectorOfVectors, sumFromOneThread, m[i], v.size());
	}
}