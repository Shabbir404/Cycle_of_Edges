#include <bits/stdc++.h>
using namespace std;

int par[100005];
int groupSize[100005];

int find(int node)
{
    if (par[node] == -1)
        return node;

    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}
void ds_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (groupSize[leader1] >= groupSize[leader2])
    {
        par[leader2] = leader1;
        groupSize[leader1] += groupSize[leader2];
    }
    else
    {
        par[leader1] = leader2;
        groupSize[leader2] += groupSize[leader1];
    }
}

int main()
{

    memset(par, -1, sizeof(par));
    memset(groupSize, 1, sizeof(groupSize));

    int n, e;
    cin >> n >> e;

    int cycle = 0;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA == leaderB)
        {
            cycle++;
        }
        else
        {
            ds_union(a, b);
        }
    }
    cout << cycle << endl;

    return 0;
}
