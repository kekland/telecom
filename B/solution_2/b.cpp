#include <bits/stdc++.h>

using namespace std;

vector<int> numbers;
bool primeNumbers[100001];
bool isPrime(int n)
{
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}

void count() {
  for(int i = 100003; i <= 199999; i++) {
    primeNumbers[i - 100003] = isPrime(i);
  }
}

bool getPrime(int num) {
  return primeNumbers[num - 100003];
}

int power(int a, int b)
{
  int res = a;
  if (b == 0)
  {
    return 1;
  }
  for (int i = 1; i < b; i++)
  {
    res *= a;
  }
  return res;
}

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

string subtract(string s, int index)
{
  if (s[index] == '0')
  {
    s[index] = '9';
  }
  else
  {
    s[index] -= 1;
  }
  return s;
}
int main(int argv, char *args[])
{
  //freopen("input.dat", "r", stdin);
  //freopen("output.dat", "w", stdout);

  count();



  for (int i = 0; i < 1000; i++)
  {
    string num;
    cin >> num;

    bool ok = false;

    int primeCnt = 0;
    int primeNum = 0;

    int inum = stoif(num);
    if(inum >= 100003 && inum <= 199999) {
      if (getPrime(inum))  {
        cout << inum << endl;
        continue;
      }
    }

    for (int j = 5; j >= 0; j--)
    {
      int subtracted = stoif(subtract(num, j));
      if (subtracted >= 100003 && subtracted <= 199999)
      {
        if (getPrime(subtracted))
        {
          primeCnt++;
          primeNum = subtracted;
        }
      }
    }

    if (primeCnt == 1) {
      cout << primeNum << endl;
    }
    else
    {
      cout << num << "*" << endl;
    }
  }
}
