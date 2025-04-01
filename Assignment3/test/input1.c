int main(){
    int a=6,b=10;
    int k=0;
    int i;
    for(i=0;i<5;i++)
    {
        int j;
        for(j=0;j<5;j++)
        {
           k++;
           break;
           k--;
        }
        a++;
        continue;
        b--;
    }
}