#pragma once
#include <string>
#include <vector>

using namespace std;

class SearchSolver {
  private:
  vector<string> v[2];

  protected:
  public:
  struct State {
    string suffix;
    int current, nonempty;

    bool operator<(const State& rhs) const {
      if (suffix == rhs.suffix)
        if (current == rhs.current)
          return nonempty < rhs.nonempty;
        else
          return current < rhs.current;
      else
        return suffix < rhs.suffix;
    }

    bool operator==(const State& rhs) const { return !(*this < rhs) && !(rhs < *this); }
    friend ostream& operator<<(ostream&, const State&);

    bool is_initial() { return suffix == "" && nonempty == 0; }
    bool is_final() { return suffix == "" && nonempty > 0; }
  };

  SearchSolver(){};
  SearchSolver(const vector<string>& a, const vector<string>& b) {
    v[0] = a;
    v[1] = b;
  }

  const vector<string>& get_sequences(int dancer);
  virtual pair<vector<int>, vector<int> > solve();
};
