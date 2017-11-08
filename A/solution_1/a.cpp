#include <bits/stdc++.h>

//TASK A

using namespace std;

int A[500][500][500];
int img[500][500];

double sinTable[361];
double cosTable[361];
vector<pair<int, int> > pixels;

int main(int argc, char *argv[]) {
  //freopen("input3.dat", "r", stdin);
  //freopen("output.dat", "w", stdout);

  for(int i = 0; i <= 360; i++) {
    sinTable[i] = sin(i * 3.14 / 180.0);
    cosTable[i] = cos(i * 3.14 / 180.0);
  }

  for(int i = 0; i < 400; i++) {
    for(int j = 0; j < 400; j++) {
      cin >> img[i][j];

      if(img[i][j] == 1) {
        pixels.push_back(make_pair(i, j));
      }
    }
  }

  int x0 = 0, y0 = 0, r0 = 0;
  int maxA = -1;
  for(int i = 0; i < pixels.size(); i++) {
    int x = pixels[i].first;
    int y = pixels[i].second;

    for(int r = 1; r <= 200; r++) {
      for(int t = 0; t <= 360; t++) {
        int a = ceil((double)x - (double)r * cosTable[t]);
        int b = ceil((double)y - (double)r * sinTable[t]);
        if(a < 0 || b < 0 || a >= 500 || b >= 500) {
          continue;
        }
        A[a][b][r]++;
        if(A[a][b][r] > maxA) {
          maxA = A[a][b][r];
          x0 = a;
          y0 = b;
          r0 = r;
        }
      }
    }
  }

  cout << y0 << " " << x0 << " " << r0;
}
