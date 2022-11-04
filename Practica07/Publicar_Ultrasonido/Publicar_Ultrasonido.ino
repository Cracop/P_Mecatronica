// Inclusión de librerías para conectar arduino con ROS

#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>

// Pines asociados al ultrasonido
#define echoPin 6
#define trigPin 7

// variables para tiempo y distancia en cms 
long duration;
float distance;

// Nodo que será publicado en ROS
ros::NodeHandle nh;

// Mensajes para publicar los rangos de distancia en tiempo real 
sensor_msgs::Range range_msg;
ros::Publisher pub_range("Ultrasonic_range", &range_msg); // Con este elemento publicamos la información a ROS 
char frameid[] = "/ultrasound"; // Contenido tipo char para imprimir ultrasound 

void setup(){
  pinMode(trigPin, OUTPUT); // Activamos pin trig como salida 
  pinMode(echoPin, INPUT); // Activamos pin echo como entrada
  
  nh.initNode(); // Iniciamos la comunicacion con el nodo publicado en ROS
  nh.advertise(pub_range); // Establecemos el medio de comunicación y lo que se hará
  
  // Valores iniciales de los rangos
  range_msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
  range_msg.header.frame_id = frameid;
  range_msg.field_of_view = 0.1;
  range_msg.min_range = 0.02;
  range_msg.max_range = 3.0;

}
void loop(){
  range_msg.range = getRange(); // medimos la distancia presente en tiempo rela 
  range_msg.header.stamp = nh.now(); // pasamos la información al nodo nh que es el respectivo de ROS. 
  pub_range.publish(&range_msg); // publicamos el rango medido
  nh.spinOnce(); // Cicla lo que se está ejecutando, es decir, mantiene la conexion 
  delay(100); // Retardo de .1 segundos 
}

// Método para obtener la distancia presente
float getRange(){
  digitalWrite(trigPin, LOW); // preparamos el trig
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Lanzamos el trig en un tiempo minimo de 0.01 segundos
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // aoagamos el trig
  
  duration = pulseIn(echoPin, HIGH); // con el echo medimos el tiempo que tardó en volver el trig una vez que fue lanzado 
  distance = duration * 0.000343/2; // calculo de distancia 
  
  return distance; // la función regresa la distancia 
}
