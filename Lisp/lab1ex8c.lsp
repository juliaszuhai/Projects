(DEFUN len(L)
(COND
((NULL L) 0)
(T (+ 1 (len(cdr L))))
))

(DEFUN odd(L)
(COND
((EQUAL(mod (len L) 2) 0) NIL)
((EQUAL(mod (len L) 2) 1) T)))

(DEFUN getFirst(L)
(COND
((NULL L) NIL)
((numberp( car L)) (car L))
(T (getFirst(cdr L)))
))


(DEFUN getOdd(L)
(COND 
((NULL L) NIL)
((and(listp(car L)) (odd (car L))) (cons (getFirst(car L)) (getOdd(cdr L))))
(T (getOdd (cdr L)))
))

(DEFUN getOddFinal(L)
(COND
((odd L) (CONS (getFirst L) (getOdd L))) 
(T (getOdd L))
))