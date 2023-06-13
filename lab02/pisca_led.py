#!/ usr / bin / python3
2
3 # script baseado no có digo disponibilizado em:
4 # Derek Molloy , Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux ,
5 # Wiley 2016 , ISBN 978 -1 -119 -1868 -1 , http :// www. exploringrpi . com /
6
7 import sys
8 from time import sleep
9 LED_PATH = "/sys / class / gpio / gpio16 /"
10 SYSFS_DIR = "/ sys / class / gpio /"
11 LED_NUMBER = "16"
12
13 def writeLED ( filename , value , path = LED_PATH ):
14 " Esta funcao escreve o valor 'value ' no arquivo 'path + filename '"
15 fo = open ( path + filename ,"w")
16 fo . write ( value )
17 fo . close ()
18 return
19
20 print (" Iniciando o script Python para alterar a gpio " + LED_NUMBER + ".")
21 if len ( sys . argv ) !=2:
22 print (" Numero incorreto de argumentos ")
23 print (" uso : ./ LED .py comando ")
24 print (" onde comando pode ser : setup , on , off , status , ou close ")
25 sys . exit (2)
26
27 if sys . argv [1]== "on":
28 print (" Acendendo o LED ")
29 writeLED ( filename =" value ", value ="1")
30 elif sys . argv [1]== " off ":
31 print (" Desligando o LED ")
32 writeLED ( filename =" value ", value ="0")
33 elif sys . argv [1]== " setup ":
34 print (" Habilitando a gpio ")
35 writeLED ( filename =" export ", value = LED_NUMBER , path = SYSFS_DIR )
36 sleep (0.1)
37 writeLED ( filename =" direction ", value =" out ")
38 elif sys . argv [1]== " close ":
39 print (" Desabilitando a gpio ")
40 writeLED ( filename =" unexport ", value = LED_NUMBER , path = SYSFS_DIR )
41 elif sys . argv [1]== " status ":
42 print (" Pegando o status da gpio ")
43 fo = open ( LED_PATH + " value ", "r")
44 print ( fo . read () )
45 fo . close ()
46 else :
47 print (" Comando invalido !")
48
49 print (" Fim do script Python .")
