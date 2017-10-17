//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007
int solve(int a[],int mp,int n){  //mp=maxProduct
    int l=0,r=-1,ans=0;
    ll pro=1;
    for(l=0;l<n;l++){
        if(a[l]>mp){
            r=l;
            continue;
        }
        while(r<n-1 and a[r+1]*pro<=mp){
            pro=pro*a[r+1];
            r++;
        }
        cout<<"l="<<l<<" r="<<r<<endl;
        for(int i=l;i<=r;i++)cout<<a[i]<<" ";
        cout<<endl;
        ans+=r-l+1;
        pro=pro/a[l];
    }
    return ans;
}
int main() {
    
    int a[]={1,2,13,15,2,3};
    int mp=4;
    cout<<"ans="<<solve(a,mp,6);
	return 0;
}





//Author- xyz

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007
 
int numSubarraysWithMaxProductSlidingWindow(int array[], int maxProduct,int n){
    int numSubarraysWithMaxProduct = 0;
    int product = 1;

    for (int left = 0, right = -1; left < n; ++left) {
        while (right + 1 < n && product * array[right + 1] <= maxProduct) {
            product *= array[++right];
        }

        int subarraySize = right - left + 1;
        numSubarraysWithMaxProduct += subarraySize;

        product /= array[left];
    }

    return numSubarraysWithMaxProduct;
}
int main() {
    int a[]={1,1,1,1,1,1};
    int mp=12;
    cout<<numSubarraysWithMaxProductSlidingWindow(a,mp,6);
	return 0;
}





