int maxArea(int* height, int heightSize){
    int front=0,rear=heightSize-1,s=0;
    while(front<rear){
        int tmp=(rear-front)*(height[front]>=height[rear] ? height[rear]:height[front]);
        if(tmp>s)
            s=tmp;
        if(height[front]>=height[rear])
            rear--;
        else
            front++;
    }
    return s;
}