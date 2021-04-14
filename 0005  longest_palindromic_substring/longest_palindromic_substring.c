#include<stdio.h>

#define MAXSIZE 1000

char * longestPalindrome(char * s)
{
    char a[MAXSIZE];
    for(int i=0;s[i]!='\0';i++){
        if(i==0&&s[i+1]=='\0'){
            a[0]=s[i];
        }
    }
}

int main()
{
    char s[MAXSIZE]="ababa";
    char *a=longestPalindrome(s);
    for(int i=0;a[i]!='\0';i++)
        printf("%d",a[i]);
    return 0;
}