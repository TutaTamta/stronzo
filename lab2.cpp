#include <iostream>
#include<cmath>
using namespace std;
const int k1 = 2000;
const int k2 = 20;

int SimpleNum(int m);
void FirstK(double *S);
void PrintSimple(double *S);

long double SrGeom(double *arr);
long double SrSq(double *arr);
long double SrArith(double *arr);
long double SrHarm(double *arr);


int main() {
  int n;
  double S[100];
  cout<<"Введите число"<<endl;
  cin>>n;
  int flag = SimpleNum(n);
  if (flag == 1) cout<<"простое число"<<endl;
  else cout<<"нихера"<<endl;
  FirstK(S);
  PrintSimple(S);
  cout<<"Среднее геометрическое равно: "<<SrGeom(S)<<endl;
  cout<<"Среднее квадратическое равно: "<<SrSq(S)<<endl;
  cout<<"Среднее арифметическое равно: "<<SrArith(S)<<endl;
  cout<<"Среднее гармоническое равно: "<<SrHarm(S)<<endl;
  return 0;
}

int SimpleNum(int m) {
  for (int i = 2; i <= sqrt(m); i++) {
    if (m % i == 0) {
      return 0; 
    }
  }
  return 1; 
}

void FirstK(double *S) {
  int v, m, flag;
  float formulaMink1, formulaMink2, formulaMaxk1, formulaMaxk2;
  m = 0;
  formulaMink1 = k1/(log(k1)-(3/2));
  formulaMaxk1 = k1/(log(k1)-(1/2));
  formulaMink2 = k2*(log(k2)+log(log(k2))-(3/2.));
  formulaMaxk2 = k2*(log(k2)+log(log(k2))-(1/2.));
  cout <<"formulaMink1 = " << formulaMink1 <<endl;
  cout <<"formulaMaxk1 = " << formulaMaxk1 <<endl;
  cout <<"formulaMink2 = " << formulaMink2 <<endl;
  cout <<"formulaMaxk2 = " << formulaMaxk2 <<endl;
  for(int i = 0, v = 0; i < k1, v < 100; i++) {
    flag = SimpleNum(i);
    if(flag == 1) {
      v++;
      S[m] = i;
      m++;
      if(v == k2) {
        cout << "20 i = " << i <<endl;
        if(formulaMink2 < i < formulaMaxk2) cout<<"Соответствует формуле"<<endl;
        else cout << "wtf" << endl;
        
      }
    }
  }
  if (formulaMink1 < v < formulaMaxk1) cout<<"Соответствует формулам"<<endl;
}

void PrintSimple(double *S) {
  for(int i = 0; i<100; i++) {
    cout << S[i] << "\t";
  }
  cout << "\n";
}

long double SrGeom(double *arr){
    long double sum=0;
    cout << "sum = " << sum << endl;
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
    sum = sum/10;
    return sum;
}

long double SrHarm(double *arr){
    long double sum=0;
    for(int i=0; i<100; i++) sum=sum+1/arr[i];
    return 100/sum;  
}
