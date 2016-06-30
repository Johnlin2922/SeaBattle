#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Coordinate {

	int row;
	int col;

};

class Grid {

	public:
		
		Grid(int, string);            /* CONSTRUCTOR */
		void set(Coordinate, char);   /* Set Grid Character (using coordinate) */
		char get(Coordinate);         /* Get Grid Character (using coordinate) */
		void set(int, int, char);     /* Set Grid Character (using row/col pair) */
		char get(int, int);           /* Get Grid Character (using row/col pair) */
		void print();                 /* Print Grid */

	private:

		vector< vector<char> > grid;  /* Grid (2D Vector) */
		int size;                     /* Grid Size */
		string name;                  /* Grid Name */
	
};
