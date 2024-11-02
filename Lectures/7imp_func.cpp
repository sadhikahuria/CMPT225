 #include <iostream>

/*
classified into
    constant
        o(1) regardless of input
    logarthmic 
        eg log2n binary search
    linear
        eg traversing
    n log n
        eg mergesort heapsort
        nlogn is best case for compasion sorts
    quadratic
        eg selection or insertion sort
        look for 2 nested loops
    polynomial
        used in alogoirthm analysis
        look for 2>= nested loops
    exonential 
        b^n very slow


Comparing alogirthm performce
    what happens when n gets larger
    O- noation evlauates the growth rate

O(n) defintion
    Functions f(n) and g(n) map non-negative integerst to real numbers
    we say that f(n) is O(g(n)) if there is a real constant c > o and an 
    integer constant n1 such that 
        f(n) <= cg(n) for all n >- n1
        find constants c and n1 such that the cost function is less than or 
        equal to c * a simpler functino fo rall n greater than or euqal to n1
    if so, we would say that f(n) is in O(g(n))
    O notation states that f(n) <= cg(n) in the asymptotic sense as n grows
    towards infinity

    the idea is that a cost function can be approximated by another simpler function
  */
