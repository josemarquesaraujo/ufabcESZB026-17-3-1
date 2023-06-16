#!/usr/bin/python3

import sys
from time import sleep

SYSFS_DIR = "/sys/class/gpio/"

LED_NUMBER_VERMELHO = "20"
LED_NUMBER_VERDE = "21"
LED_NUMBER_AMARELO = "16"

LED_PATH_VERMELHO = "/sys/class/gpio/gpio" + LED_NUMBER_VERMELHO + "/"
LED_PATH_VERDE = "/sys/class/gpio/gpio" + LED_NUMBER_VERDE + "/"
LED_PATH_AMARELO = "/sys/class/gpio/gpio" + LED_NUMBER_AMARELO + "/"

def writeLED(filename, value, path):
    fo = open(path + filename, "w")
    fo.write(value)
    fo.close()

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
