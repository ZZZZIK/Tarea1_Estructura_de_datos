Monserrath Morales
Alonso Maurel


- Documentacion del programa:
El programa cuenta con:
1. Un archivo main que contiene la estructura que se ocupara en nuestro programa y las funciones principales del programa.
2. Un archivo list que contiene las funciones y la estructuras de las estructuras de datos empleadas en el programa.
3. Un archivo list que contiene las funciones y las estructuras de las estructuras, pero con sus respectivas definiciones y cuerpo (contenido de la funcion).
4. un archivo csv creado por nosotros para la importacion de un archivo.

---------------- Implementacion detallada del archivo main: ----------------

La estructura utilizada para este programa será la siguiente, una lista enlazada doble (no circular) que almacenará los datos de un libro además de una lista enlazada doble que contiene los nombres de los estudiantes que reservan los libros (almacenados y eliminados en orden de cola):

typedef struct{
  char titulo[30];
  char autor[30];
  char genero[30];
  int ISBN;
  char ubicacion[10];
  char estadoLibro[30];
  List* nombresReservas;
  int cant_reservas;
} Libro;

Funcion void obtenerEntrada(char *, int):
Esta función obtiene una linea de texto que el usuario ingresa por teclado y la almacena en una variable tipo char, en este caso concreto llamada cadena, ademas la funcion solicita saber el tamaño maximo del arreglo para evitar que la memoria se desborde.Posteriormente se encarga de revisar en caso si hay algún salto de línea al final de la palabra para que sea reemplazado por un carácter nulo.
El objetivo real de esta función fue evitar errores al comparar entradas con elementos almacenados, ya que anteriormente cuando utilizábamos el scanf teníamos problemas al usar strcmp() y decidimos diseñar esta funcion para ello.

Funcion void registrarLibro(List *):
Esta función permite registrar un nuevo libro en una lista de libros. El usuario proporciona información como el título, autor, género, ISBN y ubicación del libro. Luego, la función crea una estructura de libro con estos datos y la agrega a la lista de libros. El libro se inicializa con estado "Disponible" y una lista vacía de nombres de reservas.

Funcion mostrar_unLibro(List *):
Esta función solicita al usuario que introduzca el título y el autor del libro que desea encontrar, luego recorre la lista de libros y compara los valores ingresados con los registros en la lista. Si encuentra una coincidencia, muestra el título, autor, género, ISBN, ubicación y estado. Si no se encuentra ninguna coincidencia, imprime que el libro no se encuentra en el registro.

Funcion void mostrar_todosLosLibros(List *):
Esta función permite mostrar todos los libros almacenados en una lista de libros. Itera a través de la lista y para cada libro, imprime información detallada, incluyendo el título, autor, género, ISBN, ubicación y estado del libro. Luego, avanza al siguiente libro en la lista y repite el proceso hasta que todos los libros se han mostrado. 

Funcion void reservarLibro(List *):
Esta función permite reservar un libro en una lista de libros. El usuario proporciona el título, autor y su nombre para la reserva. Luego, la función busca el libro correspondiente en la lista de libros (nodos). Si encuentra un libro con el mismo título y autor, y si ese libro está disponible (no reservado previamente), registra la reserva con el nombre del usuario y cambia el estado del libro a "Reservado". Si no encuentra el libro o ya está reservado, muestra un mensaje apropiado.

void cancelarReserva(List *):
Esta función permite cancelar la reserva de un libro en una lista de libros. El usuario proporciona el título, autor y su nombre para la reserva. La función busca el libro correspondiente en la lista de libros. Si encuentra un libro con el mismo título y autor, y si ese libro está en estado "Reservado", cambia el estado del libro a "Disponible" y elimina el primer nombre de la lista de personas que realizaron reservas para ese libro. Luego, muestra un mensaje de confirmación. Si el libro no está reservado o no se encuentra en los registros, muestra un mensaje apropiado.

Funcion void retirarLibro(List *, List *):
Esta función permite retirar un libro de una lista de libros y registrarlo como prestado en otra lista de libros prestados. El usuario proporciona el título, autor y su nombre. La función busca el libro correspondiente en la lista de libros. Si encuentra un libro con el mismo título y autor, y si ese libro está disponible, lo registra como prestado en la lista de libros prestados y cambia su estado a "Prestado". Si el libro no está disponible, muestra un mensaje indicando que no se puede retirar. Si no encuentra el libro en los registros, muestra un mensaje indicando que no coincide con los registros.

Funcion void devolverLibro(List *, List *):
Esta función permite registrar la devolución de un libro prestado en una lista de libros prestados. El usuario proporciona el título, autor y su nombre. La función busca el libro correspondiente en la lista de libros. Si encuentra un libro con el mismo título y autor, y si ese libro está en estado "Prestado", lo marca como "Disponible" y lo elimina de la lista de libros prestados. Luego, muestra un mensaje de confirmación. Si el libro no está prestado o no se encuentra en los registros, muestra un mensaje apropiado.

Funcion const char *get_csv_field(char *tmp, int k):
Esta función permite extraer el k-ésimo campo de un string que contiene datos separados por comas. Recorre el string, identifica los campos delimitados por comas y devuelve el campo correspondiente al valor de k. Si el campo no existe, devuelve NULL. La función maneja correctamente campos que están entre comillas dobles (puede haber comas dentro de estos campos sin considerarlas como delimitadores).

Funcion List *importarDatos()
Esta función permite importar datos de un archivo y almacenarlos en una lista de libros. El usuario proporciona el nombre del archivo a importar. La función abre el archivo, lee sus líneas, interpreta los campos CSV (título, autor, género, ISBN y ubicación) y crea estructuras de libro con esos datos. Luego, agrega estos libros a una lista y los devuelve como resultado. Cada libro se inicializa con estado de libro vacío y una lista de nombres de reservas vacía.

Funcion void Exportar_datos_libros(List* ):
Esta función permite exportar los datos de libros almacenados en una lista a un archivo CSV. El usuario proporciona el nombre del archivo que desea crear. La función abre el archivo en modo de escritura y, si tiene éxito, escribe una línea de encabezado con los nombres de las columnas de datos ("Titulo, Autor, Genero, ISBN, Ubicacion, Estado del Libro, Cantidad de Reservas"). Luego, itera a través de la lista de libros y escribe cada libro como una línea de datos CSV en el archivo. Finalmente, cierra el archivo y muestra un mensaje de confirmación.


---------------------------------------------------------------------------------
- Fallos en el programa:
Los fallos presentados son principalmente la imposibilidad del programa para ingresar al archivo "list.h" a pesar de haberlo incluido en el main y en el archivo donde se encuentra la definicion y cuerpo de cada funcion y estructura (list.c), no reconoce las estructuras. Creemos que esto se debe a la plataforma en la que se trabajó el trabajo (replit) o la falta de algun comando extra para el poner a correr los demas archivos a la par de list.h, puesto que al agregar la estructuracion del Nodo y la Lista en el archivo "list.h" (para generar un enlace mas directo), el programa comenzó a funcionar de manera optima reconociendo todo.
Nuestro segundo error principal se dio al trabajar las funciones para importar y exportar archivos en nuestro codigo. A pesar de haber buscado posibles soluciones a esto, el error persistía y no tenemos el conocimiento completo de cómo importar y exportar datos en codigos, pues aun no nos hemos formado en ese ambito de la programacion en nuestra formacion universitaria.
El tercer problema importante de destacar, es que el archivo .csv que se nos entrego para trabajar la importacion de un archivo al programa, no coincidia con los elementos presentes la estructura solicitadas en las instrucciones de la tarea. Por lo que creamos nuestro propio archivo de libros.csv.

----------------------------------------------------------------------------------
- Instrucciones de ejecución:
Para ejecutar el codigo se creó un menú de opciones que segun lo que desee hacer el usuario, se ejecutarán diferentes operaciones y sus llamados a funciones. No es necesario descargar ningun archivo externo ya que viene uno de ejemplo ya implementado (libros.csv), a menos que el usuario desee importar sus propios archivos .csv para la opcion 9.

----------------------------------------------------------------------------------
Contribución Individual: 
- Evaluación de aporte individual en el código (evaluación individual).

Monserrath Morales:

Creacion y definicion de las siguientes funciones:
- void obtenerEntrada(char *cadena, int tallaMax)
- void registrarLibro(List *lst_libros)
- void reservarLibro(List *lst_libros)
- void retirarLibro(List * lst_libros, List * lst_prestados)
- List *importarDatos()

Definicion y argumentacion de la documentacion del programa, los fallos en el programa y las instrucciones de ejecucion.

Alonso Maurel: 

Creacion y definicion de las siguientes funciones:
- void mostrar_unLibro(List* lst_libros) {
- void cancelarReserva(List* lst_libros){
- void devolverLibro(List * lst_libros, List * lst_prestados){
- void Exportar_datos_libros(List* lista) {
- void mostrar_todosLosLibros(List* lista) {

Contribuciones en conjunto:
- Organizacion para el desarrollo del programa.
- Complementacion de lógica para desarrollar algunas funciones.
- Correccion de errores que aparecian a medida que se avanzaba en el codigo.
- funcion main().
- Creacion del archivo: libros.csv
- Diseño de la presentacion del menu y las opciones con el fin de hacerlo menos confuso y más llamativo.
- Diseño de el codigo visual para mejor entendimiento.
- Explicacion de las funciones main.