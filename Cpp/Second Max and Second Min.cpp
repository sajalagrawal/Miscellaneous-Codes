long long SecondMax(long long ar[],int a,int b){
    long long m=LONG_MIN,s=LONG_MIN;  //s is second max
    for(int i=a;i<=b;i++){
        if(ar[i]>m){
            s=m;
            m=ar[i];
        }
        else if(ar[i]>s and ar[i]<=m)s=ar[i];
    }
    return s;
}
long long SecondMin(long long ar[],int a,int b){
    long long m=LONG_MAX,s=LONG_MAX;  //s is second min
    for(int i=a;i<=b;i++){
        if(ar[i]<m){
            s=m;
            m=ar[i];
        }
        else if(ar[i]<s and ar[i]>=m)s=ar[i];
    }
    return s;
}
