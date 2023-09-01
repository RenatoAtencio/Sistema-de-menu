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
    La opcion 5 verifica que el archivo este creado, si este no es el caso lo crea.
    La opcion 6 tambien verifica que el archivo este creado pero si no es el caso solamente lo indicara.

# Para compilar usar 'make' en la consola

# Para ejecutar usar ./PrimerTrabajoClases -u user -v vector de numeros -f path -t texto
    El user es el nombre del usuario que se quiere usar, la aplicacion es case sensitive asi que juan != Juan. Ej: Kylian
    El vector de numeros es un string de numeros separados por ','. Ej: 1,4,5,1,23,14,441
    El path es la direccion de una carpeta mas el nombre de un archivo. Ej: /home/user/escritorio/nombre.txt
    El texto es un string. Ej: Hola

# La base de datos guarda los usuarios y sus respectivos permisos.
    En el formato User1,permiso1,permiso2,...,permiso4;User2,permiso1,permiso2,...,permiso4;User3,... Todo en la misma linea de texto (es decir sin saltos de linea).