/*
 * Author- Sajal Agrawal
 * @sajal.agrawal1997@gmail.com
 */


import java.util.*;

class SnakeAndLadder{
	
	//initial position of player
	static int posX=0;

	void playGame(){
		int dice,temp;
		while(true){
			Scanner sc=new Scanner(System.in);
			System.out.println("Enter dice value:");
			dice=sc.nextInt();
			//checking for boundary conditions
			if(dice<2 || dice>12){
				throw new ArithmeticException("Illegal movement.");			
			}
			else if(dice%2==0){	
				temp=posX+dice+10;
				if(temp>=0 && temp<=100){
					posX=temp;
				}else{
					throw new ArithmeticException("Illegal movement.");
				}			
			}	
			else if(dice%2==1){
				temp=posX+dice-5;
				if(temp>=0 && temp<=100){
					posX=temp;
				}else{
					throw new ArithmeticException("Illegal movement.");
				}
			}
			//if the player reaches the 100th block
			if(posX==100){
				System.out.println("YOU WON THE GAME.");
				break;
			}

			System.out.println("cur position: "+posX);
		}
	}

	public static void main(String args[]){
		SnakeAndLadder obj=new SnakeAndLadder();
		//keep playing the game until the player wins.
		while(true){
			try{
				obj.playGame();
			}catch(ArithmeticException E){
				System.out.println(E.getMessage());
				System.out.println("cur position: "+posX);
			}
			if(posX==100){
				break;
			}
				
		}
	}
}
