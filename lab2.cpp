#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;
const int k1 = 2000;
const int k2 = 20;

int SimpleNum(int m); //проверка на просоту
void KK(double *S); // сверка с формулами для чисел k1 и k2
void PrintSimple(double *S); // вывод массива простых чисел

long double SrGeom(double *arr); // среднее геометрическое
long double SrSq(double *arr); // среднее квадратическое
long double SrArith(double *arr); // среднее арифметическое
long double SrHarm(double *arr); // среднее гармоническое 


int main() {
  int n;
  double S[100];
  cout<<"Введите число"<<endl;
  cin>>n;
  cout << "\n";
  int flag = SimpleNum(n);
  if (flag == 1) cout<<"Число '"<<n<<"' простое число"<<endl;
  else cout<<"Число '"<<n<<"' не является простым числом"<<endl;
  cout << "\n";
  KK(S);
  PrintSimple(S);
  cout << "\n";
  cout << "---------------------------------------\n";
  cout<<"Среднее геометрическое равно: "<<SrGeom(S)<<endl;
  cout << "---------------------------------------\n";
  cout<<"Среднее квадратическое равно: "<<SrSq(S)<<endl;
  cout << "---------------------------------------\n";
  cout<<"Среднее арифметическое равно: "<<SrArith(S)<<endl;
  cout << "---------------------------------------\n";
  cout<<"Среднее гармоническое равно: "<<SrHarm(S)<<endl;
  cout << "---------------------------------------\n";
  return 0;
}

int SimpleNum(int m) {
  if (m == 0) return 0;
  for (int i = 2; i <= sqrt(m); i++) {
    if (m % i == 0) return 0; 
  }
  return 1; 
}

void KK(double *S) {
  int v, m, flag;
  float formulaMink1, formulaMink2, formulaMaxk1, formulaMaxk2;
  m = 0;
  formulaMink1 = k1/(log(k1)-(3/2));
  formulaMaxk1 = k1/(log(k1)-(1/2));
  formulaMink2 = k2*(log(k2)+log(log(k2))-(3/2.));
  formulaMaxk2 = k2*(log(k2)+log(log(k2))-(1/2.));
  for(int i = 1, v = 0; i < k1, v < 100; i++) {
    flag = SimpleNum(i);
    if(flag == 1) {
      v++;
      S[m] = i;
      m++;
      if(v == k2) {
        if(formulaMink2 < i < formulaMaxk2) cout<<"Соответствует формуле (4)"<<endl;
        else cout << "wtf" << endl;
        
      }
    }
  }
  if (formulaMink1 < v < formulaMaxk1) cout<<"Соответствует формулам (2) и (3)"<<endl;
}

void PrintSimple(double *S) {
  for(int i = 0; i<100; i++) {
    cout <<"|"<<setw(4) << S[i] << "|\t";
  }
  cout << "\n";
}

long double SrGeom(double *arr){
    long double sum=0;
    for(int i=0; i<100; i++) sum=sum + log(arr[i]);
    sum=sum/100;
    return exp(sum);  
}

long double SrSq(double *arr){
    long double sum=0;
    for(int i=0; i<100; i++) sum=sum + pow(arr[i],2);
    sum = sum/100;
    return sqrt(sum);  
}

long double SrArith(double *arr){
    long double sum=0;
    for(int i=0; i<100; i++) sum=sum + arr[i];
    sum = sum/100;
    return sum;
}

long double SrHarm(double *arr){
    long double sum=0;
    for(int i=0; i<100; i++) sum=sum+1/arr[i];
    return 100/sum;  
}
