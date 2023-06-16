#!/bin/bash

# script baseado no código disponibilizado em:
# Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
# Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/

GPIO_AMARELO=16  # Usar uma variavel facilita alteracoes futuras na porta usada
GPIO_VERMELHO=20  # Usar uma variavel facilita alteracoes futuras na porta usada
GPIO_VERDE=21  # Usar uma variavel facilita alteracoes futuras na porta usada



# Inicio do programa
if [ $# -ne 1 ]; then                  # se nao houver exatamente um argumento passado ao programa
	echo "Nenhum comando passado. Uso: ./LED.sh command,"
	echo "onde comando pode ser: setup, on, off, status e close"
	echo -e " ex.: ./LED.sh setup, e em seguinda, ./LED.sh on"
	exit 2                         # erro que indica numero invalido de argumentos
fi

if [ "$1" == "ligar" ]; then
	for cont in 1 2 3 4 5; do
	echo "Habilitando a GPIO numero $GPIO_AMARELO"
	echo $GPIO_AMARELO >> "/sys/class/gpio/export"
	sleep 1                        # esperar 1 segundo para garantir que a gpio foi exportada
	echo "out" >> "/sys/class/gpio/gpio$GPIO_AMARELO/direction"
 	echo 1 >> "/sys/class/gpio/gpio$GPIO_AMARELO/value"
  	sleep 1
   	echo 0 >> "/sys/class/gpio/gpio$GPIO_AMARELO/value"

    	echo "Habilitando a GPIO numero $GPIO_VERMELHO"
	echo $GPIO_VERMELHO >> "/sys/class/gpio/export"
	sleep 1                        # esperar 1 segundo para garantir que a gpio foi exportada
	echo "out" >> "/sys/class/gpio/gpio$GPIO_VERMELHO/direction"
 	echo 1 >> "/sys/class/gpio/gpio$GPIO_VERMELHO/value"
  	sleep 2
   	echo 0 >> "/sys/class/gpio/gpio$GPIO_VERMELHO/value"

    	echo "Habilitando a GPIO numero $GPIO_VERDE"
	echo $GPIO_VERDE >> "/sys/class/gpio/export"
	sleep 1                        # esperar 1 segundo para garantir que a gpio foi exportada
	echo "out" >> "/sys/class/gpio/gpio$GPIO_VERDE/direction"
 	echo 1 >> "/sys/class/gpio/gpio$GPIO_VERDE/value"
  	sleep 1
   	echo 0 >> "/sys/class/gpio/gpio$GPIO_VERDE/value"
fi

	
echo "Fim"
