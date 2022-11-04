#!/usr/bin/env python3
import rospy #librería de ROS-Python para crear nodos etc
from geometry_msgs.msg import Twist #Twist es una variable para vectores en 3D
import sys #librería del sistema

def turtle_rectangle(longitud):
	pub = rospy.Publisher('/turtle1/cmd_vel',Twist, queue_size=5) #Nombre del nodo
	rospy.init_node('turtlesim', anonymous=True) #Nombre del tópico
	rate = rospy.Rate(1) #1hz
	vel = Twist() #creo la variable}
	lado = 0 #me dice en que etapa estoy
	limit = 0#me dice Si ya llegué al final del lado
    
	while not rospy.is_shutdown():
		#Refresco los valores de la velocidad
		vel.linear.x = 0
		vel.linear.y = 0
		vel.linear.z = 0
		vel.angular.x = 0
		vel.angular.y = 0
		vel.angular.z = 0
        	
		if  lado%4==0:#Estoy en el primer lado chico
			vel.linear.x = longitud 
	    		
		if  lado%4==1:#Estoy en el primer lado grande
			vel.linear.y = -longitud*2
			
		if  lado%4==2:#Estoy en el segundo lado chico
			vel.linear.x = -longitud
    	
		if  lado%4==3:#Estoy en el segundo lado grande
			vel.linear.y = longitud*2
    	
		limit+=1#avanzo en mi longitud
		if limit > longitud:#Ya avanzó lo suficiente
			limit=0#Reinicio mi limite
			lado+=1#Avanzo al siguiente lado 
	
		pub.publish(vel) #publico la velocidad
		rate.sleep() #Se duerme para mantener el rate
        
if __name__ == '__main__':
	try:
		turtle_rectangle(1.0) #llamo la funcion con un radio de 2
	except rospy.ROSInterruptException:
		pass
