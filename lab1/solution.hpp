#include "pint.hpp"
#include <vector>
#include <iostream>
using namespace std;

//retornar o indice (começando em 0) da embalagem mais leve
int solution(const vector<Pint> & input) {
  int blockSize = input.size()/3;
  cout << blockSize << endl;



  for(int i = 0; i < input.size(); i++){
    cout << input[0].compare(input[i]);
    cout <<"comp: " << Pint::getNumComparisons() << endl;
  }


  // Dicas:
  //soma:
  Pint soma = input[0] + input[1];
  input[0].print();
  cout << " + ";
  input[1].print();
  cout << " = ";
  soma.print();
  cout << endl;

  //tamanho da entrada:
  cout << input.size() << endl;
  // comparando: input[99].compare(input[2]) == 0 // iguais
  //             input[99].compare(input[2]) == -1 // input[99] < input[2]
  //             input[99].compare(input[2]) == 1 // input[99] > input[2]

  return -1;
}
