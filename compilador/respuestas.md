#Respuestas ejercicio compilador

1. Escriban qué esperan de cada uno de los pasos

* Del primer paso (Pre-procesador: `gcc -E calculator.c -o calculator.pp.c`) esperamos obtener un archivo **.pp.c** que nos evita tener que describir funciones y macros usuales.
* Del segundo paso (Compilacion I: `gcc -S calculator.c -o calculator.asm`) esperamos obtener un archivo **.asm** en lenguaje assembler generado a partir del archivo **.c**. Este archivo resulta dificl de leer pero se pueden identificar por ejemplo, las funciones.
* Del tercer paso (Compilacion II: `gcc -c calculator.asm -o calculator.o`) esperamos obtener un objeto (archivo **.o**) en lenguaje de maquina (binario) a partir de un archivo en lenguaje assembler. Este archivo no se puede abrir pero se pueden ver los descriptores con `nm`.
* Del cuarto paso (Linkeo: `gcc calculator.o -o calculator.e`) esperamos obtener un ejecutable (archivo **.e**) a partir de un objeto.

2. ¿Qué agregó el preprocesador?

Agrego el archivo **calculator.pp.c** en el que se identifican las funciones y los argumentos que las mismas reciben.

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

En el objeto **calculator.o** tenemos los simbolos *add_numbers* y *main* cuyos descriptor
es T (texto al que se puede acceder desde afuera) y el simbolo *printf* cuyo descriptor
es U (undefined)

```
$ nm calculator.o
000000000000003c T add_numbers
0000000000000000 T main
                 U printf
```

5. ¿En qué se diferencian los símbolos del objeto y del ejecutable?

En el ejecutable **calculator.e** la lista de simbolos es mas extensa en relacion
a la del objeto porque es necesario incorporar cosas para poder ejecutarlo.

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

Ademas, la funcion *printf* que estaba indefinida se linkea con la libreria dinamica GLIBC_2.2.5, es decir que esta funcion se busca y se define en tiempo de ejecucion.





