#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <utility>
#include <algorithm>
#define MAX_N 40
using namespace std;

int buf[MAX_N] = {0,};
vector<int> sum1, sum2;
vector<pair<int,int>> ssum1, ssum2;

int main()
{
  int n, s; cin >> n >> s;
  for(int i = 0 ; i < n ; i++) cin >> buf[i];
    
  int iter = (int)pow(2, n / 2);
	for (int i = 1; i < iter; i += 1) {
		int psum = 0;
		for (int j = 0; j < n / 2; j += 1)
			if ((i & 1 << j) != 0)
				psum += buf[j];
    sum1.push_back(psum);
	}

  iter = (int)pow(2, n - n / 2);
  for(int i = 1 ; i < iter ; i += 1) {
    int psum = 0;
		for (int j = n / 2; j < n; j += 1)
			if ((i & 1 << (j - n / 2)) != 0)
				psum += buf[j];
    sum2.push_back(psum);
  } 

  sort(sum1.begin(), sum1.end());
  sort(sum2.begin(), sum2.end());

  int streak = 1;
  for(int i = 1 ; i < sum1.size(); i ++) {
    if(sum1[i] == sum1[i-1]) streak++;
    else {
      ssum1.push_back(make_pair(sum1[i-1], streak));
      streak = 1;
    }
  }
  if(n > 1) ssum1.push_back(make_pair(sum1.back(), streak));

  streak = 1;
  for(int i = 1 ; i < sum2.size(); i ++) {
    if(sum2[i] == sum2[i-1]) streak++;
    else {
      ssum2.push_back(make_pair(sum2[i-1], streak));
      streak = 1;
    }
  }
  ssum2.push_back(make_pair(sum2.back(), streak));

  long long ans = count(sum1.begin(), sum1.end(), s) + count(sum2.begin(), sum2.end(), s);

  int i = 0, j = ssum2.size() - 1;
  while( i < ssum1.size() && j >= 0 ) {
    int t = ssum1[i].first + ssum2[j].first;
    if(t > s) j--;
    else if(t == s) {
      ans += (long long)ssum1[i].second * ssum2[j].second;
      i++; j--;
    }
    else i++;
  }
  cout << ans;
  return 0;
}
