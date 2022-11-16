#include <bits/stdc++.h> 
//#include <bits/stdc++.h> zawiera funkcje z różnych nagłówków, więc nie trzeba importować innych np.<math.h> do obliczania sqrt()
using namespace std;

//wyświetla wszystkie permutacje
void permutacje(string s, int l, int p) 
{ 
    if (l == p) 
        cout<<s<<endl; 
    else
    { 
        for (int i = l; i <= p; i++) 
        { 
// swap() --> funkcja pobrana z nagłówka <bits/stdc++.h> 
            swap(s[l], s[i]); 
            permutacje(s, l+1, p); 
            swap(s[l], s[i]); 
        } 
    } 
} 

// następna permutacja w kolejności leksykograficznej
void nextPer(string str)
{
	bool x = next_permutation(str.begin(), str.end());
    if (x == false)
        cout << "Brak następnej permutacji w kolejności leksykograficznej"
            << endl;
    else
        cout << str << endl;
}

// poprzednia permutacja w kolejności leksykograficznej
void prevPer(string str)
{
	bool x = prev_permutation(str.begin(), str.end());
    if (x == false)
        cout << "Brak poprzedniej permutacji w kolejności leksykograficznej"
            << endl;
    else
        cout << str << endl;
}


int main()
{
	string str; 
	cout<<"Podaj ciąg znaków: ";
	cin>>str;
    int n = str.size(); 
    permutacje(str, 0, n-1); 
	nextPer(str);
	prevPer(str);
    return 0; 
// system() włącza skrypt bash myfile.sh
	system("/home/user/permutacje_pr/myfile.sh");
}
