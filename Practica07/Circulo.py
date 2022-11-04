#!/usr/bin/env python3
import rospy #librería de ROS-Python para crear nodos etc
from geometry_msgs.msg import Twist #Twist es una variable para vectores en 3D
import sys #librería del sistema

def turtle_circle(radius):
    pub = rospy.Publisher('/turtle1/cmd_vel',Twist, queue_size=5) #Nombre del nodo
    rospy.init_node('turtlesim', anonymous=True) #Nombre del tópico
    rate = rospy.Rate(1) #1hz
    vel = Twist() #creo la variable
    
    while not rospy.is_shutdown():
        vel.linear.x = radius #La distancia del centro
        vel.angular.z = 1 #velocidad para que vaya girando
        pub.publish(vel) #publico la velocidad
        rate.sleep() #Se duerme para mantener el rate
        
if __name__ == '__main__':
    try:
        turtle_circle(3.0) #llamo la funcion con un radio de 2
    except rospy.ROSInterruptException:
        pass
