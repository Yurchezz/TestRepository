//Vasiya
#include<stdio.h>
#include<conio.h>
#include<math.h>
void Show_2d(int *mass[], int rows, int colls);
void Show_1d(double *mass, int n);
void Sort(int * mass[], int rows, int colls);
void ArifMiddle_2d(double *mass_1d, int *mass_2d[], int rows, int colls);
double Multiple(double *mass_1d, int rows);
void EnterMass(int *mass[], int rows, int colls);
main() {

	int mass_2d[5][5] = {
		40,72,6,92,98,
		18,-33,-48,81,26,
		1,-4,6,-2,0,
		36,9,0,4,1,
		-55,2,66,70,-3
	};

	

	int *mass_2d_p[5];
	for (int i = 0; i < 5; i++) {
		mass_2d_p[i] = mass_2d[i];
	}



	//printf("Enter 5x5 array:\n");
	//EnterMass(mass_2d_p, 5, 5);




	Show_2d(mass_2d_p, 5, 5);
	Sort(mass_2d_p, 5, 5);
	Show_2d(mass_2d_p, 5, 5);

	double mass_1d[5];
	double *mass_1d_p = mass_1d;
	printf("Arifm middle of each row:");
	ArifMiddle_2d(mass_1d_p, mass_2d_p, 5, 5);
	Show_1d(mass_1d_p, 5);

	printf("\nArifm middle of massive above:");
	printf(" %4.2lf", Multiple(mass_1d_p, 5));

	_getch();
}

void EnterMass(int *mass[], int rows, int colls) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			scanf_s("%d", &mass[i][j]);
		}
	}
}
void Show_2d(int *mass[], int rows, int colls) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			printf(" %4.1d ", mass[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void Show_1d(double *mass, int n) {

	for (int i = 0; i < n; i++) {
		printf(" %4.2lf", mass[i]);
	}
	printf("\n");
}
void ArifMiddle_2d(double *mass_1d, int *mass_2d[], int rows, int colls) {
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			sum += mass_2d[i][j];
		}
		mass_1d[i] = sum / rows;

		sum = 0;
	}

}
double Multiple(double *mass_1d, int rows) {
	double sum = mass_1d[0];
	for (int i = 1; i < rows; i++) {
		sum *= mass_1d[i];
	}

	return sum;

}



void Sort(int * mass[], const int rows, const int colls) {

	int tmp = 0;


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colls; j++)
		{
			for (int k = 0; k < rows; k++)
			{
				
					if (mass[j][i] <  mass[k][i])
					{

						tmp = mass[j][i];
						mass[j][i] = mass[k][i];
						mass[k][i] = tmp;

					}
				
			}
		}
	}
}