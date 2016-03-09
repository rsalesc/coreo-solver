#include "SearchSolver.hpp"
#include <map>
#include <string>
#include <vector>

using namespace std;

class A : public SearchSolver {
  private:
  int states;
  map<State, pair<State, int> > parent;
  map<State, int> dist;

  public:
  A(const vector<string>& a, const vector<string>& b) : SearchSolver(a, b) { states = 0; }
  pair<vector<int>, vector<int> > solve();
};
