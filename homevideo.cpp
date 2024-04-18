#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void PrintMatrix(int arrSize, double **arr);

long double SrGeom(double **arr, int arrSize);
long double SrSq(double **arr, int arrSize); 
long double SrArith(double **arr, int arrSize); 
long double SrHarm(double **arr, int arrSize); 

int main(){
    int m = 0;
    int pop = 0;
    int bob = 0;
    int fof = 0;
    int arrSize = 0;
    char ch = 'q';

    cout << "Введите размерность массивов А и В: ";
    cin>>arrSize;
    cout << "Введите число: ";
    cin>>m;
    

    srand(time(0));
    double **A = new double* [arrSize];
    for (int i = 0; i < arrSize; i++) {
        A[i] = new double [arrSize];
    }

    double **B = new double* [arrSize];
    for (int i = 0; i < arrSize; i++) {
        B[i] = new double [arrSize];
    }

    double **C = new double* [arrSize];
    for (int i = 0; i < arrSize; i++) {
        C[i] = new double [arrSize];
    }

    for(int i =0; i<arrSize;i++){
        for (int j = 0; j < arrSize; j++) A[i][j]= (rand() % 10 + 1) / double((rand() % 10 + 1));
    }

    for(int i =0; i<arrSize;i++){
        for (int j = 0; j < arrSize; j++) B[i][j]= (rand() % 10 + 1) / double((rand() % 10 + 1));
    }

    do
    {
        cout << "(1) Вывод матриц" << endl;
        cout << "(2) Сложение матриц" << endl;
        cout << "(3) Среднее" << endl;
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
            cout << "(a) Вывод всех матриц" << endl;
            cout << "(4) Назад" << endl;
            cout << "Выберите пункт меню: ";
            cin>>ch;
            cout<<"-------------------------------------------------------------------------\n";

            switch (ch)
            {
            case '1':{
                PrintMatrix(arrSize, A);
                break;
            }

            case '2':{
                PrintMatrix(arrSize, B);
                break;
            }

            case '3':{
                if (**C == 0) {
                    cout << "Матрица пустая" << endl;
                    cout<<"-------------------------------------------------------------------------\n";
                }
                else PrintMatrix(arrSize, C);
                break;
            }

            case '4':{
                cout<<"-------------------------------------------------------------------------\n";
                break;
            }

            case 'a':{
                PrintMatrix(arrSize, A);
                PrintMatrix(arrSize, B);
                PrintMatrix(arrSize, C);
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
            for (int i = 0; i < arrSize; i++) {
                for (int j = 0; j < arrSize; j++) {
                    C[i][j] = A[i][j] + B[i][j];
                }
            }
            break;
        }

        case 3:{
            cout << "(1) Среднее для матрицы А" << endl;
            cout << "(2) Среднее для матрицы B" << endl;
            cout << "(3) Среднее для матрицы C" << endl;
            cout << "(0) Назад" << endl;
            cout << "Выберите пункт меню: ";
            cin>>bob;
            cout<<"-------------------------------------------------------------------------\n";

            switch (bob)
            {
            case 1:{
                cout<<"Среднее геометрическое равно: "<<SrGeom(A, arrSize)<<endl;
                cout<<"-------------------------------------------------------------------------\n";
                cout<<"Среднее квадратическое равно: "<<SrSq(A, arrSize)<<endl;
                cout<<"-------------------------------------------------------------------------\n";
                cout<<"Среднее арифметическое равно: "<<SrArith(A, arrSize)<<endl;
                cout<<"-------------------------------------------------------------------------\n";
                cout<<"Среднее гармоническое равно: "<<SrHarm(A, arrSize)<<endl;
                cout<<"-------------------------------------------------------------------------\n";
                break;
            }
            case 2:{
                cout<<"Среднее геометрическое равно: "<<SrGeom(B, arrSize)<<endl;
                cout<<"-------------------------------------------------------------------------\n";
                cout<<"Среднее квадратическое равно: "<<SrSq(B, arrSize)<<endl;
                cout<<"-------------------------------------------------------------------------\n";
                cout<<"Среднее арифметическое равно: "<<SrArith(B, arrSize)<<endl;
                cout<<"-------------------------------------------------------------------------\n";
                cout<<"Среднее гармоническое равно: "<<SrHarm(B, arrSize)<<endl;
                cout<<"-------------------------------------------------------------------------\n";
                break;
            }
            case 3:{
                cout<<"Среднее геометрическое равно: "<<SrGeom(C, arrSize)<<endl;
                cout<<"-------------------------------------------------------------------------\n";
                cout<<"Среднее квадратическое равно: "<<SrSq(C, arrSize)<<endl;
                cout<<"-------------------------------------------------------------------------\n";
                cout<<"Среднее арифметическое равно: "<<SrArith(C, arrSize)<<endl;
                cout<<"-------------------------------------------------------------------------\n";
                cout<<"Среднее гармоническое равно: "<<SrHarm(C, arrSize)<<endl;
                cout<<"-------------------------------------------------------------------------\n";
                break;
            }
            case 0:{
                cout<<"-------------------------------------------------------------------------\n";
                break;
            }
            
            default:
                cout<<"Неопознанная задча\n";
                cout<<"\n";
                break;
            }

            break;
        }

        case 4:{
            cout << "(1) Сравнить число с матрицей А" << endl;
            cout << "(2) Сравнить число с матрицей B" << endl;
            cout << "(3) Сравнить число с матрицей C" << endl;
            cout << "(0) Назад" << endl;
            cout << "Выберите пункт меню: ";
            cin>>bob;
            cout<<"-------------------------------------------------------------------------\n";

            switch (bob)
            {
            case 1: {
                for (int i = 0; i < arrSize; i++)
                    for (int j = 0; j < arrSize; j++) {
                        if (A[i][j] < m) {
                            cout << "A["<<i<<"]["<<j<<"]"<<" = "<<A[i][j]<<"\t";
                        }
                    }
                break;
            }
            case 2: {
                for (int i = 0; i < arrSize; i++)
                    for (int j = 0; j < arrSize; j++) {
                        if (B[i][j] < m) {
                            cout << "B["<<i<<"]["<<j<<"]"<<" = "<<B[i][j]<<"\t";
                        }
                    }
                break;
            }
            case 3: {
                if (**C == 0) cout<<"Матрица пустая"<<endl;
                for (int i = 0; i < arrSize; i++)
                    for (int j = 0; j < arrSize; j++) {
                        if (C[i][j] < m) {
                            cout << "C["<<i<<"]["<<j<<"]"<<" = "<<C[i][j]<<"\t";
                        }
                    }
                break;
            }
            case 0: {
                cout<<"Неопознанная задча\n";
                cout<<"\n";
                break;
            }
            
            default:
                break;
            }
            break;
        }

        case 5:{
            cout << "(1) Сравнить число с матрицей А" << endl;
            cout << "(2) Сравнить число с матрицей B" << endl;
            cout << "(3) Сравнить число с матрицей C" << endl;
            cout << "(0) Назад" << endl;
            cout << "Выберите пункт меню: ";
            cin>>bob;
            cout<<"-------------------------------------------------------------------------\n";

            switch (bob)
            {
            case 1: {
                for (int i = 0; i < arrSize; i++)
                    for (int j = 0; j < arrSize; j++) {
                        if (A[i][j] > m) {
                            cout << "A["<<i<<"]["<<j<<"]"<<" = "<<A[i][j]<<"\t";
                        }
                    }
                    cout<<"\n";
                break;
            }
            case 2: {
                for (int i = 0; i < arrSize; i++)
                    for (int j = 0; j < arrSize; j++) {
                        if (B[i][j] > m) {
                            cout << "B["<<i<<"]["<<j<<"]"<<" = "<<B[i][j]<<"\t";
                        }
                    }
                    cout<<"\n";
                break;
            }
            case 3: {
                for (int i = 0; i < arrSize; i++)
                    for (int j = 0; j < arrSize; j++) {
                        if (C[i][j] > m) {
                            cout << "C["<<i<<"]["<<j<<"]"<<" = "<<C[i][j]<<"\t";
                        }
                    }
                    cout<<"\n";
                break;
            }
            case 0: {
                cout<<"Неопознанная задча\n";
                cout<<"\n";
                break;
            }
            
            default:
                break;
            }
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

void PrintMatrix(int arrSize, double **arr) {

    for (int i = 0; i < arrSize; i++){
            for (int j = 0; j < arrSize; j++) cout << setw(4) <<setprecision(2) << arr[i][j] << "   ";
            cout << endl;
        }
    cout<<"-------------------------------------------------------------------------\n";
}

long double SrArith(double **arr, int arrSize){
    long double sum=0;
    for(int i=0; i<arrSize; i++)
        for (int j = 0; j < arrSize; j++) sum=sum + arr[i][j];
    sum = sum/arrSize;
    return sum;
}

long double SrSq(double **arr, int arrSize){
    long double sum=0;
    for(int i=0; i<arrSize; i++) 
        for (int j = 0; j < arrSize; j++) sum=sum + pow(arr[i][j],2);
    sum = sum/arrSize;
    return sqrt(sum);  
}

long double SrGeom(double **arr, int arrSize){
    long double sum=0;
    for(int i=0; i<arrSize; i++) 
        for (int j = 0; j < arrSize; j++) sum=sum + log(arr[i][j]);
    sum=sum/arrSize;
    return exp(sum);  
}

long double SrHarm(double **arr, int arrSize){
    long double sum=0;
    for(int i=0; i<arrSize; i++) 
        for (int j = 0; j < arrSize; j++) sum=sum+1/arr[i][j];
    return arrSize/sum;  
}
