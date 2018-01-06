(DEFUN insert (L E)
(COND
((NULL L) (list E))
((> (car L) E) (cons e L))
((< (car L) E) (cons (car L) (insert (cdr L) E)))
((= (car L) E)  L)
))


(DEFUN sorting(L)
(COND 
((NULL L) NIL)
(T (insert( sorting( cdr L)) (car L)))))