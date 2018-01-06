(DEFUN repl(L)
(COND
((NULL L) NIL)
((listp(car l)) (append (list(get_last(car L))) (repl (cdr L))))
(T (append (list(car L)) (repl (cdr L))))))

(DEFUN replc(L)
(COND
((not (linear L)) (replc(repl L)))
((linear L) L)))



(DEFUN linear(L)
(COND
((NULL L) T)
((atom (car L)) (linear (cdr L)))
((listp (car L)) NIL)))


(DEFUN get_last(L)
(COND
((NULL (cdr L)) (car L))
(T (get_last (cdr L)))))