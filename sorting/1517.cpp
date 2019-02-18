#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
/* idea : buf[i]는 buf[j>i] 중 buf[i]보다 크거나 같은 수를 만날 때까지 swap을 함*/
int n;
int buf[500000] = {0,};
int temp_buf[500000] = {0,};
int temp_buf2[500000] = {0,};
long long swap_cnt = 0;

void m_sort(int start, int end) {
  if(start + 1 >= end) return;
  int m = (start+end)/2;
  m_sort(start, m);
  m_sort(m, end);
  
  int cnt1 = 0;
  for(int i=start; i<m;i++)
    temp_buf[cnt1++] = buf[i];
  int cnt2 = 0;
  for(int i=m; i<end;i++)
    temp_buf2[cnt2++] = buf[i];
  
  int a = 0, b = 0;
  for(int i=start; i<end;) {
    if(a == cnt1) buf[i++] = temp_buf2[b++];
    else if(b == cnt2) buf[i++] = temp_buf[a++];
    else {
      if(temp_buf2[b] < temp_buf[a]) {
        swap_cnt += cnt1 - a;
        buf[i++] = temp_buf2[b++];
      } else {
        buf[i++] = temp_buf[a++];
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int i = 0 ; i < n ; i++) cin >> buf[i];
  m_sort(0, n);
  cout << swap_cnt;
  return 0;
}
