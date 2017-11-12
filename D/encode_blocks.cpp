#include <bits/stdc++.h>

using namespace std;

vector<string> blocks;
bool COMPRESS_DATA = false;
int main(int argc, char* argv[]) {
  //freopen(argv[1], "r", stdin);
  //freopen(argv[2], "w", stdout);

  ifstream inputFile(argv[1]);
  ofstream outputFile(argv[2]);

  stringstream stream;
  stream << inputFile.rdbuf();

  string input = stream.str();
  string prefix = "0;";
  string curr = "";
  string output = "";
  int index = 0;

  for(int i = 0; i < input.size(); i++) {
    char x = input[i];
    curr += x;
    if(prefix.size() + curr.size() == 54) {
      output += prefix + curr;
      curr = "";
      index++;
      prefix = to_string(index) + ";";
    }
  }
  if(curr.size() != 0) {
      output += prefix;
      for(int i = curr.size() + prefix.size(); i <= 54; i++) {
        curr += "0";
      }
      output += curr;
  }

  outputFile << output;
}
