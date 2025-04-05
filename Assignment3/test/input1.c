int main()
{
    char i;
    int p=0;
    int a;
    switch(i)
    {
        case '+':
            p = 1;
            p=10;
            break;
        case '-':
{
            p=2;
            
            switch(a)
            {
                case 1:
                    p=3;
                    break;
                case 2:
                    p=4;
                    break;
                default:
                    p=5;
            }
            break;
            }
        case '*':         
            p=3;
            break;
    }
    
    return 0;
}