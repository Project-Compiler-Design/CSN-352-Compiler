typedef int Integer;

int subtract(int a, int b) {
    return a - b;
}

void calc(int a, int b, int (*op)(char, char)) {
    printf("%d\n", op(a, b));
}

union A {
    int i;
    float f;
    char s[20];
};

int main(){
    int m,n;
    enum Gender { Male, Female };
    char *c="hello";

    
    
    

    return 0;
}