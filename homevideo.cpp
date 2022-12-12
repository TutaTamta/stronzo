#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void FullMatrix(int arrSize);
void PrintMatrix(int arrSize, float **arr);
void SumMatrix();

/*Придумать как вставить намёк на матрицу (динамичемский массив)*/
long double SrGeom(double *arr); 
long double SrSq(double *arr); 
long double SrArith(double *arr); 
long double SrHarm(double *arr); 

int main(){
    int pop = 0;
    int bob = 0;
    int Size = 0;
    float **A;
    float **B;
    float **C;

    cout << "Введите размерность массивов А и В: ";
    cin>>Size;
    
    FullMatrix(Size);


    do
    {
        cout << "(1) вывод матриц (там будет подменю)" << endl;
        cout << "(2) сложение матриц" << endl;
        cout << "(3) среднее штуки(там будет подменю)" << endl;
        cout << "(4) Найти числа и их номера, которые меньше m от пользователя" << endl;
        cout << "(5) Найти числа и их номера, которые больше m от пользователя" << endl;
        cout << "(0) Exit" << endl;
        cout<<"Выберите пункт меню: ";
        cin>>pop;
        cout<<"-------------------------------------------------------------------------\n";

        switch (pop)
        {
        case 1:{
            cout << "(1) Вывод матрицы А" << endl;
            cout << "(2) Вывод матрицы B" << endl;
            cout << "(3) Вывод матрицы C" << endl;
            cin>>bob;

            switch (bob)
            {
            case 1:{
                PrintMatrix(Size, A);
                break;
            }

            case 2:{
                PrintMatrix(Size, B);
                break;
            }

            case 3:{
                if (**C == 0) cout << "Матрица пустая" << endl;
                else PrintMatrix(Size, C);
                break;
            }
            
            default:
            cout<<"Неопознанная задча\n";
            cout<<"\n";
                break;
            }
            break;
        }

        case 2:{

            break;
        }

        case 3:{
            break;
        }

        case 4:{
            break;
        }

        case 5:{
            break;
        }

        case 0:{
            cout<<"Выход из программы...\n";
            cout<<"-------------------------------------------------------------------------\n";
            return(0);
            break;
         }
        
        default:
            cout<<"Выбери что-то другое\n";
            cout<<"-------------------------------------------------------------------------\n";
            cout<<"\n";
            break;
        }
    } while (pop != 0);
}

void FullMatrix(int arrSize) {
    srand(time(0));
    float **A = new float* [arrSize];
    for (int i = 0; i < arrSize; i++) {
        A[i] = new float [arrSize];
    }

    float **B = new float* [arrSize];
    for (int i = 0; i < arrSize; i++) {
        B[i] = new float [arrSize];
    }

    float **C = new float* [arrSize];
    for (int i = 0; i < arrSize; i++) {
        C[i] = new float [arrSize];
    }

    for(int i =0; i<arrSize;i++){
        for (int j = 0; j < arrSize; j++) A[i][j]=(rand() % 10 - 10) / float((rand() % 10 - 10));
    }

    for(int i =0; i<arrSize;i++){
        for (int j = 0; j < arrSize; j++) B[i][j]=(rand() % 10 - 10) / float((rand() % 10 - 10));
    }
}

void PrintMatrix(int arrSize, float **arr) {

    for (int i = 0; i < arrSize; i++){
            for (int j = 0; j < arrSize; j++) cout << setw(4) <<setprecision(2) << arr[i][j] << "   ";
            cout << endl;
        }
    cout<<"-------------------------------------------------------------------------\n";
}