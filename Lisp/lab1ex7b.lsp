(DEFUN rev(L)
(COND
((NULL L) NIL)
(T (append (rev (cdr L)) (list(car L))))
))


(DEFUN inc(L C)
(COND 
((and (NULL L) (EQUAL C 1)) (list 1))
((and (NULL L) (EQUAL C 0)) NIL)
((and (EQUAL C 1) (EQUAL (+ 1 (car L)) 10)) (CONS 0 (inc (cdr L) 1)))
((and (EQUAL C 1) (< (+ 1 (car L)) 10)) (CONS (+ 1 (car L)) (inc (cdr L) 0)))
((EQUAL C 0) (CONS (car L) (inc (cdr L) 0)))
))

(DEFUN incr(L)
(rev (inc (rev L) 1)))
