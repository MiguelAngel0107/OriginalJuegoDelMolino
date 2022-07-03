#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <Windows.h>

#define DERECHA 77
#define ABAJO 80
#define ARRIBA 72
#define IZQUIERDA 75


using namespace System;
using namespace std;

char posiciones[11][11] =
{
    {'O','-','-','-','-','O','-','-','-','-','O',},
    {'|',' ',' ',' ',' ','|',' ',' ',' ',' ','|',},
    {'|',' ','O','-','-','O','-','-','O',' ','|',},
    {'|',' ','|',' ',' ','|',' ',' ','|',' ','|',},
    {'|',' ','|',' ','O','O','O',' ','|',' ','|',},
    {'O','-','O','-','O',' ','O','-','O','-','O',},
    {'|',' ','|',' ','O','O','O',' ','|',' ','|',},
    {'|',' ','|',' ',' ','|',' ',' ','|',' ','|',},
    {'|',' ','O','-','-','O','-','-','O',' ','|',},
    {'|',' ',' ',' ',' ','|',' ',' ',' ',' ','|',},
    {'O','-','-','-','-','O','-','-','-','-','O',},
};


void menu() {
    Console::ForegroundColor = ConsoleColor::Blue;
    Console::SetCursorPosition(50, 10); cout << "Menu del juego" << endl;
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(43, 13); cout << "1. Ver instrucciones del juego" << endl;
    Console::SetCursorPosition(43, 14); cout << "2. Iniciar juego" << endl;
    Console::SetCursorPosition(43, 15); cout << "3. Salir del juego" << endl;

}

void presentacion() {
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(0, 2);
    std::cout << R"( 
                                
                                 .___  ___.   ______    __       __  .__   __.   ______   
                                 |   \/   |  /  __  \  |  |     |  | |  \ |  |  /  __  \  
                                 |  \  /  | |  |  |  | |  |     |  | |   \|  | |  |  |  | 
                                 |  |\/|  | |  |  |  | |  |     |  | |  . `  | |  |  |  | 
                                 |  |  |  | |  `--'  | |  `----.|  | |  |\   | |  `--'  | 
                                 |__|  |__|  \______/  |_______||__| |__| \__|  \______/  
                                                                                          
                                
    )" << '\n';
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(50, 15); cout << "Integrantes del equipo: " << endl;
    Console::SetCursorPosition(40, 16); cout << "Camila Elena Amaro Villanueva - U202114248" << endl;
    Console::SetCursorPosition(40, 17); cout << "Miguel Angel Egocheaga Suyo - U202215188" << endl;
    Console::SetCursorPosition(40, 18); cout << "Sebastian Valente Lobato Pozo - U202215312" << endl;
    Console::ForegroundColor = ConsoleColor::DarkYellow;
    Console::SetCursorPosition(40, 25); cout << "Presione cualquier tecla para continuar" << endl;
    _getch();
    Console::Clear();
}

void instrucciones() {
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(30, 10); cout << "   El objetivo del juego es conseguir que el jugador" << endl;
    Console::SetCursorPosition(30, 11); cout << "   contrario acabe con solo 2 fichas sobre el tablero" << endl;
    Console::SetCursorPosition(30, 12); cout << "   o que no pueda realizar ningun movimiento por" << endl;
    Console::SetCursorPosition(30, 13); cout << "   tener todas las fichas bloqueadas. Para ello, cada" << endl;
    Console::SetCursorPosition(30, 14); cout << "   jugador debe intentar hacer molinos (3 en raya," << endl;
    Console::SetCursorPosition(30, 15); cout << "   fichas alineadas horizontal, vertical o diagonalmente)" << endl;
    Console::SetCursorPosition(30, 16); cout << "   con las fichas propias, lo que da derecho a capturar" << endl;
    Console::SetCursorPosition(30, 17); cout << "   cualquier ficha del contrincante." << endl;
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::SetCursorPosition(40, 25); cout << "Presione cualquier tecla para continuar" << endl;
    _getch();
    Console::Clear();

    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::SetCursorPosition(48, 2); cout << "Instrucciones del juego" << endl;
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(27, 6); cout << "Cada jugador contara con 9 fichas para colocar en el tablero";
    Console::SetCursorPosition(29, 7); cout << "Se le indicara la coordenada de una casilla disponible";
    Console::SetCursorPosition(25, 8); cout << "Para colocar su ficha en la casilla debe usar la tecla de flecha abajo";
    Console::SetCursorPosition(19, 9); cout << "Si desea colocar su ficha en una casilla distinta use la tecla de flecha derecha";
    Console::SetCursorPosition(40, 12); cout << "Ejemplo:" << endl;
    Console::SetCursorPosition(35, 14); cout << "Casilla [1][6]" << endl;
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(54, 11); cout << "O - - - -   - - - - O";
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(63, 11); cout << " X ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(54, 12); cout << "|         |         |";
    Console::SetCursorPosition(54, 13); cout << "|   O - - O - - O   |";
    Console::SetCursorPosition(54, 14); cout << "|   |     |     |   |";
    Console::SetCursorPosition(54, 15); cout << "|   |   O O O   |   |";
    Console::SetCursorPosition(54, 16); cout << "O - O - O   O - O - O";
    Console::SetCursorPosition(54, 17); cout << "|   |   O O O   |   |";
    Console::SetCursorPosition(54, 18); cout << "|   |     |     |   |";
    Console::SetCursorPosition(54, 19); cout << "|   O - - O - - O   |";
    Console::SetCursorPosition(54, 20); cout << "|         |         |";
    Console::SetCursorPosition(54, 21); cout << "O - - - - O - - - - O";
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::SetCursorPosition(40, 25); cout << "Presione cualquier tecla para continuar" << endl;
    _getch();
    Console::Clear();

    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::SetCursorPosition(48, 2); cout << "Instrucciones del juego" << endl;
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(32, 4); cout << "Para poder capturar las fichas del jugador adversario";
    Console::SetCursorPosition(34, 5); cout << "se deben formar molinos con las fichas (3 en raya),";
    Console::SetCursorPosition(26, 6); cout << "estos molinos pueden ser de manera vertical, horizontal o diagonal.";
    Console::SetCursorPosition(29, 7); cout << "Una vez formado un molino se puede capturar una ficha del jugador";
    Console::SetCursorPosition(26, 8); cout << "contrario de cualquier casilla del tablero de la misma forma en que se";
    Console::SetCursorPosition(29, 9); cout << "colocaban las fichas en el tablero, siempre que estas no formen";
    Console::SetCursorPosition(27, 10); cout << "parte de un molino. En el caso todas las fichas del jugador contrario";
    Console::SetCursorPosition(32, 11); cout << "formen molinos puede llevarse cualquier ficha del tablero";
    Console::SetCursorPosition(30, 14); cout << "Ejemplo:" << endl;
    Console::SetCursorPosition(30, 16); cout << "Jugador 1:" << endl;
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(40, 16); cout << " X ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(30, 17); cout << "Jugador 2:" << endl;
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(40, 17); cout << " Y ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(30, 18); cout << "Ficha capturada:" << endl;
    Console::ForegroundColor = ConsoleColor::Blue;
    Console::SetCursorPosition(46, 18); cout << " Y ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(54, 13); cout << "  - - - -   - - - -  ";
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(53, 13); cout << " X ";
    Console::SetCursorPosition(63, 13); cout << " X ";
    Console::SetCursorPosition(73, 13); cout << " X ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(54, 14); cout << "|         |         |";
    Console::SetCursorPosition(54, 15); cout << "|   O - -   - -     |";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(63, 15); cout << " Y ";
    Console::ForegroundColor = ConsoleColor::Blue;
    Console::SetCursorPosition(69, 15); cout << " Y ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(54, 16); cout << "|   |     |     |   |";
    Console::SetCursorPosition(54, 17); cout << "|   |   O O O   |   |";
    Console::SetCursorPosition(54, 18); cout << "O - O - O   O -   - O";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(69, 18); cout << " Y ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(54, 19); cout << "|   |   O O O   |   |";
    Console::SetCursorPosition(54, 20); cout << "|   |     |     |   |";
    Console::SetCursorPosition(54, 21); cout << "|   O - - O - - O   |";
    Console::SetCursorPosition(54, 22); cout << "|         |         |";
    Console::SetCursorPosition(54, 23); cout << "O - - - - O - - - - O";
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::SetCursorPosition(40, 25); cout << "Presione cualquier tecla para continuar" << endl;
    _getch();
    Console::Clear();

    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::SetCursorPosition(49, 2); cout << "Instrucciones del juego" << endl;
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(29, 4); cout << "Una vez ambos jugadores ya hayan colocado sus 9 fichas en el tablero";
    Console::SetCursorPosition(25, 5); cout << "se da inicio a la segunda fase del juego, donde los jugadores podran mover";
    Console::SetCursorPosition(26, 6); cout << "sus fichas de casilla. Se te indicara las coordenada de la ficha a mover";
    Console::SetCursorPosition(31, 7); cout << "Si desea seleccionar otra ficha use la tecla de flecha derecha";
    Console::SetCursorPosition(27, 8); cout << "Caso contrario para moverla de lugar debe usar la tecla de flecha abajo";
    Console::SetCursorPosition(20, 9); cout << "Luego con cualquiera de las teclas direccionales (arriba, abajo, izquierda y derecha)";
    Console::SetCursorPosition(36, 10); cout << "podra mover su ficha a una casilla adyacente vacia,";
    Console::SetCursorPosition(29, 11); cout << "si la casilla esta ocupada tendra que moverla a otra casilla libre";
    Console::SetCursorPosition(26, 14); cout << "Ejemplo:" << endl;
    Console::SetCursorPosition(26, 16); cout << "Jugador 1:" << endl;
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(36, 16); cout << " X ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(26, 17); cout << "Jugador 2:" << endl;
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(36, 17); cout << " Y ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(26, 18); cout << "Posicion original de la ficha:" << endl;
    Console::ForegroundColor = ConsoleColor::DarkYellow;
    Console::SetCursorPosition(56, 18); cout << " X ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(26, 19); cout << "Ficha movida:" << endl;
    Console::ForegroundColor = ConsoleColor::Blue;
    Console::SetCursorPosition(39, 19); cout << " X ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(64, 13); cout << "  - - - -   - - - -  ";
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(63, 13); cout << " X ";
    Console::SetCursorPosition(73, 13); cout << " X ";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(83, 13); cout << " Y ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(64, 14); cout << "|         |         |";
    Console::SetCursorPosition(64, 15); cout << "|     - -   - -     |";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(67, 15); cout << " Y ";
    Console::ForegroundColor = ConsoleColor::DarkYellow;
    Console::SetCursorPosition(73, 15); cout << " X ";
    Console::ForegroundColor = ConsoleColor::Blue;
    Console::SetCursorPosition(79, 15); cout << " X ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(64, 16); cout << "|   |     |     |   |";
    Console::SetCursorPosition(64, 17); cout << "|   |   O O     |   |";
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(75, 17); cout << " X ";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(71, 17); cout << " Y ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(64, 18); cout << "  -   -     O -   -  ";
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(83, 18); cout << " X ";
    Console::SetCursorPosition(71, 18); cout << " X ";
    Console::SetCursorPosition(63, 18); cout << " X ";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(79, 18); cout << " Y ";
    Console::SetCursorPosition(75, 18); cout << " Y ";
    Console::SetCursorPosition(67, 18); cout << " Y ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(64, 19); cout << "|   |   O   O   |   |";
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(73, 19); cout << " X ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(64, 20); cout << "|   |     |     |   |";
    Console::SetCursorPosition(64, 21); cout << "|   O - -   - - O   |";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(73, 21); cout << " Y ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(64, 22); cout << "|         |         |";
    Console::SetCursorPosition(64, 23); cout << "O - - - - O - - - -  ";
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(83, 23); cout << " X ";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(63, 23); cout << " Y ";
    Console::SetCursorPosition(73, 23); cout << " Y ";
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::SetCursorPosition(40, 25); cout << "Presione cualquier tecla para continuar" << endl;
    _getch();
    Console::Clear();

    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::SetCursorPosition(47, 8); cout << "Instrucciones del juego" << endl;
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(24, 12); cout << "Cuando a un jugador solo le quede 3 fichas puede realizar el vuelo,";
    Console::SetCursorPosition(20, 13); cout << "en otras palabras, puede mover su ficha a cualquier posicion vacia del tablero";
    Console::SetCursorPosition(20, 15); cout << "El juego culmina cuando un jugador queda con solo 2 fichas sobre el tablero y";
    Console::SetCursorPosition(38, 16); cout << "el otro automaticamente gana la partida";
}

void GraficadorDelTablero(char** tablero)
{
    int* x = new int;
    int* y = new int;
    int* i = new int;
    int* j = new int;
    *x = 3;
    *y = 50;

    for (*i = 1; *i < *x; *i += 1) {
        cout << endl;
    }
    for (int i = 0; i < 11; i++)
    {
        for (*j = 1; *j < *y; *j += 1) {
            cout << " ";
        }
        for (int j = 0; j < 11; j++)
        {
            cout << tablero[i][j] << " ";
        }
        cout << "  " << i + 1;
        cout << endl;
    }
    cout << endl;
    cout << "                                                 1 2 3 4 5 6 7 8 9 10 11 " << endl;
    delete[]x;
    delete[]y;
    delete[]i;
    delete[]j;
}


struct Jugador
{
    char nombre[15];
    char Tipoficha;
    int numerofichas = 3;

}jugador1, jugador2;

int ContadorDeFichas(char** posiciones, char TipoF)
{
    int cont = 0;

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (posiciones[i][j] == TipoF) {
                cont++;
            }
        }
    }
    return cont;
}


void ganadorjuego(char** posiciones, char* nombre1, char* nombre2, char tipoF1, char tipoF2) {

    int contB = 0;
    int contN = 0;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (posiciones[i][j] == 'B') {
                contB++;
            }
            if (posiciones[i][j] == 'N') {
                contN++;
            }
        }
    }

    //Si queda 2 fichas ese jugador pierde y por lo tanto el otro gana
    if (tipoF1 == 'B') {
        if (contB == 2) {
            Console::SetCursorPosition(54, 12); cout << jugador2.nombre << endl;
        }
    }
    if (tipoF2 == 'N') {
        if (contN == 2) {
            Console::SetCursorPosition(54, 13); cout << jugador1.nombre << endl;
        }
    }

    if (tipoF2 == 'B') {
        if (contB == 2) {
            Console::SetCursorPosition(54, 12); cout << jugador1.nombre << endl;
        }
    }
    if (tipoF1 == 'N') {
        if (contN == 2) {
            Console::SetCursorPosition(54, 13); cout << jugador2.nombre << endl;
        }
    }
}

void bannerganador(char** posiciones, char* nombre1, char* nombre2, char tipoF1, char tipoF2) {
    Console::ForegroundColor = ConsoleColor::DarkYellow;
    std::cout << R"( 
    

                             _______      ___      .__   __.      ___       _______    ______   .______      
                            /  _____|    /   \     |  \ |  |     /   \     |       \  /  __  \  |   _  \     
                           |  |  __     /  ^  \    |   \|  |    /  ^  \    |  .--.  ||  |  |  | |  |_)  |    
                           |  | |_ |   /  /_\  \   |  . `  |   /  /_\  \   |  |  |  ||  |  |  | |      /     
                           |  |__| |  /  _____  \  |  |\   |  /  _____  \  |  '--'  ||  `--'  | |  |\  \----.
                            \______| /__/     \__\ |__| \__| /__/     \__\ |_______/  \______/  | _| `._____|
                                                                                 
    )" << '\n';

    Console::ForegroundColor = ConsoleColor::White;
    ganadorjuego(posiciones, nombre1, nombre2, tipoF1, tipoF2);
}

int aleatorio(int limite_inferior, int limite_superior)
{
    int numero;
    numero = limite_inferior + rand() % (limite_superior + 1 - limite_inferior);
    return numero;
}


int a¡ = 0; int b¡ = 0; int c¡ = 0; int d¡ = 0; int e¡ = 0; int f¡ = 0;
int g¡ = 0; int h¡ = 0; int i¡ = 0; int j¡ = 0; int k¡ = 0; int l¡ = 0;
int m¡ = 0; int n¡ = 0; int p¡ = 0; int q¡ = 0; int r¡ = 0; int s¡ = 0;
int t¡ = 0; int v¡ = 0; int w¡ = 0; int x¡ = 0;

bool ValidadorMolino(char** posiciones, char tipoF1)
{
    if ((posiciones[0][0] == tipoF1) && (posiciones[0][5] == tipoF1) && (posiciones[0][10] == tipoF1) && r¡==0 )
    {
        r¡++;
        return true;
    }
    if ((posiciones[2][2] == tipoF1) && (posiciones[2][5] == tipoF1) && (posiciones[2][8] == tipoF1) && s¡ == 0)
    {
        s¡++;
        return true;
    }
    if ((posiciones[5][0] == tipoF1) && (posiciones[5][2] == tipoF1) && (posiciones[5][41] == tipoF1) && t¡ == 0)
    {
        t¡++;
        return true;
    }
    if ((posiciones[5][6] == tipoF1) && (posiciones[5][8] == tipoF1) && (posiciones[5][10] == tipoF1) && v¡ == 0)
    {
        v¡++;
        return true; 
    }
    if ((posiciones[8][2] == tipoF1) && (posiciones[8][5] == tipoF1) && (posiciones[8][8] == tipoF1) && x¡ == 0)
    {
        x¡++;
        return true;
    }
    if ((posiciones[10][0] == tipoF1) && (posiciones[10][5] == tipoF1) && (posiciones[10][10] == tipoF1) && w¡ == 0)
    {
        w¡++;
        return true;
    }
    //Camila
    if ((posiciones[0][0] == tipoF1) && (posiciones[5][0] == tipoF1) && (posiciones[10][0] == tipoF1) && a¡ == 0)
    {
        a¡++;
        return true;
    }
    if ((posiciones[2][2] == tipoF1) && (posiciones[5][2] == tipoF1) && (posiciones[8][2] == tipoF1) && b¡ == 0)
    {
        b¡++;
        return true;
    }
    if ((posiciones[4][4] == tipoF1) && (posiciones[5][4] == tipoF1) && (posiciones[6][4] == tipoF1) && c¡ == 0)
    {
        c¡++;
        return true;
    }
    if ((posiciones[0][5] == tipoF1) && (posiciones[2][5] == tipoF1) && (posiciones[4][5] == tipoF1) && d¡ == 0)
    {
        d¡++;
        return true;
    }
    if ((posiciones[6][5] == tipoF1) && (posiciones[8][5] == tipoF1) && (posiciones[10][5] == tipoF1) && e¡ == 0)
    {
        e¡++;
        return true;
    }
    if ((posiciones[4][6] == tipoF1) && (posiciones[5][6] == tipoF1) && (posiciones[6][6] == tipoF1) && f¡ == 0)
    {
        f¡++;
        return true;
    }
    if ((posiciones[2][8] == tipoF1) && (posiciones[5][8] == tipoF1) && (posiciones[8][8] == tipoF1) && g¡ == 0)
    {
        g¡++;
        return true;
    }
    if ((posiciones[0][10] == tipoF1) && (posiciones[5][10] == tipoF1) && (posiciones[10][10] == tipoF1) && h¡ == 0)
    {
        h¡++;
        return true;
    }
    //Miguel
    if ((posiciones[0][5] == tipoF1) && (posiciones[2][5] == tipoF1) && (posiciones[4][5] == tipoF1) && i¡ == 0)
    {
        i¡++;
        return true;
    }
    if ((posiciones[0][10] == tipoF1) && (posiciones[2][8] == tipoF1) && (posiciones[4][6] == tipoF1) && j¡ == 0)
    {
        j¡++;
        return true;
    }
    if ((posiciones[5][6] == tipoF1) && (posiciones[5][8] == tipoF1) && (posiciones[5][10] == tipoF1) && k¡ == 0)
    {        
        k¡++;
        return true;
    }
    if ((posiciones[6][6] == tipoF1) && (posiciones[8][8] == tipoF1) && (posiciones[10][10] == tipoF1) && l¡ == 0)
    {
        l¡++;
        return true;
    }
    if ((posiciones[6][5] == tipoF1) && (posiciones[8][5] == tipoF1) && (posiciones[10][5] == tipoF1) && m¡ == 0)
    {
       m¡++;
       return true;
    }
    if ((posiciones[6][4] == tipoF1) && (posiciones[8][2] == tipoF1) && (posiciones[10][0] == tipoF1) && n¡ == 0)
    {
        n¡++;
       return true;
    }
    if ((posiciones[5][0] == tipoF1) && (posiciones[5][2] == tipoF1) && (posiciones[5][4] == tipoF1) && p¡ == 0)
    {
        p¡++;
        return true;
    }
    if ((posiciones[0][0] == tipoF1) && (posiciones[2][2] == tipoF1) && (posiciones[4][4] == tipoF1) && q¡ == 0 )
    {
        q¡++;
        return true;
       
    }
    return false;
}

char** borradorfichas(char** posiciones, char fichaenemiga)
{
    int B;
    while (true)
    {
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (posiciones[i][j] == fichaenemiga)
                {
                    cout << endl;
                    cout << "Puedes borrar la ficha de tu oponente, que se encuentras en la ubicacion [" << i + 1 << "][" << j + 1 << "]" << endl;
                    cout << "Si deseas borrar en otra posicion, pulsa la tecla DERECHA" << endl;
                    cout << "De lo contrario pulsa ABAJO para borrar en esta posicion" << endl;
                    do
                    {
                        B = getch();
                    } while (B != 77 && B != 80);


                    if (B == DERECHA)
                    {
                        system("cls");
                        cout << endl;
                        cout << endl;
                        GraficadorDelTablero(posiciones);
                        cout << endl;
                        continue;
                    }
                    if (B == ABAJO)
                    {
                        posiciones[i][j] = 'O';
                        return posiciones;

                    }
                }
            }
        }
    }
}


char elotro(char a) {
    if (a == 'B') {
        return 'N';
    }
    else {
        return 'B';
    }
}



bool valimovificha(char** pociosiones, int i, int j, char tipoF) {
    int B;
    int xd = 1;
    char xd1 = elotro(tipoF);
    cout << xd1;
    cout << "Ha seleccionado la ficha" << " [" << i + 1 << "][" << j + 1 << "] ";
    do
    {
        B = getch();
    } while (B != DERECHA && B != IZQUIERDA && B != ABAJO && B != ARRIBA);
    if (B == ABAJO) {
        for (int a = 0; a <= 10 - i; a++) {
            if (pociosiones[a + i][j] == 'O') {
                pociosiones[a + i][j] = tipoF;
                pociosiones[i][j] = 'O';
                system("cls");
                cout << endl;
                cout << endl;
                GraficadorDelTablero(pociosiones);
                cout << endl;
                return true;
            }
            if (pociosiones[a + i][j] == xd1 && tipoF) {
                return false;
            }
        }
        return false;
    }
    if (B == ARRIBA) {
        for (int a = 0; a <= i; a++) {
            if (pociosiones[i - a][j] == 'O') {
                pociosiones[i - a][j] = tipoF;
                pociosiones[i][j] = 'O';
                system("cls");
                cout << endl;
                cout << endl;
                GraficadorDelTablero(pociosiones);
                cout << endl;
                return true;
            }
            if (pociosiones[i - a][j] == xd1 && tipoF) {
                return false;
            }
        }
        return false;
    }
    if (B == DERECHA) {
        for (int a = 0; a <= 10 - j; a++) {
            if (pociosiones[i][j + a] == 'O')
            {
                pociosiones[i][j + a] = tipoF;
                pociosiones[i][j] = 'O';
                system("cls");
                cout << endl;
                cout << endl;
                GraficadorDelTablero(pociosiones);
                cout << endl;
                return true;
            }
            if (pociosiones[i][j + a] == xd1 && tipoF) {
                return false;
            }
        }
        return false;
    }
    if (B == IZQUIERDA) {
        for (int a = 0; a <= 10; a++) {
            if (pociosiones[i][j - a] == 'O') {
                pociosiones[i][j - a] = tipoF;
                pociosiones[i][j] = 'O';
                system("cls");
                cout << endl;
                cout << endl;
                GraficadorDelTablero(pociosiones);
                cout << endl;
                return true;
            }
            if (pociosiones[i][j - a] == xd1 && tipoF) {
                return false;
            }
        }
        return false;
    }
}

int FuncionVuelo(char** posiciones, char tipoF, char* nombre)
{
    int A, B, C;
    while (true)
    {
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (posiciones[i][j] == tipoF)
                {
                    cout << "Estas en la posicion [ " << i + 1 << " ][ " << j + 1 << " ]" << endl << endl;
                    cout << "Si deseas avanzar a la siguente posicion pulsa la tecla DERECHA " << endl;
                    cout << "De lo contrario presiona la tecla ABAJO para seleccionar esta ficha, que luego se movera " << endl;
                    do
                    {
                        A = getch();
                    } while (A != 77 && A != 80);

                    if (A == DERECHA)
                    {
                        system("cls");
                        cout << endl;
                        cout << endl;
                        GraficadorDelTablero(posiciones);
                        cout << endl;
                    }
                    if (A == ABAJO)
                    {
                        posiciones[i][j] = 'O';
                        while (true)
                        {
                            for (int i = 0; i < 11; i++)
                            {
                                for (int j = 0; j < 11; j++)
                                {
                                    if
                                        (
                                            (i == 0 && j == 0) || (i == 0 && j == 5) || (i == 0 && j == 10) || (i == 2 && j == 2) || (i == 2 && j == 5) || (i == 2 && j == 8) ||
                                            (i == 4 && j == 4) || (i == 4 && j == 5) || (i == 4 && j == 6) || (i == 5 && j == 0) || (i == 5 && j == 2) || (i == 5 && j == 4) ||
                                            (i == 5 && j == 6) || (i == 5 && j == 8) || (i == 5 && j == 10) || (i == 6 && j == 4) || (i == 6 && j == 5) || (i == 6 && j == 6) ||
                                            (i == 8 && j == 2) || (i == 8 && j == 5) || (i == 8 && j == 8) || (i == 10 && j == 0) || (i == 10 && j == 5) || (i == 10 && j == 10)
                                            )
                                    {
                                        if (posiciones[i][j] == 'O')
                                        {
                                            cout << "Estas en la posicion [ " << i + 1 << " ][ " << j + 1 << " ]" << endl << endl;
                                            cout << "Si deseas avanzar a la siguente posicion pulsa la tecla DERECHA " << endl;
                                            cout << "De lo contrario presiona la tecla ABAJO para colocar tu ficha " << endl;
                                            do
                                            {
                                                C = getch();
                                            } while (C != 77 && C != 80);

                                            if (C == DERECHA)
                                            {
                                                system("cls");
                                                cout << endl;
                                                cout << endl;
                                                GraficadorDelTablero(posiciones);
                                                cout << endl;
                                            }
                                            if (C == ABAJO)
                                            {
                                                cout << endl;
                                                cout << endl;
                                                posiciones[i][j] = tipoF;
                                                system("cls");
                                                cout << endl;
                                                cout << endl;
                                                GraficadorDelTablero(posiciones);
                                                cout << endl;
                                                if (ValidadorMolino(posiciones, tipoF) == true) {
                                                    //voidsacadordeficha
                                                    if (tipoF == 'B') {
                                                        borradorfichas(posiciones, 'N');
                                                    }
                                                    else {
                                                        borradorfichas(posiciones, 'B');
                                                    }
                                                }
                                                return 0;
                                            }

                                        }
                                        system("cls");
                                        cout << endl;
                                        cout << endl;
                                        GraficadorDelTablero(posiciones);
                                        cout << endl;
                                    }
                                }
                            }
                        }

                    }
                    continue;
                }
            }
        }
    }
}
bool sipuedesmoveresta(char** pociosiones, int i, int j, char tipoF) {
    int B;
    int xd = 1;
    char xd1 = elotro(tipoF);
    cout << xd1;
    cout << "Ha seleccionado la ficha" << " [" << i + 1 << "][" << j + 1 << "] ";
    for (int a = 0; a <= 10 - i; a++) {
        if (pociosiones[a + i][j] == 'O') {
            return true;
        }
        if (pociosiones[a + i][j] == xd1 && tipoF) {
            break;
        }
    }
    for (int a = 0; a <= i; a++) {
        if (pociosiones[i - a][j] == 'O') {
            return true;
        }
        if (pociosiones[i - a][j] == xd1 && tipoF) {
            break;
        }
    }
    for (int a = 0; a <= 10 - j; a++) {
        if (pociosiones[i][j + a] == 'O') {
            return true;
        }
        if (pociosiones[i][j + a] == xd1 && tipoF) {
            break;
        }
    }
    for (int a = 0; a <= 10; a++) {
        if (pociosiones[i][j - a] == 'O') {
            return true;
        }
        if (pociosiones[i][j - a] == xd1 && tipoF) {
            break;
        }
    }
    return false;
}
int MoverFichas(char** posiciones, char tipoF, char* nombre, char* nombre1, char* nombre2, char tipoF1, char tipoF2)
{
    int C;
    while (true)
    {
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (posiciones[i][j] == tipoF)
                {
                    if (ContadorDeFichas(posiciones, tipoF) > 3)
                    {
                        cout << "Es el turno de " << nombre << " y su color de ficha es  " << tipoF << endl;
                        cout << "Estas en la posicion [" << i + 1 << "][" << j + 1 << "]" << endl;
                        cout << "Si deseas mover esta ficha, presione la tecla ABAJO" << endl;
                        cout << "De lo contrario presione la tecla DERECHA para seleccionar otra ficha" << endl;
                        do
                        {
                            C = getch();
                        } while (C != 77 && C != 80);
                        if (sipuedesmoveresta(posiciones, i, j, tipoF) == true) {
                            if (C == ABAJO)
                            {
                                bool a = true;
                                do {
                                    if (valimovificha(posiciones, i, j, tipoF) == true)
                                    {
                                        a = false;
                                        break;
                                    }
                                } while (a == true);
                                system("cls");
                                cout << endl;
                                cout << endl;
                                GraficadorDelTablero(posiciones);
                                cout << endl;
                                if (ValidadorMolino(posiciones, tipoF) == true)
                                {
                                    //voidsacadordeficha
                                    if (tipoF == 'B')
                                    {
                                        borradorfichas(posiciones, 'N');
                                    }
                                    else
                                    {
                                        borradorfichas(posiciones, 'B');
                                    }
                                }
                                return 0;
                            }
                        }
                        else {
                            system("cls");
                            cout << endl;
                            cout << endl;
                            cout << "No puedes mover esta ficha.";
                            GraficadorDelTablero(posiciones);
                            cout << endl;
                        }
                        if (C == DERECHA)
                        {
                            system("cls");
                            cout << endl;
                            cout << endl;
                            GraficadorDelTablero(posiciones);
                            cout << endl;
                            continue;
                        }
                        
                    }
                    if (ContadorDeFichas(posiciones, tipoF) == 3)
                    {
                        FuncionVuelo(posiciones, tipoF, nombre);
                        return 0;
                    }
                    if (ContadorDeFichas(posiciones, tipoF) == 2)
                    {
                        system("cls");
                        cout << endl; cout << endl;
                        bannerganador(posiciones, nombre1, nombre2, tipoF1, tipoF2);
                        _getch();
                        return -1;



                    }


                }
            }
        }
    }
}


int PosicionesValidas(char** posiciones, char* nombre, char tipoF, int cantfichas, char* nombre1, char* nombre2, char tipoF1, char tipoF2)
{
    cout << "Es el turno de " << nombre << "; su color de ficha es  " << tipoF << endl;
    cout << "Y aun le queda " << cantfichas << " fichas" << endl;
    GraficadorDelTablero(posiciones);
    int A;
    while (true)
    {
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if
                    (
                        (i == 0 && j == 0) || (i == 0 && j == 5) || (i == 0 && j == 10) || (i == 2 && j == 2) || (i == 2 && j == 5) || (i == 2 && j == 8) ||
                        (i == 4 && j == 4) || (i == 4 && j == 5) || (i == 4 && j == 6) || (i == 5 && j == 0) || (i == 5 && j == 2) || (i == 5 && j == 4) ||
                        (i == 5 && j == 6) || (i == 5 && j == 8) || (i == 5 && j == 10) || (i == 6 && j == 4) || (i == 6 && j == 5) || (i == 6 && j == 6) ||
                        (i == 8 && j == 2) || (i == 8 && j == 5) || (i == 8 && j == 8) || (i == 10 && j == 0) || (i == 10 && j == 5) || (i == 10 && j == 10)
                        )
                {
                    if (posiciones[i][j] == 'O')
                    {
                        if (cantfichas > 0)
                        {
                            cout << "Estas en la posicion [ " << i + 1 << " ][ " << j + 1 << " ]" << endl << endl;
                            cout << "Si deseas avanzar a la siguente posicion pulsa la tecla DERECHA " << endl;
                            cout << "De lo contrario presiona la tecla ABAJO para colocar tu ficha " << endl;
                            do
                            {
                                A = getch();
                            } while (A != 77 && A != 80);

                            if (A == DERECHA)
                            {
                                system("cls");
                                cout << endl;
                                cout << endl;
                                GraficadorDelTablero(posiciones);
                                cout << endl;
                            }
                            if (A == ABAJO && cantfichas <= 3)
                            {
                                cout << endl;
                                cout << endl;
                                cantfichas = cantfichas - 1;
                                posiciones[i][j] = tipoF;
                                system("cls");
                                cout << endl;
                                cout << endl;
                                GraficadorDelTablero(posiciones);
                                cout << endl;
                                if (ValidadorMolino(posiciones, tipoF) == true) {
                                    //voidsacadordeficha
                                    if (tipoF == 'B') {
                                        borradorfichas(posiciones, 'N');
                                    }
                                    else {
                                        borradorfichas(posiciones, 'B');
                                    }
                                }
                                return cantfichas;
                            }
                        }
                        else
                        {
                            cantfichas = MoverFichas(posiciones, tipoF, nombre, nombre1, nombre2, tipoF1, tipoF2);
                            return cantfichas;
                        }

                    }
                    system("cls");
                    cout << endl;
                    cout << "Es el turno de " << nombre << "; su color de ficha es  " << tipoF << endl;
                    cout << "Y aun le queda " << cantfichas << " fichas" << endl;
                    cout << endl;
                    GraficadorDelTablero(posiciones);
                    cout << endl;
                }
            }
        }
    }
}

void Turnos(char** posiciones, char* nombre1, char tipoF1, char* nombre2, char tipoF2, int turno1, int turno2)
{
    int turn1 = turno1;
    int turn2 = turno2;

    for (int i = 0; i < 100000; i++)
    {
        if (i % 2 == 0)
        {
            system("cls");
            turn1 = PosicionesValidas(posiciones, nombre1, tipoF1, turn1, nombre1, nombre2, tipoF1, tipoF2);
        }
        else
        {
            system("cls");
            turn2 = PosicionesValidas(posiciones, nombre2, tipoF2, turn2, nombre1, nombre2, tipoF1, tipoF2);
        }
        if (turn2 == -1 || turn1 == -1)
        {
            break;
        }
    }
}





int main()
{
    srand(time(NULL));

    char** TableroReal = new char* [11];
    for (int i = 0; i < 11; ++i)
        TableroReal[i] = new char[11];

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            TableroReal[i][j] = posiciones[i][j];
        }
    }



    int turnoasd;
    int opcion;
    char boton;
    char** jugadores = new char* [2];
    presentacion();
    while (true) {
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(42, 5); cout << "Bienvenido al Juego del Molino";
        cout << endl;
        menu();
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(47, 18); cout << "Ingrese una opcion" << endl;
        Console::ForegroundColor = ConsoleColor::White;
        cin >> opcion;
        switch (opcion) {
        case 1:
            system("cls");
            Console::ForegroundColor = ConsoleColor::Cyan;
            Console::SetCursorPosition(47, 4); cout << "Instrucciones del juego" << endl;
            instrucciones();
            break;
        case 2:
            system("cls");
            cout << endl << endl;

            for (int i = 0; i < 2; ++i)
            {
                jugadores[i] = new char[15];
            }

            Console::ForegroundColor = ConsoleColor::Blue;
            Console::SetCursorPosition(43, 5); cout << "Ingrese el nombre del jugador 1: " << endl;
            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(54, 7); cin >> jugador1.nombre;
            cout << endl << endl << endl << endl;
            Console::ForegroundColor = ConsoleColor::Blue;
            Console::SetCursorPosition(43, 15); cout << "Ingrese el nombre del jugador 2:" << endl;
            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(54, 17); cin >> jugador2.nombre;

            cout << endl << endl;

            system("cls");
            cout << endl;
            Console::ForegroundColor = ConsoleColor::White;
            cout << jugador1.nombre << " y " << jugador2.nombre << endl;

            cout << endl;

            cout << "Este sera su tablero: " << endl;
            GraficadorDelTablero(TableroReal);
            cout << endl;
            cout << endl;
            do
            {
                cout << "Para iniciar el juego introduzca la letra X, si desea abandonar la partida presione N" << endl;
                cin >> boton;
                boton = toupper(boton);
            } while (boton != 'X' && boton != 'N');

            if (boton == 'X')
            {
                system("cls");
                cout << endl;
                cout << endl;

                cout << endl;
                cout << endl;
                //PosicionesValidas(TableroReal
                system("cls");
                cout << endl;
                cout << endl;
                turnoasd = aleatorio(1, 2);
                Console::SetCursorPosition(25, 7); cout << "Mediante un dado de valor 2 se decidira los turnos de los jugadores" << endl;
                Sleep(500);
                Console::SetCursorPosition(44, 10); cout << "Generando valor aleatorio ..." << endl;
                Sleep(1000);
                Console::SetCursorPosition(10, 13); cout << "El dado se detuvo en el valor " << turnoasd << ", por lo tanto ese sera el numero de jugador que dara inicio a la partida" << endl;
                Sleep(1000);
                Console::ForegroundColor = ConsoleColor::Yellow;
                Console::SetCursorPosition(39, 25); cout << "Presione cualquier tecla para continuar" << endl;
                getch();
                system("cls");
                Console::ForegroundColor = ConsoleColor::White;
                cout << endl;
                cout << endl;
                if (turnoasd == 1) {
                    //jugador 1 empieza y tiene fichas blancas, osea j2 tiene fichas negras
                    jugador1.Tipoficha = 'B';
                    jugador2.Tipoficha = 'N';
                    if (jugador1.numerofichas == -1 || jugador2.numerofichas == -1)
                    {
                        for (int i = 0; i < 11; i++)
                        {
                            for (int j = 0; j < 11; j++)
                            {
                                if (TableroReal[i][j] == 'B' || TableroReal[i][j] == 'N')
                                {
                                    TableroReal[i][j] = 'O';
                                }
                            }
                        }
                        break;
                    }
                    Turnos(TableroReal, jugador1.nombre, jugador1.Tipoficha, jugador2.nombre, jugador2.Tipoficha, jugador1.numerofichas, jugador2.numerofichas);

                }
                if (turnoasd == 2) {
                    //jugador 2 empieza, osea tiene fichas blancas, osea j1 tiene fichas negras.
                    jugador2.Tipoficha = 'B';
                    jugador1.Tipoficha = 'N';
                    if (jugador1.numerofichas == -1 || jugador2.numerofichas == -1)
                    {
                        for (int i = 0; i < 11; i++)
                        {
                            for (int j = 0; j < 11; j++)
                            {
                                if (TableroReal[i][j] == 'B' || TableroReal[i][j] == 'N')
                                {
                                    TableroReal[i][j] = 'O';
                                }
                            }
                        }
                        break;
                    }
                    Turnos(TableroReal, jugador2.nombre, jugador2.Tipoficha, jugador1.nombre, jugador1.Tipoficha, jugador1.numerofichas, jugador2.numerofichas);
                }



            }
            else
            {
                system("cls");
                continue;
            }

            break;
        case 3: exit(0);
            break;
        default:
            Console::ForegroundColor = ConsoleColor::Red;
            Console::SetCursorPosition(47, 22); cout << "Error en la opcion" << endl;
            break;
        }
        Console::ForegroundColor = ConsoleColor::Yellow;
        cout << endl;
        Console::SetCursorPosition(35, 25); cout << "Presione cualquier tecla para volver al menu" << endl;
        Console::ForegroundColor = ConsoleColor::White;
        _getch();
        Console::Clear();
    }
    return 0;

}