# gsoc18-codeCompetencyTest
## A frief instruction to matrix.h  

```file included : <vector> <iostream> <cmath> <complex.h>```

class matrix

description
1. data is stored by a 2-dimention vector using ```<vector>```  
2. row and column (the dimention of the matrix) is required before inputting the data
3. operators ```(including >> , << , + , - , += , -= , * , *= )``` have been overloaded
4. complex type is supported by ```<cmath> and <complex.h>```

instructions
1. zero() ===> set all elements to zero
2. resize(int row, int col)  ===> change the row and column then set all elements to zero

complex support  

complex<T> complexExample(T real, T img)
