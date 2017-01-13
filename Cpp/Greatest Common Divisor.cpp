int gcd(int a,int b){  
    int c;
    while(b>0){
        c=a;
        a=b;
        b=c%b;
    }
    return a;
}
