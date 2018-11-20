#include<stdio.h>
#include<conio.h>
#include<math.h>
void showTwoDimentionalArray(int *mass[], int rows, int colls);
void showOneDimentionalArray(double *mass, int n);
void bubleSortInCollumns(int * mass[], int rows, int colls);
void arifmeticalAverageInRows(double *oneDimentionalArray, int *twoDimentionalArray[], int rows, int colls);
double multiplyArrayElements(double *oneDimentionalArray, int rows);
void enterArray(int *mass[], int rows, int colls);
main() {

	int twoDimentionalArray[5][5] = {
		40,72,6,92,98,
		18,-33,-48,81,26,
		1,-4,6,-2,0,
		36,9,0,4,1,
		-55,2,66,70,-3
	};

	

	int *twoDimentionalArrayPointer[5];
	for (int i = 0; i < 5; i++) {
		twoDimentionalArrayPointer[i] = twoDimentionalArray[i];
	}

	showTwoDimentionalArray(twoDimentionalArrayPointer, 5, 5);
	bubleSortInCollumns(twoDimentionalArrayPointer, 5, 5);
	showTwoDimentionalArray(twoDimentionalArrayPointer, 5, 5);

	double oneDimentionalArray[5];
	double *oneDimentionalArrayPointer = oneDimentionalArray;
	printf("Arifmetical average of each row:");
	arifmeticalAverageInRows(oneDimentionalArrayPointer, twoDimentionalArrayPointer, 5, 5);
	showOneDimentionalArray(oneDimentionalArrayPointer, 5);

	printf("\nArifm middle of massive above:");
	printf(" %4.2lf", multiplyArrayElements(oneDimentionalArrayPointer, 5));

	_getch();
}

void enterArray(int *twoDimentionalArray[], int rows, int colls) {
	for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
		for (int collumnIndex = 0; collumnIndex < colls; collumnIndex++) {
			scanf_s("%d", &twoDimentionalArray[rowIndex][collumnIndex]);
		}
	}
}
void showTwoDimentionalArray(int *twoDimentionalArray[], int rows, int colls) {

	for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
		for (int collumnIndex = 0; collumnIndex < colls; collumnIndex++) {
			printf(" %4.1d ", twoDimentionalArray[rowIndex][collumnIndex]);
		}
		printf("\n");
	}
	printf("\n");
}
void showOneDimentionalArray(double *oneDimentionalArray, int arrayLenth) {

	for (int index = 0; index < arrayLenth; index++) {
		printf(" %4.2lf", oneDimentionalArray[index]);
	}
	printf("\n");
}
void arifmeticalAverageInRows(double *oneDimentionalArray, int *twoDimentionalArray[], int rows, int colls) {
	double rowSum = 0;
	for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
		for (int collumnIndex = 0; collumnIndex < colls; collumnIndex++) {
			rowSum += twoDimentionalArray[rowIndex][collumnIndex];
		}
		oneDimentionalArray[rowIndex] = rowSum / rows;

		rowSum = 0;
	}

}
double multiplyArrayElements(double *oneDimentionalArray, int rows) {
	double multiplyResult = oneDimentionalArray[0];
	for (int index = 1; index < rows; index++) {
		multiplyResult *= oneDimentionalArray[index];
	}

	return multiplyResult;

}

void bubleSortInCollumns(int * twoDimentionalArray[],  int rows,  int colls) {

	int temporaryVariable = 0;


	for (int rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		for (int collumnIndex = 0; collumnIndex < colls; collumnIndex++)
		{
			for (int secondaryRowIndex = 0; secondaryRowIndex < rows; secondaryRowIndex++)
			{
				
					if (twoDimentionalArray[collumnIndex][rowIndex] <  twoDimentionalArray[secondaryRowIndex][rowIndex])
					{

						temporaryVariable = twoDimentionalArray[collumnIndex][rowIndex];
						twoDimentionalArray[collumnIndex][rowIndex] = twoDimentionalArray[secondaryRowIndex][rowIndex];
						twoDimentionalArray[secondaryRowIndex][rowIndex] = temporaryVariable;

					}
				
			}
		}
	}
}