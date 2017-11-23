#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("input3.dat", "r", stdin);
  //freopen("main.out", "w", stdout);

  int n = 5; //Number of channels
  int l = 50; //Length of message
  int e = 2; //Error count
  double signalPercent = 0.6; //Percent of signal
  double energy[100]; //Energy required
  int lv = 15; //Maximum levels
  double a[100][100]; //Probabilities for numbers in signal
  int nl = 1000; //Noise length
  double b[100][100]; //Probabilities for errors in signal

  int thres[100]; //Thresholds for each channel

  /* INPUTS */
  cin >> n >> l >> e >> signalPercent;

  for(int i = 0; i < n; i++) {
    cin >> energy[i];
  }

  cin >> lv;
  for(int i = 0; i < lv; i++) {
    int x; cin >> x;
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < lv; j++) {
      cin >> a[i][j];
    }
  }

  cin >> nl;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < nl; j++) {
      int noise;
      cin >> noise;
      b[i][noise] += 0.001;
    }
  }

  /* FINDING THRESHOLDS */
  for(int ch = 0; ch < n; ch++) {
    double bestR = 10000.0;
    int bestN = 0;
    for(int m = 0; m < lv; m++) {
      double r = 0.0, k = 0.0, q = 0.0;
      for(int i = m; i < lv; i++) {
        k += b[ch][i];
      }
      for(int i = 0; i < m; i++) {
        double temp = 0.0;
        for(int j = 0; i + j < m; j++) {
          temp += a[ch][j];
        }
        q += b[ch][i] * temp;
      }

      r = k + q;
      if(bestR > r) {
        bestR = r;
        bestN = m;
      }
    }

    thres[ch] = bestN;
  }
  
}
