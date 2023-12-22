# Laboratorio Nº4 de Transmisión de Datos

## 📚 Enunciado

Como parte de su trabajo le solicitan la fabricación de una botonera con interfaz USB que debe emular un teclado, utilizando los botones de la CIAA(4 teclas) y reproduciendo los caracteres “q”, “w”, “e”, “r”.  

En este laboratorio usted configurará el puerto USB-OTG. (On The Go)  

### Funcionamiento

Cada paquete enviado entre el Host y el Device tiene los campos:  

● Addr: el host le asigna una dirección para identificar el dispositivo dentro del bus (se pueden conectar hasta 127 dispositivos).  
● Endpoint: fuente o sumidero de datos. Puede haber hasta 16 endpoints por dispositivo.  
● Dirección: se lo mira desde el Host (IN si el paquete ingresa al host y OUT si va hacia el dispositivo).  

Usaremos el USB como HID (dispositivo de interfaz humana). Una de las características de estos dispositivos es la transferencia de paquetes por interrupción.  

### Actividades

Usando como guía el ejemplo del mouse:  

1. Generar el descriptor de reportes, ubicado en el archivo “hid_desc.c”. El mismo debe responder a los parámetros de un teclado, recuerde consultar los documentos adjuntos para ver la estructura de los descriptores y compararlo con el del ejemplo. (“descriptores.pdf” y “usbd_hid.h”)  

2. Generar un descriptor de string apropiado, utilizando una combinación de su nombre y apellido como número de serie del teclado (que no supere los 20 caracteres). Esto también lo realiza en el archivo “hid_desc.c”.  

3. Dentro del archivo “hid_keyboard.c”, completar las implementaciones de las rutinas de atención de interrupciones de las 4 teclas, (utilizando la variable “presionadas”) y de la función “Keyboard_UpdateReport”. La misma debe emular las teclas “q, w, e, r” mapeando las teclas 1, 2, 3 y 4. (Consultar el codigo de teclas en el archivo “hut1_21.pdf” )  

## Construidos con 🛠️

* [VisualStudioCode](https://code.visualstudio.com/) - Editor de código fuente
* [GNU Make](https://www.gnu.org/software/make/) - Herramienta de gestión de dependencias
* [GCC](https://gcc.gnu.org/) - Compilador de C para Linux (Ubuntu)

## 👨‍💻 Autor

- Grellet, Alejandro
- Medina Raed, Luis Eugenio
- Padros, Marcos Isaias
- Vaca Paz, Diego Isaias