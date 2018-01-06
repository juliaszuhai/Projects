(DEFUN merg(L R)
(COND
((and (null L)(null R)) NIL)
((and (null L)(not(null R))) (append R (merg NIL NIL)))
((and (null R)(not(null L))) (append L (merg NIL NIL)))
((> (car L) (car R)) (cons (car R) (merg L (cdr R))))
((< (car L) (car R)) (cons (car L) (merg (cdr L) R)))
((= (car L) (car R)) (cons (car L) (merg (cdr L) (cdr R))))

))