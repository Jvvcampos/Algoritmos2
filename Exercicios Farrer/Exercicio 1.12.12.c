#include <stdio.h>
int main()
{
    int contrep = 0, totalrepro, reprofreq;
    float matricula[100], nota1[100], nota2[100], nota3[100], frequencia[100], notaFinal[100];
    float maiorNota, menorNota, contadorNota = 0, mediaTurma, preprofreq;

    printf("Entrada de Dados:");
    while (contrep < 100)//vai ler 100x
    {
        printf("\nNumero da matricula do aluno %d: ", contrep+1);
        scanf("%f", &matricula[contrep]);
        printf("\nNota 1 do aluno %d: ", contrep+1);
        scanf("%f", &nota1[contrep]);
        printf("\nNota 2 do aluno %d: ", contrep+1);
        scanf("%f", &nota2[contrep]);
        printf("\nNota 3 do aluno %d: ", contrep+1);
        scanf("%f", &nota3[contrep]);
        printf("\nNumero de aulas que o aluno %d assistiu: ", contrep+1);
        scanf("%f", &frequencia[contrep]);

        notaFinal[contrep] = (nota1[contrep] + nota2[contrep] + nota3[contrep]) / 3;
        contadorNota += notaFinal[contrep];
        contrep+=1;
    }
    mediaTurma = contadorNota / 3;
    maiorNota = menorNota = notaFinal[0];

    contrep = 0;
    while (contrep < 100)
    {
        if (notaFinal[contrep] > maiorNota)
        {
            maiorNota = notaFinal[contrep];
        }
        if (menorNota > notaFinal[contrep])
        {
            menorNota = notaFinal[contrep];
        }

        printf("\nNumero da matricula do aluno %d e %.0f: ", contrep+1, matricula[contrep]);
        printf("\nNumero de aulas que o aluno %d assistiu e %.2f ", contrep+1, frequencia[contrep]);
        printf("\nNota final do aluno %d e %.2f \n", contrep+1, notaFinal[contrep]);
        if (notaFinal[contrep] >= 60 && frequencia[contrep] >= 40)
        {
            printf("\nAluno Aprovado!");
        }
        else if (notaFinal[contrep] >= 60 && frequencia[contrep] < 40)
        {
            printf("\nAluno Reprovado!");
            totalrepro+=1;
            reprofreq+=1;
        }
        else
        {
            printf("\nAluno Reprovado!");
            totalrepro+=1;
        }
    }

    printf("\nMaior nota: %.2f", maiorNota);
    printf("\nMenor nota: %.2f", menorNota);
    printf("\nMédia da turma: %.2f", mediaTurma);
    printf("\nTotal de alunos reprovados: %d", totalrepro);
    printf("\nPorcentagem de Alunos reprovados por infrequência: %d%%", reprofreq);//Cada aluno reprovado vai equivaler a 1% dos 100 alunos.
    return 0;
}