<<<<<<< HEAD
typedef int A;
int main() {
    int c=3;
    int d=4;
    A a;
    a=c+d-(4*3);
    
=======
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
>>>>>>> 3987b011a0c40ad2dffaef5d996c9bd871c081be
    return 0;
}

