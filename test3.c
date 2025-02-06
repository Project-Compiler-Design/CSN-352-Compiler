int i = a +++b++;

int c;

void fun(int b){
    int c;
    int d = b + ::c;
    bool chk = 1;
    chk ? a += 4 : (c ? d -= 5 : printf("hiyo\n %d", 55));
}

auto fun = [&](auto self)->bool{
    self(self);
    return 0;
};