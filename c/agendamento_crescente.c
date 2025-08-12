// Arquivo: agendamento_crescente.c
//
// Este código simula uma carga de trabalho que aumenta com o tempo,
// o cenário ideal para a política de agendamento "guided".


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#define NUM_TASKS 100000
#define BASE_WORK_UNITS 200
#define NUM_RUNS 5

// Função que simula uma carga de trabalho CRESCENTE.
// As últimas iterações são MUITO mais pesadas que as primeiras.
void perform_increasing_work(int task_id) {
    // A carga de trabalho aumenta linearmente com o índice da tarefa.
    // A divisão por um float garante que o crescimento seja gradual.
    long long work_units = BASE_WORK_UNITS * (task_id / 1000.0);

    volatile double dummy_sum = 0.0;
    long long i;
    for (i = 0; i < work_units; ++i) {
        dummy_sum += tan((double)i);
    }
}

int main() {
    printf("Iniciando simulacao final com carga de trabalho CRESCENTE.\n");
    printf("Executando cada politica %d vezes para obter a media.\n", NUM_RUNS);
    printf("Numero de Threads: %d\n\n", omp_get_max_threads());

    double total_time_static = 0, total_time_dynamic = 0, total_time_guided = 0;
    double start_time, end_time;
    int i;

    // --- WARM-UP ---
    #pragma omp parallel for
    for (i = 0; i < 10; ++i) { (void)0; }

	int run;

    for (run = 0; run < NUM_RUNS; ++run) {
        printf("Execucao #%d...\n", run + 1);
        
        // --- STATIC ---
        start_time = omp_get_wtime();
        #pragma omp parallel for schedule(static)
        for (i = 0; i < NUM_TASKS; ++i) {
            perform_increasing_work(i);
        }
        end_time = omp_get_wtime();
        total_time_static += (end_time - start_time);

        // --- DYNAMIC ---
        start_time = omp_get_wtime();
        #pragma omp parallel for schedule(dynamic)
        for (i = 0; i < NUM_TASKS; ++i) {
            perform_increasing_work(i);
        }
        end_time = omp_get_wtime();
        total_time_dynamic += (end_time - start_time);

        // --- GUIDED ---
        start_time = omp_get_wtime();
        #pragma omp parallel for schedule(guided)
        for (i = 0; i < NUM_TASKS; ++i) {
            perform_increasing_work(i);
        }
        end_time = omp_get_wtime();
        total_time_guided += (end_time - start_time);
    }

    // --- Apresentação dos Resultados Finais (Média) ---
    printf("\n--- Resultados Finais (Media de %d execucoes) ---\n", NUM_RUNS);
    printf("Tempo Medio [STATIC]:  %f segundos\n", total_time_static / NUM_RUNS);
    printf("Tempo Medio [DYNAMIC]: %f segundos\n", total_time_dynamic / NUM_RUNS);
    printf("Tempo Medio [GUIDED]:  %f segundos\n", total_time_guided / NUM_RUNS);
    printf("\nSimulacao concluida.\n");
    
    return 0;
}
