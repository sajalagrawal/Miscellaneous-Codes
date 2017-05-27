/*
 * Author- Sajal Agrawal
 * @sajal.agrawal1997@gmail.com
 */

import java.util.*;

class Game{
	private char[][] board;
	private char currentPlayerMark;
	
	//initialize game play
	public Game(){
		currentPlayerMark='X';
		board=new char[3][3];
		initializeBoard();
	}
	
	//initialize game board
	public void initializeBoard(){
		int i,j;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				board[i][j]='-';
			}
		}
	}
	
	//prints the current game board state 
	public void printBoard(){
		int i,j;
		System.out.println("-------------");
		for(i=0;i<3;i++){
			System.out.print("| ");
			for(j=0;j<3;j++){
				System.out.print(board[i][j]+" | ");
			}
			System.out.println();
			System.out.println("-------------");
		}
	}
	
	//check if game ends in Draw
	public boolean isBoardFull(){
		int i,j;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(board[i][j]=='-')return false;
			}
		}
		return true;
	}
	
	//check if any player wins
	public boolean checkForWin(){
		return (checkRowsForWin() || checkColsForWin() || checkDiagonalForWin() );
	}
	
	//check if any of the rows is filled by a particular mark
	public boolean checkRowsForWin(){
		int i;
		for(i=0;i<3;i++){
			if(checkRowCol(board[i][0],board[i][1],board[i][2])){
				return true;
			}
		}
		return false;
	}
	
	//check if any of the columns is filled by a particular mark
	public boolean checkColsForWin(){
		int i;
		for(i=0;i<3;i++){
			if(checkRowCol(board[0][i],board[1][i],board[2][i])==true){
				return true;
			}
		}
		return false;
	}
	
	//check if any of the diagonals is filled by a particular mark
	public boolean checkDiagonalForWin(){
		return ((checkRowCol(board[0][0],board[1][1],board[2][2])) || checkRowCol(board[0][2],board[1][1],board[2][0]));
	}
	
	public boolean checkRowCol(char a,char b,char c){
		return ((a!='-') && (a==b) && (b==c));
	}
	
	//switches player for his chance
	public void changePlayer(){
		if(currentPlayerMark=='X')currentPlayerMark='O';
		else currentPlayerMark='X';
	}
	
	//puts player mark at the desired position
	public void placeMark(int x,int y){
		board[x][y]=currentPlayerMark;
	}
	
	//returns current Player
	public char getCurrentPlayer(){
    	return currentPlayerMark;
    }
    
	//checks for valid positions 
	public boolean inValidPos(int x,int y){
	    	if(x<0 || x>2 || y<0 || y>2){
	    		System.out.println("This position is illegal");
	    		return true;
	    	}
	    	if(board[x][y]=='X' || board[x][y]=='O'){
	    		System.out.println("This position is already filled.");
	    		return true;
	    	}
	    	return false;
    }
   
}

public class TicTacToeGame {
	public static void main(String args[]){
		//start a new game
		Game obj=new Game();
		int x,y;
		char player;
		while(true){
			//print the board
			obj.printBoard();
			player=obj.getCurrentPlayer();
			System.out.println("Enter position Player "+player+" :");
			Scanner sc=new Scanner(System.in);
			x=sc.nextInt();
			y=sc.nextInt();
			while(obj.inValidPos(x,y)){
				System.out.println("Enter position Player:"+player+" :");
				x=sc.nextInt();
				y=sc.nextInt();
			}
			// These values are based on a 0-based indexing.
			obj.placeMark(x,y);
			// Did we have a winner?
			if(obj.checkForWin()){
				obj.printBoard();
				System.out.println("We have a WINNER!!!");
				System.exit(0);
			}else if(obj.isBoardFull()){
				obj.printBoard();
				System.out.println("Game ends in DRAW...");
				System.exit(0);
			}
			// No winner or draw, switch players to 'X'
			obj.changePlayer();
			
		}
	}
}




