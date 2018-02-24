/*
    Date: 2018/2/24
    Author: Sheldon Zhang
    School: Beijing University of Posts and Communications(BUPT)
    Description: A simple support for matrix
*/
#include <vector>
#include <iostream>
#include "cmath"
#include "complex.h"
using namespace std;

template <typename T>
class matrix;

template <typename T>
istream & operator >> (istream &is, matrix<T> & obj);

template <typename T>
ostream & operator << (ostream &os, matrix<T> const & obj);

template <typename T>
class matrix
{
private:
    friend istream & operator >> <>(istream &is, matrix<T> & obj);
    friend ostream & operator << <>(ostream &os, matrix<T> const & obj);
private:
    int row, col;
    vector<vector<T> > data;
private:
    void zero();
public:
    matrix();
    matrix(int inputRow, int inputCol);
    matrix(const matrix<T> &obj);
    matrix(const matrix<T> *obj);
    ~matrix();

    matrix<T> operator + (const matrix<T> &rhs);
    matrix<T> operator - (const matrix<T> &rhs);
    matrix<T> operator * (const matrix<T> &rhs);
    matrix<T> & operator = (const matrix<T> &rhs);
    void operator *= (const matrix<T> &rhs);
    void operator += (const matrix<T> &rhs);
    void operator -= (const matrix<T> &rhs);
    void resize(int row, int col);
};
/*----------------------------------------------------*/
IMPLEMENT
/*----------------------------------------------------*/
template <typename T>
istream & operator >> (istream &is, matrix<T> &obj)
{
    for(int i = 0; i < obj.row; i++)
        for(int j = 0; j < obj.col; j++)
            is >> obj.data[i][j];
    return is;
}
template <typename T>
ostream & operator << (ostream &os, matrix<T> const &obj)
{
    os << "[" << endl;
    for(int i = 0; i < obj.row; i++)
    {
        os << "[ ";
        for(int j = 0; j < obj.col; j++)
            os << obj.data[i][j] << " ";
    os << " ]" <<endl;
    }
    os << "]";
    return os;
}
template <typename T>
matrix<T>::matrix()
{
    row = 0; col = 0;
    data.resize(0, vector<T>(0));
}
template <typename T>
matrix<T>::matrix(int inputRow, int inputCol)
{
    if(inputRow <= 0 || inputCol <= 0)
        std::cerr << "Invalid Parameter" << '\n';

    row = inputRow;
    col = inputCol;
    data.resize(row, vector<T>(col));
    zero();
}
template <typename T>
matrix<T>::matrix(const matrix<T> &obj)
{
    col = obj.col;
    row = obj.row;
    data.resize(row, vector<T>(col));
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            data[i][j] = obj.data[i][j];
}
template <typename T>
matrix<T>::matrix(const matrix<T> *obj)
{
    col = obj->col;
    row = obj->row;
    data.resize(row, vector<T>(col));
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            data[i][j] = obj->data[i][j];
}
template <typename T>
matrix<T>::~matrix()
{
    row = 0;
    col = 0;
}
template <typename T>
void matrix<T>::zero()
{
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col ;j++)
            data[i][j] = 0;
}
template <typename T>
matrix<T> matrix<T>::operator + (const matrix<T> &rhs)
{
    cout << "a" << endl ;
    cout << rhs.data.size() << " " << rhs.data[0].size() << endl ;

    if(row != rhs.row || col != rhs.col)
          std::cerr << "the dimension is not the same" << '\n';
    matrix<T> matrixTemp(rhs.data.size(), rhs.data[0].size());

    cout << matrixTemp.data.size() << " " << matrixTemp.data[0].size() << endl;

    for(int i = 0; i < rhs.data.size(); i++)
        for(int j = 0; j < rhs.data[0].size(); j++)
            matrixTemp.data[i][j] = this->data[i][j] + rhs.data[i][j];
    return matrixTemp;
}
template <typename T>
matrix<T> matrix<T>::operator - (const matrix<T> &rhs)
{
    if(row != rhs.row || col != rhs.col)
        std::cerr << "the dimension is not the same" << '\n';

    matrix<T> matrixTemp(rhs);
    for(int i = 0; i < rhs.data.size(); i++)
        for(int j = 0; j < rhs.data[0].size(); j++)
            matrixTemp.data[i][j] = this->data[i][j] - rhs.data[i][j];
    return matrixTemp;
}
template <typename T>
matrix<T> matrix<T>::operator * (const matrix<T> &rhs)
{
    if(this->data[0].size() != rhs.data.size())
        std::cerr << "matrix A can not be multiplied by matrix B" << '\n';
    matrix<T> matrixTemp(this->row, rhs.col);
    for(int i = 0; i < this->row; i++)
        for(int j = 0; j < this->col; j++)
            for(int k = 0; k < rhs.col; k++)
                matrixTemp.data[i][k] += this->data[i][j] * rhs.data[j][k];
    return matrixTemp;
}
template <typename T>
matrix<T>& matrix<T>::operator = (const matrix<T> &rhs)
{
    this->row = rhs.row;
    this->col = rhs.col;
    this->data.resize(row, vector<T>(col));
    this->data = rhs.data;
    return *this;
}
template <typename T>
void matrix<T>::operator += (const matrix<T> &rhs)
{
    for(int i = 0; i < this->row; i++)
        for(int j = 0; j < this->col; j++)
            this->data[i][j] = this->data[i][j] + rhs.data[i][j];
}
template <typename T>
void matrix<T>::operator -= (const matrix<T> &rhs)
{
    for(int i = 0; i < this->row; i++)
        for(int j = 0; j < this->col; j++)
            this->data[i][j] = this->data[i][j] - rhs.data[i][j];
}
template <typename T>
void matrix<T>::operator *= (const matrix<T> &rhs)
{
    matrix<T> matrixTemp(this);
    this->resize(this->row, rhs.col);
    for(int i = 0; i < matrixTemp.row; i++)
        for(int j = 0; j < matrixTemp.col; j++)
            for(int k = 0; k < rhs.col; k++)
                this->data[i][k] += matrixTemp.data[i][j] * rhs.data[j][k];
}
template <typename T>
void matrix<T>::resize(int inputRow, int inputCol)
{
    row = inputRow; col = inputCol;
    data.resize(row, vector<T>(col));
    zero();
}
