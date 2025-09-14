#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int jumlahData = 0;
    cout << "Masukan Jumlah Data : ";
    cin >> jumlahData;

    int data[100];
    cout << "Masukkan Data : " << endl;
    for (int i = 0; i < jumlahData; i++) {
        cin >> data[i];
    }
    
    sort(data, data + jumlahData);
int pilihan;
do
{
    cout << "\nPilih operasi yang ingin digunakan: " << endl;
    cout << "1. Mean (Hitung Rata-rata)" << endl;
    cout << "2. Median (Nilai Tengah)" << endl;
    cout << "3. Modus (Nilai yang Sering Muncul)" << endl;
    cout << "4. Quartil Bawah (Q1) dan Quartil Atas (Q3)" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pilihan;

    double mean = 0, median = 0, Q1 = 0, Q3 = 0;
    int modus = 0, freqMax = 1;

    switch (pilihan) {
        case 1:
            // Menghitung Mean
            {
                double sum = 0;
                for (int i = 0; i < jumlahData; i++) sum += data[i];
                mean = sum / jumlahData;
                cout << "Mean = " << mean << endl;
            }
            break;

        case 2:
            // Menghitung Median
            if (jumlahData % 2 == 0) {
                median = (data[jumlahData/2 - 1] + data[jumlahData/2]) / 2.0;
            } else {
                median = data[jumlahData/2];
            }
            cout << "Median = " << median << endl;
            break;

        case 3:
            // Menghitung Modus
            for (int i = 0; i < jumlahData; i++) {
                int freq = 1;
                for (int j = i+1; j < jumlahData; j++) {
                    if (data[i] == data[j]) freq++;
                }
                if (freq > freqMax) {
                    freqMax = freq;
                    modus = data[i];
                }
            }
            if (freqMax == 1) 
                cout << "Tidak ada modus (semua data unik)" << endl;
            else
                cout << "Modus = " << modus << " (muncul " << freqMax << " kali)" << endl;
            break;

        case 4:
            // Menghitung Q1 dan Q3
            if (jumlahData % 2 == 0) {
                int mid = jumlahData/2;
                if (mid % 2 == 0) {
                    Q1 = (data[mid/2 - 1] + data[mid/2]) / 2.0;
                    Q3 = (data[mid + mid/2 - 1] + data[mid + mid/2]) / 2.0;
                } else {
                    Q1 = data[mid/2];
                    Q3 = data[mid + mid/2];
                }
            } else {
                int mid = jumlahData/2;
                if (mid % 2 == 0) {
                    Q1 = (data[mid/2 - 1] + data[mid/2]) / 2.0;
                    Q3 = (data[mid + 1 + mid/2 - 1] + data[mid + 1 + mid/2]) / 2.0;
                } else {
                    Q1 = data[mid/2];
                    Q3 = data[mid + 1 + mid/2];
                }
            }
            cout << "Q1 = " << Q1 << endl;
            cout << "Q3 = " << Q3 << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
    }
} while (pilihan != 5);

    return 0;
}
