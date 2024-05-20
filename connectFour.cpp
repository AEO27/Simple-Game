#include <iostream>
 
using namespace std;

void printDisplay(char game[][7]){//Prints all the contents of the 2d array in a grid like pattern
	cout << "---------------\n";
	for(int i = 5; i > -1; i--){
		cout << "|";
		for(int j = 0; j < 7; j++){
			cout << game[i][j];
			cout << "|";
		}
		cout<< "\n";
		cout << "---------------\n";
	}
	cout << " 1 2 3 4 5 6 7";
	cout << "\n\n";
}

//checks the left, left-top, right, right-down, down, down-left for a connect four. 
//The commented lines below are debug codes.
//The checker functions returns 1 if a connect four is found and 0 otherwise
int checker(int turn, char game[][7], int choice, int columnAmount){ 
	char symbol;
	int win;
	
	if(turn%2==0){//Determines which turn it is to check the correct symbol on the igven coordinates
		symbol = 'O';
	}else{
		symbol = 'X';
	}
	
	//Each loops iterates 4 times to check for a connect four in their specified direction
	
	if(choice-3>0){//Checks if there is enough space to create a connect four on the left side
		win = 0;
		//cout << "Left\n";
		for(int i = 1; i<5; i++){
			//cout << "Loop number: " << i << " (Row, Column) (" << columnAmount << ", " << choice-i << ") Content: " << game[columnAmount][choice-i] << "\n";
			if(game[columnAmount][choice-i]==symbol){
				win++;
			}
		}
		
		if(win==4){
			return 1;
		}
		
		if (columnAmount+4<7){//Checks if there is enough space to create a connect four on the left and top side
			win = 0;
			//cout << "Left-Top\n";
			for(int i = 0; i<4; i++){
				//cout << "Loop number: " << i+1 << " (Row, Column) (" << columnAmount+i << ", " << choice-i-1 << ") Content: " << game[columnAmount+i][choice-i-1] << "\n";
				if(game[columnAmount+i][choice-i-1]==symbol){
					win++;
				}
			}
			if(win==4){
				return 1;
			}
		}
	}
	
	if (columnAmount+4<7){
		if(choice+3<8){//Checks if there is enough space to create a connect four on the top right side
			win = 0;
			//cout << "Top-Right\n";
			for(int i = 0; i<4; i++){
				//cout << "Loop number: " << i+1 << " (Row, Column) (" << columnAmount+i << ", " << choice+i-1 << ") Content: " << game[columnAmount+i][choice+i-1] << "\n";
				if(game[columnAmount+i][choice+i-1]==symbol){
					win++;
				}
			}
			if(win==4){
				return 1;
			}
		}
	}
	
	if(choice+3<8){//Checks if there is enough space to create a connect four on the right side
		win = 0;
		//cout << "Right\n";
		for(int i = 0; i<4; i++){
			//cout << "Loop number: " << i+1 << " (Row, Column) (" << columnAmount << ", " << choice+i-1 << ") Content: " << game[columnAmount][choice+i-1] << "\n";
			if(game[columnAmount][choice+i-1]==symbol){
				win++;
			}
		}
		if(win==4){
			return 1;
		}
		
		if (columnAmount-3>-1){//Checks if there is enough space to create a connect four on the right down side
			win = 0;
			//cout << "Right-Down\n";
			for(int i = 0; i<4; i++){
				//cout << "Loop number: " << i+1 << " (Row, Column) (" << columnAmount-i << ", " << choice+i-1 << ") Content: " << game[columnAmount-i][choice+i-1] << "\n";
				if(game[columnAmount-i][choice+i-1]==symbol){
					win++;
				}
			}
			if(win==4){
				return 1;
			}
		}
	}
	
	if (columnAmount-3>-1){//Checks if there is enough space to create a connect four on the down side
		win = 0;
		//cout << "Down\n";
		for(int i = 0; i<4; i++){
			//cout << "Loop number: " << i+1 << " (Row, Column) (" << columnAmount-i << ", " << choice-1 << ") Content: " << game[columnAmount-i][choice-1] << "\n";
			if(game[columnAmount-i][choice-1]==symbol){
				win++;
			}
		}
		if(win==4){
			return 1;
		}
		
		if(choice-3>0){//Checks if there is enough space to create a connect four on the down-left side
			win = 0;
			//cout << "Down-Left\n";
			for(int i = 0; i<4; i++){
				//cout << "Loop number: " << i+1 << " (Row, Column) (" << columnAmount-i << ", " << choice-i-1 << ") Content: " << game[columnAmount-i][choice-i-1] << "\n";
				if(game[columnAmount-i][choice-i-1]==symbol){
					win++;
				}
			}
			if(win==4){
				return 1;
			}
		}
	}
	
	return 0;
}

int main(){
	int turn = 0, win = 0, choice, columnAmount, endTurn = 0;
	//The turn is to determine which player plays. If it is even player 1 plays, otherwise player 2
	//The win is there to check if there has been a winner. If 0 there is no connect four yet, if it is one a connect four has been found by checker
	//choice is a variable to determine which column the palyer inserts their symbol
	//columnAmount determines what row the symbol should be in
	//endTurn is to determine when a player's turn is finished
	char game[6][7]; //contains the data of the game
	
	//Fills the 2d array with blanks for the start of the game
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			game[i][j] = ' ';
		}
	}
	
	printDisplay(game);
	
	while (win == 0){
		if(turn%2 == 0){//determines whose turn it is
			
			endTurn = 0;
			while(endTurn!=1){//Loops until the player chooses the correct option
				
				cout << "Player 1's turn (O): ";
				cin >> choice;
				
				if(choice < 1 || choice > 7){
					cout << "ERROR: Invalid column number.\n";
					continue;	
				}
				columnAmount = 0;
				for(int i = 0; i < 6; i++){
					if(game[i][choice-1] == ' '){
						game[i][choice-1] = 'O';
						endTurn = 1;
						break;
					}
				}

			}
			cout << "\n";
			printDisplay(game);
			if(checker(turn, game, choice, columnAmount) == 1){
				cout << "Player 1 has won the game!";
				win = 1;
			}
			turn++;
			
		}else{
			
			endTurn = 0;
			while(endTurn!=1){
				
				cout << "Player 2's turn (X): ";
				cin >> choice;
				
				if(choice < 1 || choice > 7){
					cout << "ERROR: Invalid column number.\n";
					continue;	
				}
				columnAmount = 0;
				for(int i = 0; i < 6; i++){
					if(game[i][choice-1] == ' '){
						game[i][choice-1] = 'X';
						endTurn = 1;
						break;
					}
				}
			}
			cout << "\n";
			printDisplay(game);
			if(checker(turn, game, choice, columnAmount) == 1){
				cout << "Player 2 has won the game!";
				win = 1;
			}
			turn++;
			
		}
	}
	
	return 0;
}

