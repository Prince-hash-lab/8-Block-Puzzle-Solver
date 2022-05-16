/*
#include<iostream>
using namespace std;
 
class NUM
{
    private:
        int n;
         
    public:
        //function to get number
        void getNum(int x)
        {
            n=x;
        }
        //function to display number
        void dispNum(void)
        {
            cout << "value of n is: " << n;
        }
        //unary - operator overloading
        void operator - (void)
        {
            n=-n;
        }
};

int main()
{
    NUM num;
    num.getNum(10);
    -num;
    num.dispNum();
    cout << endl;
    return 0;
     
}

*/
//------------------------------------------

/*
#include<iostream.h>
#include<conio.h>

class FLOAT
{
    float no;
    public:
    FLOAT(){}
    void getdata()
    {
        cout<<"\n ENTER AN FLOATING NUMBER :";
        cin>>no;
     }
     void putdata()
     {
        cout<<"\n\nANSWER IS                   :"<<no;
     }
     FLOAT operator+(FLOAT);
     FLOAT operator*(FLOAT);
     FLOAT operator-(FLOAT);
     FLOAT operator/(FLOAT);
};
FLOAT FLOAT::operator+(FLOAT a)
{
    FLOAT temp;
    temp.no=no+a.no;
    return temp;
}
FLOAT FLOAT::operator*(FLOAT b)
{
    FLOAT temp;
    temp.no=no*b.no;
    return temp;
}
FLOAT FLOAT::operator-(FLOAT b)
{
    FLOAT temp;
    temp.no=no-b.no;
    return temp;
}
FLOAT FLOAT::operator/(FLOAT b)
{
    FLOAT temp;
    temp.no=no/b.no;
    return temp;
}


main()
{
  clrscr();
  FLOAT a,b,c;
  a.getdata();
  b.getdata();

  c=a+b;
  cout<<"\n\nAFTER ADDITION OF TWO OBJECTS";
  c.putdata();
  cout<<"\n\nAFTER MULTIPLICATION OF TWO OBJECTS";
  c=a*b;
  c.putdata();
  cout<<"\n\nAFTER SUBSTRACTION OF TWO OBJECTS";
  c=a-b;
  c.putdata();
  cout<<"\n\nAFTER DIVISION OF TWO OBJECTS";
  c=a/b;
  c.putdata();
  getch();
}
*/
//---------------------------------------------
/*
#include<iostream>
using namespace std;
class complex{
	private :
		int a,b;
	public:
			void getnum(int a,int b){
				this->a =a;
				this ->b =b;
			}
			void dis(){
				cout<<"a="<<a<<" b="<<b<<endl;
			}
			Complex operator+(complex c){
				complex temp;
				temp.a=a+c.a;
				temp.b=b+c.b;
				return temp;
			}
			
};
int main{
complex c1(2,3);
complex c2(3,4);
complex c3=c1+c2;
c3.disp;
return 0;
}

*/
//---------------------------------
/*
#include <cstring> 
#include <iostream> 
#include <string.h> 
  
using namespace std; 
  class CompareString { 
  
public:  char str[25];
  CompareString(char str1[]) 
    { 
        
        strcpy(this->str, str1); 
    } 
  
   
    int operator==(CompareString s2) 
    { 
        if (strcmp(str, s2.str) == 0) 
            return 1; 
        else
            return 0; 
    }  
};
void testcase1() 
{ 
    
    char str1[] = "Geeks"; 
    char str2[] = "ForGeeks"; 
  
   
    CompareString s1(str1); 
    CompareString s2(str2); 
  
    cout << "Comparing \"" << s1.str << "\" and \""
         << s2.str << "\"" << endl; 
  
    compare(s1, s2); 
} 

int main(){
	testcase1();
	return 0;
}
  
  */
 //--------------------------------------------
 /*
#include <iostream> 
#include <string.h> 
  
using namespace std; 
  
class AddString { 
  
public: 
   
    char s1[25], s2[25]; 
  
  
    AddString(char str1[], char str2[]) 
    { 
      
        strcpy(this->s1, str1); 
        strcpy(this->s2, str2); 
    } 
  
    
    void operator+() 
    { 
        cout << "\nConcatenation: " << strcat(s1, s2); 
    } 
}; 
  
int main() 
{ 
   
    char str1[] = "Aksh"; 
    char str2[] = "preetSingh"; 
  
   
    AddString a1(str1, str2); 
  
   
    +a1; 
    return 0; 
} 

*/
//------------------------------------------

/*
#include <iostream>
#include <iomanip>
using namespace std;
class Matrix
{
    private:
        int m[2][2],i,j;
    public:
        void read()
        {
            for(i=0;i<2;i++)
               for(j=0;j<2;j++)
                    cin>>m[i][j];
        }
        void display()
        {
            for(i=0;i<2;i++)
            {
                for(j=0;j<2;j++)
                    cout<<m[i][j]<<setw(2);
                cout<<endl;
            }
        }
        friend Matrix operator*(Matrix a,Matrix b)
        {
            int i,j,k,sum=0;
            Matrix c;
            for(i=0;i<2;i++)
            {
                for(j=0;j<2;j++)
               {
                    for(k=0;k<2;k++)
                    {
                        sum=sum+a.m[i][k]*b.m[k][j];
                    }
                    c.m[i][j]=sum;
                    sum=0;
                }
            }
            return c;
        }
};
int main()
{
    Matrix a,b,c;
    cout<<"Enter 1st matrix:"<<endl;
    a.read();
    cout<<"Enter 2nd matrix:"<<endl;
    b.read();
    c=a*b; //same as operator*(a,b);
    cout<<"The product is:"<<endl;
    c.display();
    return 0;
}

*/

//----------------------------------------

/*
#include <iostream>
using namespace std;
 
class Distance {
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
      
   public:
      // required constructors
      Distance() {
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i) {
         feet = f;
         inches = i;
      }
      friend ostream &operator<<( ostream &output, const Distance &D ) { 
         output << "F : " << D.feet << " I : " << D.inches;
         return output;            
      }

      friend istream &operator>>( istream  &input, Distance &D ) { 
         input >> D.feet >> D.inches;
         return input;            
      }
};

int main() {
   Distance D1(11, 10), D2(5, 11), D3;

   cout << "Enter the value of object : " << endl;
   cin >> D3;
   cout << "First Distance : " << D1 << endl;
   cout << "Second Distance :" << D2 << endl;
   cout << "Third Distance :" << D3 << endl;

   return 0;
}
*/