#include <string>

using namespace std;

class Molecule
{
	public:
		int natom;
		int charge;
		int *zvals;
		double **geom;
		string point_group;

		void print_geom();
		void rotate(double phi);
		void translate(double x, double y, double z);
		double bond(int atom1, int atom2);
		double angle(int atom1, int atom2, int atom3);
		double torsion(int atom1, int atom2, int atom3, int atom4);

		Molecule();
		~Molecule();
};
