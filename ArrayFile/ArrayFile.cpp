#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <cmath>
#include <time.h>
#include <climits> 


using namespace std;

typedef double* pDouble;
/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0;
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}
/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> A[i];
    }
    return size;
}

/*
*   RndInputArrayDouble
*
*/
int RndInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1 = 0, r2 = 0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";
    }
    return size;
}

int ConsoleInputDynamicArrayNew(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = (double*)calloc(size, sizeof(double));      // pA = (double*)malloc(size * sizeof(double)); 
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

void ConsoleInputVector(int sizeMax, vector<double>& A)
{
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> d; A.push_back(d);
    }
    return;
}


/*
*  WriteArrayTextFile
*
*/

void WriteArrayTextFile(int n, double* arr, const char* fileName)
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}
/*
*  ReadArrayTextFile
*
*/


int ReadArrayTextFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;
    for (int i = 0; i < n; i++)
        fin >> arr[i];
    fin.close();
    return size;

}


void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    streamsize  cn = static_cast<streamsize>(n) * sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

int ReadArrayBinFile(int n, double* arr, const char* fileName)
{
    int size = 0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, static_cast<streamsize>(size) * sizeof(double));
    bfin.close();
    // ssdhs
    return size;
}

void ShowMainMenu()
{
    cout << "    Main Menu  \n";
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";
}

void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Local array  \n";
    cout << "    2.  Dynamic array 1 \n";
    cout << "    3.  Dynamic array 2  new \n";
    cout << "    4.  Dynamic array : vector \n";
    cout << "    5.  Exit \n";
}

void MenuInput()
{
    cout << "     Menu Input   \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File 1.txt \n";
    cout << "    4.  bb    \n";
    cout << "    5.  Exit \n";
}



void  TestVariant(int N, double* A, double* B, double* C) {
    for (int i = 0; i < N; i++) {
        B[i] = A[2 * i];
        C[i] = A[2 * i + 1];
    }
}
/*
*  Task  Var
*
*
*/
void TaskV()
{
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
        switch (ch) {
        case '1': cout << " 1 "; break;
        case '2': cout << " 2 "; break;
            //
        case '5': return;
        }
        cout << " Press any key and enter\n";
        ch = getchar();
    } while (ch != 27);

}

void ArrayLocal()
{
    double A[1000], B[500], C[500];
    int n;
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
        switch (ch) {
        case '1': cout << " 1 "; break;
        case '2': cout << " 2 "; break;
            //
        case '5': return;
        }
        cout << " Press any key and enter\n";
        ch = getchar();
    } while (ch != 27);

}


void Task1() {

    int N;
    cout << "Введіть розмір масиву: ";
    cin >> N;

    // Створення масиву A
    double* A = new double[N];
    cout << "Введіть елементи масиву A (через пробіл): ";// ConsoleInputArray(N, A);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Створення масиву C та обчислення його значень
    double* C = new double[N];
    for (int i = 0; i < N; ++i) {
        C[i] = pow(2, A[i]); // Обчислення 2^A[i]
    }

    // Вивід масиву C
    cout << "Масив C: ";
    for (int i = 0; i < N; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;

    // Звільнення пам'яті, виділеної під масиви
    delete[] A;
    delete[] C;
}

void Task2() {
    int size;
    cout << "Введіть розмір масиву: ";
    cin >> size;

    if (size <= 0) {
        cout << "Розмір масиву повинен бути додатнім числом." << endl;
        return;
    }

    int *arr=new int[size];
    cout << "Введіть елементи масиву: ";//ConsoleInputArray(size, arr);
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int c, d;
    cout << "Введіть границі діапазону [c, d]: ";
    cin >> c >> d;

    int max_value = INT_MIN; // початкове значення максимуму
    int max_index = -1; // індекс максимального елемента
    bool found_even = false; // чи було знайдено парний елемент

    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            found_even = true;
            break; // виходимо з циклу, якщо знайдено парний елемент
        }
        if (arr[i] >= c && arr[i] <= d) { // перевірка, чи елемент у діапазоні [c, d]
            if (arr[i] >= max_value) { // оновлення максимуму
                max_value = arr[i];
                max_index = i;
            }
        }
    }

    if (!found_even) // якщо не знайдено парного елемента, виводимо повідомлення
        cout << "Не знайдено останнього максимального елемента у заданому діапазоні до першого парного елемента." << endl;
    else // інакше виводимо номер останнього максимального елемента
        cout << "Номер останнього максимального елемента: " << max_index << endl;
    delete[] arr;
}
   
void Task3() {
    const int MAX_SIZE = 500;

    int n;
    float A[MAX_SIZE];

    cout << "Введіть розмір масиву (n <= 500): ";
    cin >> n;

    if (n <= 0 || n > MAX_SIZE) {
        cout << "Некоректний розмір масиву." << endl;
        return;
    }

    cout << "Введіть елементи масиву: ";//ConsoleInputArray(n, A);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    float sum_repeated = 0;
    float product_unique = 1;

    for (int i = 0; i < n; ++i) {
        float current = A[i];
        bool is_repeated = false;

        // Перевіряємо, чи число вже зустрічалось раніше
        for (int j = 0; j < i; ++j) {
            if (A[j] == current) {
                is_repeated = true;
                break;
            }
        }

        if (is_repeated) {
            sum_repeated += current; // додаємо до суми повторюючихся чисел
        }
        else {
            product_unique *= current; // множимо на унікальне число
        }
    }

    cout << "Сума повторюючихся чисел: " << sum_repeated << endl;
    cout << "Добуток унікальних чисел: " << product_unique << endl;
}


int main() {
    setlocale(LC_CTYPE, "ukr");
    ShowMainMenu();
    cout << "Choose Task which one do you want to watch :";
    int c;
    cin >> c;
    if (c == 1) {
        Task1();
    }
    else if (c == 2) {
        Task2();
    }
    else if (c == 3) {
        Task3();
    }
    return 0;
}

