//SSTF DISK SCHEDULING 

#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;

int main() {
    int RQ[100], i, n, TotalHeadMoment = 0, initial, count = 0;
    cout << "Enter the number of Requests\n";
    cin >> n;
    cout << "Enter the Requests sequence\n";
    for (i = 0; i < n; i++)
        cin >> RQ[i];
    cout << "Enter initial head position\n";
    cin >> initial;

    while (count != n) {
        int min = INT_MAX, d, index;
        for (i = 0; i < n; i++) {
            d = abs(RQ[i] - initial);
            if (min > d) {
                min = d;
                index = i;
            }
        }
        TotalHeadMoment = TotalHeadMoment + min;
        initial = RQ[index];
        RQ[index] = INT_MAX;
        count++;
    }

    cout << "Total head movement is " << TotalHeadMoment;
    return 0;
}
