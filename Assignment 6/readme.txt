Hashing using quadratic probing for collision resolution.

Files included:

QuadraticHashing.cpp		-conatins the source code for Hashing using quadratic probing for resolution.
QuadratichHashing.exe		-executable file for Hashing using quadratic probing for resolution.
words.txt			-text file with sample words for execution.
Assignment6.docx		-Word file with question, source code, screenshot of execution.


The program  performs Hashing by reading string inputs in words.txt, which is a file having 20 animal names, and hashes them into a hashtable.The program reads these names into a string vector and attempts to hash it into a hashtable of size 31. For any collisons that occur it uses quadratic probing for collison resolution where if slot hash(x) % TableSize is full, then we try (hash(x) + i^2) % TableSize
Here, i is the number of collisions for the same input.Once loadfactor reaches>=0.5, the hash table is resized to the next prime number 67.

The program shows the positions at which the inputs are hashed and also the total number of collisons that occur to execute the entire hashing.
