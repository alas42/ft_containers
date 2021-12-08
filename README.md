# ft_containers

Namespaces will aways be ft
The containers will be tested using ft::<container>
Respect of the structore of reference (the container)
If it's not canonical, don't make it canonical
C++98 not C++11

The main has to be bigger and test more things

!one binary with only my containers!
!one binary with the stl ones!

using std::allocator
justify the inner structures for each container (so I have to be logical ok)

Iterators has to be implemented too
AND
    . iterators_traits
    . reverse_iterators
    . enable_if
    . is_integral
    . equal / lexicograhical comparisons
    . std::pair
    . std::make_pair

EVERYTHING ELSE THAT DOES NOT APPEAR ON CPPREFENCE.COM HAS TO BE PRIVATE OR PROTECTED

KEYWORD FRIEND ALLOWED FOR NON-MEMBER OVERLOADS (like << )

Now, the subject is:
    A: Vector (vector<bool> why not)
    B: Map
    C: Stack -> will use the vector class I made

EASY PEASY

BONUS: (won't do)
    D: SET (Black-Red Tree or whatnot)
    