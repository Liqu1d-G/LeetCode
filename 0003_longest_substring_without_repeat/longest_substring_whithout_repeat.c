#include<stdio.h>
#include<stdlib.h>

int WhereRepeat(int front,int rear,char * s)
{
    for(front;front<=rear;front++)
        if(s[front]==s[rear+1])
            return front;
    return -1;
}

int lengthOfLongestSubstring(char * s){
    int front,rear,max;
    front=rear=0;max=1;
    if(s[0]=='\0')
        return 0;
    for(rear;s[rear]!='\0';rear++){
        int flag=WhereRepeat(front,rear,s);
        if(flag+1){
            if(max<rear-front+1)
                max=rear-front+1;
            front=flag+1;
        }
    }
    return max>(rear-front)?max:(rear-front);                          
}



int main()
{
    char a[]="";
    printf("%d",lengthOfLongestSubstring(a));
    return 0;
}