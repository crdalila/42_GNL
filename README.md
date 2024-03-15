# 42_GNL
Proyecto para leer un file descriptor línea a línea

## ¿Qué nos piden?

+ Una **función que lea una línea de un fd**, de forma que llamarla de manera repetida (por ejemplo, usando un bucle) permita leer el contenido del archivo hacia el que apunta el fd, línea a línea hasta el final.
+ Si no hay nada más que leer o si ha ocurrido un error, que devuelta NULL.
+ Asegurarnos de que se comporta adecuadamente cuando lea de un archivo y cuando lea de stdin.


## Archivos

+ **test1, test2, test3, test4, test_ok**: distintos test realizados ANTES de ponerme con el proyecto en sí, para comprender la lógica de abrir, leer e imprimir archivos.
+ **el_x_venir.txt**: texto de ejemplo
+ **get_next_line.c**: función principal del programa, dentro tenemos tres funciones:
    + read_document -> para leer el contenido del fd
    + prepare_line -> para preparar las líneas (teniendo en cuenta cuándo tenemos salto de línea)
    + get_next_line -> función principal
+ **get_next_line.h**: librería en la que añadimos el macro de BUFFER_SIZE y las funciones
+ **get_next_line_utils.c**: archivo que contiene funciones que necesitamos de la libc, en mi caso he necesitado:
    + ft_strlen -> para medir la longitud de un string
    + ft_strjoin -> para cocatenar dos strings
    + ft_strchr -> para buscar el salto de línea en un string
    + ft_memcpy -> para copiar un bloque de memoria de un origen a un destino n bytes
+ **get_next_line_bonus.c**: función principal del programa, solo que añadidos los elementos para el bonus
+ **get_next_line_bonus.h**: librería en la que añadimos el macro de BUFFER_SIZE, el macro FD_OPEN y las funciones
+ **get_next_line_utils_bonus.c**: archivo que contiene funciones que necesitamos de la libc, igual que sin el bonus


