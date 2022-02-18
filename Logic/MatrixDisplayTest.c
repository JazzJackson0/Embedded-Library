#include <assert.h>
#include <stdlib.h>
#include "MatrixDisplay.h"

double testMatrix[3][3] = { 
	{0.45, 694.8, 97.3},
	{46.7, 92.6, 0},
	{1.0, 13.5, 0.0}
};
void Matrix_DisplayTest();

int main(int argc, char *argv[]) {

	Matrix_DisplayTest();
    return 0;
}


void Matrix_DisplayTest() {
    Matrix_Display(testMatrix);
}