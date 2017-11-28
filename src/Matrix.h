#ifndef MATRIX_
#define MATRIX_

#include <stddef.h>

template <class T>
class Matrix {
private:
	T** matrix;
	int row, col;
private:
	void deleteMatrix();

public:
	Matrix();
	Matrix(int row, int col);
	~Matrix();
	void resize(int row, int col);

	T* operator[](int i);
	const T* operator[](int i) const;
};

template <class T>
Matrix<T>::Matrix() : matrix(NULL) {
}

template <class T>
Matrix<T>::Matrix(int row_, int col_) : row(row_), col(col_), matrix(NULL) {
	resize(row_, col_);
}

template <class T>
Matrix<T>::~Matrix() {
	deleteMatrix();
}

template<class T>
inline void Matrix<T>::resize(int row_, int col_) {
	row = row_;
	col = col_;
	deleteMatrix();
	matrix = new T*[row_];
	for (int i = 0; i < row_; ++i) {
		matrix[i] = new T[col_];
	}
}

template<class T>
inline void Matrix<T>::deleteMatrix() {
	if (matrix) {
		for (int i = 0; i < row; i++) {
			delete[](*this)[i];
		}
		delete[] matrix;
	}
}

template<class T>
inline T * Matrix<T>::operator[](int i) {
	return matrix[i];
}

template<class T>
inline const T * Matrix<T>::operator[](int i) const {
	return matrix[i];
}

#endif