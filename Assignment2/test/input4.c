struct Student{
    char* name;
    int roll_no;
    int subject_marks[4][5];
};



int main(){

    int x=11;
    switch(x){
        case 1: {x--;}
        case 2: {x-=2;}
        case 11: {x+=x;}
        default: break;
    }

    int arr[3][2] = {{2,3},{5,6},{7,8}};

    char c;
    char *char_ptr = &c;

    printf("hello world");
    scanf(c);
}