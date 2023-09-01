## Trabajo sistemas operativos

# La aplicacion toma 4 inputs: user, vector de numeros, path de archivo y texto.
    primero se verifica que este usuario este en la base de datos (users.txt), de ser el caso muestra un menu con las opciones de la aplicacion, el user puede indicar que opcion quiere tomar, si tiene los permisos entonces hara la accion, sino indicara que no tiene el permiso en especifico.
    se tienen 7 opciones:
        0) Salir 
        1) Sumar Vector
        2) Promedio del Vector
        3) Moda del Vector
        4) Contar elementos del Vector
        5) Crear archivo txt
        6) Escribir en archivo txt
    Cualquier otro seleccion sera indicada como una funcionalidad no implementada.
    La opcion 5 verifica que el archivo este creado, si este no es el caso creara el archivo.
    La opcion 6 tambien verifica que el archivo este creado pero si no es el caso solamente lo indicara , si el archivo existe entonces escribe el input texto en el mismo.

    el programa se dividio en 5 archivos.cpp y uno .h:
    main.cpp : Es la columna del codigo y desde el mismo se llaman a las funciones que presentes en el main y en otros archivos.cpp.
    
    funcionesMenu.cpp : contiene funciones relacionadas con el menu de la aplicacion, como mostrarMenu que imprime el menu en la consola.

    funcionesParaUsuario : contiene funciones que son usadas para los usuarios que no eran exactamentes metodos de usuario, por ejemplo el verificar que un usuario existe en la base de datos.

    funcionesParse : funciones principalmente de separacion de string o tranformacion de los mismos a otros tipos de datos.

    Usuario.cpp : es para tener un objeto usuario, tiene principalmente los atributos del usuario y sus metodos, estos ultimos son todos los permisos que un usuario puede tener (suma,promedio,moda,etc), tambien tiene un metodo de verificacion de permisos usando un atributo vector de permisos en el usuario.

    funciones.h : donde se declaran las funciones y que luego puede ser llamado a los dintintos archivos.cpp.

# Para compilar usar 'make' en la consola
    make compila todos los archivos.cpp

# Para ejecutar usar ./main -u user -v vector de numeros -f path -t texto
    El user es el nombre del usuario que se quiere usar, la aplicacion es case sensitive asi que juan != Juan. Ej: Kylian
    El vector de numeros es un string de numeros separados por ','. Ej: 1,4,5,1,23,14,441
    El path es la direccion de una carpeta mas el nombre de un archivo. Ej: /home/user/escritorio/nombre.txt, tambien sirve poner solamente el nombre, en este caso crear el archivo en la misma carpeta
    El texto es un string. Ej: Hola
    Ejemplo de entrada: ./main -u Kylian -v 1,2,4,1,2,3 -f intento.txt -t hola

# La base de datos guarda los usuarios y sus respectivos permisos.
    En el formato User1,permiso1,permiso2,...,permiso4;User2,permiso1,permiso2,...,permiso4;User3,... Todo en la misma linea de texto (es decir sin saltos de linea).