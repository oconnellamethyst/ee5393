# ee5393
My code is set up as a Visual Studio Project, I wrote it in Visual Studio, and so there's a lot of Visual Studio files, you can ignore those.

The two main code parts of the program are in the Permutatinator folder, Logics.h and Permutatinator.cpp. Logics.h is my functions file, it implements the logic. Permutatinator.cpp is where the code that applies the logics, it's basically my test file. Right now it is implemented as a truth table, I call nand(0, 0), nand(0, 1), nand(1, 0), and nand(1, 1), and what it is supposed to do is implement the nand of these values. As you can see, it does not, because it does not return what it should as according to the homework on page 2, nor does it return the correct truth table. The lists of numbers on the left are the current permutations as it goes through the permutatinator, then it lists a truth table in a very obtuse fashion, "the truth is []" and then it lists "DONE1" which is a test to make sure the functions are going through, since I had a problem with a while loop that wouldn't stop earlier.

The Logics.h file is my functions, you have to scroll a bit to get to the functions since I have versions of functions that I couldn't get to work that are commented out. Then it defines a logics class of integers, and overrides the *, ^ and ! operators for the logics class. This part of the code is very confusing but it works for what it is doing, it defines * as logical and as defined by nand gates, ^ as logical or as defined by nand gates, and ! as logical not as defined by nand gates, basically, in theory, allowing me to get a permutation for any logical function by getting a single nand gate function to work, although, not necessarily a good permutation function. I was going to go back and optimize these logical operators with the transformations on page 3 once I got the nand gate on page 2 to work, using the other functions, but right now it's defined by nand gates so that if I don't get around to it, it still technically works, or it would technically work if the nand gate function worked. But in essence, the idea of the Logics.h class is so that you can type something like

X * Y ^ Z;

into permutatinator.cpp and in theory, get back a permutative function calculating that, rather than having to type something gross like AND(X,OR(Y,Z)).

~~The iterate function is the function that is probably broken and needs fixing. It is supposed to calculate a single line of permutations, and it does not do that. It attempts to do that using arrays though, it inputs two arrays prefixed with zeros to implement the two things, say if you were trying to go from 1,2,3,4,5 to 1,3,5,4,2 it would have two arrays, 0,1,2,3,4,5 and 0,1,3,5,4,2. I have the zero out front so that an index of 1 is the first item in the array, which allows me to nest arrays to do the whole, 1 goes to 2, 3 goes to 5 thing.~~ This is fixed now.

The compare function works but is part of an earlier version of the iterate function that I gave up on that doesn't work, it allows me to find the index of a number in an array in a very inefficient way.

The nand function probably works, it basically hardcodes the permutations from the nand function on page 2 of the homework and feeds it into the iterate function in the way that the nand function is supposed to work. Since the iterate function doesn't work, I assume the nand function works, but it could be that neither work.

Right now it doesn't work because there's a fundamental logic error as to how the logic works, but that it easily fixable.
