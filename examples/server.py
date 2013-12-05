import socket

ip = "192.168.2.2"
port = 9998
s = socket.socket()
s.bind((ip, port))
s.listen(1)

sc, addr = s.accept()

f = open("output","w")

while True:
      recibido = sc.recv(1024)
      if recibido == "quit":
         break      
      #print "Recibido:", recibido
      f.write(recibido)
      sc.send(recibido)

sc.close()
s.close()
