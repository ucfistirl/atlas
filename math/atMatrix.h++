
// ATLAS: Adaptable Tool Library for Advanced Simulation
//
// Copyright 2015 University of Central Florida
//
//
// This library provides many fundamental capabilities used in creating
// virtual environment simulations.  It includes elements such as vectors,
// matrices, quaternions, containers, communication schemes (UDP, TCP, DIS,
// HLA, Bluetooth), and XML processing.  It also includes some extensions
// to allow similar code to work in Linux and in Windows.  Note that support
// for iOS and Android development is also included.
//
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#ifndef AT_MATRIX_HPP
#define AT_MATRIX_HPP

class atMatrix;

#include <stdio.h>

#include "atGlobals.h++"
#include "atItem.h++"
#include "atOSDefs.h++"
#include "atQuat.h++"
#include "atVector.h++"


class ATLAS_SYM atMatrix : public atItem
{
private:

    // Internal storage for this object is a set of four atVectors
    // representing the four rows of the matrix.
    atVector    data[4];

public:

                      atMatrix();
                      atMatrix(double values[4][4]);
    virtual           ~atMatrix();

    void              set(double values[4][4]);
    void              copy(const atMatrix &source);

    void              clear();
    
    void              setValue(int row, int column, double value);
    double            getValue(int row, int column) const;
    bool              isEqual(const atMatrix &operand) const;
    bool              isAlmostEqual(const atMatrix &operand, 
                                    double tolerance) const;

    void              add(const atMatrix &addend);
    atMatrix          getSum(const atMatrix &addend) const;
    void              subtract(const atMatrix &subtrahend);
    atMatrix          getDifference(const atMatrix &subtrahend) const;
    void              scale(double multiplier);
    atMatrix          getScaled(double multiplier) const;
    void              transpose();
    atMatrix          getTranspose() const;
    
    double            getDeterminant() const;
    void              invert();
    atMatrix          getInverse() const;
    void              invertRigid();
    atMatrix          getInverseRigid() const;
    
    void              preMultiply(const atMatrix &operand);
    atMatrix          getPreMultiplied(const atMatrix &operand) const;
    void              postMultiply(const atMatrix &operand);
    atMatrix          getPostMultiplied(const atMatrix &operand) const;
    
    atVector          getPointXform(const atVector &operand) const;
    atVector          getVectorXform(const atVector &operand) const;
    atVector          getFullXform(const atVector &operand) const;
    
    void              setIdentity();
    bool              isIdentity();
    void              setEulerRotation(atMathEulerAxisOrder axisOrder,
                                 double axis1Degrees, double axis2Degrees,
                                 double axis3Degrees);
    void              getEulerRotation(atMathEulerAxisOrder axisOrder,
                                 double *axis1Degrees, double *axis2Degrees,
                                 double *axis3Degrees) const;
    void              setQuatRotation(const atQuat &quat);
    void              setTranslation(double dx, double dy, double dz);
    void              getTranslation(double *dx, double *dy, double *dz) const;
    atVector          getTranslation() const;
    void              setScale(double sx, double sy, double sz);
    void              getScale(double *sx, double *sy, double *sz) const;

    atVector          &operator[](int index);
    const atVector    &operator[](int index) const;
    atMatrix          operator+(const atMatrix &addend) const;
    atMatrix          operator-(const atMatrix &subtrahend) const;
    atMatrix          operator*(const atMatrix &operand) const;
    void              operator+=(const atMatrix &addend);
    void              operator-=(const atMatrix &subtrahend);
    bool              operator==(const atMatrix &operand) const;

    void              printRow(int rowNum) const;
    void              printRow(int rowNum, FILE *fp) const;

    void              print() const;
    void              print(FILE *fp) const;

    void              readRow(int rowNum);
    void              readRow(int rowNum, FILE *fp);
    void              read();
    void              read(FILE *fp);

    virtual bool      equals(atItem * otherItem);
    virtual int       compare(atItem * otherItem);
};

#endif
