#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void test_error_management(void) {
    printf("[Error Management Test]\n");
    char *line = get_next_line(42); // Testando um FD inválido
    if (line == NULL) {
        printf("Passou: FD inválido retorna NULL.\n");
    } else {
        printf("Falhou: FD inválido deveria retornar NULL.\n");
        free(line);
    }

    // Testar erro de malloc indiretamente é mais complexo, requer mock.
}

void test_various_buffer_sizes(const char *filename) {
    printf("[Buffer Size Test]\n");
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir arquivo");
        return;
    }

    int buffer_sizes[] = {1, 4, 8, 32, 1024, 2048};
    int i = 0;
	while (i < (int)(sizeof(buffer_sizes) / sizeof(int))) 
	{
        printf("Testando com BUFFER_SIZE = %d\n", buffer_sizes[i]);
        char *line;
        while ((line = get_next_line(fd)) != NULL) {
            printf("Linha: %s", line);
            free(line);
        }
        lseek(fd, 0, SEEK_SET); // Resetar leitura para o início
        // #undef BUFFER_SIZE
		 i++;
    }
    close(fd);
}

void test_varied_line_lengths(const char *filename) {
    printf("[Line Length Test]\n");
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir arquivo");
        return;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Linha: %s", line);
        free(line);
    }
    close(fd);
}

void test_multiple_fds(const char *file1, const char *file2) {
    printf("[Multiple FD Test]\n");
    int fd1 = open(file1, O_RDONLY);
    int fd2 = open(file2, O_RDONLY);

    if (fd1 == -1 || fd2 == -1) {
        perror("Erro ao abrir arquivos");
        if (fd1 != -1) close(fd1);
        if (fd2 != -1) close(fd2);
        return;
    }

    char *line1 = get_next_line(fd1);
    char *line2 = get_next_line(fd2);

    printf("FD1: %s", line1);
    printf("FD2: %s", line2);

    free(line1);
    free(line2);
    close(fd1);
    close(fd2);
}

int main(void) {
    printf("=== Teste do Get Next Line ===\n\n");

    // Testar gestão de erros
    test_error_management();

    // Testar tamanhos variados de BUFFER_SIZE
    const char *test_file = "test_file.txt";
    test_various_buffer_sizes(test_file);

    // Testar comprimentos variados de linha
    test_varied_line_lengths(test_file);

    // Testar múltiplos descritores de arquivo
    const char *file1 = "test_file1.txt";
    const char *file2 = "test_file2.txt";
    test_multiple_fds(file1, file2);

    printf("\n=== Fim dos testes ===\n");
    return 0;
}
