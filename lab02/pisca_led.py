#!/usr/bin/env python3


import sys #necessário para obter acesso aos argumentos da linha de comando.
from time import sleep #sleep insere atrasos no código, será usada para manter os leds acesos pelos tempos solicitados.

SYSFS_DIR = "/sys/class/gpio/" #diretório onde estão armazenados os arquivos de controle da GPIO.

LED_PATH_AMARELO = "/sys/class/gpio/gpio16/" #caminho para o diretório da GPIO 16
LED_PATH_VERMELHO = "/sys/class/gpio/gpio20/" #caminho para o diretório da GPIO 20
LED_PATH_VERDE = "/sys/class/gpio/gpio21/" #caminho para o diretório da GPIO 21

LED_NUMBER_AMARELO = "16" #número do pino da GPIO
LED_NUMBER_VERMELHO = "20" #número do pino da GPIO
LED_NUMBER_VERDE = "21" #número do pino da GPIO

#função responsável pela escrita em arquivos sysfs para controlar os leds.
def writeLED(filename, value, path):
    fo = open(path + filename, "w")
    fo.write(value)
    fo.close()

#o seguinte loop irá ativar os leds em ordem ao se escrever o número do pino GPIO no arquivo export, 
#após isso será aguardado 0,1 segundo, o arquivo direction será configurado como saída, o valor do led passará a 1, 
#acesso, será aguardado o tempo necessário de acordo com a cor do led, vermelho 2 segundos, verde e amarelo 1 segundo 
#cada, após isso o valor do led passará a 0, apagado, e o pino GPIO será desativado por meio do comando unexport. O loop 
#se repetirá 5 vezes e o programa será finalizado.

for cont in range(5):
    writeLED(filename="export", value=LED_NUMBER_VERMELHO, path=SYSFS_DIR)
    sleep(0.1)
    writeLED(filename="direction", value="out", path=LED_PATH_VERMELHO)
    writeLED(filename='value', value='1', path=LED_PATH_VERMELHO)
    sleep(2)
    writeLED(filename='value', value='0', path=LED_PATH_VERMELHO)
    writeLED(filename="unexport", value=LED_NUMBER_VERMELHO, path=SYSFS_DIR)

    writeLED(filename="export", value=LED_NUMBER_VERDE, path=SYSFS_DIR)
    sleep(0.1)
    writeLED(filename="direction", value="out", path=LED_PATH_VERDE)
    writeLED(filename='value', value='1', path=LED_PATH_VERDE)
    sleep(1)
    writeLED(filename='value', value='0', path=LED_PATH_VERDE)
    writeLED(filename="unexport", value=LED_NUMBER_VERDE, path=SYSFS_DIR)

    writeLED(filename="export", value=LED_NUMBER_AMARELO, path=SYSFS_DIR)
    sleep(0.1)
    writeLED(filename="direction", value="out", path=LED_PATH_AMARELO)
    writeLED(filename='value', value='1', path=LED_PATH_AMARELO)
    sleep(1)
    writeLED(filename='value', value='0', path=LED_PATH_AMARELO)
    writeLED(filename="unexport", value=LED_NUMBER_AMARELO, path=SYSFS_DIR)

print("Fim do script Python.")
