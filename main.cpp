#include <bits/stdc++.h> 
//#include <bits/stdc++.h> zawiera funkcje z różnych nagłówków, więc nie trzeba importować innych np.<math.h> do obliczania sqrt()
using namespace std;


void permutacja(string s, int l, int p) 
{ 
    if (l == p) 
        cout<<s<<endl; 
    else
    { 
        for (int i = l; i <= p; i++) 
        { 
            swap(s[l], s[i]); 
            permutacja(s, l+1, p); 
            swap(s[l], s[i]); 
        } 
    } 
} 

int main()
{
	string str; 
	cout<<"Podaj ciąg znaków: ";
	cin>>str;
    int n = str.size(); 
    permutacja(str, 0, n-1); 
    return 0; 
	system("/home/user/permutacje_pr/myfile.sh");
}
