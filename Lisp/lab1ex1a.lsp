;a) Write a function to return the n-th element of a list, or NIL if such an element does not exist
(DEFUN check(L N)
(COND
((NULL L) NIL)
((EQUAL N 1)  (CAR L))
(T (check (CDR L) (- N 1))))) 


(DEFUN check2(L N)
(COND
((NULL L) NIL)
((AND (EQUAL N 1) (ATOM (CAR L))) (CAR L))
((AND(LISTP(CAR L)) (>= (- N (len (CAR L))) 1)) (check2 (CDR L) (- N (len (CAR L)))))
((AND(LISTP(CAR L)) (< (- N (len (CAR L))) 1)) (check2 (CAR L) N))
(T (check2 (CDR L) (- N 1)))
))


(DEFUN len (L)
(COND
((NULL L) 0)
((ATOM (CAR L)) (+ 1 (len (CDR L))))
((LISTP (CAR L)) (+ (len (CAR L)) (len (CDR L))))
))