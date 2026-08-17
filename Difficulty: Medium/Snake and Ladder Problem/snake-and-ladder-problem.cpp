class Solution {
  public:
      int minThrows(int n, vector<int>& lad, vector<int>& sn) {

          int N = n * n;

          // jump[i] = destination if snake/ladder starts at i
          // -1 means there is no snake/ladder
          vector<int> jump(N + 1, -1);

          for (int i = 0; i < lad.size(); i += 2) {
              jump[lad[i]] = lad[i + 1];
          }

          for (int i = 0; i < sn.size(); i += 2) {
              jump[sn[i]] = sn[i + 1];
          }

          vector<bool> vis(N + 1, false);

          queue<int> q;

          q.push(1);
          vis[1] = true;

          int throws = 0;

          while (!q.empty()) {

              int sz = q.size();

              // All nodes currently in queue
              // require the same number of throws
              while (sz--) {

                  int u = q.front();
                  q.pop();

                  if (u == N)
                      return throws;

                  for (int dice = 1; dice <= 6; dice++) {

                      int v = u + dice;

                      if (v > N)
                          continue;

                      // Take snake/ladder immediately
                      if (jump[v] != -1)
                          v = jump[v];

                      if (!vis[v]) {
                          vis[v] = true;
                          q.push(v);
                      }
                  }
              }

              throws++;
          }

          return -1;
      }
  };