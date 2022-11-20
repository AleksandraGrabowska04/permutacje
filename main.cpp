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
        cout << "Next: ";
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
        cout << "PREV: ";
        cout << str << endl;
        string s = str;
}

//generuje m-tą permutację
string mPerm(string str, long int m)
{
    sort(str.begin(), str.end());
  
    long int i = 1;
    do {
        if (i == m)
            break;
  
        i++;
    } while (next_permutation(str.begin(), str.end()));
    
    cout << str << endl;
    return str;
}

// liczba transpozycji (zamian), które trzeba wykonać w str, aby otrzymać m-tą permutację
int liczbaTransp(string s1, string s2)
{
    int size = s2.size();
    int i = 0, j = 0;
    int zamiany = 0;

    while (i < size) 
    {
        j = i;
 
        while (s1[j] != s2[i]) 
        {
            j += 1;
        }
 
        while (i < j) 
        {
 
            swap(s1[j], s1[j-1]);
            j -= 1;
            zamiany += 1;
        }
        i += 1;
    }
    return zamiany+1;
}

//sprawdza czy m-ta permutacja jest parzysta czy nieparzysta
void parzystoscMtej(int x)
{
    if(x%2==0)
        cout << "Parzysta" << endl;
    else
        cout << "Nieparzysta" << endl;
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
    int m;
    cout<<"Podaj numer permutacji: ";
    cin>>m;
    string mTa = mPerm(str, m);
    liczbaTransp(str, mTa);
    int liczbaTra = liczbaTransp(str, mTa);
    cout<<"Liczba transpozycji: ";
    cout<<liczbaTra<<endl;
    parzystoscMtej(liczbaTra);

    return 0; 
// system() włącza skrypt bash myfile.sh
	system("/home/user/permutacje_pr/myfile.sh");
}
