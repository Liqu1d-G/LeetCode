#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool isPalindrome(int x){
    if(x<0)
        return false;
    else if(x<10)
        return true;
    else if(!(x%10))
        return false;
    else{
        int y=0;
        do{
            y=y*10+x%10;
            x/=10;
            if((x==y)||((x/10)==y))
                return true;
        }while(x>y);
        return false;
    }
}


int main(int argc, char **argv)
{
    int x=123;

    printf("%s\n", isPalindrome(x) ? "true" : "false");
    return 0;
}