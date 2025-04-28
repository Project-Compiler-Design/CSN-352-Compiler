int addx(int a, int b){
    if(b == 0){
        return a;
    }
    else{    
        return a+addx(a, b-1);
    }
}


int main(){
    int b = addx(5, 3);
    printf("HI%d\n", b);
    return 0;
}
