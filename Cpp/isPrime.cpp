bool isPrime(int n){
    if(n==2)return true;
    if(n==1 || n%2==0)return false;
   
    int i=3;
    while(i*i<=n){
        if(n%i==0)return false;
        i=i+2;
    }
    return true;
}
