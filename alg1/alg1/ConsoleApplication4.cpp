#include <iostream>
#include <time.h>
#include "Matrix.h"

int main()
{

	srand(time(NULL));
	int size = 1000;
	Matrix m1 = Matrix(size, size);
	Matrix m2 = Matrix(size, size);

	m1.FillSequentially();
	m2.FillSequentially();

	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end;

	begin = std::chrono::steady_clock::now();
	Matrix* mSum = Matrix::SumMatrices(&m1, &m2);
	end = std::chrono::steady_clock::now();
	PrintTimeDifference(begin, end);
	delete mSum;

	begin = std::chrono::steady_clock::now();
	Matrix* mSum1 = Matrix::SumMatricesHC(&m1, &m2);
	end = std::chrono::steady_clock::now();
	PrintTimeDifference(begin, end);
	delete mSum1;

	begin = std::chrono::steady_clock::now();
	Matrix* mSum2 = Matrix::SumMatricesParallel(&m1, &m2);
	end = std::chrono::steady_clock::now();
	PrintTimeDifference(begin, end);
	delete mSum2;

	begin = std::chrono::steady_clock::now();
	Matrix* mSum3 = Matrix::DiffMatrices(&m1, &m2);
	end = std::chrono::steady_clock::now();
	PrintTimeDifference(begin, end);
	delete mSum3;

	begin = std::chrono::steady_clock::now();
	Matrix* mSum4 = Matrix::MultiplyMatrices(&m1, &m2);
	end = std::chrono::steady_clock::now();
	PrintTimeDifference(begin, end);
	delete mSum4;
	return 0;

}

