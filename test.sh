#!/bin/bash

RUN=./run.sh
TIME_F=./test/time.txt
LOG=./test/wynik.log
MAH=./test/wynikiStare


#Sprawdzenie, czy można uruchomić run.sh i czy wgl istnieje
if test -f "$RUN"; then
    if [ -x "$RUN" ]; then
        opcja=()
        readarray -t opcja < ./opcje.txt
        echo "$opcja[*]"
        date +%T%N > ./test/godzinaRozpoczecia.txt #godzina rozpoczęcia testu
        if [[ " ${opcja[*]} " =~ " A " ]]; then 
cat > ./konfiguracja.conf << EOF
1
9
2
1
3
3
2
EOF
        { time ./run.sh 2>> ./test/runA.stderr ; } 2>> ./test/wynikTestA.txt
        fi
        if [[ " ${opcja[*]} " =~ " B " ]]; then
cat > ./konfiguracja.conf << EOF
1
4
2
1
3
3
2
EOF
{ time ./run.sh 2>> ./test/runB.stderr ; } 2>> ./test/wynikTestB.txt
        fi
        if [[ " ${opcja[*]} " =~ " C " ]]; then
cat > ./konfiguracja.conf << EOF
1
3
2
1
3
3
2
EOF
{ time ./run.sh 2>> ./test/runC.stderr ; } 2>> ./test/wynikTestC.txt
        fi

        date +%T%N >> ./test/godzinaRozpoczecia.txt #godzina zakończenia testu
    
    
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
pdflatex ./test/sprawozdanie.tex
mv -t ./test/wynikiStare  ./test/wynikTestA.txt ./test/wynikTestB.txt ./test/wynikTestC.txt ./test/runA.stderr ./test/runB.stderr ./test/runC.stderr

mv -t ./test  sprawozdanie.aux sprawozdanie.log sprawozdanie.pdf 