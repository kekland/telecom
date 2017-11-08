#include <bits/stdc++.h>

using namespace std;

vector<string> blocks;
int main(int argc, char* argv[]) {
  freopen(argv[1], "r", stdin);
  freopen(argv[2], "w", stdout);

  while(!cin.eof()) {
    string ln;
    getline(cin, ln);
    blocks.push_back(ln);
  }

  for(int i = 0; i < blocks.size(); i++) {
    if(blocks[i].size() == 0) {continue;}
    cout << i << ";" << blocks[i] << endl;
  }
}
