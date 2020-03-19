#include <stdio.h>
#include <math.h>
#include <string.h>

// Pedro Antonio Estévez Pérez

// Ejercicio 11

/* He modificado un poco el enunciado del problema, generalizándolo. El nuevo sería:
 * Crea un programa que convierta los números hexadecimales en binarios y realice
 * con ellos las siguientes operaciones: &, |, ^, ~, >, <.*/

// En cuanto al primer apartado, el 10101001011010101010101010101010111b es: 0x54B555557

int main(void)
{
    /* Hay dos formas de pasar de hexadecimal a binario, directamente o pasando a decimal
     * y después a binario. Dado que ya tengo un programa que pasa de decimal a binario,
     * lo que haremos primero será pasar a decimal.
     *
     * El problema es que tengo que pasar tres números a decimal y después a binario, así que
     * o hago un código con las mismas operaciones tres veces pero con distintos nombres, o lo
     * que he hecho aquí. Antes de empezar con la conversión a decimal, si estamos con el primer
     * número, cambiaré los nombres de las variables a las que usará el conversor en sí mismo.
     * Una vez tengamos el binario, haremos el proceso inverso y repetiremos el proceso, pero
     * esta vez para el segundo numero. La variable 'auxiliar' nos dirá qué número se convertirá.*/


    int longitud, i, j, k, decimal=0, cifra, longitud1, longitud2, longitud3, auxiliar;
    int vector[500], binario1[500], binario2[500], binario3[500], desplazamiento;
    char numero[500],numero1[500],numero2[500], numero3[500], operacion;

    printf("Introduce la operacion, (&, |, ^, ~, >, <): ");
    scanf("%c", &operacion);
    if (operacion == '&' || operacion == '|' || operacion == '^')
    {
        printf("Introduce el primer numero: ");
        scanf("%s", &numero1);
        longitud1 = strlen(numero1);
        for (i=0; i<longitud1; i++)
        {
            if (!(numero1[i] == '0' || numero1[i] == '1' || numero1[i] == '2' || numero1[i] == '3' || numero1[i] == '4' || numero1[i] == '5' || numero1[i] == '6' || numero1[i] == '7' || numero1[i] == '8' || numero1[i] == '9' || numero1[i] == 'A' || numero1[i] == 'B' || numero1[i] == 'C' || numero1[i] == 'D' || numero1[i] == 'E' || numero1[i] == 'F' || numero1[i] == 'a' || numero1[i] == 'b' || numero1[i] == 'c' || numero1[i] == 'd' || numero1[i] == 'e' || numero1[i] == 'f'))
            {
                printf("Introduce un numero hexadecimal valido.\n\n");
                return;
            }

        }
        printf("Introduce el segundo numero: ");
        scanf("%s", &numero2);
        longitud2 = strlen(numero2);
        for (i=0; i<longitud2; i++)
        {
            if (!(numero2[i] == '0' || numero2[i] == '1' || numero2[i] == '2' || numero2[i] == '3' || numero2[i] == '4' || numero2[i] == '5' || numero2[i] == '6' || numero2[i] == '7' || numero2[i] == '8' || numero2[i] == '9' || numero2[i] == 'A' || numero2[i] == 'B' || numero2[i] == 'C' || numero2[i] == 'D' || numero2[i] == 'E' || numero2[i] == 'F' || numero2[i] == 'a' || numero2[i] == 'b' || numero2[i] == 'c' || numero2[i] == 'd' || numero2[i] == 'e' || numero2[i] == 'f'))
            {
                printf("Introduce un numero hexadecimal valido.\n\n");
                return;
            }

        }
        auxiliar = 1;
    }
    else if (operacion == '~' || operacion == '<' || operacion == '>')
    {
        printf("Introduce el numero: ");
        scanf("%s", &numero3);
        longitud3 = strlen(numero3);
        for (i=0; i<longitud3; i++)
        {
            if (!(numero3[i] == '0' || numero3[i] == '1' || numero3[i] == '2' || numero3[i] == '3' || numero3[i] == '4' || numero3[i] == '5' || numero3[i] == '6' || numero3[i] == '7' || numero3[i] == '8' || numero3[i] == '9' || numero3[i] == 'A' || numero3[i] == 'B' || numero3[i] == 'C' || numero3[i] == 'D' || numero3[i] == 'E' || numero3[i] == 'F' || numero3[i] == 'a' || numero3[i] == 'b' || numero3[i] == 'c' || numero3[i] == 'd' || numero3[i] == 'e' || numero3[i] == 'f'))
            {
                printf("Introduce un numero hexadecimal valido.\n\n");
                return;
            }

        }
        if (operacion == '<' || operacion == '>')
        {
            printf("Introduce el numero de desplazamientos: ");
            scanf("%d", &desplazamiento);
        }
        auxiliar = 0;
    }
    else
    {
        printf("Introduce una operacion valida.\n\n");
        return;
    }

    while(auxiliar < 3)
    {
        if (auxiliar == 0)
        {
            if (numero3[0] == '0' && (numero3[1] == 'x' || numero3[1] == 'X'))
                printf("El numero ");
            else
                printf("El numero 0x");

            for (i=0; i<longitud3; i++)
                printf("%c", numero3[i]);
            printf(" equivale a: ");
            longitud = longitud3;
            for (i=0; i<longitud; i++)
                numero[i] = numero3[i];
        }
        else if (auxiliar == 1)
        {
            if (numero1[0] == '0' && (numero1[1] == 'x' || numero1[1] == 'X'))
                printf("El numero ");
            else
                printf("El numero 0x");

            for (i=0; i<longitud1; i++)
                printf("%c", numero1[i]);
            printf(" equivale a: ");
            longitud = longitud1;
            for (i=0; i<longitud; i++)
                numero[i] = numero1[i];
        }
        else if (auxiliar == 2)
        {
            if (numero2[0] == '0' && (numero2[1] == 'x' || numero2[1] == 'X'))
                printf("El numero ");
            else
                printf("El numero 0x");

            for (i=0; i<longitud2; i++)
                printf("%c", numero2[i]);
            printf(" equivale a: ");
            longitud = longitud2;
            for (i=0; i<longitud; i++)
                numero[i] = numero2[i];
        }

        for (i=0; i<longitud; i++)
        {
            if (numero[i] == '0' || numero[i] == 'x' || numero[i] == 'X')// Distinguiremos si el usuario ha escrito 0x o no
                continue;
            if (numero[i] == 'A' || numero[i] == 'B' || numero[i] == 'C' || numero[i] == 'D' || numero[i] == 'E' || numero[i] == 'F')
                cifra = numero[i] - '0' - 7;
            else if (numero[i] == 'a' || numero[i] == 'b' || numero[i] == 'c' || numero[i] == 'd' || numero[i] == 'e' || numero[i] == 'f')
                cifra = numero[i] - '0' - 39;
            else
                cifra = numero[i] - '0';

            decimal = decimal + cifra * pow(16, longitud-1-i);
        }

        // Una vez tenemos el número en decimal, lo pasamos a binario.

        int n, resto;
        n = decimal;
        longitud = 0;

        i = -1;
        while (n >= 2)
        {
            resto = n % 2;
            n = n / 2;
            i++;
            vector[i] = resto;
        }
        vector[i+1] = n;
        vector[i+2] = 2;

        i = 0;
        while (vector[i] != 2) // No puedo usar strlen porque estoy con int
        {
            longitud++;
            i++;
        }

        if (auxiliar == 0)
        {
            for (i=0; i<longitud; i++)
                binario3[i] = vector[i];
            longitud3 = longitud;
            auxiliar = 3;
            for (i=longitud3-1; i>=0; i--)
                printf("%d", binario3[i]);
            printf("b\n");
        }
        else if (auxiliar == 1)
        {
            for (i=0; i<longitud; i++)
                binario1[i] = vector[i];
            longitud1 = longitud;
            decimal = 0;
            auxiliar = 2;
            for (i=longitud1-1; i>=0; i--)
                printf("%d", binario1[i]);
            printf("b\n");
        }
        else if (auxiliar == 2)
        {
            for (i=0; i<longitud; i++)
                binario2[i] = vector[i];
            longitud2 = longitud;
            auxiliar = 3;
            for (i=longitud2-1; i>=0; i--)
                printf("%d", binario2[i]);
            printf("b\n");
        }
    }

    // Ya tenemos los dos números en binario, Ahora hay que realizar las operaciones.
    // Podría haberlas separado en funciones, pero creo que habría sido más engorroso.

    int and[500], or[500], xor[500], not[500], derecha[500], izquierda[500];

    if (operacion == '&')
    {
        /* No hay mayor problema que comparar, ya que cuando se acabe el número, todo lo
         * demás son 0.*/

        i=0;
        j=0;
        while (i<=longitud1 && j<=longitud2)
        {
            if (binario1[i] == 1 && binario2[j] == 1)
                and[i] = 1;
            else
                and[i] = 0;
            i++;
            j++;
        }

        if (longitud1 > longitud2)
            longitud = longitud2;
        else
            longitud = longitud1;

        printf("El resultado de la AND es: ");
        for (i=longitud-1; i>=0; i--)
            printf("%d", and[i]);
        printf("b\n\n");

    }
    else if (operacion == '|')
    {
        /* El problema de este es que cuando se acabe un número, hay que compltar con
         * el resto del otro.*/

        i=0;
        j=0;
        while (i<longitud1 && j<longitud2)
        {
            if (binario1[i] == 1 || binario2[j] == 1)
                or[i] = 1;
            else
                or[i] = 0;
            i++;
            j++;
        }
        if (i == longitud1)
        {
            for (k=j; k<longitud2; k++)
                or[k] = binario2[k];
        }
        else if (j == longitud2)
        {
            for (k=i; k<longitud1; k++)
                or[k] = binario1[k];
        }
        if (longitud1 > longitud2)
            longitud = longitud1;
        else
            longitud = longitud2;

        printf("El resultado de la OR es: ");
        for (i=longitud-1; i>=0; i--)
            printf("%d", or[i]);
        printf("b\n\n");
    }
    else if (operacion == '^')  // Casi igual que el anterior
    {
        i=0;
        j=0;
        while (i<longitud1 && j<longitud2)
        {
            if (binario1[i] == 1 && binario2[j] == 1)
                xor[i] = 0;
            else if (binario1[i] == 1 && binario2[j] == 0)
                xor[i] = 1;
            else if (binario1[i] == 0 && binario2[j] == 1)
                xor[i] = 1;
            else if (binario1[i] == 0 && binario2[j] == 0)
                xor[i] = 0;
            i++;
            j++;
        }
        if (i == longitud1)
        {
            for (k=j; k<longitud2; k++)
                xor[k] = binario2[k];
        }
        else if (j == longitud2)
        {
            for (k=i; k<longitud1; k++)
                xor[k] = binario1[k];
        }
        if (longitud1 > longitud2)
            longitud = longitud1;
        else
            longitud = longitud2;

        printf("El resultado de la XOR es: ");
        for (i=longitud-1; i>=0; i--)
            printf("%d", xor[i]);
        printf("b\n\n");
    }
    else if (operacion == '~') // Obvio
    {
        printf("El resultado de la NOT es: ");
        for (i=longitud3-1; i>=0; i-- )
        {
            if (binario3[i] == 1)
                not[i] = 0;
            else
                not[i] = 1;
            printf("%d", not[i]);
        }
        printf("b\n\n");
    }
    else if(operacion == '<') // Sólo lioso
    {
        for (i=desplazamiento; i<longitud3; i++)
            izquierda[i] = binario3[i-desplazamiento];

        for (i=0; i<desplazamiento;i++)
            izquierda[i] = 0;

        printf("El resultado del desplazamiento es: ");
        for (i=longitud3-1; i>=0; i--)
            printf("%d", izquierda[i]);
        printf("b\n\n");
    }
    else if(operacion == '>')
    {
        for (i=desplazamiento; i<longitud3; i++)
            derecha[i] = binario3[i];

        printf("El resultado del desplazamiento es: ");
        for (i=longitud3-1; i>=desplazamiento; i--)
            printf("%d", derecha[i]);
        printf("b\n\n");
    }
}
