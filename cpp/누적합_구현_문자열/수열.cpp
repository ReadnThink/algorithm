#include <iostream>

using namespace std;

int n,m;
int ret = - 10000004;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    int prefix[n];
    for(int i = 1; i <= n; i++){
        int tmp; cin >> tmp;
        prefix[i] = prefix[i - 1] + tmp;
    }
    // 10 5
    // 3 -2 -4 -9 0 3 7 13 8 -3

    for(int i = m; i <= n; i++){
        ret = max(ret, prefix[i] - prefix[i - m]);
    }
    cout << ret;

    return 0;
}
