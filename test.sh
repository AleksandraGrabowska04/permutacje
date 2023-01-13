#!/bin/bash

RUN=./run.sh
TIME_F=./test/time.txt
LOG=./test/wynik.log
CONFIG=$1

# Towrzenie pliku time.txt jeżeli nie istnieje
test -f $TIME_F || touch $TIME_F

#wczytanie config z wieloma przypadkami
source $CONFIG

#Sprawdzenie, czy można uruchomić run.sh i czy wgl istnieje
if test -f "$RUN"; then
    if [ -x "$RUN" ]; then

        #Uruchomienie run.sh i zapisanie czasów do time.txt
        { time ./run.sh $PRZYPADKI 2>> ./test/run.stderr ; } 2>> $TIME_F
    else
        echo "Błąd!!!!!!!!!!! Plik $RUN nie istnieje lub nie jest wykonywalny."
    fi
else
    echo "Błąd!!!!!!!! Plik $RUN posiada błędne uprawnienia"
fi

#Sprawdza, czy czasy zostały zapisane do pliku
if [ ! -s "$TIME_F" ]; then
    echo "Błąd!!!!!!! Pomiary nie zostały zapisane do pliku $TIME_F."
fi

#Sprawdza, czy przebieg testu (czyli log) został zapisany do pliku wynik.log
if [ ! -s "$LOG" ]; then
    echo "Błąd!!!!!!!!!!! Dane nie zostały zapisane do pliku $LOG :(."
fi




#--------------->>>>>>>>>>>.WIADOMOŚĆ DLA JAKUBA -->>>>> zmieniłam skrypt, żeby czytał config, który powinien zawierać zmienną PRZYPADKI (linia 19).
# Ta zmienna bd przekazywana do run.sh, co pozwoli na użycie różnych przypadków w config w testowaniu.
# Wyczytałam w wiarygodnym źródle, jakim jest internet, że trzeba wszystko uruchamiać tak: ./run_test.sh configs/test1_config.cfg (oczywiście trzeba coś pozmieniać w tej ścieżce)
# żeby uruchomić test łącznie z configiem 
# wyrocznia powiada, że można zapisać różne scenariusze w jednym config, zadeklarować je w test.sh i uruchamiać test 
# na przykład:
:'
Tak można je deklarować w test.sh

#Scenario 1
string s = SCENARIO1_STRING;
int x = SCENARIO1_X;
int y = SCENARIO1_Y;

function(s, 0, s.size()-1, x, y);

#Scenario 2
s = SCENARIO1_STRING;
x = SCENARIO1_X;
y = SCENARIO1_Y;

function(s, 0, s.size()-1, x, y);


W config jakoą tak:
SCENARIO1_STRING="abcd"
SCENARIO1_X = 123456
SCENARIO1_Y = 123
'
