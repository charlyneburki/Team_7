#include "matrix.h"
#include <cmath>
using namespace std;

Matrix::Matrix(){
	for (size_t i(0); i < matrix.size() ; ++i){
		for (size_t j(0); j < 4 ; ++j){
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(vector < array <double, 4> > m){
	for (size_t i(0); i < matrix.size() ; ++i){
		for (size_t j(0); j < 4 ; ++j){
			matrix[i][j] = m[i][j];
		}
	}
}

void Matrix::set_component(size_t x, size_t y, double poids){
	matrix[x][y] = poids;
}

double Matrix::score_calculation(string sequence) const{
	double score(0);
	for (size_t i(0); i < sequence.length(); ++i){
		switch (sequence[i]){
			case 'A' : 
			score = score + 2 + log2(matrix[i][0]);
			break;
			case 'C' :
			score = score + 2 + log2(matrix[i][1]);
			break;
			case 'G' :
			score = score + 2 + log2(matrix[i][2]);
			break;
			case 'T' :
			score = score + 2 + log2(matrix[i][3]);
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
	


