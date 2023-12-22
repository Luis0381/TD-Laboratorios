# Laboratorio Nº3 de Transmisión de Datos

## 📚 Enunciado

Se deberá implementar el siguiente caso:  

Se le encarga realizar el desarrollo de un sistema que mediante la presión de 3 botones táctiles, permita comandar 3 luces LED de diferentes colores.  
Para realizar esta tarea, debe manejar el CI CAP1203 de la marca MICROCHIP. El mismo deberá comunicarse con la CIAA mediante el bus I2C.  

### Actividades

1. Completar la función “ConfigureKeys” declarando las constantes que la misma necesite. Utilice velocidad Standard.  
2. Realice las lecturas de los registros “Product ID”, “Menufacturer ID” y “Revision” utilizando la función del fabricante NXP “Chip_I2CM_XferBlocking“. La misma utiliza un STRUCT con los siguientes parámetros:  
a. slaveAddr: Dirección del dispositivo esclavo a leer (el CHIP utiliza la dirección 0X28)  
b. txBuff: Buffer con los datos a Transmitir  
c. tsSz: Tamaño del buffer a transmitir  
d. rxBuff: Buffer donde se guardarán los datos recibidos  
e. rxSz: Tamaño del Buffer donde se guardarán los datos recibidos  
Una vez leidos estos valores, envíenos a la PC por el puerto UART como se hizo en el TP2 y visualícelos en el terminal GTKTerm. En la hoja de datos, en la página 20, podra encontrar un listado de todos los registros del chip y su respectiva dirección.  
3. Completar la función “ReadLeys” que sirve para leer si se presionó alguna tecla. Utilice nuevamente la función “Chip_I2CM_XferBlocking“.  
Tenga en cuenta que luego de leer un valor, deberá borrar el Bit INT. De lo contrario, las siguientes lecturas seguirán indicando presión en el botón correspondiente.  

## Construidos con 🛠️

* [VisualStudioCode](https://code.visualstudio.com/) - Editor de código fuente
* [GNU Make](https://www.gnu.org/software/make/) - Herramienta de gestión de dependencias
* [GCC](https://gcc.gnu.org/) - Compilador de C para Linux (Ubuntu)

## 👨‍💻 Autor

- Medina Raed, Luis Eugenio
- Padros, Marcos Isaias
- Vaca Paz, Diego