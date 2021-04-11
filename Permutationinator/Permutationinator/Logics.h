#pragma once
#include <iostream>
int nand(int, int);
class Logics
{
    friend Logics operator* (const Logics&, const Logics&);
    friend Logics operator^ (const Logics&, const Logics&);
    friend Logics operator! (const Logics&);

//overriding the *, ^, and ! operators to behave like logic operators for logic
public:
    Logics(int = 0, int = 1);
    Logics(const Logics&);
    Logics& operator=(const Logics&);
private:
    int x, y;
};
Logics operator*(const Logics& x, const Logics& y)
{
    Logics z(nand(nand(x.x,y.y),nand(x.x,y.y)));
    return z;
}
Logics operator^(const Logics& x, const Logics& y)
{
    Logics z(nand(nand(x.x,x.x),nand(y.y,y.y)));
    return z;
}
Logics operator!(const Logics& x)
{
    Logics z(nand(x.x,x.x));
    return z;
}

inline Logics operator==(const Logics&, int)
{
    return Logics();
}

int compare(int, int, int[]);
int compare(int len, int t, int arr[]) {
    int i = 0;
    while (i < len) {
//This is a search algorithm to find which index the thing is at.
//I'm lazy and/or efficient, if you want to run this a billion times on a super computer
//REPLACE THIS WITH A BINARY SEARCH OR SOMETHING THAT IS ACTUALLY EFFICIENT

        // if the i-th element is t
        // then return the index
        if (arr[i] == t) {
            return i;
        }
        else {
            i = i + 1;
        }
    }
}

int nand(int x, int y)
{
    //Here I'm partially hard coding a permutative nand, which I will use to do all the comps
    //If you are Marc Riedel et. al and you want to use this for researchy things
    //You might want to like generate nand functions
    //So you'd modify this part of the code
    //This is not a good nand, this isn't even the best nand, this is just the nand you introduced
    //at the begining of the homework and I'm lazy and/or efficient
    //if you wanted to improve this program's efficiency, you'd maybe swap it for a better nand

    int a[] = {1,3,4,2,5};
    int b[] = {1,4,5,2,3};
    int c[] = {1,5,2,4,3};
    int d[] = {1,3,2,5,4};
    int e[] = {1,2,5,3,4};
    int p[] = { 1,2,3,4,5 };
    int t = 0;
    int i = 0;
    int f[] = { 0,0,0,0,0 };
    int z = 0;

    //cout << "a = (" << a[0] << "," << a[1] << "," << a[2] << "," + a[3] << "," << a[4] << ")";
    //cout << "b = (" << b[0] << "," << b[1] << "," << b[2] << "," + b[3] << "," << b[4] << ")";
    //cout << "c = (" << c[0] << "," << c[1] << "," << c[2] << "," + c[3] << "," << c[4] << ")";
    //cout << "d = (" << d[0] << "," << d[1] << "," << d[2] << "," + d[3] << "," << d[4] << ")";
    //cout << "e = (" << e[0] << "," << e[1] << "," << e[2] << "," + e[3] << "," << e[4] << ")";
    //cout << "* = (" << p[0] << "," << p[1] << "," << p[2] << "," + p[3] << "," << p[4] << ")";

    //Line 1 x: {a,p}
    if (x == 1) t = a[i];
    else t = p[i];
    f[0] = t;
    std::cout << "{x: (" << a[0] << "," << a[1] << "," << a[2] << "," + a[3] << "," << a[4] << ") , * }";

    //Line 2 y: b,p
    if (y == 1) {
        i = compare(5, t, b);
        t = b[i + 1];
    }
    else {
        i = compare(5, t, p);
        t = p[i + 1];
    }
    f[1] = t;
    std::cout << "{x: (" << b[0] << "," << b[1] << "," << b[2] << "," + b[3] << "," << b[4] << ") , * }";

    //Line 3 x: c,p
    if (y == 1) {
        i = compare(5, t, c);
        t = c[i + 1];
    }
    else {
        i = compare(5, t, p);
        t = p[i + 1];
    }
    f[2] = t;
    std::cout << "{x: (" << c[0] << "," << c[1] << "," << c[2] << "," + c[3] << "," << c[4] << ") , * }";

    //Line 4 y: d,p
    if (y == 1) {
        i = compare(5, t, d);
        t = d[i + 1];
    }
    else {
        i = compare(5, t, p);
        t = p[i + 1];
    }
    f[3] = t;
    std::cout << "{x: (" << d[0] << "," << d[1] << "," << d[2] << "," + d[3] << "," << d[4] << ") , * }";

    //Line 5 x/y: e,e
    
        i = compare(5, t, e);
        t = e[i + 1];

    f[4] = t;
    std::cout << "{x: (" << e[0] << "," << e[1] << "," << e[2] << "," + e[3] << "," << e[4] << ") , * }";

    if ((f[0] == p[0]) && (f[1] == p[1]) && (f[2] == p[2]) && (f[3] == p[3]) && (f[4] == p[4])) {
        //there is a better way to do this if you don't know the length of the permutation, but we do so we're doing this
        //if you have randomly lengthed permutations, you'll have to modify this part of the code
        //and honestly more of the code than I care to admit

        z = 0;
        return z;
    }
    else {
        z = 1;
        return z;
    }



}
