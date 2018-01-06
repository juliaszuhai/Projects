(DEFUN cmmdc(A B)
(COND
((EQUAL A 0) A)
((EQUAL B 0) B)
((EQUAL A B) A)
((> A B) (cmmdc (- A B) B))
((< A B) (cmmdc A (- B A)))
))


(DEFUN cmmdc_list(L)
(COND
((null L) 0)
((and(null (cdr L)) (numberp (car L))) (car L))
((numberp (car L)) (cmmdc (car L) (cmmdc_list(cdr L))))
((listp( car L)) (cmmdc (cmmdc_list(car L)) (cmmdc_list(cdr L))))

(T (cmmdc_list(cdr L)))
))