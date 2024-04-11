#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>

void imprimirEstatisticasCPU() {
    FILE* stat_file = fopen("/proc/stat", "r");
    if (!stat_file) {
        perror("Erro ao abrir /proc/stat");
        exit(EXIT_FAILURE);
    }

    char linha[256];
    int tempoTotalCPU[10] = {0};
    int tempoOciosidadeCPU = 0;
    int tempoTotal = 0;

    while (fgets(linha, sizeof(linha), stat_file)) {
        if (strncmp(linha, "cpu ", 4) == 0) {
            sscanf(linha + 5, "%d %d %d %d %d %d %d %d %d %d", 
                &tempoTotalCPU[0], &tempoTotalCPU[1], &tempoTotalCPU[2], &tempoTotalCPU[3], 
                &tempoTotalCPU[4], &tempoTotalCPU[5], &tempoTotalCPU[6], &tempoTotalCPU[7], 
                &tempoTotalCPU[8], &tempoTotalCPU[9]);

            for (int i = 0; i < 10; i++) {
                tempoTotal += tempoTotalCPU[i];
            }

            tempoOciosidadeCPU += tempoTotalCPU[3];
            
            break;
        }
    }

    fclose(stat_file);

    float usoCPU = 100.0 * (1.0 - ((float)tempoOciosidadeCPU / (float)tempoTotal));
    printf("CPU: %.2f%%\n", usoCPU);
}



void imprimirEstatisticasRAM() {
    struct sysinfo info;
    if(sysinfo(&info) != 0) {
        printf("Erro ao obter informações do sistema.\n");
        return;
    }

    long total_ram_kb = info.totalram / 1024;
    long free_ram_kb = info.freeram / 1024;

    long total_ram_mb = total_ram_kb / 1024;
    long free_ram_mb = free_ram_kb / 1024;

    long used_ram_mb = total_ram_mb - free_ram_mb;
    float percent_used = (float)used_ram_mb / total_ram_mb * 100.0;
    printf("RAM: %.2f%%\n", percent_used);

}

void imprimirEstatisticasDoSistema() {
    printf("====================\n");
    imprimirEstatisticasCPU();
    imprimirEstatisticasRAM();
}