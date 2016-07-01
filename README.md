# SeaBattle!!!
Welcome to SeaBattle!!! This was the third project in Computer Programming I (C++). This game was written to be multiplayer with two instances running on two separate machines. This game was heavely inspired by the popular game "Battleship". Despite it completely being in a command line environment, it still provides the full experience including the hit, miss, and sink system. 

##Instructions
**If you are running windows, simply open the "SeaBattle!!!.exe" file to start playing.**

**If not, you need a compilier to compile it for your machine's language first to play.**

This is a two player game to make sure to open two instances on two machines. The first player will enter 1 and the second player will enter 1 when prompted. The person who goes first will be up to the players, However; it needs match on both machines. The following screenshots show the view of both player one(top) and player two(bottom)

![alt text](https://github.com/Johnlin2922/SeaBattle/blob/master/Screenshots/1.JPG "initial screen")![alt text](https://github.com/Johnlin2922/SeaBattle/blob/master/Screenshots/4.JPG "initial screen")

Once initiated, the game will print two grids for each player. The primary grid is 9 ships of set sizes in a random assorment. The tracking grid is used to keep track of where you have attempted to hit. it will automatically be filled with "X" and "/" for hit and miss. Keep in mind that this very dependent on verbal communication between the two players. 

![alt text](https://github.com/Johnlin2922/SeaBattle/blob/master/Screenshots/7.JPG "initial screen")![alt text](https://github.com/Johnlin2922/SeaBattle/blob/master/Screenshots/8.JPG "initial screen")

After a few turns, your tracking grid should start to resemble your opponents primary grid. This will give you a general idea of where to attack next. 

![alt text](https://github.com/Johnlin2922/SeaBattle/blob/master/Screenshots/9.JPG "initial screen")![alt text](https://github.com/Johnlin2922/SeaBattle/blob/master/Screenshots/10.JPG "initial screen")

The ship counter is displayed every turn. Once it reaches 0 for your opponent, then you've won!

##Notes
The main game logic was simple to code, However, the random distribution of the ships was not. The main problem was the ships kept overlapping. I had to use a for loop to check for emepty space while populating the grid with the ship. Trying to figure out how to navigate the grid was also tough. I had to figure out if the "X" or "Y" goes first and which represented row or column. 
