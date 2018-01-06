(DEFUN addition( L R)
(COND
((NULL L) NIL)
(T (list (+ (car L) (car R)) (+ (cadr L) (cadr R))))
))