#include "matrix.h"
#include "ctime"
using namespace std;

int main()
{
    freopen("testData.txt","r",stdin);
    matrix<int> testPlus_A(1000, 1000);
    matrix<int> testPlus_B(1000, 1000);
    matrix<int> intAns(1000, 1000);
    cin >> testPlus_A;
    cin >> testPlus_B;
    clock_t start, finish;
    start = clock();
    intAns = testPlus_A + testPlus_B;
    finish = clock();
    std::cout << "the matrix(1000*1000) plus operation takes"
      << finish-start   << "/" << CLOCKS_PER_SEC  << " (s) "<< endl;

    matrix<double> testMulti_A(1000, 1000);
    matrix<double> testMulti_B(1000, 1000);
    matrix<double> doubleAns(1000, 1000);
    cin >> testMulti_A;
    cin >> testMulti_B;
    start = clock();
    doubleAns = testMulti_A * testMulti_B;
    finish = clock();
    std::cout << "the matrix(1000*1000) multiple operation takes"
      << finish-start   << "/" << CLOCKS_PER_SEC  << " (s) "<< endl;
    return 0 ;
}
/*
the matrix(1000*1000) plus operation takes27/1000 (s)
the matrix(1000*1000) multiple operation takes14698/1000 (s)
*/
