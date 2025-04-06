int func(int y, int z, int k){
    int x;
    x=y+z+k;
    return x;
}

int y=0;

void hihello(int a, int b){
    int x;
    x=a+b;
    int i=0;
    for(i=0;i<10;i++){
        if(i%2==0) x+=i;
        else x-=i;
    }
    return;
}

int main(){
    int a=0;
    int b=8;
    int c=10;
    int d;
    d=func(a,b,c);
    hihello(a,b);
    return 0;
}

