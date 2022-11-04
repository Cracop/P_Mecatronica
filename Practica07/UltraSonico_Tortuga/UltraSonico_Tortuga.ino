// Librerías necesarias para la comunicación con ROS
#include <ros.h>
#include <geometry_msgs/Twist.h>

// Definimos los pines para echo y triger
#define echoPin 7
#define trigPin 6

// Varibles para almacenar el valor de la duración y la distancia 
long duration;
float distance;

// Nodo que se activará para la comunicacón con ROS
ros::NodeHandle nh;

// Objetos geometry_msgs para asignar las velocidades linearles y angulares
geometry_msgs::Twist velCommand;

// Publicamos los comandos de velocidad 
ros::Publisher pub("turtle1/cmd_vel", &velCommand);


void setup(){
  pinMode(trigPin, OUTPUT); // Activamos el triger como salida
  pinMode(echoPin, INPUT); // Activamos el echo como entrada
  
  nh.initNode(); // Nodo de ROS 
  nh.advertise(pub); // Adevierte que iniciará la comunicación con un publisher
  
  // Iniciamos todas las velocidades en 0
  velCommand.linear.x = 0.0;
  velCommand.linear.y = 0.0;
  velCommand.linear.z = 0.0;
  velCommand.angular.x = 0.0;
  velCommand.angular.y = 0.0;
  velCommand.angular.z = 0.0;
}


void loop(){
  Frena(); // Cuando se detecta que hay un objeto con el ultrasónico a menos de 15 cms, entonces se frenan
  pub.publish(&velCommand); // Publicamos todas las velocidades que se tienen
  nh.spinOnce(); // Se mantiene la comunicación 

}

// Método para asignar velocidades diferentes antes y después de 15 cms de distancia detectados
void Frena(){
  // Preparamos el TRIG, mandamos un triger por 10 ms y lo apagamos
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // Medimos el tiempo que duró en viajar y regresar el triger, recibiendolo en el echo
  distance = duration * 0.0343/2; // Distancia obtenida
  // Si la distancia es menor o igual a 15, se detiene el movimiento de la tortuga
  if(distance <= 15){
    velCommand.linear.x = 0.0;
    velCommand.linear.y = 0.0;
    velCommand.linear.z = 0.0;
    velCommand.angular.x = 0.0;
    velCommand.angular.y = 0.0;
    velCommand.angular.z = 0.0;
  }
  // Si la distancia es mayor a 15, la tortuga gira alrededor del eje z, con una velocidad de 2.0 en x.
  else{
    velCommand.linear.x = 2.0;
    velCommand.linear.y = 0.0;
    velCommand.linear.z = 0.0;
    velCommand.angular.x = 0.0;
    velCommand.angular.y = 0.0;
    velCommand.angular.z = 1.0;
  }

}
