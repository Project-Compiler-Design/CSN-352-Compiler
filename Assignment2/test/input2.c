typedef int Integer;

int subtract(int a, int b) {
    return a - b;
}

void calc(int a, int b, int (*op)(char, char)) {
    printf("%d\n", op(a, b));
}

int main(){
    int m=100;
    int *ptr=&m;
    calc(10, 5, subtract);

    
    
    

    return 0;
}