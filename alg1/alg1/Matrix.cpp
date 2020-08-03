#include "Matrix.h"

Matrix::Matrix(size_t nRows, size_t nCols)
{
	this->_nRows = nRows;
	this->_nCols = nCols;
	this->_data = new int[nRows * nCols];
}

Matrix::~Matrix()
{
	delete[] this->_data;
}

void Matrix::FillWithRandomNumbers(int max)
{
	for (size_t i = 0; i < this->_nCols * this->_nRows; i++) {
		this->_data[i] = rand() % (max + 1);
	}
}

void Matrix::FillSequentially()
{
	for (size_t i = 0; i < this->_nCols * this->_nRows; i++) {
		this->_data[i] = i;
	}
}

size_t Matrix::GetNumberOfItemsInMatrix()
{
	return this->_nCols * this->_nRows;
}

int Matrix::GetItem(size_t row, size_t col)
{
	return this->_data[row * this->_nCols + col];
}

void Matrix::SetItem(int item, size_t row, size_t col)
{
	this->_data[row * this->_nCols + col] = item;
}

void Matrix::Print()
{
	for (size_t i = 0; i < this->_nRows; i++) {
		for (size_t j = 0; j < this->_nCols; j++) {
			printf("%d ", this->GetItem(i, j));
		}
		printf("\n");
	}
}

Matrix* Matrix::MultiplyByScalar(Matrix* m, int scalar)
{

	Matrix* res = new Matrix(m->_nRows, m->_nCols);

	for (size_t i = 0; i < res->GetNumberOfItemsInMatrix(); i++) {
		res->_data[i] = m->_data[i] * scalar;
	}

	return res;
}

Matrix* Matrix::SumMatrices(Matrix* matrixA, Matrix* matrixB)
{
	Matrix* res = new Matrix(matrixA->_nRows, matrixA->_nCols);

	for (size_t i = 0; i < res->_nRows; i++)
	{
		for (size_t j = 0; j < res->_nCols; j++)
		{
			int sum = matrixA->GetItem(i, j) + matrixB->GetItem(i, j);
			res->SetItem(sum, i, j);
		}
	}

	return res;
}

Matrix* Matrix::SumMatricesHC(Matrix* matrixA, Matrix* matrixB)
{
	Matrix* res = new Matrix(matrixA->_nRows, matrixA->_nCols);

	size_t size = res->GetNumberOfItemsInMatrix();

	int* pA = matrixA->_data;
	int* pB = matrixB->_data;
	int* pRes = res->_data;

	for (size_t i = 0; i < size; i++)
	{
		*(pRes++) = *(pA++) + *(pB++);
	}


	return res;
}

Matrix* Matrix::SumMatricesParallel(Matrix* matrixA, Matrix* matrixB)
{
	Matrix* res = new Matrix(matrixA->_nRows, matrixA->_nCols);

	concurrency::parallel_for(0, (int)res->_nRows, [&, res](int i) {

		for (size_t j = 0; j < res->_nCols; j++)
		{
			int sum = matrixA->GetItem(i, j) + matrixB->GetItem(i, j);
			res->SetItem(sum, i, j);
		}
		});

	return res;
}

Matrix* Matrix::DiffMatrices(Matrix* matrixA, Matrix* matrixB)
{
	Matrix* res = new Matrix(matrixA->_nRows, matrixA->_nCols);

	for (size_t i = 0; i < res->_nRows; i++)
	{
		for (size_t j = 0; j < res->_nCols; j++)
		{
			res->SetItem(matrixA->GetItem(i, j) - matrixB->GetItem(i, j), i, j);
		}

	}

	return res;
}

Matrix* Matrix::MultiplyMatrices(Matrix* matrixA, Matrix* matrixB)
{
	Matrix* res = new Matrix(matrixA->_nRows, matrixA->_nCols);
	for (int k = 0; k < res->_nRows; k++)
	{
		for (int i = 0; i < res->_nCols; i++)
		{
			int count = 0;
			for (int j = 0; j < res->_nCols; j++)
			{
				count = count + (matrixA->_data[k * matrixA->_nCols + j] * matrixB->_data[j * matrixB->_nCols + i]);
			}
			res->_data[k * res->_nCols + i] = count;
		}
	}
	return res;
}