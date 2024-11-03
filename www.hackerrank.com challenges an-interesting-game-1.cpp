#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
        int N;
        scanf("%d", &N);
        int last=0, ans=0;
        for(int i=0; i<N; i++)
        {
            int x;
            scanf("%d", &x);
            if(x>last)
                last=x, ans^=1;
        }
        if(ans==0)
            printf("ANDY\n");
        else
            printf("BOB\n");
    }
    return 0;
}
