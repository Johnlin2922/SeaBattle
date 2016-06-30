#include "util.h"

/* UTILITY FUNCTIONS */

int randint(int max) {
	
	/* Generate pseudorandom number */
	/* 0 <= N < MAX */

	return ( rand() % max );

} // End randint()


void skip_to_int() {
	
	/* Reads from standard input until an integer character is found */
	/* (Copied from sample code provided in "Errors, Part 2" lecture notes) */
	
	if ( cin.fail() ) {                       // We found something that isn't an integer
   
		cin.clear();                          // We'd like to look at the characters
		char ch;
      
		while ( cin >> ch ) {                 // Throw away non-digit characters
      
			if ( isdigit(ch) || ch == '-' ) { // We found a digit or a '-'
         	
				cin.unget();                  // Put the digit back so we can read it
				return;
            
			}
         
		}
      
	}
   
	throw runtime_error("No input!");         // eof() or bad(): give up
   
}


int get_int() {
	
	/* Read an integer from standard input */
	/* (Copied from sample code provided in "Errors, Part 2" lecture notes) */
	
	int n = 0;
	
	while (true) {
		
		if ( cin >> n )
			return n;
			
		skip_to_int();
		
	}
	
}
