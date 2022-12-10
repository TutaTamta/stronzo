#include <iostream>
#include<cmath>
using namespace std;
const int k1 = 2000, k2 = 20;


int SimpleNum(int m) {
  int s;
  s = 0; // maybe its a bullshit
  for (int i = 2; i <= sqrt(m); i++) {
    if (m % i == 0) {
      s = 0;
      return s; // возможно можно просто вписать число
    }
  }
  s = 1;
  return s; // same
}

void FirstK(int k1, int k2, int S[100]) {
  int v, formulaMin, formulaMax, m, flag;
  v, m = 0;
  formulaMin = k1/(log(k1)-(3/2));
  formulaMax = k1/(log(k1)-(1/2));
  for(int i = 0; i < k1; i++) {
    flag = SimpleNum(i);
    if(flag == 1) {
      v++;
      S[m] = i;
      m++;
      if(v == k2) {
        if((k2*(log(k2)+log(log(k2)))-(3/2)) < v < (i*(log(k2)+log(log(k2))-(1/2)))) cout<<"Соответствует формуле"<<endl;
      }
    }
  }
  if (fomulaMin < v < formulaMax) cout<<"Соответствует формулам"<<endl;
}

PrintSimple(int S[100]) {
  for(int i = 0; i<100; i++) {
    st << i;
  }
}

/*long double SrGeom(double *arr);
long double SrSq(double *arr);
long double SrArith(double *arr);
long double SrHarm(double *arr);*/


int main() {
  int n;
  int S[100];
  cout<<"Введите число"<<endl;
  cin>>n;
  int flag = SimpleNum(n);
  (flag == 1) cout<<"простое число"<<endl;
  else cout<<"нихера"<<endl;
  FirstK(k1, k2, S);
  PrintSimple(S);
/*  cout<<""<<SrGeom<<endl;
  cout<<""<<SrSq<<endl;
  cout<<""<<SrArith<<endl;
  cout<<""<<SrHarm<<endl;*/
  return 0;
}
/*
long double SrGeom(double *arr){
    long double sum=0;
    for(int i=0; i<100; i++)
        sum=sum+log(arr[i]);
    sum=sum/100;
    return exp(sum);  
}

long double SrSq(double *arr){
    long double sum=0;
    for(int i=0; i<100; i++)
        sum=sum + pow(arr[i],2);
    sum = sum/100;
    return sqrt(sum);  
}

long double SrArith(double *arr){
    long double sum=0;
    for(int i=0; i<100; i++)
        sum=sum + arr[i];
    sum = sum/10;
    return sum;
}

long double SrHarm(double *arr){
    long double sum=0;
    for(int i=0; i<100; i++)
        sum=sum+1/arr[i];
    return 100/sum;  
}
*/