#pragma once
#ifndef FUNC_H
#define FUNC_H

 #include <cstdlib>
 #include <ctime>

 struct Matrix {
	 size_t rows = 0; 
		size_t cols = 0; 
		int** data = nullptr; 
		
};

 Matrix * creating_matrix(size_t rows, size_t cols);
 void randomization(Matrix*);
 void deleting_matrix(Matrix*);

 #endif
