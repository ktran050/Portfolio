# CS164 lab6
from mininet.topo import Topo
from mininet.net import Mininet
from mininet.util import dumpNodeConnections
from mininet.log import setLogLevel
#from mininet.node import Host, OVSSwitch, Controller
#from mininet.link import Link


 #h1 = Host( 'h1' )
 #h2 = Host( 'h2' )
 #h3 = Host( 'h3' )
 #h4 = Host( 'h4' )
 #s1 = OVSSwitch( 's1', inNamespace = False )
 #c0 = Controller( 'c0', inNamespace = False )
 #Link( h1, s1 )
 #Link( h2, s1 )
 #Link( h3, s1 )
 #Link( h4, s1 )
 #h1.setIP = ( '10.0.0.1/24' )
 #h2.setIP = ( '10.0.0.2/24' )
 #h3.setIP = ( '10.0.0.3/24' )
 #h4.setIP = ( '10.0.0.4/24' )
 #c0.start()
 #s1.start( [c0] )
 #print h1.IP
  ##print b2.IP
  ##print b3.IP
  ##print b4.IP
 ##print h1.cmd( 'ping -c3', h2.IP() )
 #s1.stop()
 #c0.stop()

class lab9topo( Topo ):
     "Simple topology example."
     def __init__( self ):
       "Create custom topo."
       #Initialize topology
       Topo.__init__( self )
       # Add hosts and switches
       b1 = self.addHost( 'b1' )
       b2 = self.addHost( 'b2' )
       b3 = self.addHost( 'b3' )
       b4 = self.addHost( 'b4' )
       mainSwitch = self.addSwitch( 's1' )
       # Add links
       self.addLink( b1, mainSwitch )
       self.addLink( b2, mainSwitch )
       self.addLink( b3, mainSwitch )
       self.addLink( b4, mainSwitch )
       print

def runExperiment():
   topo = lab9topo( )
   net = Mininet(topo)
   net.start()
   print "Dumping host connections"
   dumpNodeConnections(net.hosts)
   print "Testing network connectivity"
   net.pingAll()
   net.stop()
 
if __name__ == '__main__':
  setLogLevel('info')
  runExperiment() 
