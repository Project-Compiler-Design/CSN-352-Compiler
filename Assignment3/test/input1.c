struct A{
    int x;
    int y;
};

int main(){
   struct A a;
    a.x=10;
    a.y=10;

    int c=4;
    int* p=&c;
    int **q=&p;
    return 0;
}