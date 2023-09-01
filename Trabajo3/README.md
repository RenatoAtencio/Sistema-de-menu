## Trabajo sistemas operativos

# La aplicacion toma 6 inputs: user, vector de numeros, path de archivo, texto, path archivo a cargar, path para la salida del conteo.

    primero se verifica que este usuario este en la base de datos (users.txt), de ser el caso muestra un menu con las opciones de la aplicacion, el user puede indicar que opcion quiere tomar, si tiene los permisos entonces hara la accion, sino indicara que no tiene el permiso en especifico.
    Antes de mostrar el menu muestra el nombre del user y su rol, el rol establece que permisos tendra.
    se tienen 7 opciones:
        0) Salir 
        1) Sumar Vector
        2) Promedio del Vector
        3) Moda del Vector
        4) Contar elementos del Vector
        5) Crear archivo txt
        6) Escribir en archivo creado txt
        7) Cargar archivo dado
        8) Contar palabras en el archivo dado
    Cualquier otro seleccion sera indicada como una funcionalidad no implementada.
    La opcion 5 verifica que el archivo este creado, si este no es el caso creara el archivo.
    La opcion 6 tambien verifica que el archivo este creado pero si no es el caso solamente lo indicara , si el archivo existe entonces escribe el input texto en el mismo.
    Opcion 7 carga el archivo del path dado y crea un archivo temporal sin puntuaciones como , ! ? etc, esto para que al usar la opcion 8 sea mas facil.
    Opcion 8 toma el archivo temporal y cuenta las repeticiones por palabra, creando una salida.txt con el formato palabra,cantidad de repeticiones.

    el programa se dividio en 5 archivos.cpp y uno .h:
    main.cpp : Es la columna del codigo y desde el mismo se llaman a las funciones que presentes en el main y en otros archivos.cpp, el main tiene 2 funciones verificarArchivo que devuelve true si un archivo existe y separarTextoFormatoNormal que crea un vector de vectores de inputs con un formato var11,var12,var13;var21,var22,var23;var31,var,32,var33;
    
    funcionesMenu.cpp : contiene funciones relacionadas con el menu de la aplicacion, como mostrarMenu que imprime el menu en la consola y ver seleccion que se encarga de tomar el input del usuario y determinar si se permite la operacion o no, si se permite llama a la operacion si no indica que no se puede hacer la operacion.

    funcionesParaUsuario : contiene funciones que son usadas para los usuarios que no eran exactamentes metodos de usuario, por ejemplo el verificarUsuario que verifica que un usuario existe en la base de datos o crear usuario que hace todos los procesos necesarios para crear un usuario (por ejemplo hacer el parse del vector de numeros, ver que rol es el usuario,etc).

    funcionesParse : funciones principalmente de separacion de string o tranformacion de los mismos a otros tipos de datos, se tiene separarStringPorComaVectorInt que toma un string y devuelve un vector<int>, separarStringPorComaVectorString que hace lo mismo pero devuelve un vector<string> y vectorstoi que pasa un vector<string> a vector<int>.

    Usuario.cpp : es para tener un objeto usuario, tiene principalmente los atributos del usuario (nombre,rol,vector de numeros, vector de permisos) y sus metodos, estos ultimos son todos los permisos que un usuario puede tener (suma,promedio,moda,etc), tiene un metodo de verificacion de permisos usando un atributo vector de permisos en el usuario y metodos para quitar puntuaciones en el texto y una struct que ayuda a contar las palabras.

    funciones.h : donde se declaran las funciones y que luego puede ser llamado a los dintintos archivos.cpp.

# Para compilar usar 'make' en la consola

    make compila todos los archivos.cpp
    tambien se debe usar los siguientes comandos en la consola
        -set o allexport, permite que el comando source funcione correctamente
        source config.env, carga las variables de entorno a usar

# Para ejecutar usar ./main -u user -v vector de numeros -f path para crear archivo -t texto -i path para cargar el archivo a contar -o path de salida del conteo

    -u: El user es el nombre del usuario que se quiere usar, la aplicacion es case sensitive asi que juan != Juan. Ej: Kylian
    -v: El vector de numeros es un string de numeros separados por ','. Ej: 1,4,5,1,23,14,441
    -f El path es la direccion de una carpeta mas el nombre de un archivo. Ej: /home/user/escritorio/nombre.txt, tambien sirve poner solamente el nombre, en este caso crear el archivo en la misma carpeta
    -t El texto es un string. Ej: Hola
    -i path del archivo que se va a cargar y posiblemente del cual se va a hacer el conteo de palabras
    -o path para el archivo de salida del resultado del conteo

    Ejemplo de entrada: ./main -u Kylian -v 3,1,4,5,2,2,3 -f intento4.txt -t hola -i Entrada_Salida/cuento.txt -o Entrada_Salida/salida.txt

# La base de datos guarda los usuarios y sus respectivos permisos.

    se tienen 3 bases de datos y 1 archivo .env
    menu.txt
        base de datos con el menu del programa
        tiene formato proceso,numero del proceso
        ej: sumar,1
    permisos.txt
        tiene los roles y sus respectivos permisos
        ej: admin,1,2,3,4,5,6,7,8;userRookie,1,4;userGeneral,1,2,3,4;
    user.txt
        son los usuarios seguidos por su rol
        ej: Kylian,userGeneral;Pol,admin;
    
    config.env
        contiene las variables de entorno que se van a cargar al usar el source config.env
        las variables estan en mayusculas y los valores son paths principalmente, todo junto.
        ej: DB_USERS=BasesDatos/users.txt
    