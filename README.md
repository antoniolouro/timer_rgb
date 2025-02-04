# timer_rgb

## Esta é a Tarefa 1 da aula síncrona de 29/01/2025 - Semáforo baseado em timer
### Neste trabalho é usado um único LED RGB. O Programa é simulado no wokwi e executado na placa BitdogLab

Basicamente o projeto é composto pela função main() e pela função callback. 
Na main(), está a __função que "cria um temporizador"__, o qual chama a __função de callback__ a cada 3000 ms.
o SDK esconde os detalhes do hardware timer, facilitando a criação de timers periódicos com *add_repeating_timer_ms()*. 
Não é necessário se preocupar em configurar registradores e habilitar interrupções, você simplesmente define um intervalo e uma função callback.

A função callback tem a responsabilidade de identificar qual é o led que deverá ser aceso. Isto é feito usando o conteúdo da variável state, que determina
a sequência de acendimento (0-> Vermelho, 1-> Amarelo, 2-> Verde). A cada execução da função callback, um único estado é considerado.

## Vídeo Demonstrativo
Confira o vídeo no link abaixo:

[![Assista no YouTube](https://img.youtube.com/vi/NQUnABE11w4/maxresdefault.jpg)](https://youtu.be/NQUnABE11w4)

