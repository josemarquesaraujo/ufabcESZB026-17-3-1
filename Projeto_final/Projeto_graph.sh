#!/bin/sh
ARQUIVODADOS=/home/pi/ufabcESZB026-17-3-1/Projeto_final/Projeto.txt
ARQUIVOSAIDA=/home/pi/ufabcESZB026-17-3-1/Projeto_final/Projeto.png

gnuplot << EOF
set title "Título"
set ylabel "Eixo Y"
set xlabel "Eixo X"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
     linecolor rgb '#0060ad' \
     linetype 1 \
     linewidth 1 \
     pointtype 2 \
     pointsize 1.0 \
     title "meus dados" \
     with linespoints
EOF

