#include<stdio.h>
#define size 50
int stack[size];
int top=-1;
int push(int x)
{
    if(top==size-1)
    {
        printf("stack is full");
        return 0;
    }
    else
    {
        top++;
        stack[top]=x;
        return 1;
    }
}
int pop()
{
    int x;
    if(top==-1)
    {
        printf("stack is empty");
        return 0;
    }
    else
    {
        x=stack[top];
        top--;
        return x;
    }
}
int peek()
{
    int x;
    if(top==-1)
    {
        printf("stack is empty");
        return 0;
    }
    else
    {
        x=stack[top];
        return x;
    }
}
void main()
{
    int x,op,res;
    do
    {
        printf("1 : push \n 2 : pop \n 3 : peek \n 4 : exit \n");
        printf("enter ur op \n");
        scanf("%d",&op);
        switch(op)
        {
            case 1 : printf("enter the element to be pushed");
                     scanf("%d",&x);
                     res=push(x);
                     if(res==1)
                        printf("%d is pushed \n",x);
                     else
                        printf("stack is full \n");
                     break;
            case 2 : res=pop();
                     if(res==0)
                        printf("stack is empty \n");
                     else
                        printf("%d is pooped \n",res);
                     break;
            case 3 : res=peek();
                     if(res==0)
                        printf("stack is empty \n");
                     else
                        printf("%d is at top \n",res);
                     break;
            case 4 : break;
            default : printf("invalid option");
        }
    }
    while(op!=6);
}
