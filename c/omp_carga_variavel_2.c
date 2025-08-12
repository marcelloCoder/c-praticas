#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

// AUMENTEI A CARGA PARA TORNAR O OVERHEAD MENOS RELEVANTE
#define NUM_TASKS 1000
#define HEAVY_TASK_COUNT 1000
#define HEAVY_FACTOR 1000      // Aumentei o desbalanceamento
#define BASE_WORK_UNITS 5000 // Aumentei o trabalho base

void perform_work(int task_id) {
    long long work_units = BASE_WORK_UNITS;
    long long i;
    if (task_id < HEAVY_TASK_COUNT) {
        work_units *= HEAVY_FACTOR;
    }
    volatile double dummy_sum = 0.0;
    for (i = 0; i < work_units; ++i) {
        dummy_sum += sin((double)i) * cos((double)i);
    }
}

int main() {
    printf("Iniciando simulação ROBUSTA com carga de trabalho desbalanceada.\n");
    // É crucial saber com quantos threads estamos trabalhando
    printf("Número de Threads disponíveis: %d\n\n", omp_get_max_threads());

    double start_time, end_time;
    int i;

    // --- WARM-UP RUN ---
    // Executa uma vez para "aquecer" os threads e estabilizar a CPU
    #pragma omp parallel for
    for (i = 0; i < 10; ++i) {
        volatile int x = 0;
    }

    // ================== TESTE STATIC ==================
    start_time = omp_get_wtime();
    #pragma omp parallel for schedule(static)
    for (i = 0; i < NUM_TASKS; ++i) {
        perform_work(i);
    }
    end_time = omp_get_wtime();
    printf("Tempo [STATIC]:  %f segundos\n", end_time - start_time);

    // ================== TESTE DYNAMIC ==================
    start_time = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic)
    for (i = 0; i < NUM_TASKS; ++i) {
        perform_work(i);
    }
    end_time = omp_get_wtime();
    printf("Tempo [DYNAMIC]: %f segundos\n", end_time - start_time);

    // ================== TESTE GUIDED ===================
    start_time = omp_get_wtime();
    #pragma omp parallel for schedule(guided)
    for (i = 0; i < NUM_TASKS; ++i) {
        perform_work(i);
    }
    end_time = omp_get_wtime();
    printf("Tempo [GUIDED]:  %f segundos\n", end_time - start_time);

    printf("\nSimulação concluída.\n");
    return 0;
}
