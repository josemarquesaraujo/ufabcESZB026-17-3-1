#!/bin/bash

GPIO_AMARELO=16
GPIO_VERMELHO=20
GPIO_VERDE=21

if [ $# -ne 1 ]; then
    echo "Nenhum comando passado. Uso: ./LED.sh command,"
    echo "onde comando pode ser: on"
    echo "ex.: ./LED.sh on"
    exit 2
fi

if [ "$1" == "on" ]; then
    for cont in 1 2 3 4 5; do
        echo "Habilitando a GPIO número $GPIO_VERMELHO"
        echo $GPIO_VERMELHO > "/sys/class/gpio/export"
        sleep 1
        echo "out" > "/sys/class/gpio/gpio$GPIO_VERMELHO/direction"
        echo 1 > "/sys/class/gpio/gpio$GPIO_VERMELHO/value"
        sleep 2
        echo 0 > "/sys/class/gpio/gpio$GPIO_VERMELHO/value"

        echo "Habilitando a GPIO número $GPIO_VERDE"
        echo $GPIO_VERDE > "/sys/class/gpio/export"
        sleep 1
        echo "out" > "/sys/class/gpio/gpio$GPIO_VERDE/direction"
        echo 1 > "/sys/class/gpio/gpio$GPIO_VERDE/value"
        sleep 1
        echo 0 > "/sys/class/gpio/gpio$GPIO_VERDE/value"

        echo "Habilitando a GPIO número $GPIO_AMARELO"
        echo $GPIO_AMARELO > "/sys/class/gpio/export"
        sleep 1
        echo "out" > "/sys/class/gpio/gpio$GPIO_AMARELO/direction"
        echo 1 > "/sys/class/gpio/gpio$GPIO_AMARELO/value"
        sleep 1
        echo 0 > "/sys/class/gpio/gpio$GPIO_AMARELO/value"
    done
fi

echo "Fim"
