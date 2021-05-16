int romanToInt(char * s){
    int sum=0,i=0,lenth=strlen(s);
    for(i;i<lenth;i++){
        switch(s[i]){
            case 'M':sum+=1000;break;
            case 'D':sum+=500;break;
            case 'L':sum+=50;break;
            case 'V':sum+=5;break;
            case 'C':
                switch(s[i+1]){
                    case 'D':sum-=100;break;
                    case 'M':sum-=100;break;
                    default:sum+=100;
                }break;
            case 'X':
                switch(s[i+1]){
                    case 'L':sum-=10;break;
                    case 'C':sum-=10;break;
                    default:sum+=10;
                }break;
            case 'I':
                switch(s[i+1]){
                    case 'V':sum-=1;break;
                    case 'X':sum-=1;break;
                    default:sum+=1;
                }
        }
    }
    return sum;
}