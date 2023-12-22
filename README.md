# Laboratorio Nº2 de Transmisión de Datos

## 📚 Enunciado

Se deberá implementar el siguiente caso:  

Se le encarga realizar el desarrollo de un sistema que asista en el control de turnos dentro de un establecimiento. Se deberá mostrar por pantalla el turno actual y se podrá contar desde “00” hasta “99”.  
Se desea utilizar un smartphone para controlar el avance, retroceso y reinicio del número
de turnos.  
Como pantalla donde mostrar los turnos se utilizará la terminal del gtkterm. Por lo tanto el celular se comunicará con el módulo bluetooth y éste con la EDU-CIAA a través de la USART3. Luego la EDU-CIAA se comunicará a la pc a través del USART2.  

### Actividades

1. Completar la función “ConfigurarUART” teniendo en cuenta que la velocidad será de 38.400bps, que el PCLOCK tiene una frecuencia de 204MHz y que se utilizan 8
bits de tamaño de palabra, 1 bit de stop y no se utiliza paridad. Utilizarla para configurar la USART2 y la USART3.   
2. Completar la función “ConfigurarMODEM” que sirve para configurar, utilizando códigos AT, el HC-05 al iniciar el programa. Se deben configurar las siguientes opciones:  
a. Nombre del dispositivo  
b. Contraseña del dispositivo  
c. Cambiar el rol del dispositivo a modo Esclavo  
d. Habilitar el perfil SPP.  
3. Completar la función main implementando la lógica propuesta:  
a. Cuando se reciba un caracter “q”, la cuenta debe aumentar en uno (volviendo a cero cuando llegue a 100).  
b. Cuando se reciba un caracter “w”, la cuenta debe disminuir en uno (volviendo a 99 cuando se llegue a 0).  
c. Cuando se reciba un caracter “e”, la cuenta debe volver a cero.  
4. Ejecutar y configurar GTKTERM para poder comunicarse con la EDU-CIAA.  
5. Conectarse con su smartphone al HC-05  
6. Usando la aplicación “Serial Bluetooth Terminal” enviar mensajes entre su PC y su smartphone.  

## Construidos con 🛠️

* [VisualStudioCode](https://code.visualstudio.com/) - Editor de código fuente
* [GNU Make](https://www.gnu.org/software/make/) - Herramienta de gestión de dependencias
* [GCC](https://gcc.gnu.org/) - Compilador de C para Linux (Ubuntu)

## 👨‍💻 Autor

- Lozano, Iñaki Fernando
- Medina Raed, Luis Eugenio