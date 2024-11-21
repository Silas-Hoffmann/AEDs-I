#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preencherAlunos(){
    FILE* arquivo;
    arquivo=fopen("notas_alunos","w");
    fputs('Aluno1;10\n',arquivo);
    fputs('Aluno2;15\n',arquivo);
    fputs('Aluno3;9\n',arquivo);
    fputs('Aluno4;11\n',arquivo);
    fputs('Aluno5;20\n',arquivo);
    fputs('Aluno6;14\n',arquivo);
    fputs('Aluno7;25\n',arquivo);
    fputs('Aluno8;22\n',arquivo);
}

int main (){
    preencherAlunos();
}
