# Projeto 03 - Mini Firewall de Portas

**Disciplina:** Redes e Segurança da Informação | **Turma:** ______
**Integrantes:** Joaquim C, Joaquim F, Samuel G
**Data:** 07/11/2026

## Problema
Simular um firewall muito simples: o programa recebe números de portas
solicitadas e decide se cada uma é PERMITIDA ou BLOQUEADA, com base em uma
lista fixa de portas autorizadas (22, 53, 80 e 443).

## Analogia com redes
Firewalls analisam regras para permitir ou negar comunicações. Aqui, a "regra"
 é um vetor com quatro portas liberadas, e cada solicitação é comparada com ele.

## Relação com segurança da informação
O programa usa a política de bloqueio por padrão: tudo que não corresponde a
uma regra autorizada é recusado. Isso reduz a superfície exposta de um sistema.

## Como funciona
1. Valida a quantidade de solicitações (1 a 8).
2. Lê e valida cada porta (1 a 65535).
3. Um laço percorre o vetor de portas liberadas e compara com cada solicitação.
4. Exibe PERMITIDA ou BLOQUEADA e contabiliza os resultados.

## Testes
| Entrada | Esperado | Obtido |
|---|---|---|
| 22, 25, 53, 445, 443 | 3 permitidas, 2 bloqueadas | 22 PERMITIDA, 25 BLOQUEADA, 53 PERMITIDA, 445 BLOQUEADA, 443 PERMITIDA (3 permitidas / 2 bloqueadas) |
| 8080 | Bloqueada | Porta 8080: BLOQUEADA |
| 0 e 65536 (depois 80) | Porta inválida; aceita 80 | "Porta invalida" para 0 e 65536; depois 80 PERMITIDA |

## Limitações
Não há conexões reais, endereços IP, protocolos TCP/UDP, direção do tráfego nem
filtragem de pacotes. O programa só compara números digitados. Liberar a porta
443 não torna um servidor seguro: ele ainda pode ter falhas ou configuração fraca.
Se for digitada uma letra no lugar de um número, o `scanf` reconhece a entrada
como inválida e o programa pede novamente. Isso é um comportamento esperado em C.

## Como compilar e executar
```bash
gcc firewall.c -o firewall
./firewall
```

