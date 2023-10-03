onibus(araraquara, ribeirao).
onibus(bauru, marilia).
onibus(bauru, sanca).
onibus(botucatu, bauru).
onibus(franca, barretos).
onibus(riberao, franca).
onibus(sanca, araraquara).
onibus(sorocaba, franca).

viagemSomenteIda(X, Y):-
    (onibus(X, Y), !); (viagem(X, Z), viagem(Z, Y)).

viagem(X, Y):-
    (onibus(X, Y), !); (onibus(Y, X), !); (viagem(X, Z), viagem(Z, Y)).
