aluno("Grades Silva", "Rua das Orquídeas, 32", "016966666666", "05/05/1955", 9, 10, 5, 0, 2, -1, freq).
aluno("Rafael Nobre", "Avenida das Palmeiras, 45", "016977777777", "12/08/1990", 8, 2, 7, 2, 0, -1, freq).
aluno("Victor Rodrigues", "Rua das Flores, 18", "016988888888", "20/03/2000", 7, 8, 6, 0, 4, -1, freq).
aluno("Kenzo Zimmer", "Avenida dos Pinheiros, 60", "016999999999", "15/09/1988", 9, 9, 8, 1, 0, -1, freq).
aluno("Adalton Guairarensis", "Rua das Acácias, 75", "016910101010", "10/11/1995", 6, 7, 6, 2, 3, 1, freq).
aluno("Terezinius Esposito", "Avenida das Rosas, 23", "016911111111", "25/06/2002", 10, 7, 10, 5, 0, -1, freq).


media_p(Nome, Media):-
    aluno(Nome, _, _, _, _, P1, _, P2, Sub, _, _),
    Np = P1 * 2 + P2 * 3,
    (Np >= 5 -> Media is Np / 5; Sub >= 0 ->  Media is (Np + Sub) / 6).

media_t(Nome, Media):-
    aluno(Nome, _, _, _, T1, _, T2, _, _, _, _),
    Nt = T1 + T2 * 3,
    Media is Nt / 4.

media(Nome, Media):-
    media_p(Nome, MediaP),
    media_t(Nome, MediaT),
    Media is (MediaP + MediaT) / 2.

aprovado(Nome):-
    media(Nome, Media),
    Media >= 5.


/*

?- 	aluno(Nome, _, _, _, T1, P1, T2, P2, Sub, Rec, _),
   	P1 = 10.

?- 	aluno(Nome, _, _, _, T1, P1, T2, P2, Sub, Rec, _),
   	P2 = 10.
   
?- 	aluno(Nome, _, _, _, T1, P1, T2, P2, Sub, Rec, _),
   	T1 = 10, T2 = 10.

?- 	aluno(Nome, _, _, _, _, P1, _, P2, _, _, _), 
   	P1 >= 5, P2 >= 5.
   
?- aprovado(Nome).
*/
