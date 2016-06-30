#include "grid.h"

Grid::Grid(int s, string n) {
	
	/* CONSTRUCTOR */
	
	size = s;
	name = n;
	grid = vector< vector<char> >(size, vector<char>(size, '-'));
	
}

void Grid::set(int x, int y, char k) {
	
	/* Sets Grid Cell (cell 0,0 is in upper left corner!) */
	
	grid[y][x] = k;
	
}

char Grid::get(int x, int y) {
	
	/* Returns Grid Cell (cell 0,0 is in upper left corner!) */
	
	return grid[y][x];
	
}

void Grid::set(Coordinate c, char k) {
	
	/* Sets Grid Cell (cell 0,0 is in upper left corner!) */
	
	grid[c.row][c.col] = k;
	
}

char Grid::get(Coordinate c) {
	
	/* Returns Grid Cell (cell 0,0 is in upper left corner!) */
	
	return grid[c.row][c.col];
	
}

void Grid::print() {
	
	/* Prints grid name and contents to the screen */

	cout << setw(12) << left << name << "  1  2  3  4  5  6  7  8  9  10\n" << right;

	for (int i = 0; i < grid.size(); ++i) {				// Loop through rows

		cout << setw(12) << char(i + 'A') << ' ';		// Print row label

		for (int j = 0; j < grid[i].size(); ++j) {		// Loop through columns

			switch( grid[i][j] ) {

				case '-': case '/': case 'X':			// Non-ship pieces enclosed in spaces
					cout << ' ' << grid[i][j] << ' ';
					break;
				default:
					cout << '[' << grid[i][j] << ']';	// Ship pieces enclosed in square brackets

			} // end switch

		} // end for (columns)

		cout << '\n';

	} // end for (rows)
	
} // end print()
