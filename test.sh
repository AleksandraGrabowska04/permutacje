#!/bin/bash
chmod u+x ./run.sh
FILE1=./run.sh
FILE4=./test/time.txt
FILE5=./test/wynik.log
test -f $FILE4 || touch $FILE4
if test -f "$FILE1"; then
if [ -x "$FILE1" ]; then
{ time ./run.sh 1 2>> ./test/run.stderr ; } 2>> ./test/time.txt
else
    echo "Błąd! Plik $FILE1 nie istnieje, nie można przeprowadzić testów."
fi
else
    echo "Błąd! Brak uprawnień do uruchamiania pliku $FILE1"
fi
if [ ! -s "$FILE4" ]; then
    echo "Błąd! Nie zapisano czasów w pliku $FILE4."
fi
if [ ! -s "$FILE5" ]; then
    echo "Błąd! Plik $FILE5 z rejestrem zdarzeń jest pusty."
fi
