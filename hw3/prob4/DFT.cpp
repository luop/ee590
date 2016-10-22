#include <iostream>
#include "DFT.h"

DFT::DFT (int n) : numPoints(n){
  getDFTMatrix();
}

DFT::~DFT() {
  delete dftMatrix;
  delete unitary;
  delete invUnitary;

}

DFT::DFT ( const DFT &d ) {

  numPoints = d.numPoints;

}

matrix<ComplexNum>& DFT::getDFTMatrix (){

  if (dftMatrix){
    std::cout << "Matrix is not null" << std::endl;
  }else{
    std::cout << "Matrix is null" << std::endl;
    dftMatrix = new matrix<ComplexNum>(numPoints, numPoints);
  }
  return *dftMatrix;
}
