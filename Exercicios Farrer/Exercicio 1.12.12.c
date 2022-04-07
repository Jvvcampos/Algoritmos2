/*
1.12.12. O sistema de avaliação de uma determinada disciplina obedece aos seguintes critérios:
* Durante o semestre são dadas três notas;
* A nota final é obtida pela média aritmética das notas dadas durante o curso;
* É considerado aprovado o aluno que obtiver a nota final superior ou igual a 60 e que
tiver comparecido a um mínimo de 40 aulas.
Fazer um algoritmo que:

a) Leia um conjunto de dados contendo o número de matrícula, as três notas e a frequência
(número de aulas frequentadas) de 100 alunos.
b) Calcule:
* A nota final de cada aluno;
* A maior e menor nota da turma;
* A nota média da turma;
* O total de alunos reprovados; 
* A porcentagem de alunos reprovados por infrequência;
c) Escreva:
* para cada aluno, o número de matrícula, a frequência, a nota final e o código
(aprovado ou reprovado);
* O que foi calculado no item b (2,3,4 e 5)
*/

#include <stdio.h>
int main()
{
    int cont_rep = 0, total_repro, repro_freq;
    float matricula[99], nota1[99], nota2[99], nota3[99], frequencia[99], notaFinal[99];
    float maiorNota, menorNota, contadorNota = 0, mediaTurma, preprofreq;

    printf("Entrada de Dados:");
    while (cont_rep < 100)//vai ler 100x
    {
        printf("\nNumero da matricula do aluno %d: ", cont_rep+1);
        scanf("%f", &matricula[cont_rep]);
        printf("\nNota 1 do aluno %d: ", cont_rep+1);
        scanf("%f", &nota1[cont_rep]);
        printf("\nNota 2 do aluno %d: ", cont_rep+1);
        scanf("%f", &nota2[cont_rep]);
        printf("\nNota 3 do aluno %d: ", cont_rep+1);
        scanf("%f", &nota3[cont_rep]);
        printf("\nNumero de aulas que o aluno %d assistiu: ", cont_rep+1);
        scanf("%f", &frequencia[cont_rep]);

        notaFinal[cont_rep] = (nota1[cont_rep] + nota2[cont_rep] + nota3[cont_rep]) / 3;
        contadorNota += notaFinal[cont_rep];
        cont_rep+=1;
    }
    mediaTurma = contadorNota / 3;
    maiorNota = menorNota = notaFinal[0];

    cont_rep = 0;
    while (cont_rep < 100)
    {
        if (notaFinal[cont_rep] > maiorNota)
        {
            maiorNota = notaFinal[cont_rep];
        }
        if (menorNota > notaFinal[cont_rep])
        {
            menorNota = notaFinal[cont_rep];
        }

        printf("\nNumero da matricula do aluno %d e %.0f: ", cont_rep+1, matricula[cont_rep]);
        printf("\nNumero de aulas que o aluno %d assistiu e %.2f ", cont_rep+1, frequencia[cont_rep]);
        printf("\nNota final do aluno %d e %.2f \n", cont_rep+1, notaFinal[cont_rep]);
        if (notaFinal[cont_rep] >= 60 && frequencia[cont_rep] >= 40)
        {
            printf("\nAluno Aprovado!");
        }
        else if (notaFinal[cont_rep] >= 60 && frequencia[cont_rep] < 40)
        {
            printf("\nAluno Reprovado!");
            total_repro+=1;
            repro_freq+=1;
        }
        else
        {
            printf("\nAluno Reprovado!");
            total_repro+=1;
        }
    }

    printf("\nMaior nota: %.2f", maiorNota);
    printf("\nMenor nota: %.2f", menorNota);
    printf("\nMédia da turma: %.2f", mediaTurma);
    printf("\nTotal de alunos reprovados: %d", total_repro);
    printf("\nPorcentagem de Alunos reprovados por infrequência: %d%%", repro_freq);//Cada aluno reprovado vai equivaler a 1% dos 100 alunos.
    return 0;
}