#include <iostream>
#include <fstream>
#include <cmath>

using std::endl;
using std::cout;
using std::ifstream;
using std::string;
using std::ios;

int main(){
// PART 1
	FILE *my_input;		
	string line;
	int natom;
	my_input = fopen("input/acetaldehyde.dat", "r");

	fscanf(my_input, "%d", &natom);
	int zval[natom];
        double coordinates[natom][3];
	for(int i=0; i < natom; i++)
		fscanf(my_input, "%d %lf %lf %lf",  &zval[i], &coordinates[i][0], &coordinates[i][1], &coordinates[i][2]);
	
	cout << natom << endl;
	for(int i=0; i<natom; i++)
		printf("%d %lf %lf %lf \n",  zval[i], coordinates[i][0], coordinates[i][1], coordinates[i][2]);
	
//PART 2
	double R[natom][natom];	
	double x, y, z;

	for(int i=0; i < natom; i++){
		for(int j=0; j < natom; j++){
			x = coordinates[i][0] - coordinates[j][0];
			y = coordinates[i][1] - coordinates[j][1];
			z = coordinates[i][2] - coordinates[j][2];
			R[i][j] = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		}
	}

//PART 3
	double e[natom][natom][3];
	double theta[natom][natom][natom];
	for(int i=0; i < natom; i++){
		for(int j=0; j < i; j++){
			e[i][j][0] = -(coordinates[i][0] - coordinates[j][0])/R[i][j];
			e[i][j][1] = -(coordinates[i][1] - coordinates[j][1])/R[i][j];
			e[i][j][2] = -(coordinates[i][2] - coordinates[j][2])/R[i][j];
		}
	}
	
	for(int i=0; i < natom; i++){
		for(int j=0; j < i; j++){
			for(int k=0; k < j; k++){
				theta[i][j][k] = acos((-e[i][j][0] * e[j][k][0]) + (-e[i][j][1] * e[j][k][1]) + (-e[i][j][2] * e[j][k][2])) * (180.0 / M_PI); 
				printf("%2d-%2d-%2d %10.6f\n", i, j, k, theta[i][j][k]);
			}
		}
	}
	return 0;
}
