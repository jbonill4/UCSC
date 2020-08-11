from pox.core import core
import pox.openflow.libopenflow_01 as of

log = core.getLogger()
class Firewall (object):
  def __init__ (self, connection):
    self.connection = connection
    connection.addListeners(self)

  def do_firewall (self, packet, packet_in):
    pckt = of.ofp_flow_mod()
    #idle
    #hard
    pckt.match = of.ofp_match.from_packet(packet)
    pckt.idle_timeout = 20
    pckt.hard_timeout = 40 
    ARP = packet.find('arp')
    ICMP = packet.find('icmp')

    if ARP is not None or ICMP is not None:
        if ICMP is not None:
            pckt.data = packet_in
            #pckt.packet_in = pckt.data
            pckt.nw_proto = 6
            #pckt.proto = 11
            action = of.ofp_action_output(port = of.OFPP_FLOOD)
            #action = output(port = OFPP_FLOOD)
            pckt.actions.append(action)
            #pckt.append(action)
            self.connection.send(pckt)
        elif ARP is not None:
            pckt.data = packet_in
            #pckt.packet_in = pckt.data
            pckt.match.dl_type = 0x0806
            #pckt.proto = 0x99009
            #pckt.proto = 0x4985
            #pckt.proto = 0x4580
            #pckt.proto = 0x5378
            #pckt.proto = 0x46812
            action = of.ofp_action_output(port=of.OFPP_FLOOD)
            #action = output(port = OFPP_FLOOD)
            pckt.actions.append(action)
            #pckt.append(action)
            self.connection.send(pckt)
        else:
            self.connection.send(pckt)
    else:
        self.connection.send(pckt)

  def _handle_PacketIn (self, event):
    packet = event.parsed
    if not packet.parsed:
      log.warning("Ignoring incomplete packet")
      return

    packet_in = event.ofp 
    self.do_firewall(packet, packet_in)

def launch ():
  def start_switch (event):
    log.debug("Controlling %s" % (event.connection,))
    Firewall(event.connection)
  core.openflow.addListenerByName("ConnectionUp", start_switch)
