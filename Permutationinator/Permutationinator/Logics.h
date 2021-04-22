#pragma once
#include <iostream>
using namespace std;
int nand(int, int);
int mysteryfunct(int, int);
#define VAR_NAME(x) #x;

class Logics {
private:
    int bit;
public:
    Logics(int bt = 0) {
        bit = bt;
    }

    Logics operator * (Logics const& obj) {
        Logics result;
        std::cout << "Start AND" << endl;
        result.bit = nand(nand(bit, obj.bit), nand(bit, obj.bit));
        return result;
    }
    Logics operator ^ (Logics const& obj) {
        Logics result;
        std::cout << "Start OR" << endl;
        result.bit = nand(nand(bit, bit), nand(obj.bit, obj.bit));
        return result;
    }
    Logics operator ! () {
        Logics result;
        std::cout << "Start NOT" << endl;
        result.bit = nand(nand(bit,bit), nand(bit,bit));
        return result;
    }

};

int * iterate(int[], int[]);
int* iterate(int first[], int second[]) {
    static int third[]= { 0,0,0,0,0,0 };
    int j = 1;
    while (j < 6) {
        int first1[7];
        int second1[7];
        first1[1] = first[1];
        first1[2] = first[2];
        first1[3] = first[3];
        first1[4] = first[4];
        first1[5] = first[5];
        first1[6] = first[1];
        second1[1] = second[1];
        second1[2] = second[2];
        second1[3] = second[3];
        second1[4] = second[4];
        second1[5] = second[5];
        second1[6] = second[1];
        std::cout << "third of " << second1[j+1] << "is first of " << j << endl;
        third[(second1[j])] = first1[j];
        j = j + 1;
    }
    j = 1;
    return third;  
}

int compare(int, int, int[]);
int compare(int len, int t, int arr[]) {
    int j = 0;
    while (j < len) {
//This is a search algorithm to find which index the thing is at.
//I'm lazy and/or efficient, if you want to run this a billion times on a super computer
//REPLACE THIS WITH A BINARY SEARCH OR SOMETHING THAT IS ACTUALLY EFFICIENT
        std::cout << "I am:" << arr[0] << endl;
        std::cout << "I am:" << arr[1] << endl;
        std::cout << "I am:" << arr[2] << endl;
        std::cout << "I am:" << arr[3] << endl;
        std::cout << "I am:" << arr[4] << j<< endl;
        // if the i-th element is t
        // then return the index
        if (arr[j]== t) {
            std::cout << "I am returning i of:" << j << endl;
            return j;
        }
        else {
            j = j + 1;
        }
    }
    std::cout << "CRITICAL ERROR, ITEM t NOT FOUND in ARRAY";
    return 5;
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
//or even find a permutative unit similar to the logical nand inherent to the structure of permutations
//that can efficiently represent all logics. I'm not about to win math awards here though, gonna use NAND

    int a[] = { 0,1,3,4,2,5 }; //Why is there a zero here? for convienience, so that int[1] is the first col, and I don't have to reorient things
    int b[] = { 0,1,4,5,2,3 };
    int c[] = { 0,1,5,2,4,3 };
    int d[] = { 0,1,4,2,3,5 };
    int e[] = { 0,1,2,5,3,4 };
    int p[] = { 0,1,2,3,4,5 };
    int t = 0;
    int i = 0;
    int *f;
    int g[] = { 0,0,0,0,0,0 };
    //int cont[] = { 1,2,1,2 }; //x, y, x, y
    int z = 0;

    if (x == 1) {
        f=iterate(a, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f=iterate(p, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }

    g[1] = f[1]; // You may be wondering what all these grossnesses are and the answer is that I like to code in Python, but I'm coding in C++
    g[2] = f[2]; // This means that I'm used to the luxuries of Python's array handling, and not used to weird C++ things where it will glitch
    g[3] = f[3]; // out and say that the next permutation is 1, 5, 5, 5, 5, and that the one after that is 5, 5, 5, 5, 5
    g[4] = f[4]; // I have only a vague idea what causes this, but periodically copying the array to a new array fixes it.
    g[5] = f[5];

    if (y == 1) {
        f=iterate(g, b);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (x == 1) {
        f = iterate(g, c);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (y == 1) {
        f = iterate(g, d);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, e);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5]; 

    if (((f[5] == p[5]) && (f[1] == p[1]) && (f[2] == p[2]) && (f[3] == p[3]) && (f[4] == p[4]))) {
        //there is a better way to do this if you don't know the length of the permutation, but we do so we're doing this
        //if you have randomly lengthed permutations, you'll have to modify this part of the code
        //and honestly more of the code than I care to admit

        z = 0;
        std::cout << "The truth is zero.";
        return z;
    }
    else {
        z = 1;
        std::cout << "The truth is one.";
        return z;
    }

}

int mysteryfunct(int x, int y)
{
    int a[] = { 0,1,4,3,5,2 }; //Why is there a zero here? for convienience, so that int[1] is the first col, and I don't have to reorient things
    int b[] = { 0,1,4,5,2,3 };
    int c[] = { 0,1,3,4,2,5 };
    int d[] = { 0,1,2,4,5,3 };
    int e[] = { 0,1,4,2,3,5 };
    int na[] = { 0,1,2,5,3,4 }; //Why is there a zero here? for convienience, so that int[1] is the first col, and I don't have to reorient things
    int nb[] = { 0,1,3,2,5,4 };
    int nc[] = { 0,1,5,2,4,3 };
    int nd[] = { 0,1,3,5,4,2 };
    int ne[] = { 0,1,5,3,2,4 };
    int p[] = { 0,1,2,3,4,5 };
    int t = 0;
    int i = 0;
    int* f;
    int g[] = { 0,0,0,0,0,0 };
    //int cont[] = { 1,2,1,2 }; //x, y, x, y
    int z = 0;

    if (x == 1) {
        f = iterate(p, d);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(p, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }

    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (y == 1) {
        f = iterate(g, c);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (x == 1) {
        f = iterate(g, nd);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (y == 1) {
        f = iterate(g, nc);
        g[1] = f[1];
        g[2] = f[2];
        g[3] = f[3];
        g[4] = f[4];
        g[5] = f[5];
        f = iterate(g, b);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (x == 1) {
        f = iterate(g, d);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }

    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (y == 1) {
        f = iterate(g, a);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (x == 1) {
        f = iterate(g, nd);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }

    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (y == 1) {
        f = iterate(g, na);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (x == 1) {
        f = iterate(g, c);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }

    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (y == 1) {
        f = iterate(g, d);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (x == 1) {
        f = iterate(g, nc);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }

    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (y == 1) {
        f = iterate(g, nd);
        g[1] = f[1];
        g[2] = f[2];
        g[3] = f[3];
        g[4] = f[4];
        g[5] = f[5];
        f = iterate(g, nb);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, nb);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (x == 1) {
        f = iterate(g, a);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }

    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (y == 1) {
        f = iterate(g, d);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (x == 1) {
        f = iterate(g, na);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }

    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (y == 1) {
        f = iterate(g, p);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    else {
        f = iterate(g, d);
        cout << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << "," << f[5] << endl;
    }
    g[1] = f[1];
    g[2] = f[2];
    g[3] = f[3];
    g[4] = f[4];
    g[5] = f[5];

    if (((f[5] == p[5]) && (f[1] == p[1]) && (f[2] == p[2]) && (f[3] == p[3]) && (f[4] == p[4]))) {
        //there is a better way to do this if you don't know the length of the permutation, but we do so we're doing this
        //if you have randomly lengthed permutations, you'll have to modify this part of the code
        //and honestly more of the code than I care to admit

        z = 0;
        std::cout << "The truth is zero.";
        return z;
    }
    else {
        z = 1;
        std::cout << "The truth is one.";
        return z;
    }

}

/* This code for a nand has a grandiose logical error but I worked hard on it so I'm not deleting it
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
} */
/*
class Logics
{
public:
    Logics& operator*(const Logics& x, const Logics& y);
};
std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    return out << f.num() << '/' << f.den();
}
bool operator==(const Fraction& lhs, const Fraction& rhs)
{
    return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}
bool operator!=(const Fraction& lhs, const Fraction& rhs)
{
    return !(lhs == rhs);
}
Fraction operator*(Fraction lhs, const Fraction& rhs)
{
    return lhs *= rhs;
} 
int nand(int x, int y)
{


    int a[] = {1,3,4,2,5};
    int b[] = {1,4,5,2,3};
    int c[] = {1,5,2,4,3};
    int d[] = {1,3,2,5,4};
    int e[] = {1,2,5,3,4};
    int p[] = {1,2,3,4,5};
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
    if (i == 5) { /*x = 0; std::cout << "The truth is zero!!!";}
    else {
        if (x == 1) {
            t = a[i];
            f[0] = t;
            std::cout << a[i] << "This is t, a" << endl;
            i = compare(5, t, a);
            t = a[i + 1];
        }
        else {
            t = p[i];
            f[0] = t;
            std::cout << p[i] << "This is t, b" << endl;
            i = compare(5, t, p);
            //t = p[i + 1];
        }
        f[1] = t;
        std::cout << "{";
        std::cout << VAR_NAME(x);
        std::cout << ": (" << a[0] << "," << a[1] << "," << a[2] << "," << a[3] << "," << a[4] << ") , * }" << t << endl;
    }
    //Line 2 y: b,p
    if (i == 5) {/* y = 0;  std::cout << "The truth is zero!!!"; }
    else {
        if (y == 1) {
            std::cout << b[i] << "This is t, c" << endl;
            i = compare(5, t, b);
            t = b[i + 1];
        }
        else {
            std::cout << p[i] << "This is t, d" << endl;
            i = compare(5, t, p);
            t = p[i + 1];
        }
        f[2] = t;
        std::cout << "{";
        std::cout << VAR_NAME(y);
        std::cout << ": (" << b[0] << "," << b[1] << "," << b[2] << "," << b[3] << "," << b[4] << ") , * }" << t << endl;
    }
    //Line 3 x: c,p
    if (i == 5) {/* x = 0;  std::cout << "The truth is zero!!!";}
    else {
        if (x == 1) {
            i = compare(5, t, c);
            t = c[i + 1];
        }
        else {
            i = compare(5, t, p);
            t = p[i + 1];
        }
        f[3] = t;
        std::cout << "{";
        std::cout << VAR_NAME(x);
        std::cout << ": (" << c[0] << "," << c[1] << "," << c[2] << "," << c[3] << "," << c[4] << ") , * }" << t << endl;
    }
    //Line 4 y: d,p
    if (i == 5) {/* y = 0;  std::cout << "The truth is zero!!!";}
    else {
        if (y == 1) {
            i = compare(5, t, d);
            t = d[i + 1];
        }
        else {
            i = compare(5, t, p);
            t = p[i + 1];
        }
        f[4] = t;
        std::cout << "{";
        std::cout << VAR_NAME(y);
        std::cout << ": (" << d[0] << "," << d[1] << "," << d[2] << "," << d[3] << "," << d[4] << ") , * }" << t << endl;
    }
    //Line 5 x/y: e,e
    if (i == 5) {/* std::cout << "The truth is zero!!!";}
    else {
            i = compare(5, t, e);
            t = e[i + 1];
    }
    f[4] = t;
    std::cout << "{*: (" << e[0] << "," << e[1] << "," << e[2] << "," << e[3] << "," << e[4] << ") , * }" << t << endl;

    std::cout << "{f: (" << f[0] << "," << f[1] << "," << f[2] << "," << f[3] << "," << f[4] << ") , * }" << endl;

    if ((t < 0) || ((f[0] == p[0]) && (f[1] == p[1]) && (f[2] == p[2]) && (f[3] == p[3]) && (f[4] == p[4]))) {
        //there is a better way to do this if you don't know the length of the permutation, but we do so we're doing this
        //if you have randomly lengthed permutations, you'll have to modify this part of the code
        //and honestly more of the code than I care to admit

        z = 0;
        std::cout << "The truth is zero.";
        return z;
    }
    else {
        z = 1;
        std::cout << "The truth is one.";
        return z;
    }



}*/
