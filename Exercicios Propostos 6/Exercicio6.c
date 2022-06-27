#include <stdio.h>
#include <string.h>
#include <locale.h>

#define SAL_MINIM0 1200

char dados_pessoais(char nomes[]);
float salario(float *sal_liquido, float *sal_recebido, float *refeicoes, float *idesc_eventuais, float *vales);
void imprime(char inome[], float isal_liquido, float isalario, float iref, float idesc_event, float idesc_vale);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char nome[50];
    dados_pessoais(nome);

    float sal_final;
    float sal;
    float ref;
    float de;
    float val;

    salario(&sal_final, &sal, &ref, &de, &val);

    imprime(nome, sal_final, sal, ref, de, val);
    
    return 0;
}

char dados_pessoais(char nomes[])
{
    //lê o nome do funcionário
    printf("Digite o nome do funcionário: ");
    fgets(nomes, 50, stdin);
}

float salario(float *sal_liquido, float *sal_recebido, float *refeicoes, float *idesc_eventuais, float *vales)
{
    float valor_hed;
    float valor_hen;
    float hed;
    float hen;
    int nd;
    int fal;

//lê o salário do empregado
    printf("Salário do empregado: R$");
    scanf("%f", &*sal_recebido);
    
    //lê o valor-hora-diurna
    printf("Valor hora extra diurna: R$");
    scanf("%f", &valor_hed);
    
    //lê o valor-hora-noturna
    printf("Valor hora extra noturna: R$");
    scanf("%f", &valor_hen);
    
    //quantidade de horas extras diurnas trabalhadas
    printf("Quantas horas extras diurnas o funcionário trabalhou esse mês? ");
    scanf("%f", &hed);
    
    //quantidade de horas extras noturnas trabalhadas
    printf("Quantas horas extras diurnas o funcionário trabalhou esse mês? ");
    scanf("%f", &hen);
    
    //quantidade de dependentes
    printf("Quantos dependentes o funcionário tem? ");
    scanf("%d", &nd);
    
    //quantidade de faltas do funcionário
    printf("Quantas faltas o funcionário tem esse mês? ");
    scanf("%d", &fal);
    
    //descontos eventuais  
    printf("Descontos evetuais no salário: R$");
    scanf("%f", &*idesc_eventuais);
    
    //gastos com refeições feitas na empresa
    printf("Quanto o funcionário gastou com refeição esse mês? R$");
    scanf("%f", &*refeicoes);
    
    //vales retirados durante o mês
    printf("Quanto de vale deverá ser descontado no salário do funcionário? R$");
    scanf("%f", &*vales);

    //calcula e aplica valores a variáveis necessárias para cálculos
    float hora_extra = hed * *sal_recebido/160 + hen * 1.2 * *sal_recebido/160;
    float sal_familia = nd * 0.05 * SAL_MINIM0;
    float total_horas_extras = (hen * valor_hen) + (hed * valor_hed);
    float sal_bruto = *sal_recebido + total_horas_extras + sal_familia;
    float inamps = 0.08 * (*sal_recebido);
    float faltas = fal * (*sal_recebido / 160);
    float imposto_renda = 0.08 * sal_bruto;

    //calcula o desconto total
    float desc_total;
    desc_total = sal_bruto - faltas - *refeicoes - *idesc_eventuais - *vales - inamps - imposto_renda;

    //calcula o salário líquido
    *sal_liquido = sal_bruto - desc_total;
}

void imprime(char inome[], float isal_liquido, float isalario, float iref, float idesc_event, float idesc_vale)
{
    //imprime os valores
    printf("\n\n\nDados do colaborador:\n");
    printf("\n\nNome do colaborador: %s", inome);
    printf("Salário do colaborador: R$%.2f", isalario);
    printf("\nDescontos em refeições: R$%.2f", iref);
    printf("\nDescontos em vales: R$%.2f", idesc_vale);
    printf("\nDescontos eventuais: R$%.2f", idesc_event);
    printf("\nSalario líquido: R$%.2f", isal_liquido);
}