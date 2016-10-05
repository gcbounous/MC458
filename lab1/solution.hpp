#include "pint.hpp"
#include <vector>
#include <iostream>
using namespace std;

int weightPints(const vector<Pint> & input, int r, int l);

//retornar o indice (começando em 0) da embalagem mais leve
int solution(const vector<Pint> & input) {
	
	return weightPints(input, 0, input.size());

}

int weightPints(const vector<Pint> & input, int r, int l){
	int inputSize = l - r;
	int result;

	if(inputSize == 2){
		result = input[r].compare(input[r+1]);
		if(result == 1){
			return r+1; 
		} else {
			return r;
		}
	}else if(inputSize == 1){
		return r;
	}

	int blockSize = inputSize/3;
  	Pint block1 = Pint(0);
  	Pint block2 = Pint(0);
  	Pint block3 = Pint(0);

	for(int i = r; i < r+blockSize; i++){
		block1 = block1 + input[i];
	}
	for(int i = r+blockSize; i < r+2*blockSize; i++){
		block2 = block2 + input[i];
	}
	for(int i = r+2*blockSize; i < l; i++){
		block3 = block3 + input[i];
	}

	result = block1.compare(block2);
	if(result == 1){
		return weightPints(input, r+blockSize, r+2*blockSize);
	}else if(result == 0){
		return weightPints(input, r+2*blockSize, l);
	}else{
		return weightPints(input, r, r+blockSize);
	}
}
