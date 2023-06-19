#!/bin/bash

# script baseado no código disponibilizado em:
# Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
# Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/

GPIO_AMARELO=16  # Usar uma variavel facilita alteracoes futuras na porta usada
GPIO_VERMELHO=20  # Usar uma variavel facilita alteracoes futuras na porta usada
GPIO_VERDE=21  # Usar uma variavel facilita alteracoes futuras na porta usada



# Inicio do programa

#o seguinte loop irá se repetir por 5 vezes
	for cont in 1 2 3 4 5; do

 		echo "Habilitando a GPIO numero $GPIO_VERMELHO"
		echo $GPIO_VERMELHO >> "/sys/class/gpio/export" #exporta a gpio
		sleep 1                        #exporta a gpio
		echo "out" >> "/sys/class/gpio/gpio$GPIO_VERMELHO/direction"#classifica o pino como saída
 		echo 1 >> "/sys/class/gpio/gpio$GPIO_VERMELHO/value"#muda o valor da saída para 1, acende o led
  		sleep 2 #aguarda 2 segundos
   		echo 0 >> "/sys/class/gpio/gpio$GPIO_VERMELHO/value"#muda o valor da saída para 0, apaga o led
     		echo $GPIO_VERMELHO >> "/sys/class/gpio/unexport"#desabilita a gpio 

    		echo "Habilitando a GPIO numero $GPIO_VERDE"
		echo $GPIO_VERDE >> "/sys/class/gpio/export"#exporta a gpio
		sleep 1                        # esperar 1 segundo para garantir que a gpio foi exportada
		echo "out" >> "/sys/class/gpio/gpio$GPIO_VERDE/direction"#classifica o pino como saída
 		echo 1 >> "/sys/class/gpio/gpio$GPIO_VERDE/value"#muda o valor da saída para 1, acende o led
  		sleep 1 #aguarda 1 segundo
   		echo 0 >> "/sys/class/gpio/gpio$GPIO_VERDE/value"#muda o valor da saída para 0, apaga o led
     		echo $GPIO_VERDE >> "/sys/class/gpio/unexport"#desabilita a gpio 
     
		echo "Habilitando a GPIO numero $GPIO_AMARELO"
		echo $GPIO_AMARELO >> "/sys/class/gpio/export"#exporta a gpio
		sleep 1                        # esperar 1 segundo para garantir que a gpio foi exportada
		echo "out" >> "/sys/class/gpio/gpio$GPIO_AMARELO/direction"#classifica o pino como saída
 		echo 1 >> "/sys/class/gpio/gpio$GPIO_AMARELO/value"#muda o valor da saída para 1, acende o led
  		sleep 1 #aguarda 1 segundo
   		echo 0 >> "/sys/class/gpio/gpio$GPIO_AMARELO/value"#muda o valor da saída para 0, apaga o led
     		echo $GPIO_AMARELO >> "/sys/class/gpio/unexport"#desabilita a gpio 


	
echo "Fim" #mensagem de finalização do código
