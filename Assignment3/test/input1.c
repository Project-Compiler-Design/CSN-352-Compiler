struct Student{
    int roll,marks;
    char section,grade;
};

union A{
    int cd;
};

int main(){

    struct Student s1;
    s1.roll=1;
    struct Student s2;
    s2.marks=3;
    union A all;
    all.cd=4;


    
    
    
}