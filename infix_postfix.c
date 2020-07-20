//Infix to Postfix without parenthesis
#include<stdio.h>
#define size 30
int top=-1;

void push(char opstack[],char x)
{
    if(top==size-1)
        printf("stack is full");
    else
    {
        top++;
        opstack[top]=x;
    }
}

char pop(char opstack[])
{
    char x;
    if(top==-1)
    {
        printf("stack empty ]n");
        return ' ';
    }
    else
    {
        x=opstack[top];
        top--;
        return x;
    }
}

char stop(char opstack[])
{
    char x;
    if(top==-1)
    {
        printf("stack empty");
        return ' ';
    }
    else
    {
        x=opstack[top];
        return x;
    }
}

int f(char x)
{
    switch(x)
    {
        case '-':
        case '+':return 1;
        case '*':
        case '/':return 2;
    }
    return 0;
}
void inf_post(char infix[])
{
    char opstack[size],post[size],symbol,tsymbol;
    int i=0,j=0;
    while(infix[i]!='#')
    {
        symbol=infix[i];
        if(symbol>='A' && symbol <='Z')
            post[j++]=infix[i];
        else
        {
            while(top!=-1 && f(stop(opstack))>=f(symbol))
            {
                tsymbol=pop(opstack);
                post[j++]=tsymbol;
            }
            push(opstack,symbol);
        }
        i++;
    }
    while(top!=-1)
    {
        tsymbol=pop(opstack);
        post[j++]=tsymbol;
    }
    post[j]='#';
    i=0;
    while(post[i]!='#')
        printf("%c",post[i++]);
}
void main()
{
    char x[50];
    int i=0;
    printf("enter char in infix form ending with #");
    do
        scanf("%c",&x[i]);
    while(x[i++]!='#');
        inf_post(x);
}
