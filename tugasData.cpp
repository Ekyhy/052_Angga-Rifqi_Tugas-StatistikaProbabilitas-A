#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    int data[100]; // maksimal 100 data
    cout << "Masukkan data:\n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Urutkan data
    sort(data, data + n);

    // Hitung Mean
    double sum = 0;
    for (int i = 0; i < n; i++) sum += data[i];
    double mean = sum / n;

    // Hitung Median
    double median;
    if (n % 2 == 0)
        median = (data[n/2 - 1] + data[n/2]) / 2.0;
    else
        median = data[n/2];

    // Hitung Q1 dan Q3
    double Q1, Q3;
    if (n % 2 == 0) {
        int mid = n/2;
        if (mid % 2 == 0) {
            Q1 = (data[mid/2 - 1] + data[mid/2]) / 2.0;
            Q3 = (data[mid + mid/2 - 1] + data[mid + mid/2]) / 2.0;
        } else {
            Q1 = data[mid/2];
            Q3 = data[mid + mid/2];
        }
    } else {
        int mid = n/2;
        if (mid % 2 == 0) {
            Q1 = (data[mid/2 - 1] + data[mid/2]) / 2.0;
            Q3 = (data[mid + 1 + mid/2 - 1] + data[mid + 1 + mid/2]) / 2.0;
        } else {
            Q1 = data[mid/2];
            Q3 = data[mid + 1 + mid/2];
        }
    }

    // Hitung Modus
    int modus = data[0], freqMax = 1, freq;
    for (int i = 0; i < n; i++) {
        freq = 1;
        for (int j = i+1; j < n; j++) {
            if (data[i] == data[j]) freq++;
        }
        if (freq > freqMax) {
            freqMax = freq;
            modus = data[i];
        }
    }

    // Output
    cout << "\nHasil Perhitungan:\n";
    cout << "Mean   = " << mean << endl;
    cout << "Median = " << median << endl;
    cout << "Q1     = " << Q1 << endl;
    cout << "Q3     = " << Q3 << endl;

    if (freqMax == 1)
        cout << "Modus  = Tidak ada (semua data unik)\n";
    else
        cout << "Modus  = " << modus << " (muncul " << freqMax << " kali)\n";

    return 0;
} 