int fact(int n)
{
    if(n==0){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
    
}
int main()
{
    int x=10;
    int ans = fact(x);

    return 0;
}