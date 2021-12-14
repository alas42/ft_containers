# ft_containers

/********************************************************************\
|************************* RULES ************************************|
\*******************************************************************/

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

Iterators has to be implemented too [A]
AND
    . iterators_traits [B]
    . reverse_iterators [C]
    . enable_if [D]
    . is_integral [E]
    . equal / lexicograhical comparisons [F]
    . std::pair [G]
    . std::make_pair [H]

/*
** EVERYTHING ELSE THAT DOES NOT APPEAR ON CPPREFENCE.COM HAS TO BE PRIVATE OR PROTECTED
*/

KEYWORD FRIEND ALLOWED FOR NON-MEMBER OVERLOADS (like << )

Now, the subject is:
A: vector
B: map
C: stack -> will use the vector class I made as base class
BONUS: (won't do)
    D: SET (Black-Red Tree or whatnot)


TO TEST :
/*
** github.com/Mazoise/FT_CONTAINERS_TESTER
*/

So basically, Have to write some code, hpp files, Template classes
What do I have to write and when can I just inherit something ? Dont know
Do I have to rewrite iterators and iterators_traits ? maybe, this is hell

/****************************************************\
|***************** RESEARCH**************************|
\***************************************************/

[A]

"std::iterator is the base class provided to simplify definitions of the required types for iterators."
Yeah to simplify, my ass

It has FIVE template paramaters.
1. A Category of iterator, it can one of FIVE categories
2. A Type of value that can be obtained by deferencing an iterator like *it gives 5 in case of an int
3. A Distance that is used to know the distance (?) between iterators (iterations ?)
4. A Pointer to the type iterated over *
5. A Reference to the type iterated over. &

THE FIVE CATEGORIES OF ITERATORS
(by the way, these are "empty_type" whatever that means ans are stucts)
1. struct input_iterator_tag 
2. struct output_iterator_tag
3. forward_iterator_tag: public input_iterator_tag
4. struct bidirectional_iterator_tag: public forward_iterator_tag
5. struct random_access_iterator_tag: public bidirectional_iterator_tag

One of these five categries has to be typedefed in every iterators. It indicated the "most specific category that the iterator is in".
They carry information used to select the most efficient algorithm that has to be used.

[B]

THEN, there is what is called iterators_traits
-> It provides a uniform interface for the iterators.
(makes possible to implement the algorithms for iterators)
It has to have FIVE (again) member types, variables (? have to check what it means)
1. difference type
2. value_type
3. pointer (can be declared void)
4. reference
5.  iterator_category 

So what do we learned ? jack s***

[C]
reverse_iterators

For a reverse iterator r constructed from an iterator i, the relationship &*r == &*(i-1) is always true
It has exactly the same template parameters as the iterator listed up here |

[D]
enable_if <bool B, class T = void>
BASICALLY what I can understand with my limited brain is that :
    the boolean determines what happens with the second template paramater
    if true = T has a type
    if false = void is the type (it has then no type)
By the way, this is not existing in c++98 but we have to do it in c++98. The more I read, the more fun it gets

[E]
is_integral
CHECK if template T is an integral type and returns true if it is a:
    bool, char, char16_t, char32_t, wchar_t, short, int, long, long long
returns false if not.

[F]
Yeah, I guess I know what that thing is but without any more info I don't even know what to check

[G]
std::pair is a class template to store two objects as one. OK ok, hear me out now.
What the heck ? Do we have to create a tuple class just to do it or ???
Because and I quote "a pair is specific case of a std::tuple with two elements"
Yeah, so since tuple are a c++11 thing, I will say we have to code it too...

[H]
std::make_pair
create a std::apir object ? then it just calls std::pair and returns it... why tho ?
why not calll std::pair directly ?

Et voila, you have 140 hours if you want. Don't forget a fucking main that will test EVERYTHING YOU DID.
140 hours, that's what, one month ?
Hilf mir Gott, die sind verrueckt

WHAT IS AN ALLOCATOR ? 
It is an object that has strategies to access access and address values, to allocate and deallocate memory AND to construct and destruct objects.
the std::allocator class template is the one by default for all std containers. 
have to #include <memory> meybe to use it.

WHAT IS AN ITERATOR ?
"The reason that STL containers and algorithms work so well together, is that they know nothing of each other — Alex Stepanov"

In C++, every iterator is treated as a pointer
"Due to different types of iterator categories, C++ defines the iterator traits which a programmer needs to specify if he/she wants the best optimization when STL algorithm is used."
"n C++98, iterator traits are defined with typedef typename sintaxis"