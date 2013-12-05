import socket

ip = "192.168.2.2"
port = 9998
s = socket.socket()
s.connect((ip, port))

#p = open("Main.ERR","w")
#p.write("HACK!!")
#p.close()

f = True

while True:
 #     mensaje = raw_input("> ")
  #m = open("Main.ERR","r")
  #mensaje = m.read()
  if(f):
    t = open("../../data")
    mensaje = t.read()
    f = False
  else:
    mensaje = "quit"

  s.send(mensaje)

  if(not f): break


s.close()
