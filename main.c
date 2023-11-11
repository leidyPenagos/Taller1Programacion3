#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


void menu();

int pPunto();

int **matrizMagica();

int **multiplicacionM();
int getValue(char letra);
int validateRomanNumeral(const char* roman);
int romanNumerals(char* romano);
void infoRomanNumerals();
void primeNumbers(int num);
void infoPrimeNumbers();
void deleteGaps(char* texto);
void infoDeleteGaps();
int Numeros_Egolatras(int num);
int NumeroMagico(int num);
void Date(char date[10]);

int main() {
    menu();
    return 0;
}

void menu() {
    int num = 0;
    while (num == 0) {
        printf("\nBienvenido al Menu Matematico por favor elija la opcion que desea\n");
        printf("1. Numeros Romanos\n");
        printf("2. Factores Primos\n");
        printf("3. Borrar Espacios\n");
        printf("4. Numeros Egolatras\n");
        printf("5. Numero Magico\n");
        printf("6. Fechas\n");
        printf("7. Producto Punto\n");
        printf("8. Multiplicacion de Matrices\n");
        printf("9. Matriz Magica\n");
        printf("0. Salir\n");
        int num1;
        scanf("%d", &num1);
        switch (num1) {
             case 1:
                infoRomanNumerals();
                break;
            case 2:
                infoPrimeNumbers();
                break;
            case 3:
                infoDeleteGaps();
                break;
            case 4:
               
                printf("NUMEROS EGOLATRAS\n");
                printf("Ingrese el Numero que desea saber si es Egolatra O no\n");
                scanf("%d", &num);
                printf("El numero %d %s", num , Numeros_Egolatras(num)?
                "es un Numero egolatra": "No es un Numero egolatra\t");
                break;
            case 5:
                
                printf("NUMERO MAGICO\n");
                printf("Ingrese el numero que desea saber si es magico o no\n");
                scanf("%d", &num);
                printf("El numero %d %s", num, NumeroMagico(num)? " es un Numero Magico ":
                " No es Magico");
                break;
            case 6:
                printf("FORMATO DE FECHAS \n");
                printf("Ingrese la Fecha en el siguiente formato DD/MM/AAAA\n");
                char date[10];
                scanf("%s", &date);
                Date(&date);
                break;
            case 7:

                pPunto();
                break;
            case 8:
                multiplicacionM();
                break;
            case 9:
                matrizMagica();
                break;
            case 0:
                printf("Gracias por utilizar nuestro Menu Matematico lo esperamos de vuelta pronto");
                num = 1;
                break;
            default:
                printf("Lo sentimos la opcion ingresada es invalida");
                break;

        }
    }
}
int getValue(char letra) {
    switch (letra) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:

            return 0;
    }
}
int validateRomanNumeral(const char* roman) {
    int longitud = strlen(roman);

    //validacion: no puede tener mas de 3 letras seguidas iguales
    for (int i = 0; i < longitud - 2; i++) {
        if (roman[i] == roman[i + 1] && roman[i] == roman[i + 2]) {
            return 0; // No es un  numero romano
        }
    }

    //validacion: no puede tener mas de una V, L o D seguidas
    for (int i = 0; i < longitud - 1; i++) {
        if ((roman[i] == 'V' || roman[i] == 'L' || roman[i] == 'D') &&
            (roman[i + 1] == 'V' || roman[i + 1] == 'L' || roman[i + 1] == 'D')) {
            return 0; //  No es un  numero romano
        }
    }
    //validacion: no puede tener un grupo de letras repetidas
    for (int i = 0; i < longitud - 4; i++) {
        int j = i + 2;
        while (j < longitud - 1) {
            if (roman[i] == roman[j] && roman[i + 1] == roman[j + 1] &&
                roman[i + 2] == roman[j + 2] && roman[i + 3] == roman[j + 3]) {
                return 0; // No cumple la regla
            }
            j += 2;
        }
    }



    return 1; // Si es un numero romano
}
int romanNumerals(char* romano) {
    int decimal = 0;

    for (int i = 0; i < strlen(romano); i++) {

        if(getValue(romano[i])==0){
            return 0;
        }

        int currentValue = getValue(romano[i]);
        int nextValue = getValue(romano[i + 1]);

        if (nextValue > currentValue) {
            decimal += nextValue - currentValue;
            i++;
        } else {
            decimal += currentValue;
        }
    }

    return decimal;
}

void infoRomanNumerals(){
    //  HACER VALIDACIONES ANTES DE EMPEZAR
    int again=1;

    while (again==1){

        char roman[100] ;
        printf("Ingrese un numero romano: \n");
        scanf("%s", roman);
        int valido= validateRomanNumeral(roman);
        if(valido){
            for (int i = 0; i < strlen(roman); i++) {
                roman[i] = toupper(roman[i]);
            }

            int decimal = romanNumerals(roman);
            if(decimal==0){
                printf("Entrada invalida\n");
            }else {
                printf("El numero romano %s es equivalente a %d en decimal.\n", roman, decimal);
            }
        } else{
            printf("Entrada invalida\n");
        }

        printf("Quiere intentar con otro numero?\n"
               "1. Si\n"
               "2. No\n");

        scanf("%d",&again);
    }
}

void primeNumbers(int num){
    int factor = 2;
    int exp = 0;

    while (num > 1) {
        if (num % factor == 0) {
            exp++;
            num = num / factor;
        } else {
            if (exp > 0) {
                printf("%d^%d ,", factor, exp);
                exp = 0;
            }
            factor++;
        }
    }

    if (exp > 0) {
        printf("%d^%d ,", factor, exp);
    }
}

void infoPrimeNumbers(){
    int again=1;
    while (again==1){
        int num;

        printf("Ingrese un numero: ");
        scanf("%d", &num);

        printf("Los factores primos de %d en descomposicion: ", num);
        primeNumbers(num);
        printf("\n");
        printf("Quiere intentar con otro numero?\n"
               "1. Si\n"
               "2. No\n");

        scanf("%d",&again);
    }
}

void deleteGaps(char* texto){
    int start = 0;
    int end = strlen(texto) - 1;

    while (isspace(texto[start])) {
        start++;
    }

    while (end >= start && isspace(texto[end])) {
        end--;
    }
    int i;
    for (i = start; i <= end; i++) {
        texto[i - start] = texto[i];
    }

    texto[i - start] = '\0';

    //////////////////////////////////////////////////////////////
    int longitud = strlen(texto);
    int indexCleaned = 0;
    int isSpace = 0;

    for (int i = 0; i < longitud; i++) {
        if (isspace(texto[i])) {
            if (!isSpace) {
                texto[indexCleaned++] = ' ';
                isSpace = 1;
            }
        } else {
            texto[indexCleaned++] = texto[i];
            isSpace = 0;
        }
    }

    texto[indexCleaned] = '\0';

}

void infoDeleteGaps(){
    int again=1;

    while (again==1){
        char text[100] ;
        printf("Ingrese un texto: \n");
        //scanf("%s", text);
        scanf("%[^\n]", text);

        deleteGaps(text);

        printf("El texto sin espacios extra es %s.\n",text );


        printf("\n");
        printf("Quiere intentar con otro texto?\n"
               "1. Si\n"
               "2. No\n");

        scanf("%d",&again);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }

    }
}
int NumerosEgolatras(int n) {
    int numDigitos = floor(log10(n) + 1);
    char cadena[numDigitos + 1];
    sprintf(cadena, "%d", n);
    int suma = 0;
    for (int i = 0; i < numDigitos; i++) {
        int cont = cadena[i] - '0';
        int potencia = pow(cont, numDigitos);
        suma = suma + potencia;
    }
    if (suma == n) {
        return 1;
    } else {
        return 0;
    }
}
int NumeroMagico(int num) {
    int num1, num2, num3, aux;
    while (num2 <= 9) {
        aux = num;
        while (aux > 0) {
            num3 = aux % 10;
            if (num3 == num2) {
                num1 = (num1 * 10) + num3;
            }
            aux = (aux - num3) / 10;
        }
        num2 = num2 + 1;
    }
    int N_menor = num1;
    int invert = 0;
    while (num1 > 0) {
        invert = (invert * 10) + (num1 % 10);
        num1 = num1 / 10;
    }
    int N_mayor = invert;
    int OpResta = N_mayor - N_menor;
    if (OpResta == num) {
        return 1;
    } else {
        return 0;
    }
}
void Date(char date[10]) {
    if (date[2] == '/' && date[5] == '/' && date[9] !=
                                            '\0' && date[8] !=
                                                    '\0' && date[7] !=
                                                            '\0' && date[6] !=
                                                                    '\0') {

        char dia1 = date[0];
        char dia2 = date[1];

        char mes1 = date[3];
        char mes2 = date[4];

        char año1 = date[6];
        char año2 = date[7];
        char año3 = date[8];
        char año4 = date[9];
        if (dia1 == '0' || dia1 == '1' || dia1 == '2' || dia1 == '30' || dia1 =='31') {
            if (mes1 == '0' && mes2 == '1') {
                printf("%c%c de Enero de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '2') {
                printf("%c%c de Febrero de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '3') {
                printf("%c%c de Marzo de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '4') {
                printf("%c%c de Abril de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '5') {
                printf("%c%c de Mayo de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '6') {
                printf("%c%c de Junio de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '7') {
                printf("%c%c de Julio de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '8') {
                printf("%c%c de Agosto de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '0' && mes2 == '9') {
                printf("%c%c de Septiembre de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '1' && mes2 == '0') {
                printf("%c%c de Octubre de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '1' && mes2 == '1') {
                printf("%c%c de Noviembre de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else if (mes1 == '1' && mes2 == '2') {
                printf("%c%c de Diciembre de %c%c%c%c", dia1, dia2, año1, año2, año3, año4);
            } else {
                printf("El mes no correponde a los estandares establecidos");
            }
        } else {
            printf("El dia no corresponde a los estandares estblecidos");
        }
    } else {
        printf("Formato de fecha incorrecto, por favor ingrese la fecha con el siguiente formato=DD/MM/AAAA"
               "EJEMPLO: 09/07/2023\n");
    }
}

int pPunto() {
    int num, num1;
    printf("Actualmente se encuentra en la opcion 7 Producto Punto\n");
    printf("Para esto debe ingresar dos arreglos a continuacion:\n");
    printf("Ingrese la cantidad de datos del arreglo\n");
    scanf("%d", &num);
    int v1[num];
    for (int i = 0; i < num; i++) {
        printf("Ingrese el dato n %d:  ", i + 1);
        scanf("%d", &num1);
        v1[i] = num1;
    }
    printf("Ingrese la cantidad de datos del arreglo\n");
    scanf("%d", &num);
    int v2[num];
    for (int i = 0; i < num; i++) {
        printf("Ingrese el dato n %d:  ", i + 1);
        scanf("%d", &num1);
        v2[i] = num1;
    }
    int tam1 = sizeof(v1) / sizeof(v1[0]);
    int tam2 = sizeof(v2) / sizeof(v2[0]);
    if (tam1 == tam2) {
        int sum = 0;
        for (int i = 0; i < tam1; i++) {
            sum = (v1[i] * v2[i]) + sum;
        }
        printf("El producto punto es: %d \n", sum);
        return sum;
    } else {
        printf("No es posible calcular el producto punto\n");
    }
    return (int) NULL;
}
int **multiplicacionM() {
    int f1, f2;
    int c1, c2;
    int x, s, r;
    srand(time(NULL));
    printf("A continuacion a ingresado a la funcion de multiplicacion de matrices\n");
    printf("Por favor ingrese el numero de filas de la primera matriz:\n");
    scanf("%d", &f1);
    printf("Por favor ingrese el numero de columnas de la primera matriz: \n");
    scanf("%d", &c1);
    int matriz[f1][c1];
    for (int i = 0; i < f1; i++) {
        for (int j = 0; j < c1; j++) {
            x = rand() % 25;
            matriz[i][j] = x;
        }
    }
    printf("Matriz 1:\n");
    for (int i = 0; i < f1; i++) {
        for (int j = 0; j < c1; j++) {
            printf(" %d |", matriz[i][j]);

        }
        printf("\n");
    }

    printf("Por favor ingrese el numero de filas de la segunda matriz:\n");
    scanf("%d", &f2);
    printf("Por favor ingrese el numero de columnas de la segunda matriz: \n");
    scanf("%d", &c2);
    int matriz2[f2][c2];
    for (int i = 0; i < f2; i++) {
        for (int j = 0; j < c2; j++) {
            s = rand() % 15;
            matriz2[i][j] = s;
        }
    }
    printf("Matriz 2:\n");
    for (int i = 0; i < f2; i++) {
        for (int j = 0; j < c2; j++) {
            printf(" %d |", matriz2[i][j]);
        }
        printf("\n");
    }

    if (c1 == f2) {
        int resultado[f1][c2];
        for (int i = 0; i < f1; i++) {
            for (int j = 0; j < c2; j++) {
                r = 0;
                for (int k = 0; k < c2; k++) {
                    r = r + matriz[i][k] * matriz2[k][j];

                }
                resultado[i][j] = r;
            }

        }

        printf("Multiplicacion de las matrices: \n");
        for (int i = 0; i < f1; i++) {
            for (int j = 0; j < c2; j++) {
                printf(" %d |", resultado[i][j]);
            }
            printf("\n");
        }
        return resultado;
    } else {
        printf("No es posible realizar esta operacion\n");
    }

    return NULL;
}

int **matrizMagica() {
    int c;
    int f;
    int x = 0;
    int num = 0;
    printf("A continuacion a ingresado a la funcion de matriz magica\n");
    while (num == 0) {
        printf("Por favor ingrese el numero de filas recuerde que debe ser impar:\n");
        scanf("%d", &c);
        if (c % 2 != 0) {
            printf("Por favor ingrese el numero de columnas recuerde que debe ser impar: \n");
            scanf("%d", &f);
            if (f % 2 != 0) {
                int matriz[c][f];
                for (int i = 0; i < c; i++) {
                    for (int j = 0; j < f; j++) {
                        matriz[i][j] = x + 1;
                        x += 1;
                    }
                }
                int fila = sizeof(matriz) / sizeof(matriz[0]);
                int columna = sizeof(matriz[0]) / sizeof(matriz[0][0]);
                printf("Matriz Magica: \n");
                for (int i = 0; i < fila; i++) {
                    for (int j = 0; j < columna; j++) {
                        printf(" %d |", matriz[i][j]);
                    }
                    printf("\n");
                }
                num = 1;
                return matriz;
            } else {
                printf("El numero no es impar intente de nuevo\n");
            }
        } else {
            printf("El numero no es impar intente de nuevo\n");
        }
    }
    return NULL;

}

