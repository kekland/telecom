#include <bits/stdc++.h>

using namespace std;

int n = 5; //Number of channels
int l = 50; //Length of message
int e = 2; //Error count
double signalPercent = 0.6; //Percent of signal
double energy[100]; //Energy required
int lv = 15; //Maximum levels
double a[100][1000]; //Probabilities for numbers in signal
int nl = 1000; //Noise length
double b[100][1000]; //Probabilities for errors in signal

int thres[100]; //Thresholds for each channel

double rrr[100][100];
void readInput() {
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
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < nl; j++) {
      int noise;
      cin >> noise;
      cnt++;
      b[i][noise] += 0.001;
    }
  }
}

void findThresholds() {
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
      rrr[ch][m] = r;
      if(bestR > r) {
        bestR = r;
        bestN = m;
      }
    }

    thres[ch] = bestN;
  }
}

pair<double, double> calculate(vector<bool> enabled) {
    double p = 1.0;

    for(int i = 0; i < enabled.size(); i++) {
        if(enabled[i]) {
            p *= rrr[i][thres[i]];
        }
    }

    double q = 1.0 - p;

    double temp = 0.0;
    long double d = l * (l - 1) / 2.0;
    d *= p * p;
    d *= pow(q, l - 2);
    temp += d;
    d = l;
    d *= p;
    d *= pow(q, l - 1);
    temp += d;
    d = 1;
    d *= pow(q, l);
    temp += d;
    for(int i = 0; i < 5; i++) {
      cout << enabled[i];
    }
    cout << " " << temp << endl;
    if(temp < 0.99) {
        return make_pair(-1, -1);
    }
    else {
        double sum = 0.0;
        for(int i = 0; i < enabled.size(); i++) {
            sum += energy[i] * enabled[i];
        }
        return make_pair(temp, sum);
    }
}

vector<bool> usedChannels;
double usedEnergy = 1239471212.0;
double usedAns = 0.0;

void mask() {
    double minAns = 555555.0;
    for(int i = 0; i < (1 << n); i++) {
        vector<bool> enabled;
        for(int j = n - 1; j >= 0; j--) {
            if((i & (1 << j)) != 0) {
                enabled.push_back(true);
            }
            else {
                enabled.push_back(false);
            }
        }

        pair<double, double> ans = calculate(enabled);
        //cout << ans << endl;
        //cout << ans.first << " " << ans.second << endl;
        if(ans.second < usedEnergy && ans.first != -1) {
            usedEnergy = ans.second;
            usedAns = ans.first;
            usedChannels = enabled;
        }
    }
}
int main() {
  freopen("input1.dat", "r", stdin);

  readInput();
  findThresholds();
  mask();

  for(int i = 0 ; i < n; i++) {
    cout << rrr[i][thres[i]] << endl;
  }

  int cnt = 0;
  double p = 1.0;
  for(int i = 0; i < n; i++) {
    if(usedChannels[i]) {
    	cnt++;
    	p *= rrr[i][thres[i]];
      cout << p << " ";
    }
  }
  double q = 1.0 - p;

  cout << cnt << endl;
  for(int i = 0; i < n; i++) {
  	if(usedChannels[i]) {
  		cout << i << " ";
  	}
  }
  cout << endl;
  for(int i = 0; i < n; i++) {
  	if(usedChannels[i]) {
  		cout << thres[i] << " ";
  	}
  }
  cout << endl;
  cout << q << endl;
  cout << usedAns << endl;
  cout << usedEnergy;
}
