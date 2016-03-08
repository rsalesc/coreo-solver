#pragma once
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Parameters {
  string in, out;
  bool informed;

  public:
  Parameters(int argc, char* argv[]);

  string get_input_path() { return in; }
  string get_output_path() { return out; }
  bool is_informed() { return informed; }
};
