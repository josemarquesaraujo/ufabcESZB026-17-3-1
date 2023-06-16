#!/usr/bin/python3

# script baseado no código disponibilizado em:
# Derek Molloy , Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux ,
# Wiley 2016 , ISBN 978-1-119-1868-1, http://www. exploringrpi.com/

import sys #importa todo o pacote sys
from time import sleep #do pacote time importa sleep

SYSFS_DIR = "/sys/class/gpio/"

LED_PATH_AMARELO = "/sys/class/gpio/gpio16/" #navega até o subdiretório gpio16.
LED_PATH_VEMELHO = "/sys/class/gpio/gpio20/" #navega até o subdiretório gpio20.
LED_PATH_VERDE = "/sys/class/gpio/gpio21/" #navega até o subdiretório gpio21.


LED_NUMBER_AMARELO = "16" #led amarelo
LED_NUMBER_VERMELHO = "20" #led vermelho
LED_NUMBER_VERDE = "21" #led verde

" Esta funcao escreve o valor 'value ' no arquivo 'path + filename '"
def writeLED( filename , value , path ):
	fo = open( path + filename ,"w")
	fo.write( value )
	fo.close()
	return

for cont in range (5):

	writeLED(filename="export", value=LED_NUMBER_VERMELHO, path=SYSFS_DIR)
	sleep(0.1)
	writeLED (filename="direction", value="out", path=LED_PATH_VERMELHO)
	writeLED (filename = 'value', value = '1', path = LED_PATH_VERMELHO)
	sleep(2)
	writeLED(filename = 'value', value = '0', path = LED_PATH_VERMELHO)
	writeLED(filename="unexport", value=LED_NUMBER_VERMELHO, path=SYSFS_DIR)
	
	writeLED(filename="export", value=LED_NUMBER_VERDE, path=SYSFS_DIR)
	sleep(0.1)
	writeLED (filename="direction", value="out", path=LED_PATH_VERDE)
	writeLED (filename = 'value', value = '1', path = LED_PATH_VERDE)
	sleep(1)
	writeLED(filename = 'value', value = '0', path = LED_PATH_VERDE)
	writeLED(filename="unexport", value=LED_NUMBER_VERDE, path=SYSFS_DIR)

	writeLED(filename="export", value=LED_NUMBER_AMARELO, path=SYSFS_DIR)
	sleep(0.1)
	writeLED (filename="direction", value="out", path=LED_PATH_AMARELO)
	writeLED (filename = 'value', value = '1', path = LED_PATH_AMARELO)
	sleep(1)
	writeLED(filename = 'value', value = '0', path = LED_PATH_AMARELO)
	writeLED(filename="unexport", value=LED_NUMBER_AMARELO, path=SYSFS_DIR)	


print("Fim do script Python.")
