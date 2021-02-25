# jumpPrime
written in C++

Each jumpPrime object encapsulates a positive integer, which must be at least 4-digits long, and yields the prime numbers closest to that number.  
For example, an active jumpPrime myObj that encapsulates 2488:

                        myObj.up();           // returns prime number 2503

                        myObj.down();          // returns prime number 2477
                        
Additionally, the encapsulated number will ‘jump’ after a limited number of queries, a number determined by the distance between the two closest prime numbers. 
Hence, the active jumpPrime myObj that encapsulates 2488 will ‘jump’ to a value > 2503 or to a value < 2477 after 26 queries. 
Every jumpPrime object is initially active but transitions to inactive once the number of jumps exceeds a bound.  
The client may reset as well as revive a jumpPrime object. An attempt to revive an active jumpPrime object causes that object to be permanently deactivated.


Each duelingJP object encapsulates some number of distinct jumpPrime objects; the cardinality of jumpPrime subobjects varies across duelingJP objects. 
The key functionality of a duelingJP object is to manage the jumpPrime subobjects and answer client queries as to the number of ‘collisions’ and ‘inversions’.

Two jumpPrime objects are said to ‘collide’ if they produce the same prime number upon an up (or down) request. 
For example, if active jumpPrime object j1 encapsulates 2222, and jumpPrime object j2 encapsulates 2233, they both will produce 2221 for down()and 2237 for up().

Two jumpPrime objects are said to be ‘inversions’ if they produce the same prime number for complementary requests. 
For example, if active jumpPrime object j3 encapsulates 3519, and jumpPrime object j4 encapsulates 3528, j4 produces 3527 for down()and j3 produces 3527 for up().

Includes the operator overloading jumpPrime and duelingJP objects
