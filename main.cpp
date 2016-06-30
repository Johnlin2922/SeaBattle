#include <ctime>
#include "util.h"

/* CONSTANT DEFINITIONS */

const int GRID_SIZE = 10;				/* Height and width of grid */
const int NUM_SHIPS = 9;				/* Number of ships in fleet */


/* FUNCTION PROTOTYPES */

void arrange_fleet(Grid&);				/* Randomly deploy fleet to player's primary grid */
Coordinate get_coordinate();			/* Get row/col from player; return as Coordinate object */


/* FUNCTION DEFINITIONS */

int main(int argc, char** argv) {
	
	/* Seed pseudorandom number generator */

	srand( time(NULL) );
	
	/* Initialize grids */

	Grid primary(GRID_SIZE, "PRIMARY");
	Grid tracking(GRID_SIZE, "TRACKING");
	
	/* Initialize state variables */

	int num_player_ships = NUM_SHIPS;	/* Player Ship Counter */
	int num_opponent_ships = NUM_SHIPS;	/* Opponent Ship Counter */
	
	int player_num = 0;					/* Player ID (1 or 2) */
	int player_first = 0;				/* First Player (1 or 2) */

	bool player_turn = false;			/* "Turn Over" Flag */
	bool game_over = false;				/* "Game Over" Flag */

	char player_input;					/* Holds Player Input */
	char opponent_target;				/* Holds Opponent Target Cell Contents */
    bool loop = true;

	Coordinate cell;					/* Holds Player's Coordinate Input */

	/* Print Greeting */

	cout << "Welcome to SEA BATTLE!\n\n";
	
	/* Get Player ID */
	
	while ( !player_num ) {
	
		cout << "Will you play as Player (1) or as Player (2)? ";
		player_num = get_int();
		
		if (player_num < 1 || player_num > 2 ) /* Reject Invalid Input */
		
			player_num = 0;
		
	}
	
	/* Who Goes First? */
	
	while ( !player_first ) {
	
		cout << "Which player will take the first turn (1/2)? ";
		player_first = get_int();
		
		if (player_first < 1 || player_first > 2 ) /* Reject Invalid Input */
		
			player_first = 0;
		
	}
	
	/* Is it my turn?  If so, flip "player_turn" to true */
	
	if ( player_num == player_first ) 
		
		player_turn = true;
   
	/* Arrange Fleet */

	arrange_fleet(primary);
    
    
	/* MAIN GAME LOOP */

	while ( !game_over ) {

		/* Print Grids */

		cout << '\n';

		primary.print();
		tracking.print();

		/* Print fleet counts for player and opponent */
        
		cout << "Player: " << num_player_ships << ", Opponent: " << num_opponent_ships << ".  ";
    
		/* Is it the player's turn? */

		if ( player_turn ) {
            loop = true;
			/* Prompt the player to enter target coordinates */
            
            cout << "Choose Your Target (in tracking grid): ";
            
            while (loop == true){
                cell = get_coordinate();
                
                switch (tracking.get(cell)){
                        
                    case '/' : case 'X' :  cout << "Sorry, You already picked that one. Try again: ";
                        break;
                        
                    case '-' : //tracking.set(cell, '/');
                        loop = false;
                        break;
                        
                    default : //tracking.set(cell, 'X');
                        
                        loop = false;
                        break;
                }
                
                
                
            }
			/* Get coordinates */

			/* Prompt for result */
            

			/* Was it a miss?  If so, place a splash mark into the tracking grid cell */
            
            cout <<  "Was this a (M)iss, a (H)it, or a (S)ink? ";
            cin >> player_input;
            player_input = toupper(player_input);
          
            if (player_input == 'M'){
               
                tracking.set(cell , '/');
            
            }
            if (player_input == 'H'){
                
                tracking.set(cell , 'X');
                
                
            }
            if (player_input == 'S'){
                
                --num_opponent_ships;
                tracking.set(cell , 'X');
                
            }
			/* Was it a hit or a sink?  If so, place a "bang mark" into the tracking grid cell */

			/* Was it a sink?  If so, decrement the opponent's fleet count */

			/* It is now the opponent's turn */

			player_turn = false;

		} // end if()

		/* Is it the opponent's turn? */

		else {

			/* Ask the opponent to select target coordinates */
            loop = true;
            
            cout<< "Ask Opponent For Target: ";
            while (loop == true){
                cell = get_coordinate();
                
                switch (primary.get(cell)){
                        
                    case '/' : case 'X' :  cout << "Sorry, You already picked that one. Try again: ";
                        break;
                        
                    case '-' : primary.set(cell, '/');
                                loop = false;
                        break;
                        
                    default : primary.set(cell, 'X');
                        
                        cout << "*    *    *    *    B    O    O    M    *    *    *    *\n";
                        cout << "Did it sink the ship? ";
                        cin >> player_input;
                        player_input = toupper(player_input);
                        if (player_input == 'Y'){
                            
                           --num_player_ships;
                        }
                        if (player_input == 'S'){
                            
                            --num_player_ships;
                        }
                        
                        if (player_input == 'N'){
                            
                            
                        }

                        loop = false;
                        break;
                }
                
            
            
            }

			/* Find out what was in the target cell (in primary grid) */

			/* Was the cell occupied? (does the cell contain something other than '-' or '/') */

			/* If so, place a "bang mark" into the primary grid cell */

			/* Create an explosion */
            
			/* Did this hit sink a ship? (ask the player) */

			/* If so, decrement player's fleet count */

			/* Was the cell empty? */
			
			/* If so, place a "splash mark" into the primary grid cell */

			/* It is now the player's turn */

			player_turn = true;

		} // end else()

		/* Before starting the next turn, check if the game is over */

		if ( num_player_ships == 0 || num_opponent_ships == 0 )

			game_over = true;

	} // end while()



	/* GAME IS OVER */

	/* Did player win? */

	if ( num_player_ships == 0 )
		cout << "GAME OVER: Your opponent sank your fleet!\n\n";

	/* Did opponent win? */

	else if ( num_opponent_ships == 0 )
		cout << "CONGRATULATIONS!  You sank your opponent's fleet!\n\n";

	/* Print exit message; wait for input */

	cout << "Thanks for playing!  Enter X to exit:";
	cin >> player_input;

	/* EXIT */

	return 0;
	
}


void arrange_fleet(Grid& grid) {

	/* Define Number, type, and length of ships in the fleet */

	char ship_type[] = { 'A', 'B', 'C', 'C', 'S', 'S', 'P', 'P', 'P' };
	int ship_size[] = { 5, 4, 3, 3, 3, 3, 2, 2, 2 };

	/* Define State Variables */

	int alignment = 0;	/* Ship Alignment (0=horizontal, 1=vertical) */
	int row = 0;		/* Column of First Ship Cell (chosen at random) */
	int col = 0;		/* Row of First Ship Cell (chosen at random) */
	int emptycount = 0;	/* Empty Space Counter */
	int length = 0;		/* Ship Length */
	char ship;			/* Ship Character */
	bool empty;			/* Empty Ship Footprint */
    //int lengthup = 0;
    //int rowup = 0;
    //int colup = 0;
    
    

	/* Arrange Ships */

	for (int i = 0; i < NUM_SHIPS; ++i) {

		empty = false;

		ship = ship_type[i];
		length = ship_size[i];

		/* Begin search for empty footprint for next ship */

		while ( empty == false ) {

			/* Reset empty space counter */

			emptycount = 0;

			/* Select alignment and initial row/column of footprint at random */
			
			alignment = randint(2); // (0 is horizontal, 1 is vertical)
            
            //lengthup = length + 1;

			if (alignment == 1) {
                
                col = randint(GRID_SIZE);
                row = randint(GRID_SIZE  - length + 1);
                
                
              
                
				/* Ship will be vertical; select row within range! */
                
                //if (grid.get(col, row) == '-'){
                    
                   // emptycount++;
                    
                    for (int i = 0; i < length; ++i) {
                        
                        //colup = col + 1;
                        //rowup = row + 1;
                    
                        if ( grid.get(col, row + i) == '-' ){
                            //cout << emptycount;
                            emptycount++;
                        
                        }
                    
                        
                    }
                //}
            }
            
            else if (alignment == 0){
                
                col = randint(GRID_SIZE - length + 1);
                row = randint(GRID_SIZE);
                
                
				/* Ship will be horizontal; select column within range! */
                
                
                
                //if (grid.get(col, row) == '-'){
                    
                    //emptycount++;
                    
                    for (int i = 0; i < length; ++i) {
                        
                        //colup = col + 1;
                        //rowup = row + 1;
                        
                        if ( grid.get(col + i, row) == '-' ) {
                            
                         //cout << emptycount;
                            
                            emptycount++;
                            
                        }
                        
                        
                    }
                //} // end if coord == -
				
            }  //end if alignment

			/* Count empty spaces within footprint */

			/* If vertical, check for empty spaces in next rows */
            
            
           // cout << emptycount;
			/* If horizontal, check for empty spaces in next columns */

			/* If empty space count equals ship length, footprint is not occupied; end search */

			if ( emptycount == length ) {

				empty = true;

			}
            emptycount = 0;

		} // end while()

		/* Place ship inside empty footprint */

		for (int j = 0; j < length; ++j) {

			if ( alignment ) {

				grid.set(col, row + j, ship);

			}

			else {

				grid.set(col + j, row, ship);

			}
            
            

		} // end for()

	} // end for()
    
   // cout << grid.get(3, 6);

}


Coordinate get_coordinate() {
	
	/* Read a row/column pair from standard input and populate a Coordinate return value */
	/* (Adapted from sample code provided in "Errors, Part 2" lecture notes) */

	char c;
	int n;
	Coordinate coordinate;

	while (true) {

		cin >> c;											// Read row (a char)
		c = toupper(c);

		n = get_int();										// Read column (an int)

		if ( 1 <= n && n <= GRID_SIZE ) {					// Check if row is in range

			if ( 'A' <= c && c < ('A' + GRID_SIZE) ) {	    // Check if column is in range

				coordinate.row = c - 'A';					// If in range, convert row letter to row index
				coordinate.col = n - 1;						// If in range, convert column number to column index
                
				return coordinate;

			}

		}

		cout << "Please Try Again: ";						// If not in range, print error and repeat

	}

}

