# Analizador_Sintactico_Descendente

Desarrollo de un analizador sintáctico descendente recursivo en C para el análisis de expresiones mediante una gramática definida.

## Requisitos

- GCC instalado y disponible desde PowerShell como el comando `gcc`.
- PowerShell abierto en la carpeta del proyecto.

## Compilación

Desde la carpeta del proyecto, compila todos los módulos C en un ejecutable:

```powershell
gcc principal.c inic.c simbolos.c analizlex.c analizsint.c error.c emisor.c -o analizador.exe
```

## Ejecución

El analizador lee desde la entrada estándar. En PowerShell puedes pasarle una expresión así:

```powershell
"a + 4 - (b * 8 / 2 div 3 mod c);" | .\analizador.exe
```

La expresión de ejemplo usa todos los elementos que se pueden escribir en la entrada: identificadores (`a`, `b`, `c`), números (`4`, `8`, `2`, `3`), suma (`+`), resta (`-`), multiplicación (`*`), división (`/`), división entera (`div`), módulo (`mod`), paréntesis (`(` y `)`) y terminador (`;`). Las palabras reservadas `div` y `mod` deben escribirse en minúsculas.

La salida postfija esperada es:

```text
a
4
+
b
8
*
2
/
3
DIV
c
MOD
-
```

Cada expresión debe terminar con `;`. También puede ejecutar el programa directamente con `.\analizador.exe`, escribir una o más expresiones y terminar la entrada con **Ctrl+Z** y luego **Enter**.

## Gramática

```text
programa   ::= { expresion ";" }
expresion  ::= termino { ("+" | "-") termino }
termino    ::= factor { ("*" | "/" | "div" | "mod") factor }
factor     ::= NUM | ID | "(" expresion ")"
```

`NUM` representa un entero y `ID` un identificador que empieza con una letra y continúa con letras o dígitos. `FIN` es el token que el analizador léxico genera al llegar al final de la entrada; no se escribe. `FDC` y `NINGUNO` son valores internos del programa.
