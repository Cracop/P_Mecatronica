#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
def talker():
  pub = rospy.Publisher('chatter', String, queue_size=10)#Nombre tópico
  rospy.init_node('talker', anonymous=True) #Nombre del nodo
  rate = rospy.Rate(1) # 1hz

  i = 0
  while not rospy.is_shutdown():
    hello_str = "hello world %s" % i
    rospy.loginfo(hello_str)
    pub.publish(hello_str)
    rate.sleep()
    i=i+1
    
if __name__ == '__main__':
  try:
    talker()
  except rospy.ROSInterruptException:
   pass
