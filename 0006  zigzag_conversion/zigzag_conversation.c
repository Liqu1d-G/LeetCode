#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* convert(char* s, int numRows)
{
    if (numRows <= 1) return s;

    int len = strlen(s);
    char *new_str = malloc(len + 1);    
    char *p = new_str;
    int row = 0;
    for (row = 0; row < numRows; row++) {
        int interval1 = numRows + (numRows - 2) - row * 2;
        int interval2 = 2 * row;
        int flag = 0;
        int i = row;
        while (i < len) {
            *p++ = s[i];
            int delta = 0;
            do {
                delta = flag == 0 ? interval1 : interval2;
                flag = !flag;
            } while (delta == 0);
            i += delta;
        }
    }

    new_str[len] = '\0';
    return new_str;
}

int main()
{
    char s[]="PAYPALISHIRING";
    int numRows=3;
    char *a=convert(s,3);
    for(int i=0;a[i]!='\0';i++)
        printf("%c",a[i]);
    return 0;
}