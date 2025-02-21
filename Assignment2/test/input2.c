typedef int Integer;

int subtract(int a, int b) {
    return a - b;
}

void calc(int a, int b, int (*op)(char, char)) {
    printf("%d\n", op(a, b));
}

int main(){
    int m=100;
    auto fun = [&](int a, int b) -> int{

};
    
    
    

    return 0;
}