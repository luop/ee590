#include <iostream>
#include <math.h>
#include "DFT.h"

#define PI 3.14159265358979323846

DFT::DFT (int n) : numPoints(n){
  getDFTMatrix();
  getUnitary();
  getInvDFT();
}

DFT::~DFT() {
  delete dftMatrix;
  delete unitary;
  delete invDFT;

}

DFT::DFT ( const DFT &d ) {

  numPoints = d.numPoints;

}

matrix<ComplexNum> * DFT::getDFTMatrix (){

  if (! dftMatrix){

    dftMatrix = new matrix<ComplexNum>(numPoints, numPoints);

    ComplexNum A(0, ((-2) * PI)/numPoints);

    for (int j = 0; j < numPoints; j ++){
      for (int k = 0; k < numPoints; k ++){
        (*dftMatrix).set(j, k, (A.expPower()).power(j * k));
      }
    }
  }
  return dftMatrix;
}

matrix<ComplexNum> * DFT::getUnitary (){

  if (dftMatrix && ! unitary){

    unitary = new matrix<ComplexNum>(numPoints, numPoints);
    ComplexNum sq = 1/sqrt(numPoints);

    for (int j = 0; j < numPoints; j ++){
      for (int k = 0; k < numPoints; k ++){
        (*unitary).set(j, k, ((*dftMatrix).get(j, k))*sq);
      }
    }
  }
  return unitary;
}

matrix<ComplexNum> * DFT::getInvDFT (){

  if (! invDFT){

    invDFT = new matrix<ComplexNum>(numPoints, numPoints);

    ComplexNum A(0, ((2) * PI)/numPoints);
    ComplexNum np = numPoints;

    for (int j = 0; j < numPoints; j ++){
      for (int k = 0; k < numPoints; k ++){
        (*invDFT).set(j, k, ((A.expPower()).power(j * k))/np);
      }
    }
  }
  return invDFT;
}

matrix<ComplexNum> DFT::getDFTSeq ( const matrix<ComplexNum> &inputSeq ) const {

  if ( numPoints != inputSeq.rows()){
    throw dft_exception("the number of points in a sequence mismatches with DFT");
  }

  if ( inputSeq.columns() != 1){
    throw dft_exception("Input sequence is represented as an nx1 matrix.");
  }

  return (*dftMatrix).mult(inputSeq);
}

matrix<ComplexNum> DFT::getInvDFTSeq ( const matrix<ComplexNum> &inputSeq ) const {

  if ( numPoints != inputSeq.rows()){
    throw dft_exception("the number of points in a sequence mismatches with DFT");
  }

  if ( inputSeq.columns() != 1){
    throw dft_exception("Input sequence is represented as an nx1 matrix.");
  }

  return (*invDFT).mult(inputSeq);
}
