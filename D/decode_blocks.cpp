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

string endblocks[500000];
int main(int argc, char* argv[]) {
  //freopen(argv[1], "r", stdin);
  //freopen(argv[2], "w", stdout);

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
      for(int j = 0; j < curr.size(); j++) {
        if(curr[j] == ';') {
          endblocks[stoif(curr.substr(0, j))] = curr.substr(j + 1);
          index++;
          curr = "";
          break;
        }
      }
    }
  }

  string last = endblocks[index - 1];

  for(int i = last.size() - 1; i >= 0; i--) {
    if(last[i] != '0') {
      endblocks[index - 1] = last.substr(0, i + 1);
      break;
    }
  }

  for(int i = 0; i < index; i++) {
    outputFile << endblocks[i];
  }
}
