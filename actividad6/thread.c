

main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        fork();
        thread_create(. . .);
    }

    fork();
}

