#Respuestas carpeta compilador

1. Escriban qué esperan de cada uno de los pasos

* Del primer paso (Pre-procesar) esperamos tener un archivo **.pp.c** en el que se reconozcan
las funciones y el tipo de argumentos requeridos.
* Del segundo paso (Compilacion I) esperamos tener un archivo **.asm** generado a partir
del archivo **.c** del paso 1 en el lenguaje de assembler.
* Del tercer paso (Compilacion II) esperamos tener un archivo **.o** en el que se pasa
del lenguaje assembler a lenguaje de maquina (binario).
Del cuarto paso (Linkeo) esperamos tener un archivo **.e** en el que el objeto se convierte
en un ejecutable.

2. ¿Qué agregó el preprocesador?

Agrego el archivo **calculator.pp.c**

3. Identificar en la rutina de assembler las funciones

En el archivo **calculator.asm** identificamos las funciones a partir del string *call*:
```
        call    add_numbers
        mov     DWORD PTR [rbp-4], eax
        mov     eax, DWORD PTR [rbp-4]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        mov     eax, 0
```

4. Explicar qué quieren decir los símbolos que se crean en el objeto
```
$ nm calculator.o
000000000000003c T add_numbers
0000000000000000 T main
                 U printf
```

T= texto que puede ser leido desde afuera.
U= undefined function.

5. ¿En qué se diferencian los símbolos del objeto y del ejecutable?

En el ejecutable **calculator.e** la lista de simbolos es mas extensa en relacion
a la del objeto porque es necesario incorporar cosas para poder ejecutarlo. A
```
0000000000400572 T add_numbers
0000000000600e20 d __JCR_LIST__
                 w _Jv_RegisterClasses
0000000000400600 T __libc_csu_fini
0000000000400590 T __libc_csu_init
                 U __libc_start_main@@GLIBC_2.2.5
0000000000400536 T main
                 U printf@@GLIBC_2.2.5
00000000004004b0 t register_tm_clones
0000000000601040 D __TMC_END__
```
Ademas, la funcion *printf* que estaba indefinida se linkea en forma dinamica, 
es decir, se busca y se define en tiempo de ejecucion.





