#include <iostream>
using namespace std;

// Fungsi untuk menu
void displayMenu() {
    cout << "Pilihan Metode Pengurutan:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Shell Sort" << endl;
    cout << "5. Merge Sort" << endl;
    cout << "6. Quick Sort" << endl;
    cout << "Masukkan pilihan (1-6): ";
}

// Fungsi untuk Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar elemen jika elemen saat ini lebih besar dari elemen berikutnya
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // Tampilkan tahapan pengurutan
        cout << "Tahapan " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // Tampilkan tahapan pengurutan
        cout << "Tahapan " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Tukar elemen terkecil dengan elemen saat ini
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        // Tampilkan tahapan pengurutan
        cout << "Tahapan " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;

            // Tampilkan tahapan pengurutan
            cout << "Tahapan dengan gap " << gap << ": ";
            for (int k = 0; k < n; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;

            // Tampilkan penjelasan
            cout << "Membandingkan dan memindahkan elemen " << temp << " pada posisi yang tepat" << endl;
        }
    }
}


// Fungsi untuk Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Fungsi untuk Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);

        // Tampilkan tahapan pengurutan
        cout << "Tahapan Merge Sort: ";
        for (int k = l; k <= r; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;

        // Tampilkan penjelasan
        cout << "Menggabungkan dua bagian array: [";
        for (int k = l; k <= m; k++) {
            cout << arr[k];
            if (k != m) {
                cout << ", ";
            }
        }
        cout << "] dan [";
        for (int k = m + 1; k <= r; k++) {
            cout << arr[k];
            if (k != r) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}


// Fungsi untuk Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // Tukar elemen jika elemen saat ini lebih kecil dari pivot
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Tukar elemen pivot dengan elemen di indeks i+1
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        cout << "Pivot " << arr[pi] << " ditempatkan pada posisi yang tepat: ";
        for (int k = low; k <= high; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk menampilkan elemen array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan data:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    displayMenu();
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            system("cls");
            cout << ".:Menggunakan Bubble Sort:." << endl;
            cout << "Data Sebelum diurutkan:" << endl;
            printArray(arr,n);
            bubbleSort(arr, n);
            break;
        case 2:
            system("cls");
            cout << "Menggunakan Insertion Sort:" << endl;
            cout << "Data Sebelum diurutkan:" << endl;
            printArray(arr,n);
            insertionSort(arr, n);
            break;
        case 3:
            system("cls");
            cout << "Menggunakan Selection Sort:" << endl;
            cout << "Data Sebelum diurutkan:" << endl;
            printArray(arr,n);
            selectionSort(arr, n);
            break;
        case 4:
            system("cls");
            cout << "Menggunakan Shell Sort:" << endl;
            cout << "Data Sebelum diurutkan:" << endl;
            printArray(arr,n);
            shellSort(arr, n);
            break;
        case 5:
            system("cls");
            cout << "Menggunakan Merge Sort:" << endl;
            cout << "Data Sebelum diurutkan:" << endl;
            printArray(arr,n);
            mergeSort(arr, 0, n - 1);
            break;
        case 6:
            system("cls");
            cout << "Menggunakan Quick Sort:" << endl;
            cout << "Data Sebelum diurutkan:" << endl;
            printArray(arr,n);
            quickSort(arr, 0, n - 1);
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            return 0;
    }

    cout << "Data setelah diurutkan: ";
    printArray(arr, n);

    return 0;
}
