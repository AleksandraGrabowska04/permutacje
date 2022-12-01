#!/bin/bash
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
