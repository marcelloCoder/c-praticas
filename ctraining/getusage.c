#include <windows.h>
#include <stdio.h>

double tempoCPU() {
    FILETIME creationTime, exitTime, kernelTime, userTime;

    // Obtém os tempos de CPU do processo atual
    if (GetProcessTimes(GetCurrentProcess(), &creationTime, &exitTime, &kernelTime, &userTime)) {
        ULARGE_INTEGER kTime, uTime;

        // Converte FILETIME para um número de 64 bits
        kTime.LowPart = kernelTime.dwLowDateTime;
        kTime.HighPart = kernelTime.dwHighDateTime;

        uTime.LowPart = userTime.dwLowDateTime;
        uTime.HighPart = userTime.dwHighDateTime;

        // Retorna o tempo total em segundos
        return (kTime.QuadPart + uTime.QuadPart) / 1e7; // FILETIME é em unidades de 100 nanossegundos
    }

    return -1; // Em caso de erro
}

int main() {
    for (volatile long i = 0; i < 1e8; i++);

    double tempo_total = tempoCPU();
    if (tempo_total != -1) {
        printf("Tempo total de CPU (usuário + sistema): %.6f segundos\n", tempo_total);
    } else {
        printf("Erro ao obter o tempo de CPU.\n");
    }

    return 0;
}
