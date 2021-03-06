#include <stdio.h>
#include <stdlib.h>

/*
    INSTRUCCIONES

    LOAD 'val'      Carga el acumulador con 'val'
    ADD  'val'      Suma 'val' al acumulador
    SUB  'val'      Resta 'val' al acumulador
    MUL  'val'      Multiplica 'val' por acumulador
    DIV  'val'      Divide 'val' por acumulador
    PRINT           Imprime el contenido de acumulador
    JNZ  'dir'      Salta a a 'dir' si el acumulador es distinto de 0
    JMP  'dir'      Salta a 'dir'
    JSR  'dir'      Salta a una subrutina que empieza en 'dir'
    RET             Vuelve de una subrutina
    STOP            Detiene la ejecucion
    AND  'val'      Realiza un AND logico con el acumulador y 'val'
    OR   'val'      Realiza un OR logico con el acumulador y 'val'
    NOT  'val'      Realiza un NOT logico con el acumulador y 'val'
    XOR  'val'      Realiza un XOR logico al acumulador y 'val'
*/

    //Conjunto de instrucciones
    enum iset {LOAD, ADD, SUB, MUL, DIV, PRINT, JNZ, JMP, JSR, RET, STOP, AND, OR, NOT, XOR};

    //Cargar el programa en memoria
    int mem[256] = {LOAD,
                    0,
                    AND,
                    0,
                    PRINT,
                    STOP,
                    RET};

    int acc; //Acumulador

void ejecutar(int pc);

int main()
{
    ejecutar(0); //Comienza la ejecuccion en la direccion de memoria 0
    return(0);
}

void ejecutar(int pc)
{
    int ip;     //Contador de instrucciones
    int inst;   //Instruccion
    int iop;    //Operando de instruccion;

    ip = pc;
    do
    {
        inst = mem[ip++];   //Lectura de instruccion
        iop = mem[ip++];    //Lectura operando
        switch(inst)
        {
            case LOAD : acc = iop; break;
            case ADD :  acc += iop; break;
            case SUB :  acc -= iop; break;
            case MUL :  acc *= iop; break;
            case DIV :  acc /= iop; break;
            case PRINT :
            {
                printf("Acumulador = %5d\n", acc);
                ip--;
                break;
            }
            case JNZ : ip = (acc != 0) ? iop : ip; break;
            case JMP : ip = iop; break;
            case JSR : ejecutar(iop); break;
            case RET : return; break;
            case STOP: break;
            case AND : acc = acc & iop; break;
            case OR  : acc = acc | iop; break;
            case NOT : acc = !iop; break;
            case XOR : acc = acc ^ iop; break;
        }
    } while(inst != STOP);
}

/** MiniMicro del libro **\

#include <stdio.h>
#include <stdlib.h>

    //Conjunto de instrucciones
    enum iset {LOAD, ADD, SUB, MUL, DIV, PRINT, JNZ, JMP, JSR, RET, STOP};

    //Cargar el programa en memoria
    int mem[256] = {LOAD,
                    100,
                    JSR,
                    6,
                    PRINT,
                    STOP,
                    MUL,
                    9,
                    DIV,
                    5,
                    ADD,
                    32,
                    RET};

    int acc; //Acumulador

void ejecutar(int pc);

int main()
{
    ejecutar(0); //Comienza la ejecuccion en la direccion de memoria 0
    return(0);
}

void ejecutar(int pc)
{
    int ip;     //Contador de instrucciones
    int inst;   //Instruccion
    int iop;    //Operando de instruccion;

    ip = pc;
    do
    {
        inst = mem[ip++];   //Lectura de instruccion
        iop = mem[ip++];    //Lectura operando
        switch(inst)
        {
            case LOAD : acc = iop; break;
            case ADD :  acc += iop; break;
            case SUB :  acc -= iop; break;
            case MUL :  acc *= iop; break;
            case DIV :  acc /= iop; break;
            case PRINT :
            {
                printf("Acumulador = %5d\n", acc);
                ip--;
                break;
            }
            case JNZ : ip = (acc != 0) ? iop : ip; break;
            case JMP : ip = iop; break;
            case JSR : ejecutar(iop); break;
            case RET : return; break;
            case STOP : break;
        }
    } while(inst != STOP);
}
*/
