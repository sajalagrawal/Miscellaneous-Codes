/*
 * Author- Sajal Agrawal
 */

import java.util.*;

public class RemoveDuplicatesFromArray {
	public static void main(String args[]){
		int n;
		System.out.println("Enter number of elements:");
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		int a[]=new int[n],i,j,k;
		//accept i/p from user
		for(i=0;i<n;i++)a[i]=sc.nextInt();

		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;){
				if(a[i]==a[j]){   //if duplicate element is found
					for(k=j;k<n-1;k++){   //shift all elements from index=j to left
						a[k]=a[k+1];    
					}
					n--;   //reduce size of array by 1
				}else{
					j++;
				}
			}
		}
		//printing the final o/p
		for(i=0;i<n;i++)
			System.out.print(a[i]+" ");
	}
}
