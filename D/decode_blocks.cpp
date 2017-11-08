#include <bits/stdc++.h>

using namespace std;

int stoif(string s)
{
  int res = 0;

  for (int i = 0; i < s.size(); i++)
  {
    res *= 10;
    res += (s[i] - '0');
  }
  return res;
}

int size = 0;
string endblocks[500000];
int main(int argc, char* argv[]) {
  freopen(argv[1], "r", stdin);
  freopen(argv[2], "w", stdout);

  while(!cin.eof()) {
    string ln;
    getline(cin, ln);
    string blockId = "";

    if(ln.size() == 0) {
      continue;
    }

    for(int i = 0; i < ln.size(); i++) {
      if(ln[i] == ';') {
        endblocks[stoif(blockId)] = ln.substr(i + 1);
        break;
      }
      blockId += ln[i];
    }
    size++;
  }

  for(int i = 0; i < size; i++) {
    cout << endblocks[i] << endl;
  }
}
