#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Matrix {
private:
	T** arr;
	int column;
	int row;
public:
	Matrix() = delete;
	Matrix(int column, int row);
	int getColumn();
	int getRow();
	void setMatrixRandom(int from, int to);
	template <typename T>
	friend istream& operator>>(istream& in, Matrix<T>& obj);

	template <typename T>
	friend ostream& operator<<(ostream& out, Matrix<T>& obj);

	Matrix<T>& operator+(const Matrix<T>& obj);
	Matrix<T>& operator-(const Matrix<T>& obj);
	Matrix<T>& operator/(const Matrix<T>& obj);
	Matrix<T>& operator*(const Matrix<T>& obj);
	void operator=(Matrix<T>& obj);
	T findMin();
	T findMax();

	T* operator[](int rowIndex);

	~Matrix();
};

template<typename T>
inline Matrix<T>::Matrix(int column, int row)
{
	this->column = column;
	this->row = row;
	arr = new T * [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new T[column];
	}
}

template<typename T>
inline int Matrix<T>::getColumn()
{
	return column;
}

template<typename T>
inline int Matrix<T>::getRow()
{
	return row;
}

template<>
inline void Matrix<int>::setMatrixRandom(int from, int to)
{
	srand(time(0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			arr[i][j] = from + rand() % (to - from + 1);
		}
	}
}

template<typename T>
inline Matrix<T>& Matrix<T>::operator+(const Matrix<T>& obj)
{
	if (this->column != obj.column || this->row != obj.row)
		throw runtime_error("First Matrix != Second Matrix");
	Matrix<T> tempMatrix(this->column, this->row);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			tempMatrix.arr[i][j] = this->arr[i][j] + obj.arr[i][j];
		}
	}
	return tempMatrix;
}

template<typename T>
inline Matrix<T>& Matrix<T>::operator-(const Matrix<T>& obj)
{
	if (this->column != obj.column || this->row != obj.row)
		throw runtime_error("First Matrix != Second Matrix");
	Matrix<T> tempMatrix(this->column, this->row);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			tempMatrix.arr[i][j] = this->arr[i][j] - obj.arr[i][j];
		}
	}
	return tempMatrix;
}

template<typename T>
inline Matrix<T>& Matrix<T>::operator/(const Matrix<T>& obj)
{
	if (this->column != obj.column || this->row != obj.row)
		throw runtime_error("First Matrix != Second Matrix");
	Matrix<T> tempMatrix(this->column, this->row);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			tempMatrix.arr[i][j] = this->arr[i][j] / obj.arr[i][j];
		}
	}
	return tempMatrix;
}

template<typename T>
inline Matrix<T>& Matrix<T>::operator*(const Matrix<T>& obj)
{
	if (this->column != obj.column || this->row != obj.row)
		throw runtime_error("First Matrix != Second Matrix");
	Matrix<T> tempMatrix(this->column, this->row);
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			tempMatrix.arr[i][j] = this->arr[i][j] * obj.arr[i][j];
		}
	}
	return tempMatrix;
}

template<typename T>
inline void Matrix<T>::operator=(Matrix<T>& obj)
{
	if (this->arr != nullptr)
		this->~Matrix();
	this->arr = new T * [obj.getRow()];
	for (int i = 0; i < obj.getRow(); i++) {
		this->arr[i] = new T[obj.getColumn()];
	}
	this->column = obj.getColumn();
	this->row = obj.getRow();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			arr[i][j] = obj.arr[i][j];
		}
	}
}

template<typename T>
inline T Matrix<T>::findMin()
{
	T tempEl = arr[0][0];
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			if (tempEl > arr[i][j])
				tempEl = arr[i][j];
		}
	}
	return tempEl;
}

template<typename T>
inline T Matrix<T>::findMax()
{
	T tempEl = arr[0][0];
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			if (tempEl < arr[i][j])
				tempEl = arr[i][j];
		}
	}
	return tempEl;
}

template<typename T>
inline T* Matrix<T>::operator[](int rowIndex)
{
	if (rowIndex >= 0 && rowIndex < row)
		return arr[rowIndex];
}

template<typename T>
inline Matrix<T>::~Matrix()
{
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

template <typename T>
istream& operator>>(istream& in, Matrix<T>& obj)
{
	for (int i = 0; i < obj.getRow(); i++) {
		for (int j = 0; j < obj.getColumn(); j++) {
			cout << "Input element " << i + 1 << " row, " << j + 1<< " column: ";
			in >> obj[i][j];
			cout << endl;
		}
	}
	return in;
}

template <typename T>
ostream& operator<<(ostream& out, Matrix<T>& obj)
{
	for (int i = 0; i < obj.getRow(); i++) {
		for (int j = 0; j < obj.getColumn(); j++) {
			out << obj[i][j] << " ";
		}
		cout << endl;
	}
	return out;
}
