
#include "A.hpp"
#include "BFS.hpp"
#include "Parameters.hpp"
#include "SearchSolver.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  Parameters parameters(argc, argv);

  vector<string> a, b;

  ifstream in(parameters.get_input_path().c_str());
  if (!in.is_open()) {
    cerr << "o arquivo de entrada nao pode ser lido" << endl;
    throw new runtime_error("");
  }

  int a_sz, b_sz;
  in >> a_sz;
  for (int i = 0; i < a_sz; i++) {
    a.emplace_back();
    in >> a.back();
  }

  in >> b_sz;
  for (int i = 0; i < b_sz; i++) {
    b.emplace_back();
    in >> b.back();
  }

  in.close();
  vector<int> resa, resb;
  SearchSolver* solver;

  if (parameters.is_informed())
    solver = new A(a, b);
  else
    solver = new BFS(a, b);

  tie(resa, resb) = solver->solve();

  ofstream out(parameters.get_output_path().c_str());
  if (!out.is_open()) {
    cerr << "o arquivo de saida nao pode ser escrito" << endl;
    throw new runtime_error("");
  }

  if (resa.empty() || resb.empty()) {
    cerr << "a busca terminou mas nenhuma solucao foi encontrada" << endl;
    out << 0 << endl;
    out.close();
    return 0;
  }

  out << 1 << endl;
  out << resa.size() << endl;
  for (unsigned i = 0; i < resa.size(); i++) {
    out << resa[i] << " \n"[i + 1 == resa.size()];
  }

  out << resb.size() << endl;
  for (unsigned i = 0; i < resb.size(); i++) {
    out << resb[i] << " \n"[i + 1 == resb.size()];
  }

  // imprime ultimas linhas somente para debug
  out << endl;
  for (unsigned i = 0; i < resa.size(); i++) {
    out << a[resa[i]];
  }
  out << endl;

  out.close();
}
