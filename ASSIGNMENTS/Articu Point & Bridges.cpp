vi par,sz,disc,low;
set<li> AP;
set<pi> bridge;
vector<vi> graph;
vector<vector<pair<li,li>>> wgraph;

li Time=0;

void init(li n)
{
    disc.resize(n);
    low.resize(n);
    graph.resize(n);
}

li dfsAP(li u,li p)
{
    li children=0;

    low[u]=disc[u]=++Time;

    for(li v:graph[u])
    {
        if(v==p)
            continue;

        if(!disc[v])
        {
            children++;

            dfsAP(v,u);

            if(disc[u]<=low[v])
            {
                AP.insert(u);
            }
                
            low[u]=min(low[u],low[v]);
        }
        else
        {
            low[u]=min(low[u],disc[v]);
        }
    }

    return children;
}

void dfsBRIDGE(li u,li p)
{
    low[u]=disc[u]=++Time;

    for(li v:graph[u])
    {
        if(v==p)
            continue;

        if(!disc[v])
        {

            dfsBRIDGE(v,u);

            if(disc[u]<low[v])
            {
                bridge.insert({min(u,v),max(u,v)});
            }
                
            low[u]=min(low[u],low[v]);
        }
        else
        {
            low[u]=min(low[u],disc[v]);
        }
    }
}