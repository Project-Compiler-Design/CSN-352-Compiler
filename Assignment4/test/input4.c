//union

union u{
    int i;
    int f;
};

int main(){
    union u a;
    a.i = 1;
    a.f = 2;
    return 0;
}