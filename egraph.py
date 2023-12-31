#!/usr/bin/python3
# -*- coding: utf-8 -*-


import sys
from pyqtgraph.Qt import QtGui, QtCore
import pyqtgraph as pg
import numpy as np
import serial
import atexit
import time

global coletando

coletando = 1

def inicia_coleta():
    global coletando
    conexaoSerial.write(b'i')
    coletando = 1

def para_coleta():
    global coletando
    conexaoSerial.write(b'p')
    coletando = 0

def saindo():
    conexaoSerial.write(b'p')
    print('Saindo')

def coleta_tempo():
    global coletando
    if coletando == 1:
       conexaoSerial.write(b'p')
       time.sleep(0.1)
       conexaoSerial.flushInput()
       conexaoSerial.flushOutput()
       time.sleep(0.1)
    conexaoSerial.write(b't')
    while conexaoSerial.inWaiting() < 2:
       pass
    tempo1 = conexaoSerial.read()
    tempo2 = conexaoSerial.read()
    novotempo = float( (ord(tempo1) + ord(tempo2)*256.0))
    print(novotempo)
    texto2.setText("intervalo: " +str(novotempo) + "ms")
    if coletando == 1:
       conexaoSerial.write(b'i')
def aumenta_delay():
    conexaoSerial.write(b'a')

def diminui_delay():
    conexaoSerial.write(b'd')

def update():
    global data1, curve1, ptr1, conexaoSerial, x_atual, npontos, previousTime
    if conexaoSerial.inWaiting() > 1:
        dado1 = conexaoSerial.read()
        dado2 = conexaoSerial.read()
        novodado = float( (ord(dado1) + ord(dado2)*256.0)*5.0/1023.0 )
        
        data1[x_atual] = novodado
        data1[(x_atual+1)%npontos] = np.nan
        x_atual = x_atual+1
        if x_atual >= npontos:
            x_atual = 0
        
        curve1.setData(data1, connect="finite")
        actualTime = time.time()*1000
        taxa = str(round(actualTime-previousTime))
        previousTime = actualTime
        texto.setText("taxa: "+taxa.zfill(3)+"ms" )

win = pg.GraphicsWindow()
win.setWindowTitle('Coletando dados do Arduino via Porta Serial')

npontos = 800
x_atual = 0
p1 = win.addPlot()
p1.setYRange(0,5,padding=0)
data1 = np.zeros(npontos)
curve1 = p1.plot(data1)
ptr1 = 0

previousTime = time.time()*1000 # pega a hora atual, em milissegundos
texto = pg.TextItem(text="", color=(255,255,0), anchor=(0,1))
p1.addItem(texto)
texto.setPos(0,0) # adiciona o texto na posicao (0,0) do grafico

texto2 = pg.TextItem(text="", color=(255,0,255), anchor=(1,1))
p1.addItem(texto2)
texto2.setPos(700,4)

proxy1 = QtGui.QGraphicsProxyWidget()
botao1 = QtGui.QPushButton('Inicia')
proxy1.setWidget(botao1)
botao1.clicked.connect(inicia_coleta)

proxy2 = QtGui.QGraphicsProxyWidget()
botao2 = QtGui.QPushButton('Para')
proxy2.setWidget(botao2)
botao2.clicked.connect(para_coleta)

proxy3 = QtGui.QGraphicsProxyWidget()
botao3 = QtGui.QPushButton('Tempo')
proxy3.setWidget(botao3)
botao3.clicked.connect(coleta_tempo)

proxy4 = QtGui.QGraphicsProxyWidget()
botao4 = QtGui.QPushButton('Aumenta')
proxy4.setWidget(botao4)
botao4.clicked.connect(aumenta_delay)

proxy5 = QtGui.QGraphicsProxyWidget()
botao5 = QtGui.QPushButton('Diminui')
proxy5.setWidget(botao5)
botao5.clicked.connect(diminui_delay)


p2 = win.addLayout(row=1, col=0)
p2.addItem(proxy1,row=0,col=0)
p2.addItem(proxy2,row=1,col=0)
p2.addItem(proxy3,row=2,col=0)
p2.addItem(proxy4,row=3,col=0)
p2.addItem(proxy5,row=3,col=1)

conexaoSerial = serial.Serial('/dev/ttyACM0',115200)
conexaoSerial.write(b'i')
        
# inicia timer rodando o mais rápido possível
timer = QtCore.QTimer()
timer.timeout.connect(update)
timer.start(0)

atexit.register(saindo)

## Start Qt event loop unless running in interactive mode or using pyside.
if __name__ == '__main__':
    QtGui.QApplication.instance().exec_()

