(DEFUN inv(L C)
(COND
((NULL L) NIL)
((atom(car L)) (inv (cdr L) (append C (list(car L)))))
((listp (car L)) (cons (inv (car L) NIL) (inv (cdr L) NIL)))
))