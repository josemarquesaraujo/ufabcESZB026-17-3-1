#!/bin/sh
ARQUIVODADOS=/home/pi/sist_embarcados_git/lab07/gnuplot/dados3.txt
ARQUIVOSAIDA=/home/pi/sist_embarcados_git/lab07/gnuplot/dados3.png

gnuplot << EOF
set title "Grafico 3 O inimigo agora é outro"
set ylabel "Eixo Y"
set xlabel "Eixo X"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
     linecolor rgb '#006000' \
     linetype 1 \
     linewidth 2 \
     pointtype 2 \
     pointsize 1.0 \
     title "meus dados" \
     with linespoints
EOF

