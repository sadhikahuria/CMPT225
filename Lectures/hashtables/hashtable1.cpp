/*
#1

HASH TABLES
    maps, 
        key and value
        similar to dictionarys in python
            int size()
            void put(k,v)
                overwrite if same key
            bool contains(k)
            get(key)
            remove(key)
    
    rapid access
        eg
            dictionary, flight details using flight numbers, etc

    hashtables dont need to be in order

    Balanced binary search tree
        lookup and insertion - o(log(n)) time 

    Arrays 
        insertion 
            requires constant time, if array, using in index as key
        finding 
            requires linear time
            but if index/key is known, then constant time
        downside, only +integer values can be keys


#2

    using keys other than integers
    names
        unique integers
        each letter has a number, and multiple by 26^i, i is the position
        eg
            "dog" = 4 * 26^2  +  15 * 26^1  +  7 * 26^0  = 3101

    most of the time keys are not known, 
        not practical to reserve space for all possible values.
    
    use a hash function to convert key to index

hashtable
    array, element is the data or a pointer to data
    a hashfunction maps the key to an index

    a hash code
        first maps the key to an integer
        O(n) n is the key length
    compression fucntion 
        maps the integer to a legal array index
        O(1)
    hash function
        should distribute the keys across the hash table 
        as they had been randomly assigned
        determistic
            given input always return the same value
    
    hash code
        doesn't have to map key to index
        convert to a integer
        hash code should not result in collisions.
        cast down
            if the data type has at most as many bits as an integer,
            then reinterpret the key's bits as an integer
            eg byte, short, int, and float in c++
        polynominal hash code is the better hash code

    compression function
        map integer to an index 
        division method
            h(k) = k mod n , k is hash code, n is size of hashtable
        MAD method
            multiple add divide 
            h(k) = (ak + b) mod n ; a and b are +intergers, a mod n != 0. 

    strings to integers
        Horner's method
            z = 33
            value = ch0 + ch1 * 33 + ch2 * 33^2 ... + chn-1 * 33^(n-1)
            factor ((... ( chn01 * 33 + chn-2) * 33 + chn-3)* ...) * 33 + ch0
            mod (((... ( chn01 * 33 + chn-2) %n * 33 + chn-3) %n * ...) * 33 + ch0) %n


    Dealing with collisions
        Open addressing
            linear probing
                add one to the index of collision
            quadratic probing
                for each probe add p^2, 
                h(x) + 1^2
                h(x) + 2^2 ...
            Double hashing
                have a second hash function
                h2(key) != 0
                h2 != h1
            mark empty, occupied or removed

        separate chaining
            have a linked list at each index

    rehasing
        lenda = number of items / table size
        if lenda = 2/3, its big
        if lenda < 0.5, its not bad
        if lenda is big, separate chainging is better
        rehash
            for separate chainging, when lenda > 1.0
            for open addressing, whne lenda approching 1.0
            

*/
