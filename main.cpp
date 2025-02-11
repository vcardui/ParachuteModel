/*
10 de febrero de 2025
Vanessa Reteguín - 375533

Práctica “Comparación de un método exacto y uno aproximado”

Universidad Aútonoma de Aguascalientes
Ingeniería en Computación Inteligente (ICI)
Semestre III

Grupo 4 - E
Programación Científica
Aurora Torres Soto

Instrucciones:
1. Haciendo uso del DEVC++ desarrolle un programa que calcule y muestre el resultado de
evaluar 50 puntos de ambas expresiones (exacta y aproximada). El programa deberá
solicitar al usuario los valores de la masa del paracaidista ‘m’, de la constante de resistencia
del viento ‘c’ y de los incrementos del tiempo que se desean usar ( 𝑡_{i+1}'− 𝑡_{i} ). Parta de las
condicione iniciales conocidas: 𝑣(0) = 0.

2. El programa debe mostrar el valor del tiempo en el que esta evaluando y los valores: exacto
y aproximado de la velocidad. Redacte una función para cada resultado.
Su programa debe mostras una salida como la siguiente:
Introduce el valor de la masa del paracaidista: 65
Introduce el coeficiente de resistencia: 12.5
Introduce el incremento del tiempo: 0.5
t        vexacta      vnumerica
0.00     0.000000     0.000000
0.50     4.676563     4.905000
…
Nota: Estos valores suponen una gravedad de 9.81 [m/s^2]

3. Elabore un reporte en word que contenga copia del código fuente de su programa, captura
de pantalla de su ejecución mostrando los parámetros empleados y sus conclusiones.
Realice el envío de este documento y su código ejecutable al vínculo “Reporte Práctica2”
de aulavirtual.uaa.mx
El documento debe ser enviado de manera individual para el 10 de febrero de 2025.

*/

/* ------------------------- Libraries ------------------------- */
#include <iostream>
#include <math.h> /* exp */
#include <iomanip> /* setprecision(n) */
using namespace std; /* cin/cout */

/* ------------------------- Functions ------------------------- */

void diplayMenu() {
    cout << endl
         << "\nSeleccione una opción: "
            "\n.-----------------."
            "\n||  -{ Modeo }-  ||"
            "\n.-----------------."
            "\n| [1] Exacto      |"
            "\n| [2] Aproximado  |"
            "\n|-----------------|"
            "\n| [3] Comparación |"
            "\n|-----------------|"
            "\n|       [4] Salir |"
            "\n.-----------------.\n";
}

void endTitle() {
    cout << "\n  ^~^  , * ------------- *"
            "\n ('Y') ) |  Hasta luego! | "
            "\n /   \\/  * ------------- *"
            "\n(\\|||/)        FIN      \n";
}

void getConstraints(float& mass, float& airResistance, float& timeIncrease){
    cout << endl << "[*] Introduzca los datos correspondientes";
    cout << endl << "Masa del paracaidista [kg]: ";
    while (!(cin >> mass)) {
        cin.clear();
        cin.ignore();
    }

    cout << endl << "Coeficiente de resistencia [N]: ";
    while (!(cin >> airResistance)) {
        cin.clear();
        cin.ignore();
    }

    cout << endl << "Incremento en el tiempo [s]: ";
    while (!(cin >> timeIncrease)) {
        cin.clear();
        cin.ignore();
    }
}

float exactModel(float m, float g, float c, float t){
    return ( ((g * m) / c ) * (1 - exp( ((-c) / m) * t )));
}

float approximateModel(float m, float g, float c, float t, float oldV){
    if (t == 0) {
        return 0;
    } else {
        return ( ( (g - ( (c * oldV) / m )) * t ) + oldV);
    }
}

int main() {
    /* ------------------------- Variables ------------------------- */
    /* - Menu - */
    int userChoice;
    bool run = true;

    /* - Formula - */
    const float GRAVITY = 9.81;
    float mass = 0, airResistance = 0, timeIncrease = 0;

    /* - Auxiliaries - */
    int i = 0, iterations = 0; ;
    float exactResult = 0, aproxResult = 0, currentTime = 0, oldVelocity = 0;

    /* --------------------------- Code ---------------------------- */

    while (run == true) {
        diplayMenu();
        while (!((cin >> userChoice) && (userChoice >= 1 && userChoice <= 4))) {
            cin.clear();
            cin.ignore();
        }

        mass = 0, airResistance = 0, timeIncrease = 0;
        exactResult = 0, aproxResult = 0, currentTime = 0, oldVelocity = 0;
        iterations = 0;

        switch (userChoice) {
            case 1:
                getConstraints(mass, airResistance, timeIncrease);
                cout << endl << "-{ Modelo exacto }-" << endl;

                cout << "La velocidad en el tiempo " << timeIncrease << " es de " << setprecision(4) << fixed << exactModel(mass, GRAVITY, airResistance, timeIncrease);

                break;

            case 2:
                cout << endl << "-{ Modelo aproximado }-" << endl;

                getConstraints(mass, airResistance, timeIncrease);

                oldVelocity = 0;
                currentTime = 0;
                for(i = 0; i <= 1; i++){
                    aproxResult = approximateModel(mass, GRAVITY, airResistance, currentTime, oldVelocity);
                    oldVelocity = aproxResult;
                    currentTime += timeIncrease;
                }

                cout << "La velocidad en el tiempo " << timeIncrease << " es de aproximadamente " << setprecision(4) << fixed  << setprecision(4) << fixed << aproxResult << endl;

                break;

            case 3:
                cout << endl << "-{ Comparación de modelos }-" << endl;
                getConstraints(mass, airResistance, timeIncrease);

                cout << endl << "Iteraciones a ejecutar (máx. 100): ";
                while (!((cin >> iterations) && (iterations >= 1 && iterations <= 100))) {
                    cin.clear();
                    cin.ignore();
                }

                cout << endl << "t\t\tvExacta\t\tvNumérica\tError" << endl;
                oldVelocity = 0;
                currentTime = 0;
                for(i = 0; i <= iterations; i++){
                    exactResult = exactModel(mass, GRAVITY, airResistance, currentTime);
                    aproxResult = approximateModel(mass, GRAVITY, airResistance, currentTime, oldVelocity);
                    oldVelocity = aproxResult;

                    cout << setprecision(4) << fixed << currentTime << 
                    "\t\t" << setprecision(4) << fixed << exactResult << 
                    "\t\t" << setprecision(4) << fixed << aproxResult << 
                    "\t\t" << setprecision(4) << fixed << (aproxResult - exactResult) << endl;

                    currentTime += timeIncrease;
                }
                break;

            case 4:
                endTitle();
                run = false;
                break;
        }
    }

    return 0;
}