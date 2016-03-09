#include "A.hpp"
#include <algorithm>
#include <iostream>
#include <queue>
#include <stdexcept>

using namespace std;

pair<vector<int>, vector<int> > A::solve() {
  // inicializa o conjunto de estados vistos
  states = 1;
  parent.clear();
  dist.clear();

  State initial = {"", 0, 0};
  priority_queue<pair<int, State>, vector<pair<int, State> >, greater<pair<int, State> > > PQ;
  parent[initial] = make_pair(initial, -1);
  dist[initial] = 0;
  PQ.push({0, initial});

  while (!PQ.empty()) {
    State cur;
    int func;
    int cost;
    tie(func, cur) = PQ.top();
    cost = dist[cur];
    // cout << cur.suffix << endl;
    PQ.pop();

    if (cur.is_final()) {
      // constrói o caminho a partir do map parent e retorna as sequências
      // resultantes
      vector<int> res[2];

      while (!cur.is_initial()) {
        State prev;
        int step;
        tie(prev, step) = parent[cur];
        res[prev.current ^ 1].push_back(step);
        cur = prev;
      }

      reverse(res[0].begin(), res[0].end());
      reverse(res[1].begin(), res[1].end());
      return {res[0], res[1]};
    }

    int addon = cur.current ^ 1;
    const vector<string>& sequences = get_sequences(addon);
    for (unsigned i = 0; i < sequences.size(); i++) {
      const string& s = sequences[i];
      // cout << "trying " << s << endl;
      int matches = 0;
      int s_sz = s.size();
      int suffix_sz = cur.suffix.size();

      for (; matches < s_sz && matches < suffix_sz; matches++)
        if (s[matches] != cur.suffix[matches])
          break;

      if (matches < s_sz && matches != suffix_sz)
        continue;

      State next;

      if (matches == suffix_sz) { // a string detentora do sufixo comum muda
        next = {s.substr(matches), addon, 1};
      } else {
        next = {cur.suffix.substr(matches), cur.current, 1};
      }

      int FC = cost + matches;
      int FA = next.suffix.size();

      // cout << next << endl;

      if (parent.find(next) == parent.end()) {
        parent[next] = {cur, i};
        dist[next] = FC;
        PQ.push({FC + FA, next});
        states++;
      }
    }
  }

  return {{}, {}};
}
