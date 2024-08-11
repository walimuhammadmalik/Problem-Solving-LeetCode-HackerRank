#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    if (N == 1){
        cout << "1\n0 0 1\n";
    } else if (N == 2){
        cout << "2\n0 0 2\n1 1 0\n";
    } else if (N == 3){
        cout << "3\n0 1 2\n2 0 1\n1 2 0\n";
    } else if (N == 4){
        cout << "3\n0 0 4\n1 1 2\n2 2 0\n";
    } else {
        if (N % 3 == 0){
            int h = N/3*2+1;
            cout << h << "\n";
            for (int i=0; i<h; i++){
                cout << i << ' ' << (N/3+i)%h << ' ' << (N - i - (N/3+i)%h) << '\n';
            }
        } else if (N % 3 == 2){
            int h = N-N/3;
            cout << h << "\n0 0 " << N << "\n";
            for (int i=1; i<h; i++){
                int m = i <= h/2 ? (i + N/3) : (i - N/3 - 1);
                cout << i << ' ' << m << ' ' << (N-i-m) << "\n";
            }
        } else {
            int h = N-N/3;
            cout << h << "\n0 0 " << N << "\n1 1 " << N-2 << "\n";
            for (int i=1; i<=N/3; i++){
                cout << i+1 << ' ' << i+N/3 << ' ' << N - (i+1) - (i+N/3) << '\n';
            }
            for (int i=1; i<N/3; i++){
                cout << i+N/3+1 << ' ' << i+1 << ' ' << N - (i+N/3+1) - (i+1) << '\n';
            }        
        }
    }
    return 0;
}
