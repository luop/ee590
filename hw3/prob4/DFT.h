#ifndef DFT_H
#define DFT_H

#include <iostream>
#include <stdexcept>
#include "matrix.hh"
#include "ComplexNum.h"

class dft_exception : public std::runtime_error {
public:
  dft_exception(const char msg[]) : std::runtime_error(msg) { }
};

class DFT{
  private :
    int numPoints;
    matrix<ComplexNum> * dftMatrix = NULL;
    matrix<ComplexNum> * unitary = NULL;
    matrix<ComplexNum> * invDFT = NULL;
  public :
    // Constructors and destructors
    DFT(int n);
    ~DFT();

    // The copy constructor
    DFT( const DFT &d );
    //ComplexNum& operator=(const DFT &other);

    inline int getNum(void) const { return numPoints; }

    // Operations
    matrix<ComplexNum> * getDFTMatrix ();
    matrix<ComplexNum> * getUnitary ();
    matrix<ComplexNum> * getInvDFT ();
    matrix<ComplexNum> getDFTSeq ( const matrix<ComplexNum> &inputSeq ) const;
    matrix<ComplexNum> getInvDFTSeq ( const matrix<ComplexNum> &inputSeq ) const;
};

#endif
