# Algoritmo de Luhn

> Há muitas pessoas com cartões de crédito no mundo, então esses números são bem longos e por isso os números de cartão de crédito têm um “checksum” embutido, uma relação matemática entre pelo menos um número e outros. Essa soma de verificação permite que os computadores (ou humanos que gostam de matemática) detectem erros de digitação (por exemplo, transposições), se não números fraudulentos, sem ter que consultar um banco de dados, que pode ser lento.

Foi criado um código em C para validar números de cartões de crédito usando o Algoritimo de Luhn e verificar qual é a bandeira do cartão.

Ex.:

```txt
Número: 1234567890
INVALID

Número: 378282246310005
AMEX

Número: 5105105105105100
MASTERCARD

Número: 4111111111111111
VISA
```
