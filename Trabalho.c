#include <stdio.h>
typedef struct
{
    double raiz1;
    double raiz2;
} Raizes;
double soma(double a, double b);
double subtracao(double a, double b);
double multiplicacao(double a, double b);
double divisao(double a, double b);
double potenciacao(double base, double expoente);
double raizQuadrada(double x);
int fatorial(int fat);
int MDC(int a, int b);
int MMC(int num1, int num2);
Raizes equacaoSegundoGrau(double a, double b, double c);

int main()
{
    int choice;
    int stop = 0;
    double a, b, c;
    double x;
    double base, expoente;
    int num1, num2, fat;

    while (stop == 0)
    {
        printf("Escolha uma operação:\n0 - Sair\n1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n5 - Potenciacao\n6 - Raiz Quadrada\n7 - Fatorial\n8 - MDC\n9 - MMC\n10- Equacao de Segundo Grau\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Até logo!\n");
            stop++;
            break;
        case 1:
            printf("Digite o primeiro número: ");
            scanf("%lf", &a);
            printf("Digite o segundo número: ");
            scanf("%lf", &b);
            printf("Soma: %.5lf\n", soma(a, b));
            break;
        case 2:
            printf("Digite o primeiro número: ");
            scanf("%lf", &a);
            printf("Digite o segundo número: ");
            scanf("%lf", &b);
            printf("subtração: %.5lf\n", subtracao(a, b));
            break;
        case 3:
            printf("Digite o primeiro número: ");
            scanf("%lf", &a);
            printf("Digite o segundo número: ");
            scanf("%lf", &b);
            printf("Multiplicação: %.5lf\n", multiplicacao(a, b));
            break;
        case 4:
            printf("Digite o primeiro número: ");
            scanf("%lf", &a);
            printf("Digite o segundo número: ");
            scanf("%lf", &b);
            printf("Divisão = %.5lf\n", divisao(a, b));
            break;
        case 5:
            printf("Digite o primeiro número\n");
            scanf("%lf", &base);
            printf("Digite o segundo número\n");
            scanf("%lf", &expoente);
            printf("Potenciação: %.5lf\n", potenciacao(base, expoente));
            break;
        case 6:
            printf("Digite o primeiro número\n");
            scanf("%lf", &x);
            printf("RaizQuadrada: %.5lf\n", raizQuadrada(x));
            break;
        case 7:
            printf("Digite o primeiro número\n");
            scanf("%d", &fat);
            printf("Fatorial: %d\n", fatorial(fat));
            break;
        case 8:
            printf("Digite o primeiro número\n");
            scanf("%d", &num1);
            printf("Digite o segundo número\n");
            scanf("%d", &num2);
            printf("MDC: %d\n", MDC(num1, num2));
            break;
        case 9:
            printf("Digite o primeiro número\n");
            scanf("%d", &num1);
            printf("Digite o segundo número\n");
            scanf("%d", &num2);
            printf("MMC: %d\n", MMC(num1, num2));
            break;
        case 10:
            printf("Digite o primeiro número: ");
            scanf("%lf", &a);
            printf("Digite o segundo número: ");
            scanf("%lf", &b);
            printf("Digite o terceiro número: ");
            scanf("%lf", &c);
            Raizes resultado = equacaoSegundoGrau(a, b, c);
            printf("Raiz 1: %.5f\n", resultado.raiz1);
            printf("Raiz 2: %.5f\n", resultado.raiz2);

            break;
        }
    }

    return 0;
}

double soma(double a, double b)
{
    return a + b;
}
double subtracao(double a, double b)
{
    return a - b;
}
double multiplicacao(double a, double b)
{
    return a * b;
}
double divisao(double a, double b)
{
    double result;
    if (b == 0)
    {
        printf("A divisão por zero não é definida\n");
        return 0.00000;
    }

    result = a / b;
    return (result);
}
double potenciacao(double base, double expoente)
{
    double result = 1;
    for (int i = 0; i < expoente; i++)
    {
        result *= base;
    }
    return result;
}
double raizQuadrada(double x)
{
    double precisao = 0.00001;
    double estimativa = x;

    if (x < 0)
    {
        printf("Não é possível calcular a raiz quadrada de um número negativo.\n");
        return -1;
    }

    do
    {
        double novaEstimativa = (estimativa + x / estimativa) / 2.0;
        if ((novaEstimativa - estimativa) * (novaEstimativa - estimativa) < precisao * precisao)
        {
            return novaEstimativa;
        }

        estimativa = novaEstimativa;

    } while (1);
}
int fatorial(int fat)
{
    if (fat < 0)
    {
        printf("Não é possível calcular o fatorial de um número negativo.\n");
        return -1;
    }

    int resultado = 1;
    for (int i = 1; i <= fat; i++)
    {
        resultado *= i;
    }

    return resultado;
}
int MDC(int a, int b)
{
    int result = 0;
    while (b != 0)
    {
        result = a % b;
        a = b;
        b = result;
    }
    return (a);
}
int MMC(int num1, int num2)
{
    if (num1 == 0 || num2 == 0)
    {
        return 0;
    }
    return (num1 * num2) / MDC(num1, num2);
}
Raizes equacaoSegundoGrau(double a, double b, double c)
{
    Raizes resultado;
    resultado.raiz1 = resultado.raiz2 = -1;

    if (a == 0)
    {
        printf("O coeficiente 'a' não pode ser zero em uma equação de 2 grau.\n");
        return resultado;
    }

    double delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        printf("A equação não tem raízes reais.\n");
        return resultado;
    }

    double raizDeDelta = raizQuadrada(delta);
    resultado.raiz1 = (-b + raizDeDelta) / (2 * a);
    resultado.raiz2 = (-b - raizDeDelta) / (2 * a);

    return resultado;
}