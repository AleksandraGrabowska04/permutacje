#include <bits/stdc++.h> 
//#include <bits/stdc++.h> zawiera funkcje z różnych nagłówków, więc nie trzeba importować innych np.<math.h> do obliczania sqrt()
using namespace std;
// następna permutacja w kolejności leksykograficznej
void nextPer(string str)
{
	bool x = next_permutation(str.begin(), str.end());
    if (x == false)
    {
        cout << "\nBrak następnej permutacji w kolejności leksykograficznej\n"
            << endl;
    }
    else
    {
        cout << "\nNext: ";
        cout << str << endl;
     }
}

// poprzednia permutacja w kolejności leksykograficznej
void prevPer(string str)
{
	bool x = prev_permutation(str.begin(), str.end());
    if (x == false)
    {
        cout << "\nBrak poprzedniej permutacji w kolejności leksykograficznej\n"
            << endl;
    }
    else
    {
        cout << "Prev: ";
        cout << str << endl;
    }
}

//generuje m-tą permutację
string mPerm(string str, long int m)
{
    sort(str.begin(), str.end());
  
    long int i = 1;
    do
    {
        if (i == m)
            break;
  
        i++;
    } 
    while (next_permutation(str.begin(), str.end()));
    
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
        cout << "Parzysta\n" << endl;
    else
        cout << "Nieparzysta\n" << endl;
}

//wyświetla wszystkie permutacje s-string permutacji l- p-dlugosc permutacji
void permutacje(string s, int l, int p, int m, int* ilosc)
{ 
    if(*ilosc>0){
        if (l == p)
        {   
            *ilosc-=1;
            cout << endl << " \\X \n" << endl << endl;
            cout<<s<<endl;
            nextPer(s);
            prevPer(s);
            cout << endl <<"permutacja nr " << m << ": ";
            string mTa = mPerm(s, m);
            int liczbaTra = liczbaTransp(s, mTa);
            cout<<"\nLiczba transpozycji: "<<liczbaTra<<endl;
            parzystoscMtej(liczbaTra);
        }
        else
        {
            for (int i = l; i <= p; i++) 
            { 
    // swap() --> funkcja pobrana z nagłówka <bits/stdc++.h> 
                swap(s[l], s[i]); 
                permutacje(s, l+1, p, m, ilosc);
                swap(s[l], s[i]); 
            }
        }
    }
} 

int main()
{
    int permliczba, permdlugosc, permilosc, permm;
    string perm="1", strtemp;
    ifstream file("konfiguracja.conf");
    if(file.good()==false)
    {
        cout<<"Plik nie istnieje!";
        exit(1);
    }
    try{
        getline(file, strtemp);
        permliczba=stoi(strtemp);
    }
        catch (invalid_argument){
            return 2;
    }
    for(int i=1 ;i<=permliczba ;i++){
        int r=0;
        r++;
        try{
            getline(file, strtemp);
            permdlugosc=stoi(strtemp);
            if(permdlugosc < 2 || permdlugosc > 9)
                throw 3;
            getline(file, strtemp);
            permilosc=stoi(strtemp);
            getline(file, strtemp);
            permm=stoi(strtemp);
        }
        catch (invalid_argument){
            return 2;
        }
        catch (int errNum){
            return errNum;
        }
        cout << "\nRozdzial " << r << endl;
        for(int j=1; j<permdlugosc; j++)
        {
            string permtemp=to_string(j+1);
            perm.insert(j, permtemp);
        }
        permutacje(perm, 0, permdlugosc-1, permm, &permilosc);
        perm="1";
    }
    return 0;
    
/*  string str;
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

    return 0; */
// system() włącza skrypt bash myfile.sh
	system("/home/user/permutacje_pr/myfile.sh");
}
