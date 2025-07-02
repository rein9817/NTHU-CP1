#include <iostream>
using namespace std; 
void up(int n);
void down(int n);

void up(int n) 
{
    if(n>1) up(n-1);
    if(n>2) down(n-2);
    cout << "Move ring " << n << " in " << endl;
    if(n>2) up(n-2);
}

void down(int n)
{
    if(n>2) down(n-2);
    cout <<"Move ring " << n << " out " << endl;
    if(n>2) up(n-2);
    if(n>1) down(n-1);
}

int main()                  
{
    int n;
    cin>>n;
    down(n);
}