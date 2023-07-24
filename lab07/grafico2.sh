#!/bin/sh
ARQUIVODADOS=/home/pi/sist_embarcados_git/lab07/gnuplot/dados2.txt
ARQUIVOSAIDA=/home/pi/sist_embarcados_git/lab07/gnuplot/dados2.png

gnuplot << EOF
set title "Grafico 2 (Barbie)"
set ylabel "Eixo Y"
set xlabel "Eixo X"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
     linecolor rgb '#ff007f' \
     linetype 1 \
     linewidth 5 \
     pointtype 2 \
     pointsize 7.0 \
     title "meus dados" \
     with linespoints
EOF

