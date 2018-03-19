import socket, optparse
import threading

# Member variables
IP = "10.0.0.1"
portMACList = [["temp",1,"dp"],
               ["temp",2,"dp"],
               ["temp",2,"dp"]]
    # Entries follow the format string MAC, int PORT, string Status
nodeIpTable = [[1,"10.0.0.1"],
               [2,"10.0.0.2"],
               [3,"10.0.0.3"],
               [4,"10.0.0.4"]]
    # Entries follow: int NodeNum, string IP
portMap = [[1,1,2,3],
           [2,1,3,1],
           [3,1,4,2],
           [4,2,1,3],
           [5,2,3,2],
           [6,2,4,1],
           [7,3,1,1],
           [8,3,2,2],
           [9,3,4,3],
           [10,4,1,2],
           [11,4,2,1],
           [12,4,3,3]]
    # Enries follow: int num, int srcBridge, int destBridge, int destPort

# Member functions
def fetchNodeNum(IP): 	# Given an IP return the corresponding node number
  for x in nodeIpTable:
    if x[1] == IP:
      return x[0]

#def fetchIP(srcIP, targIP, srcPORT)
#  for x in portMap:
#    if fetchNodeNum(IP)==x[1]:
      

# Parser info
parser = optparse.OptionParser()
parser.add_option('-i', dest='ip', default = '127.0.0.1')
parser.add_option('-p', dest='port', type ='int', default = 8000)
parser.add_option('-m', dest = 'msg')
(options, args) = parser.parse_args()

# Socket Setup
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.listen(10)
#s.sendto("TODO", (options.ip, options.port))
cont = []

# Function to send info every few seconds
def set_timer():
  threading.Timer(5.0,set_timer).start()
  print 'Print every 5s'

def clientthread(conn, portNum):
  conn.send('Welcome, hit send to pass data\n')

  while True:
    data = conn.recv(1024)
    reply = 'OK...' + data
    if not data:
      break
  conn.sendall(reply)
  conn.close()

# Main?
#set_timer() 
#while 1:
#  conn,addr = s.accept()
#  cont.append(conn)
#  print 'Connected with '+ addr[0] + ':' + str(addr[1])

#  start_new_thread(clientthread, (conn, portNum,))

s.close()
