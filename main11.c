#include <stdio.h>

/*


    Permutação = n!/r!(n-r)!

    onde n é o numero total de objetos e r é numero de objetos selecionados


    (4!/(3!(4-3)!)) * (4!/(3!(4-3)!))

    (4*3*2*1)/3! * (4*3*2*1)/3!
    ((4*3*2*1)/(3*2*1)) * ((4*3*2*1)/(3*2*1))


*/

long long int fatorial(long long int num);
long long int combinacion(long long int num_frutas, long long int num_legumes);

int main()
{
    long long int num_frutas = 0, num_legumes = 0;

    scanf("%lld %lld", &num_frutas, &num_legumes);

    long long int result = combinacion(num_frutas, num_legumes);

    printf("%lld\n", result);
    return 0;
}

long long int fatorial(long long int num)
{
    long long int res = 1;

    for (int i = 2; i <= num; i++)
    {
        res *= i;
    }

    return res;
}
long long int combinacion(long long int num_frutas, long long int num_legumes)
{
    int obj_selecionado = 3;
    long long int permutacion_frutas = 0, permutacion_legumes = 0;

    permutacion_frutas = ((fatorial(num_frutas)) / (fatorial(obj_selecionado) * (fatorial(num_frutas - obj_selecionado))));
    permutacion_legumes = ((fatorial(num_legumes)) / (fatorial(obj_selecionado) * (fatorial(num_legumes - obj_selecionado))));

    return permutacion_frutas * permutacion_legumes;
}