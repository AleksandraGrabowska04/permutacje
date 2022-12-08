#!/bin/bash
FILE=./main.cpp
if test -f "$FILE"; then
if [ -d "./wynik" ]; then
if [ -d "./images" ]; then
if [ -d "./build" ]; then
cmake --build ./build
./build/main | tee ./wynik/wynik.txt
touch ./wynik/wynik.tex
cat > ./wynik/wynik.tex << EOF
\documentclass{article}
\usepackage{graphicx}
\graphicspath{ {./images/} }
\usepackage[T1]{fontenc}
\begin{document}
\begin{center}
\begin{large}
\newcommand\X{-----------------------------------------------------------------------------------------------------------\\\}
\input{"./wynik/wynik.txt"}
\includegraphics[width=\textwidth]{dfa}
\end{large}
\end{center}
\end{document}
EOF
pdflatex ./wynik/wynik.tex
mv -t ./wynik wynik.aux wynik.log wynik.pdf
xdg-open ./wynik/wynik.pdf
else
    echo "Błąd! Nie znaleziono katalogu build, nie można skompilować program."
fi
else
    echo "Błąd! Nie znaleziono katalogu images, stwórz katalog images w lokalizacji programu oraz dodaj zdjęcie o nazwie dfa."
fi
else    
    echo "Błąd! Nie znaleziono katalogu wynik, stwórz katalog wynik w lokalizacji programu."
fi
else
    echo "Błąd! Nie znaleziono pliku $FILE."
fi
