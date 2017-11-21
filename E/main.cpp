#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("input1.dat", "r", stdin);
  //freopen("main.out", "w", stdout);

  int channelCount;
  int messageLength;
  int maximumErrorCount;
  double messageTransmitChance;
  double energyRequired[100];
  int signalLevels;
  int signals[100];
  double signalProbability[100][100];
  int length;
  int dataWithError[100][1000];

  cin >> channelCount;
  cin >> messageLength;
  cin >> maximumErrorCount;
  cin >> messageTransmitChance;

  for(int i = 0; i < channelCount; i++) {
    cin >> energyRequired[i];
  }

  cin >> signalLevels;
  for(int i = 0; i < signalLevels; i++) {
    cin >> signals[i];
  }

  for(int i = 0; i < channelCount; i++) {
    for(int j = 0; j < signalLevels; j++) {
      cin >> signalProbability[i][j];
    }
  }

  cin >> length;

  for(int i = 0; i < channelCount; i++) {
    for(int j = 0; j < length; j++) {
      cin >> dataWithError[i][j];
    }
  }

  for(int i = 0; i < channelCount; i++) {
    for(int j = 0; j < 10; j++) {
      cout << dataWithError[i][j] << " ";
    }
    cout << endl;
  }
}
