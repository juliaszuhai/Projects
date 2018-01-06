(DEFUN maxim(L M)
(COND
((NULL L) M)
((and (numberp(car l)) (> (car L) M)) (maxim (cdr L) (car L)))
((and (numberp(car l)) (<= (car L) M)) (maxim (cdr L) M))
(T (maxim (cdr L) M))
))


(DEFUN maximum(L)
(COND
((numberp(car L)) (maxim L (car L)))
(T (maximum (cdr L)))
))