#include<iostream>
using namespace std;
class Complex                       
 {
	 double real;       
	 double img;
	 public: 
	 Complex();           
	 friend istream & operator >> (istream &, Complex &);  
	 friend ostream & operator << (ostream &, const Complex &); 
	 Complex operator + (Complex); 
	 Complex operator * (Complex); 
 };
 Complex::Complex()                 
 {
	 real = 0;
	 img = 0;
 }
 istream & operator >> (istream &, Complex & i)
 {
	 cin >> i.real >> i.img;
	 return cin;
 }
 ostream & operator << (ostream &, const Complex & d)
 {
	 cout << d.real << " + " << d.img << "i" << endl;
	 return cout;
 }
 Complex Complex::operator + (Complex c1)   
 {
	 Complex temp;
	 temp.real = real + c1.real;
	 temp.img = img + c1.img;
	 return temp;
 }
 Complex Complex::operator * (Complex c2)   
 {
	 Complex tmp;
	 tmp.real = real * c2.real - img * c2.img;
	 tmp.img = real * c2.img + img * c2.real;
	 return tmp;
 }
 int main()
 {
	 Complex C1, C2, C3, C4;
	 int flag = 1;
	 char b;
	 while (flag == 1)
	 {
		 cout << "Enter Real and Imaginary part of the Complex Number 1 : \n";
		 cin >> C1;
		 cout << "Enter Real and Imaginary part of the Complex Number 2 : \n";
		 cin >> C2;
		 int f = 1;
		 while (f == 1)
		 {
			 cout << "Complex Number 1 : " << C1 << endl;
			 cout << "Complex Number 2 : " << C2 << endl;
			 cout << "**********MENU**********" << endl;
			 cout << "1. Addition of Complex Numbers" << endl;
			 cout << "2. Multiplication of Complex Numbers" << endl;
			 cout << "3. Exit\n";
			 int a;
			 cout << "Enter your choice from above MENU (1 to 3) : ";
			 cin >> a;
		 if (a == 1)
		 {
			 C3 = C1+C2;
			 cout << "Addition : " << C3 << endl;
			 cout << "Do you wan to perform another operation (y/n) : \n";
			 cin >> b;
		 if (b == 'y' || b == 'Y')
		 {
		 	f=1;
		 }
		 else
		 {
			 cout << "Thanks for using this program!!\n";
			 flag=0;
			 f=0;
		 }
		 }
		 else if (a == 2)
		 {
			 C4 = C1 * C2;
			 cout << "Multiplication : " << C4 << endl;
			 cout << "Do you wan to perform another operation (y/n) : \n";
			 cin >> b;
		 if (b == 'y' || b == 'Y')
		 {
			 f=1;
		 }
		 else
		 {
			 cout << "Thanks for using this program!!\n";
			 flag=0;
			 f=0;
		 }
		 }
		 else
		 {
			 cout << "Thanks for using this program!!\n";
			 flag=0;
			 f=0;
		 }
		 }
		 }
		 return 0;
 }