#include <bits/stdc++.h>

using namespace std;

vector<string> blocks;

int main(int argc, char* argv[]) {
  srand(time(NULL));
  ifstream inputFile(argv[1]);
  ofstream outputFile(argv[2]);

  stringstream stream;
  stream << inputFile.rdbuf();

  string input = stream.str();
  string curr = "";
  int index = 0;

  for(int i = 0; i < input.size(); i++) {
    char x = input[i];
    curr += x;
    if(curr.size() == 54) {
      blocks.push_back(curr);
      index++;
      curr = "";
    }
  }

  random_shuffle(blocks.begin(), blocks.end());

  for(int i = 0; i < blocks.size(); i++) {
    outputFile << blocks[i];
  }
}
