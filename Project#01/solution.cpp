#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>

int main(){
//Step 1: Read the Coordinate Data from Input

	//check if you are able to open up the molcule file first
	std::ifstream input("input/acetaldehyde.dat");
	if (!input.is_open()){
		std::cerr << "Uninstall yourself.\n";
	       return 1;
	}

	int natom; //number of atoms in the molecule
	input >> natom;
	double numero; //using it to read the inputs of the molecule file
	std::vector<int> Z_val(natom); //atomic number of a said atom
  	std::vector<double> x_vect(natom); // x values
  	std::vector<double> y_vect(natom); // y ''
  	std::vector<double> z_vect(natom); // z ''

	std::cout << "Number of atoms: " << natom << "\n";
	std::cout << "Input Cartesian coordinates:\n";
	for(int i=0; i < natom; i++)
	{
		input >> numero;
		Z_val[i] = numero;
		input >> std::fixed >> std::setprecision(12) >> numero;
		x_vect[i] = numero;
		input >> std::fixed >> std::setprecision(12) >> numero;
		y_vect[i] = numero;
		input >> std::fixed >> std::setprecision(12) >> numero;
		z_vect[i]= numero;
		printf("%d %20.12f %20.12f %20.12f\n", (int) Z_val[i], x_vect[i], y_vect[i], z_vect[i]);
	}		

	input.close();

//Step 2 Bond Lengths
	std::vector<std::vector<double>> x(natom, std::vector<double>(natom, 0.0));
	std::vector<std::vector<double>> y(natom, std::vector<double>(natom, 0.0));
	std::vector<std::vector<double>> z(natom, std::vector<double>(natom, 0.0));
	//double xij, yij, zij;
	std::vector<std::vector<double>> R(natom, std::vector<double>(natom, 0.0));
	
	std::cout << "Interatomic distances (bohr):\n";

	for(int i=1; i < natom; i++){
		for(int j=0; j < i; j++){
			x[i][j] = x_vect[i] - x_vect[j];
			y[i][j] = y_vect[i] - y_vect[j];
			z[i][j] = z_vect[i] - z_vect[j];
			R[i][j] = sqrt(pow(x[i][j],2) + pow(y[i][j],2) + pow(z[i][j],2));
			std::cout << i << " " << j << " " << R[i][j] << " \n";
		}
	}

//Step 3 Angles
	
	return 0;
}
