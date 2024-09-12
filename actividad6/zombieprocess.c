#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Se debe de crear un proceso hijo; pid = process_id

    if (pid < 0) {
        // Existe un error al crear el proceso
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Código del proceso hijo
        printf("Se ha creado un proceso hijo con un PID: %d\n", getpid());
        exit(0);  // Terminar el proceso hijo para convertirlo en zombie
    }
    else {
        // Código del proceso padre
        printf("El proceso padre tiene un PID: %d\n", getpid());
        printf("El proceso hijo con PID: %d ahora se convertirá en un proceso zombie.\n", pid);
        printf("Durante 60 segundos...");
        
        // Realizar una pausa de 60 segundos para mantener al proceso hijo como zombie
        sleep(60);

        // Luego de 60 segundos, el proceso padre espera al hijo, eliminando el zombie
        wait(NULL);
        printf("Ha terminado el tiempo para el proceso Zombie y Este ha sido eliminado.\n");
    }

    return 0;
}



