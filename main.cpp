#include "Functions1.h"

bool checking(const int* row, const size_t size) {
unsigned short Positive = 0;
unsigned short Negative = 0;

		 for (size_t i = 0; i < size; i ++ ) {
		 if (row[i] > 0)
		 Positive ++ ;
		 else if (row[i] < 0)
		 Negative ++ ;
		
	}
	
		 return Positive > Negative;

}

float processing(Matrix * M) {
float Rows = 0; 
float Sum = 0;

		 for (size_t i = 0; i < (M ->rows); i ++ ) {
		 if (checking(M -> data[i], M -> cols)) {
			 int rowSum = 0; 
			
				
				 for (size_t j = 0; j < M ->cols; j ++ ) {
				 rowSum += M -> data[i][j];
				
			}
			
			Rows ++ ;
			Sum += rowSum;
			
		}

	}

		 return Sum / Rows;
	
}
