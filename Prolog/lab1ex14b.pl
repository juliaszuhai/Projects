nThElem([H|_],1,H).
nThElem([_|T],N,E):-
    N=\=1,
    N1 is N-1,
    nThElem(T,N1,E).
