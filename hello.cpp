#include<iostream> 
#include<fstream>  
using namespace std; 
 
int main() 
{ 
 
ofstream ff("output.txt", ios::out); 
 
 
ff << "hello world"; 
ff.close(); 
 
system("PAUSE"); 
return 0; 
} 