#include <stdio.h>

#define MAX 100000

typedef struct
{
    int s1[MAX];
    int s2[MAX];
    int top1;
    int top2;
} MinStack;

void MinStackInit(MinStack *st)
{
    st->top1 = -1;
    st->top2 = -1;
}

void MinStackPush(MinStack *st, int val)
{
    st->top1++;
    st->s1[st->top1] = val;

    if(st->top2 == -1 || val <= st->s2[st->top2])
    {
        st->top2++;
        st->s2[st->top2] = val;
    }
    else
    {
        st->top2++;
        st->s2[st->top2] = st->s2[st->top2 - 1];
    }
}

void MinStackPop(MinStack *st)
{
    if(st->top1 == -1)
        return;

    st->top1--;
    st->top2--;
}

int MinStackTop(MinStack *st)
{
    if(st->top1 == -1)
        return -1;
    return st->s1[st->top1];
}

int MinStackGetMin(MinStack *st)
{
    if(st->top2 == -1)
        return -1;
    return st->s2[st->top2];
}

/* Demo main (optional)
   Input format example:
   n
   then n operations:
   1 x -> push x
   2   -> pop
   3   -> top (print)
   4   -> getMin (print)
*/
int main()
{
    MinStack st;
    MinStackInit(&st);

    int n, op, x;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &op);

        if(op == 1)
        {
            scanf("%d", &x);
            MinStackPush(&st, x);
        }
        else if(op == 2)
        {
            MinStackPop(&st);
        }
        else if(op == 3)
        {
            printf("%d\n", MinStackTop(&st));
        }
        else if(op == 4)
        {
            printf("%d\n", MinStackGetMin(&st));
        }
    }

    return 0;
}
