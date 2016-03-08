#pragma once
#include "SearchSolver.hpp"
#include <map>

using namespace std;

class BFS : public SearchSolver {
  private:
  int states;
  map<State, pair<State, int> > parent;

  public:
  BFS(const vector<string>& a, const vector<string>& b) : SearchSolver(a, b) { states = 0; }
  pair<vector<int>, vector<int> > solve();
};
