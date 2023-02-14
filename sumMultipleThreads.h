#pragma once

#include <iostream>
#include <vector>
#include <thread>

long long totalAmount(std::vector<long long>& sumFromOneThread);

void sumOfNumbersInOneThread(const std::vector<int>& vector, std::vector<long long>& summ, int pos);

long long countOfNumbersInTread(long long n, int m);

std::vector<std::vector<int>> createVectorOfVectors(const std::vector<int>& v, int m, long long countOfNumbers, std::vector<long long>& sumFromOneThread);

void createAndRunThreads(const std::vector<std::vector<int>>& vecOfVec, std::vector<long long>& sumFromOneThread, int m, long long n);

void countingSumWithThreads(const std::vector<int>& v, long long n, const std::vector<int>& m);