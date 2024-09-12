#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// Función que será ejecutada por el hilo creado
void *thread_function(void *arg) {
    printf("Hilo creado con PID: %d, TID: %ld\n", getpid(), pthread_self());
    return NULL;
}

int main() {
    pid_t pid;
    
    // Primer fork
    pid = fork();  

    if (pid == 0) {  // Proceso hijo
        fork();  // Segundo fork dentro del proceso hijo
        
        pthread_t thread_id;
        // Crear un hilo dentro del proceso hijo
        pthread_create(&thread_id, NULL, thread_function, NULL);
        pthread_join(thread_id, NULL);  // Esperar a que el hilo termine
    }

    // Tercer fork en ambos procesos (padre e hijo)
    fork();  

    // Mantener el programa en ejecución por unos segundos para observar los procesos/hilos
    sleep(2);

    return 0;
}
