void solve()
{
    vector<int> d (n, INF);
    d[v] = 0;
    vector<int> p (n - 1);
    int x;
    for (int i=0; i<n; ++i)
    {
        x = -1;
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }

    if (x == -1)
        cout << "No negative cycle from " << v;
    else
    {
        int y = x;
        for (int i=0; i<n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());

        cout << "Negative cycle: ";
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] << ' ';
    }
}
/**
Everywhere above we considered that there is no negative cycle in the graph (precisely, we are interested in a negative cycle that is reachable
from the starting vertex v, and, for an unreachable cycles nothing in the above algorithm changes). In the presence of a negative cycle(s),
there are further complications associated with the fact that distances to all vertices in this cycle, as well as the distances to the vertices
reachable from this cycle is not defined — they should be equal to minus infinity (−∞).
It is easy to see that the Bellman-Ford algorithm can endlessly do the relaxation among all vertices of this cycle and the vertices
reachable from it. Therefore, if you do not limit the number of phases to n−1, the algorithm will run indefinitely, constantly improving
the distance from these vertices.

Hence we obtain the criterion for presence of a cycle of negative weights reachable for source vertex v: after (n−1)th phase,
if we run algorithm for one more phase, and it performs at least one more relaxation, then the graph contains a negative weight
cycle that is reachable from v; otherwise, such a cycle does not exist.

Moreover, if such a cycle is found, the Bellman-Ford algorithm can be modified so that it retrieves this cycle as a sequence
of vertices contained in it. For this, it is sufficient to remember the last vertex x for which there was a relaxation in nth phase.
This vertex will either lie in a negative weight cycle, or is reachable from it. To get the vertices that are guaranteed to lie in a
negative cycle, starting from the vertex x, pass through to the predecessors n times. Hence we will get the vertex y, namely the vertex
in the cycle earliest reachable from source. We have to go from this vertex, through the predecessors, until we get back to the same vertex
y (and it will happen, because relaxation in a negative weight cycle occur in a circular manner).

Due to the presence of a negative cycle, for n iterations of the algorithm, the distances may go far in the negative
(apparently, to negative numbers of order − 2n). Hence in the code, we adopted additional measures against the integer overflow as follows:
d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
The above implementation looks for a negative cycle reachable from some starting vertex v; however, the algorithm can be modified to
just looking for "any negative cycle in the graph". For this we need to put all the distance d[i] to zero and not infinity — as if we are
looking for the shortest path from all vertices simultaneously; the validity of the detection of a negative cycle is not affected.
 */
