

int main(){
    int a=6,b=10;
    int d=0;
    if(a>b){
        d=a-b;
        if(d>0)
        {
            d=d+1;
        }
        else{
            d=d-1;
        }
    }
    else{
       d= b-a;
       if(d>0)
        {
            d=d*2;
        }
    }
}