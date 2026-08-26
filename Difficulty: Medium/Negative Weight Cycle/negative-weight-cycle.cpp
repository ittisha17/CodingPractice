class Solution {
  public:
      bool isNegativeWeightCycle(int V, vector<vector<int>>& edges)
      {
          vector<long long> dist(V, 0);

          // Relax V times
          for(int i = 0; i < V; i++)
          {
              bool changed = false;

              for(auto &e : edges)
              {
                  int u = e[0];
                  int v = e[1];
                  int w = e[2];

                  if(dist[v] > dist[u] + w)
                  {
                      dist[v] = dist[u] + w;
                      changed = true;

                      // Relaxation on V-th iteration
                      // => negative cycle exists
                      if(i == V - 1)
                          return true;
                  }
              }

              if(!changed)
                  return false;
          }

          return false;
      }
  };