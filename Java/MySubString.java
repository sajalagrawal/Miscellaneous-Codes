/*
 * Function to check whether one string is substring of another.
 * Author- Sajal Agrawal
 * @sajal.agrawal1997@gmail.com
 */

import java.util.*;

public class MySubString {
	static boolean mySubS(String s1,String s2){
		if(s1.length()<s2.length()){
			String temp=s1;
			s1=s2;
			s2=temp;
		}
		int j=0,i,index;
		for(i=0;i<=s1.length()-s2.length();i++){
			index=i;
			while(j<=s2.length()-1 && s1.charAt(index)==s2.charAt(j)){
				j++;
				index++;
			}
			if(j==s2.length())return true;
			j=0;
		}
		return false;
	}
	
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		String s1,s2;
		System.out.println("Enter string 1:");
		s1=sc.nextLine();
		System.out.println("Enter string 2:");
		s2=sc.nextLine();
		System.out.println(mySubS(s1,s2));
	}
}

