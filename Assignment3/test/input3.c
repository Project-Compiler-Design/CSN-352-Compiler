int main(){
    int x = 2+3*(9-10)+8/4;
    int y = x*x-1;

    if(x>y){
        y++;
    }else{
        x++;
    }

    int i;
    for(i=0;i<12;i++){
        do{
            y++;
        }while (x>y);
    }
}
