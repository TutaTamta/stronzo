#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;
const int arrSize=100;

void Sr100();
int Fact(int num);
int Fib(int num);
double Fun(int point);
string PlusMinus(int num);

int main(){
   int pop = 0;
   do
   {
      cout<<"(1) Вычислить средние значения 100 случайных чисел из диапазона от 1 до 100" << endl;
      cout<<"(2) Вычислить 7!, 10!, 12!" << endl;
      cout<<"(3) Вычислить числа Фибоначчи с номерами 6, 11, 41" << endl;
      cout<<"(4) Вычислить значение функции f в точках 4, 12, 16, 32 согласно варианту 2" << endl;
      cout<<"(5) Проверить на четность числа Фибоначчи с номерами 13 и 15" << endl;
      cout<<"(0) Exit \n";
      cout<<"Выбери что-нибудь: ";
      cin>>pop;
      cout<<"-------------------------------------------------------------------------\n";
      switch(pop)
      {
         case 1:{
            Sr100();
            cout<<"-------------------------------------------------------------------------\n";
            break;
         }
         case 2:{
            int num7=7, num10=10, num12=12;
            cout<<"7! = "<<Fact(num7)<<endl;
            cout<<"10! = "<<Fact(num10)<<endl;
            cout<<"12! = "<<Fact(num12)<<endl;
            cout<<"-------------------------------------------------------------------------\n";
            break;
         }
         case 3:{
            int num6=6, num11=11, num41=41;
            cout<<"6-е число в последовательности Фибоначчи = "<<Fib(num6)<<endl;
            cout<<"11-е число в последовательности Фибоначчи = "<<Fib(num6)<<endl;
            cout<<"41-е число в последовательности Фибоначчи = "<<Fib(num6)<<endl;
            cout<<"-------------------------------------------------------------------------\n";
            break;
         }
         case 4:{
            int point1=4, point2=12, point3=16, point4=32;
            cout<<"Значение функции f в точке 4 = "<<Fun(point1)<<endl;
            cout<<"Значение функции f в точке 12 = "<<Fun(point2)<<endl;
            cout<<"Значение функции f в точке 16 = "<<Fun(point3)<<endl;
            cout<<"Значение функции f в точке 32 = "<<Fun(point4)<<endl;
            cout<<"-------------------------------------------------------------------------\n";
            break;
         }
         case 5:{
            int num13=13, num15=15;            
            cout<<"13-е число в последовательности Фибоначчи "<<Fib(num13)<<" является "<<PlusMinus(Fib(num13))<<endl;
            cout<<"15-е число в последовательности Фибоначчи "<<Fib(num15)<<" является "<<PlusMinus(Fib(num15))<<endl;
            cout<<"-------------------------------------------------------------------------\n";
            break;
         }
         case 0:{
            cout<<"Выход из программы...\n";
            cout<<"-------------------------------------------------------------------------\n";
            return(0);
            break;
         }
         default:{
            cout<<"Выбери что-то другое\n";
            cout<<"-------------------------------------------------------------------------\n";
            cout<<"\n";
            break;
         }
      }
   }
   while(!(pop==0));
}

void Sr100()
{
    srand(time(0));
    double *array;
    array=new double[arrSize];
    for(int i =0; i<arrSize;i++){
        array[i]=rand()%100+1;
        cout<<array[i]<<'\t';
    }
    cout<<endl;
    cout<<"-------------------------------------------------------------------------\n";
///////////////////
    long double sum=0;
    for(int i =0; i<arrSize;i++) sum+=1/array[i];
    cout<<"Среднее гармоническое = "<<arrSize/sum<<endl;
//////////////////
    sum=0;
    for(int i =0; i<arrSize;i++) sum=sum+log(array[i]);
    sum=sum/arrSize;
    cout<<"Среднее геометрическое = "<<exp(sum)<<endl;
//////////////////
    sum=0;
    for(int i =0; i<arrSize;i++) sum+=array[i];
    cout<<"Среднее арифметическое = "<<sum/arrSize<<endl;
/////////////////
    sum=0;
    for(int i =0; i<arrSize;i++) sum+=pow(array[i],2);
    cout<<"Среднее квадратическое = "<<sqrt(sum/arrSize)<<endl;  
/////////////////
    delete array;
}
int Fact(int num)
{
    if(num==0) return 1;
    else return num*Fact(num-1);   
}
int Fib(int num)
{
    if(num==1 || num==2) return 1;
    else return Fib(num-1)+Fib(num-2);
}
double Fun(int point)
{
    if(point<7) return Fact(point)/Fib(point);
    else if(point>=8 && point<14) return Fact(point)/pow(4,point);
    else if(point>=15 && point<31) return pow(2,point)/Fib(point);
    else if(point>=31) return 1;
}
string PlusMinus(int num)
{
    if(num%2==0)  return "четным";
    else if(num%2!=0) return "нечетным";
}