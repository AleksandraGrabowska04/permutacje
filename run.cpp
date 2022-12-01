#include<iostream>
int main()
{
system("./main | tee ./wynik/wynik.txt");
system("chmod 777 ./wyniktopdf.sh");
system("./wyniktopdf.sh");
system("mv -t ./wynik wynik.aux wynik.log wynik.pdf");
system("xdg-open ./wynik/wynik.pdf");
return 0;
}
