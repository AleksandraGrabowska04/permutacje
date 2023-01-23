#!/bin/bash

RUN=./run.sh
TIME_F=./test/time.txt
LOG=./test/wynik.log

# Towrzenie nowe pliku time.txt dla każdego uruchomienia testu
TIME_F=./test/time-$(date +%s).txt
touch $TIME_

#Sprawdzenie, czy można uruchomić run.sh i czy wgl istnieje
if test -f "$RUN"; then
    if [ -x "$RUN" ]; then

        #Uruchomienie run.sh i zapisanie czasów do time.txt
        { time ./run.sh 2>> ./test/run.stderr ; } 2>> $TIME_F
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
