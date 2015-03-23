/*****************************************
 * Filename: battleship.cpp
 * Author: Zach Rogers, Brandon Lee
 * Date: 12 March 2014
 * Description: 2 player battleship game
 *****************************************/
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <limits>

//Board info
#define GAME_SIZE       10
#define BOARD_EMPTY     'x'
#define BOARD_SHIP      'O'
#define BOARD_HIT       'H'
#define BOARD_MISS      'M'

//Color Attributes
#define RESET           0
#define BRIGHT          1
#define DIM             2
#define UNDERLINE       3
#define BLINK           4
#define REVERSE         7
#define HIDDEN          8

//Actual Colors
#define BLACK           0
#define RED             1
#define GREEN           2
#define YELLOW          3
#define BLUE            4
#define MAGENTA         5
#define CYAN            6
#define WHITE           7


using namespace std;

//Structs
struct ship
{
    //Name of ship
    const char *name;
    
    //Spaces ship takes up
    int spaces;
    
    //Remaining ship spaces
    int remaining_spaces;
    
    //Ship positions
    int *row, *col;
    
    //Is the ship still alive?
    bool alive;
};

struct player
{
    //Name of player
    string name;
    
    //Player board
    char board[GAME_SIZE][GAME_SIZE];
    
    //Remaining ships
    int remaining_ships;
    
    //Ships
    ship carrier;
    ship battleship;
    ship cruiser;
    ship submarine;
    ship destroyer;
};

//Terminal color functions
void textcolor(int attr, int fg, int bg);
void ship_color(player *p, int r, int c);
void print_ship(ship *s);

//Player functions
void player_init(player *p1, player *p2);
void ship_init(player *p);
void ship_place(player *p, ship *s);
bool ship_populate(player *p, ship *s, int r, int c);
int _toint(char row);

//Game board functions
void init_board(player *p);
void setup_board(player *p);
void display_board(player *p);

//Game functions
void game(player *p1, player *p2);
void attack_input(player *p, player *o);
void attack(player *p, player *o, int r, int c);
const char *get_ship(player *p, int r, int c);
bool check_winner(player *p);
void info();

int main()
{
    //Our players
    player p1;
    player p2;
    
    //Welcome the user to battleship!
    info();
    
    //Initalize our players
    player_init(&p1, &p2);
    
    //Clear setup stuff
    system("clear");
    
    //Start our battleship game!
    game(&p1, &p2);
    
    return 0;
}

/*********************************************************************
 * Function: textcolor
 * Parameters: Color argument, foreground color, background color
 * Description: Sets output color
 * Pre-Conditions: Color data has been defined
 * http://www.dreamincode.net/forums/topic/59656-color-text-in-c-programming/page__p__394955&#entry394955
 *********************************************************************/
void textcolor(int attr, int fg, int bg)
{
    //Command storage for color changing
    char command[13];
    
    //Command is the control command to the terminal
    sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
    printf("%s", command);
}

/*********************************************************************
 * Function: ship_color
 * Parameters: pointer to our player object, row index, col index
 * Description: Changes output color based on game board ship placement
 * Pre-Conditions: Player has been initialized, and ship data has been set
 *********************************************************************/
void ship_color(player *p, int r, int c)
{
    //Carrier Ship -- See if the current game board indices match the indices of the positions where the ship is
    for(int ir = 0; ir < p->carrier.spaces; ir++)
    {
        for(int ic = 0; ic < p->carrier.spaces; ic++)
        {
            if(r == p->carrier.row[ir] && c == p->carrier.col[ic])
            {
                textcolor(BRIGHT, RED, BLACK);
            }
        }
    }
    
    //Battle Ship -- See if the current game board indices match the indices of the positions where the ship is
    for(int ir = 0; ir < p->battleship.spaces; ir++)
    {
        for(int ic = 0; ic < p->battleship.spaces; ic++)
        {
            if(r == p->battleship.row[ir] && c == p->battleship.col[ic])
            {
                textcolor(BRIGHT, GREEN, BLACK);
            }
        }
    }
    
    //Destoryer Ship -- See if the current game board indices match the indices of the positions where the ship is
    for(int ir = 0; ir < p->destroyer.spaces; ir++)
    {
        for(int ic = 0; ic < p->destroyer.spaces; ic++)
        {
            if(r == p->destroyer.row[ir] && c == p->destroyer.col[ic])
            {
                textcolor(BRIGHT, BLUE, BLACK);
            }
        }
    }
    
    //Submarine -- See if the current game board indices match the indices of the positions where the ship is
    for(int ir = 0; ir < p->submarine.spaces; ir++)
    {
        for(int ic = 0; ic < p->submarine.spaces; ic++)
        {
            if(r == p->submarine.row[ir] && c == p->submarine.col[ic])
            {
                textcolor(BRIGHT, YELLOW, BLACK);
            }
        }
    }
    
    //Cruiser Ship -- See if the current game board indices match the indices of the positions where the ship is
    for(int ir = 0; ir < p->cruiser.spaces; ir++)
    {
        for(int ic = 0; ic < p->cruiser.spaces; ic++)
        {
            if(r == p->cruiser.row[ir] && c == p->cruiser.col[ic])
            {
                textcolor(BRIGHT, CYAN, BLACK);
            }
        }
    }
}

/*********************************************************************
 * Function: print_ship
 * Parameters: pointer to our ship object
 * Description: Outputs a ship's name with a specific color
 * Pre-Conditions: Ship data has been set
 *********************************************************************/
void print_ship(ship *s)
{
    //Set color based on ship name
    if(!strcmp("Carrier ship", s->name)) textcolor(BRIGHT, RED, BLACK);
    if(!strcmp("Battle ship", s->name)) textcolor(BRIGHT, GREEN, BLACK);
    if(!strcmp("Destroyer ship", s->name)) textcolor(BRIGHT, BLUE, BLACK);
    if(!strcmp("Submarine", s->name)) textcolor(BRIGHT, YELLOW, BLACK);
    if(!strcmp("Cruiser ship", s->name)) textcolor(BRIGHT, CYAN, BLACK);
    
    //Output ship name
    cout << s->name;
    
    //Reset color
    textcolor(RESET, WHITE, BLACK);
}

/*********************************************************************
 * Function: player_init
 * Parameters: pointers to our player objects
 * Description: Initialize player object data
 * Pre-Conditions: Player objects have been defined
 *********************************************************************/
void player_init(player *p1, player *p2)
{
    //Get player 1 's name
    cout << "Please enter a name for Player 1: ";
    cin >> p1->name;
    
    //Get player 2 's name
    cout << "Please enter a name for Player 2: ";
    cin >> p2->name;
    
    //Set player 1 and player 2 's remaining ship count
    p1->remaining_ships = 5;
    p2->remaining_ships = 5;
    
    //Player 1 board init
    init_board(p1);
    
    //Player 2 board init
    init_board(p2);
    
    //Player 1 ship init
    ship_init(p1);
    
    //Player 2 ship init
    ship_init(p2);
    
    //Player 1 ship placement
    setup_board(p1);
    
    //Player 2 ship placement
    setup_board(p2);
}

/*********************************************************************
 * Function: ship_init
 * Parameters: pointers to our player objects
 * Description: Initializes player's ship data
 * Pre-Conditions: Game boards have been initalized in player objs
 *********************************************************************/
void ship_init(player *p)
{
    //Carrier ship
    p->carrier.name = "Carrier ship";
    p->carrier.spaces = 5;
    p->carrier.remaining_spaces = 5;
    p->carrier.row = new int[p->carrier.spaces];
    p->carrier.col = new int[p->carrier.spaces];
    p->carrier.alive = true;
    
    //Battleship ship
    p->battleship.name = "Battle ship";
    p->battleship.spaces = 4;
    p->battleship.remaining_spaces = 4;
    p->battleship.row = new int[p->battleship.spaces];
    p->battleship.col = new int[p->battleship.spaces];
    p->battleship.alive = true;
    
    //Destoryer ship
    p->destroyer.name = "Destroyer ship";
    p->destroyer.spaces = 2;
    p->destroyer.remaining_spaces = 2;
    p->destroyer.row = new int[p->destroyer.spaces];
    p->destroyer.col = new int[p->destroyer.spaces];
    p->destroyer.alive = true;
    
    //Submarine
    p->submarine.name = "Submarine";
    p->submarine.spaces = 3;
    p->submarine.remaining_spaces = 3;
    p->submarine.row = new int[p->submarine.spaces];
    p->submarine.col = new int[p->submarine.spaces];
    p->submarine.alive = true;
    
    //Cruiser ship
    p->cruiser.name = "Cruiser ship";
    p->cruiser.spaces = 3;
    p->cruiser.remaining_spaces = 3;
    p->cruiser.row = new int[p->cruiser.spaces];
    p->cruiser.col = new int[p->cruiser.spaces];
    p->cruiser.alive = true;
}

/*********************************************************************
 * Function: ship_place
 * Parameters: pointers to our player object and ship object
 * Description: Places the player's ships on their game board
 * Pre-Conditions: Game boards and ships have been initalized in player objs
 *********************************************************************/
void ship_place(player *p, ship *s)
{
    //Error checking for ship placement
    while(true)
    {
        //Get input for ship placement
        string loc;
        cout << endl << "\tWhere would you like to place your ";
        print_ship(s);
        cout << "? ";
        cin >> loc;
        
        //Check placement input
        char row;
        int col;
        
        //Find the dash seperator
        if(loc.find("-") != string::npos)
        {
            row = loc.substr(0, loc.find("-")).at(0);
            col = atoi(loc.substr(loc.find("-") + 1).c_str());
        }
        else
        {
            cout << "\t * You must follow the format ROW-COL, for example: " << endl;
            cout << "\t\t * If you want to place your ship at D4, please input D-4." << endl;
            cout << "\t\t * The dash \"-\" is required!" << endl;
            continue;
        }
        
        //Check row placement (A-J) upper and lower case
        if((row >= 65 && row <= 74) || (row >= 97 && row <= 106))
        {
            //Check col placement
        	if(col >= 1 && col <= 10)
        	{
                //Get our row and col indicies
                int r = _toint(row);
                int c = col - 1; //Account for 0 index
                
                //Ship placement process
                if(!ship_populate(p, s, r, c))
                {
                    //Let the user know the position they selected isn't empty
                    cout << "\t * You can't place your ship there!" << endl;
                    cout << "\t * Please pick another position to place your ship" << endl;
                    cout << "\t\t Remember that your " << s->name << " takes up " << s->spaces << " spaces!" << endl << endl;
                    
                    //Get input again, since something failed
                    continue;
                }
                
                //Exit our error checking loop
                break;
        	}
        	else
        	{
            	cout << "\t * You must input a valid col to place your ship!" << endl;
            	cout << "\t * Valid cols are 1 - 10. " << endl;
            	continue;
        	}
        }
        else
        {
            cout << "\t * You must input a valid row to place your ship!" << endl;
            cout << "\t * Valid rows are A - J." << endl;
            continue;
        }
	}
}

/*********************************************************************
 * Function: ship_populate
 * Parameters: pointers to our player object and ship object and row/col indicies
 * Description: Populates a player's game board with their ship placement selections
 * Pre-Conditions: Game boards and ships have been initalized in player objs
 *********************************************************************/
bool ship_populate(player *p, ship *s, int r, int c)
{
    //Our return variable -- True if everything went well, false if not
    bool status = false;
    
    //Ship population method - If false, we use the default row placement method, if true we use col placement method
    bool alt_method = false;
    
    //Make note of our initial r index and c index
    int r_initial = r;
    int c_initial = c;
    
    //Ship space indicies
    int s_r = 0;
    int s_c = 0;
    
    //Number of ship places from current ship placement
    int r_space = r + s->spaces;
    int c_space = c + s->spaces;
    
    //General loop counter
    int count = 0;
    
    //Ship placement loop -- Row placement method
    for(; r < r_space; r++)
    {
        //cout << "ROW LOOP: r = " << r << ", c = " << c << endl;
        
        //Stay within bounds
        if(r < GAME_SIZE)
        {
            //Is this space empty?
            if(p->board[r][c] == BOARD_EMPTY)
            {
                //Make note where are ship space is located
                s->row[s_r] = r;
                s->col[s_c] = c;
                
                //Place ship on the board
                p->board[r][c] = BOARD_SHIP;
                
                //Update ship space indicies
                s_r++;
                s_c++;
                
                //So far, everything is just fine
                status = true;
            }
            
            //If the space we are checking is NOT empty, and try the col placement method
            else
            {
                //Only rest previous data if we have placed more one or more ships on the game board
                if(count > 0)
                {
                    //Use the other method of ship placement
                    alt_method = true;
                }
                
                //Things are not working currently
                status = false;
                
                //Stop the row placement method
                break;
            }
        }
        
        //Out of bounds
        else
        {
            //Use the other method of ship placement
            alt_method = true;
            
            //Things are not working currently
            status = false;
            
            //Stop the row placement method
            break;
        }
        
        //Update our loop counter
        count++;
    }
    
    //Did something go wrong?
    if(!status)
    {
        //Are we using the alternate ship placement method?
        if(alt_method)
        {
            //Loop through our game board and remove previously added data (Undo everything we added before)
            for(int ir = 0; ir < s->spaces; ir++)
            {
                for(int ic = 0; ic < s->spaces; ic++)
                {
                    //cout << "REMOVING r = " << ir << ", c = " << ic << endl;
                    p->board[s->row[ir]][s->col[ic]] = BOARD_EMPTY;
                }
            }
            
            //Reset ship space data we may have set previously
            delete []s->row;
            delete []s->col;
            s->row = new int[s->spaces];
            s->col = new int[s->spaces];
            
            //Reset everything
            r = r_initial;
            c = c_initial;
            s_r = 0;
            s_c = 0;
            count = 0;
            
            //Ship placement loop - Col placement method
            for(; c < c_space; c++)
            {
                //cout << "COL LOOP: r = " << r << ", c = " << c << endl;
                
                //Are we in bounds?
                if(c < GAME_SIZE)
                {
                    //Check if the space we are checking is empty
                    if(p->board[r][c] == BOARD_EMPTY)
                    {
                        //Make note where are ship space is located
                        s->row[s_r] = r;
                        s->col[s_c] = c;
                        
                        //Place ship on the board
                        p->board[r][c] = BOARD_SHIP;
                        
                        //Update ship space indicies
                        s_r++;
                        s_c++;
                        
                        //So far, everything is just fine
                        status = true;
                    }
                    else
                    {
                        //If this method failed too, the ship can't at this cordnate location
                        status = false;
                    }
                }
                else
                {
                    //If this method failed too, the ship can't at this cordnate location
                    status = false;
                }
            }
        }

    }
    
    //Return the status of our ship placement
    return status;
}

/*********************************************************************
 * Function: _toint
 * Parameters: row character
 * Description: Converts the row character to a number index, for game board arrays
 *********************************************************************/
int _toint(char row)
{
    if(row == 'a' || row == 'A') return 0;
    else if(row == 'b' || row == 'B') return 1;
    else if(row == 'c' || row == 'C') return 2;
    else if(row == 'd' || row == 'D') return 3;
    else if(row == 'e' || row == 'E') return 4;
    else if(row == 'f' || row == 'F') return 5;
    else if(row == 'g' || row == 'G') return 6;
    else if(row == 'h' || row == 'H') return 7;
    else if(row == 'i' || row == 'I') return 8;
    else if(row == 'j' || row == 'J') return 9;
    else return -1;
}

/*********************************************************************
 * Function: init_board
 * Parameters: pointers to our player object
 * Description: Initialize game board 2D arrays
 * Pre-Conditions: Game board arrays declared as 2D arrays
 *********************************************************************/
void init_board(player *p)
{
    //Set our initial values for our player 1 and player 2 game board
    for(int r = 0; r < GAME_SIZE; r++)
    {
        for(int c = 0; c < GAME_SIZE; c++)
        {
            p->board[r][c] = BOARD_EMPTY;
        }
    }
}

/*********************************************************************
 * Function: setup_board
 * Parameters: pointer to our player object
 * Description: Places player ships on the game board
 * Pre-Conditions: Player object has been setup accordingly
 *********************************************************************/
void setup_board(player *p)
{
    //Introduce the user to the game board setup process
    cout << endl << "* Ship placement for " << p->name << ":" << endl;
    cout << "\tFor the following questions, please give the coordinates you would like to place each ship" << endl;
	cout << "\tFor example, input D-4 to place a ship at position D4 on the game board" << endl << endl;
    
    //Place ships
    ship_place(p, &p->carrier);
    display_board(p);
    
    ship_place(p, &p->battleship);
    display_board(p);
    
    ship_place(p, &p->destroyer);
    display_board(p);
    
    ship_place(p, &p->submarine);
    display_board(p);
    
    ship_place(p, &p->cruiser);
    display_board(p);
    
}

/*********************************************************************
 * Function: display_board
 * Parameters: pointer to our player object
 * Description: Displays the passed game board
 * Pre-Conditions: Game board array has been initalized with data
 *********************************************************************/
void display_board(player *p)
{
    cout << "\t-----------------------------------------------------------------" << endl;
	cout << "\tx  |  1  |  2  |  3  |  4  |  5  ";
    cout << "|  6  |  7  |  8  |  9  |  10 |" << endl;
	cout << "\t-----------------------------------------------------------------" << endl;
    
    for(int r = 0; r < GAME_SIZE; r++)
    {
        if (r == 0) cout << "\tA  |  ";
        if (r == 1) cout << "\tB  |  ";
        if (r == 2) cout << "\tC  |  ";
        if (r == 3) cout << "\tD  |  ";
        if (r == 4) cout << "\tE  |  ";
        if (r == 5) cout << "\tF  |  ";
        if (r == 6) cout << "\tG  |  ";
        if (r == 7) cout << "\tH  |  ";
        if (r == 8) cout << "\tI  |  ";
        if (r == 9) cout << "\tJ  |  ";
        
        for(int c = 0; c < GAME_SIZE; c++)
        {
            //Set color based on ship
            if(p->board[r][c] == BOARD_SHIP) ship_color(p, r, c);
            if(p->board[r][c] == BOARD_MISS || p->board[r][c] == BOARD_HIT) textcolor(REVERSE, RED, BLACK);
            
            cout << p->board[r][c];
            
            //Reset terminal color
            textcolor(RESET, WHITE, BLACK);
            
            cout << "  |  ";
        }
        cout << endl;
    }
    
    cout << "\t-----------------------------------------------------------------" << endl;
}

/*********************************************************************
 * Function: game
 * Parameters: pointer to our player objects
 * Description: The main game loop for battleship
 * Pre-Conditions: All game data has been initalized
 *********************************************************************/
void game(player *p1, player *p2)
{
    //Our game loop exists until someone wins
    while(true)
    {
        //Player 1 attacks Player 2
        attack_input(p1, p2);
        
        //Did Player 1 play the winning move?
        if(!(p2->remaining_ships > 0)) break;
        
        //Player 2 attacks Player 1
        attack_input(p2, p1);
        
        //Did Player 2 play the winning move?
        if(!(p1->remaining_ships > 0)) break;
    }
    
    //Someone must have won, who was it?
    if(check_winner(p1))
    {
        cout << endl;
        cout << "[!] " << p1->name << " is the winner!" << endl;
        cout << "\t Sorry " << p2->name << ", you lost the game :(" << endl << endl;
    }
    else if(check_winner(p2))
    {
        cout << endl;
        cout << "[!] " << p2->name << " is the winner!" << endl;
        cout << "\t Sorry " << p1->name << ", you lost the game :(" << endl << endl;
    }
}

/*********************************************************************
 * Function: attack_input
 * Parameters: pointer to our player object, and the player object they are attacking
 * Description: Player p attacks Player o -- Input validation
 * Pre-Conditions: All game data has been initalized
 *********************************************************************/
void attack_input(player *p, player *o)
{
    cout << "* " << p->name << " attacking " << o->name << endl;
    
    display_board(p);
    
    cout << "\tPlease enter the cord you would like to attack, for example D-4" << endl;
    
    //Error checking for ship placement
    while(true)
    {
        //Get input for ship placement
        string loc;
        
        //Prompt the player to attack
        cout << "\t\t" << p->name << ": Where would you like to attack? ";
        cin >> loc;
        
        //Check placement input
        char row;
        int col;
        
        //Find the dash seperator
        if(loc.find("-") != string::npos)
        {
            row = loc.substr(0, loc.find("-")).at(0);
            col = atoi(loc.substr(loc.find("-") + 1).c_str());
        }
        else
        {
            cout << "\t * You must follow the format ROW-COL, for example: " << endl;
            cout << "\t\t * If you want to attack D4, please input D-4." << endl;
            cout << "\t\t * The dash \"-\" is required!" << endl;
            continue;
        }
        
        //Check row placement (A-J) upper and lower case
        if((row >= 65 && row <= 74) || (row >= 97 && row <= 106))
        {
            //Check col placement
        	if(col >= 1 && col <= 10)
        	{
                //Get our row and col indicies
                int r = _toint(row);
                int c = col - 1; //Account for 0 index
                
                //Process attack input
                attack(p, o, r, c);
                
                //Exit our error checking loop
                break;
        	}
        	else
        	{
            	cout << "\t * You must input a valid col to attack!" << endl;
            	cout << "\t * Valid cols are 1 - 10. " << endl;
            	continue;
        	}
        }
        else
        {
            cout << "\t * You must input a valid row to attack" << endl;
            cout << "\t * Valid rows are A - J." << endl;
            continue;
        }
	}
    
}

/*********************************************************************
 * Function: attack
 * Parameters: pointer to our player object, and the player object they are attacking, and the row and col
 * Description: Player p attacks Player o
 * Pre-Conditions: All game data has been initalized
 *********************************************************************/
void attack(player *p, player *o, int r, int c)
{
    //ATTACK THE SHIP -- If it is a ship position
    if(o->board[r][c] == BOARD_SHIP)
    {
        //Place the hit marker on players's board (Don't overwrite our own ship info though)
        if(p->board[r][c] != BOARD_SHIP) p->board[r][c] = BOARD_HIT;
        
        //Place the hit marker on opponent's board
        o->board[r][c] = BOARD_HIT;
        
        //Let the user know they hit something!
        cout << "[!] You hit " << o->name << "'s ";
        
        //What ship did the player actually hit
        if(!strcmp("Carrier ship", get_ship(o, r, c)))
        {
            //Let user know what they hit
            print_ship(&o->carrier);
            cout << endl;
            
            //Decrease spaces, as the ship was hit
            o->carrier.remaining_spaces--;
            
            //Check if the ship should still be alive or not
            if(o->carrier.remaining_spaces > 0)
            {
                o->carrier.alive = true;
            }
            else
            {
                //Ship is dead!
                o->carrier.alive = false;
                
                //Update number of ships
                o->remaining_ships--;
            }
        }
        else if(!strcmp("Battle ship", get_ship(o, r, c)))
        {
            //Let user know what they hit
            print_ship(&o->battleship);
            cout << endl;
            
            //Decrease spaces, as the ship was hit
            o->battleship.remaining_spaces--;
            
            //Check if the ship should still be alive or not
            if(o->battleship.remaining_spaces > 0)
            {
                o->battleship.alive = true;
            }
            else
            {
                //Ship is dead!
                o->battleship.alive = false;
                
                //Update number of ships
                o->remaining_ships--;
            }
        }
        else if(!strcmp("Destroyer ship", get_ship(o, r, c)))
        {
            //Let user know what they hit
            print_ship(&o->destroyer);
            cout << endl;
            
            //Decrease spaces, as the ship was hit
            o->destroyer.remaining_spaces--;
            
            //Check if the ship should still be alive or not
            if(o->destroyer.remaining_spaces > 0)
            {
                o->destroyer.alive = true;
            }
            else
            {
                //Ship is dead!
                o->destroyer.alive = false;
                
                //Update number of ships
                o->remaining_ships--;
            }
        }
        else if(!strcmp("Submarine", get_ship(o, r, c)))
        {
            //Let user know what they hit
            print_ship(&o->submarine);
            cout << endl;
            
            //Decrease spaces, as the ship was hit
            o->submarine.remaining_spaces--;
            
            //Check if the ship should still be alive or not
            if(o->submarine.remaining_spaces > 0)
            {
                o->submarine.alive = true;
            }
            else
            {
                //Ship is dead!
                o->submarine.alive = false;
                
                //Update number of ships
                o->remaining_ships--;
            }
        }
        else if(!strcmp("Cruiser ship", get_ship(o, r, c)))
        {
            //Let user know what they hit
            print_ship(&o->cruiser);
            cout << endl;
            
            //Decrease spaces, as the ship was hit
            o->cruiser.remaining_spaces--;
            
            //Check if the ship should still be alive or not
            if(o->cruiser.remaining_spaces > 0)
            {
                o->cruiser.alive = true;
            }
            else
            {
                //Ship is dead!
                o->cruiser.alive = false;
                
                //Update number of ships
                o->remaining_ships--;
            }
        }
        
    }
    
    //Otherwise, it was a miss
    else
    {
        //Place the miss marker on players's board (Don't overwrite our own ship info though)
        if(p->board[r][c] != BOARD_SHIP) p->board[r][c] = BOARD_MISS;
        
        cout << "[!] You missed! " << endl;
    }
    
    //Prompt player for next player's turn
    cout << "Press enter to let " << o->name << " take their turn!";
    
    //Flush our cin buffer to ensure cin.get
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
    
    //Clear the screen
    system("clear");
    
    //Flush our cin buffer incase the user inputted anything random
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

const char *get_ship(player *p, int r, int c)
{
    //Carrier Ship -- See if the current game board indices match the indices of the positions where the ship is
    for(int ir = 0; ir < p->carrier.spaces; ir++)
    {
        for(int ic = 0; ic < p->carrier.spaces; ic++)
        {
            if(r == p->carrier.row[ir] && c == p->carrier.col[ic])
            {
                return p->carrier.name;
            }
        }
    }
    
    //Battle Ship -- See if the current game board indices match the indices of the positions where the ship is
    for(int ir = 0; ir < p->battleship.spaces; ir++)
    {
        for(int ic = 0; ic < p->battleship.spaces; ic++)
        {
            if(r == p->battleship.row[ir] && c == p->battleship.col[ic])
            {
                return p->battleship.name;
            }
        }
    }
    
    //Destoryer Ship -- See if the current game board indices match the indices of the positions where the ship is
    for(int ir = 0; ir < p->destroyer.spaces; ir++)
    {
        for(int ic = 0; ic < p->destroyer.spaces; ic++)
        {
            if(r == p->destroyer.row[ir] && c == p->destroyer.col[ic])
            {
                return p->destroyer.name;
            }
        }
    }
    
    //Submarine -- See if the current game board indices match the indices of the positions where the ship is
    for(int ir = 0; ir < p->submarine.spaces; ir++)
    {
        for(int ic = 0; ic < p->submarine.spaces; ic++)
        {
            if(r == p->submarine.row[ir] && c == p->submarine.col[ic])
            {
                return p->submarine.name;
            }
        }
    }
    
    //Cruiser Ship -- See if the current game board indices match the indices of the positions where the ship is
    for(int ir = 0; ir < p->cruiser.spaces; ir++)
    {
        for(int ic = 0; ic < p->cruiser.spaces; ic++)
        {
            if(r == p->cruiser.row[ir] && c == p->cruiser.col[ic])
            {
                return p->cruiser.name;
            }
        }
    }
    
    return NULL;
}

/*********************************************************************
 * Function: check_winner
 * Parameters: pointer to our player objects
 * Description: The main game loop for battleship
 * Pre-Conditions: All game data has been initalized
 *********************************************************************/
bool check_winner(player *p)
{
    //If the player we are checking still has atleast one ship they must have won the game
    if(p->remaining_ships > 0) return true;
    
    return false;
}

/*********************************************************************
 * Function: info
 * Parameters: N/A
 * Description: Displays information about the game
 *********************************************************************/
void info()
{
    cout << "Welcome to the game of Battleship! " << endl;
    
    cout << "* Directions: " << endl;
	cout << "\tEach player will place their fleet of 5 ships on the board, after that, each" << endl;
	cout << "\tplayer will take turns picking target areas on the board to attack. If a" << endl;
	cout << "\ttarget area you are attacking has an enemy ship, you will damage that ship." << endl;
	cout << "\tAfter so many hits on an enemy ship, you will sink that ship. The first person" << endl;
	cout << "\tto sink all the ships will win." << endl << endl;
    
    cout << "* Game board: " << endl;
    cout << "\t The game board is a 10x10 grid that ships are placed on. Ships are placed " << endl;
    cout << "\t by inputing the coordinates where you'd like that ship to be. For example, " << endl;
    cout << "\t you would input D-4 to place a ship at row D, column 4." << endl << endl;
}