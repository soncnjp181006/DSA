// https://coderbyte.com/editor/Bracket%20Combinations:Cpp

#include <bits/stdc++.h>
using namespace std;

int dem = 0;
void backtrack(vector<int> A, int n, int cnt)
{
    // Nếu size(A) == n & cnt != 0 -> sai
    if(size(A) == n && cnt != 0) return;

    // Nếu cnt < 0 -> có ')' đứng đầu -> sai
    if(cnt < 0) return;

    // Nếu đúng -> quay lui
    if(size(A) == n && cnt == 0) {
        dem += 1;
        return;
    }

    for(int j : {0, 1}) {
        A.push_back(j);
        if(j == 0) backtrack(A, n, cnt + 1);
        else backtrack(A, n, cnt - 1);
        A.pop_back();
    }
}

int BracketCombinations(int num) {
  
    vector<int> A;
    backtrack(A, 2*num, 0);
    return dem;
}

int main() {
    int n;
    cin >> n;
    vector<int> A;
    backtrack(A, 2*n, 0);
    cout << dem;
}

