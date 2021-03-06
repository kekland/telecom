#include <bits/stdc++.h>

//Checker for task B
//Takes program output and correct output and compares each line - prints into STDOUT if detects errors

using namespace std;
int main(int argv, char* args[]) {
  ifstream progin("output.dat", ifstream::in);
  ifstream corrin("output3.dat", ifstream::in);

  int errcnt = 0;
  for(int i = 0; i < 1000; i++) {
    string s1;
    string s2;
    progin >> s1;
    corrin >> s2;

    if(s1 != s2) {
      cout << "Error occured at line " << i + 1 << endl;
      cout << "Program output : " << s1;
      cout << endl << "Correct output : " << s2 << endl;
      errcnt++;
    }
  }
  cout << "Finished, error count: " << errcnt;
}
