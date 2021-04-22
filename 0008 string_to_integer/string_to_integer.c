#include<stdio.h>

int myAtoi(char *s)
{
    int i=0,flag=1;
    long int num=0;
    while(s[i]==' ')
        i++;
    if(s[i]=='-'||s[i]=='+')
        flag=44-s[i++];  // '+'=43£¬¡®-¡¯=45
    
    while(s[i]>='0'&&s[i]<='9'&&s[i]!='\0'){
        num=num*10+s[i++]-'0';
        if(num!=(int)num)
            break;
    }
    num*=flag;
    return num==(int)num ? (int)num:num<0 ? -2147483648:2147483647;
}

int main()
{
    char s[]="-91283472332";
    printf("%d",myAtoi(s));
    return 0;
}