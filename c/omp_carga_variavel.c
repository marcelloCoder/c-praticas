#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void trabalho_simulado(int i) {
    volatile int j;
    for (j = 0; j < 1000 * (i % 10 + 1); j++);
}

int main() {
    int n = 100;
    double inicio, fim;
    omp_set_num_threads(16);  // Ajuste conforme seu processador

    const char* politicas[] = {"static", "dynamic", "guided"};
    omp_sched_t tipos_sched[] = {omp_sched_static, omp_sched_dynamic, omp_sched_guided};
    int chunk = 1; // Tamanho do chunk
	int modo, i;

    for (modo = 0; modo < 3; modo++) {
        // Define a política em tempo de execução
        omp_set_schedule(tipos_sched[modo], chunk);

        printf("Agendamento: %s\n", politicas[modo]);

        inicio = omp_get_wtime();

        #pragma omp parallel for schedule(runtime)
        for (i = 0; i < n; i++) {
            trabalho_simulado(i);
        }

        fim = omp_get_wtime();
        printf("Tempo de execucao: %.6f segundos\n\n", fim - inicio);
    }

    return 0;
}

