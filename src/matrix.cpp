#include "matrix.h"
#include <cmath>

void Matrix::set_component(size_t x, size_t y, double poids){
	matrix[x][y] = poids;
}

double score_calculation(string sequence){
	double score(0);
	for (size_t i(0); i < sequence.length(); ++i){
		switch (sequence[i]){
			case 'A' : 
			score = score + 2 + log2(matrix[0][i]);
			break;
			case 'C' :
			score = score + 2 + log2(matrix[1][i]);
			break;
			case 'G' :
			score = score + 2 + log2(matrix[2][i]);
			break;
			case 'T' :
			score = score + 2 + log2(matrix[3][i]);
			break;
		}
	}

	return score;
}

double Matrix::get_component(size_t x, size_t y) const{
	return matrix[x][y];
}

bool Matrix::accept(double threshold, string sequence) const{
	if (score_calculation(sequence) > threshold){
		return true;
	} else {
		return false;
	}
}
	


