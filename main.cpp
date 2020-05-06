/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6
 
 Create a branch named Part2
 
 New/This/Pointers/References conclusion
 
 Build/Run often with this task to make sure you're not breaking the code with each step.
 I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line.
 on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A'
 on the heap without leaking, without using smart pointers.
 */

struct A {};

struct HeapA
{
    A* a;
    HeapA(A* a_) : a(a_) { }
    ~HeapA() { delete a; }
};

/*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers
 IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
 this argument will initialize the owned primitive's value.
 i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
 a) make them modify the owned numeric type
 b) set them up so they can be chained together.
 i.e.
 DoubleType dt(3.5);
 dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
 These are in addition to your member functions that take primitives
 for example, IntType::divide(const DoubleType& dt);
 These functions should return the result of calling the function that takes the primitive.
 
 5) print out the results with some creative couts
 i.e.
 FloatType ft(0.1f);
 IntType it(3);
 std::cout << "adding 3 and subtracting 'it' from 'ft' results in the following value: " << *ft.add(2.f).subtract( it ).value << std::endl;  //note the dereference of the `value` member of `ft`
 
 6) Don't let your heap-allocated owned type leak!
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.
 
 send me a DM to check your pull request
 
 Wait for my code review.
 */


#include <iostream>

 struct IntType;
 struct FloatType
 {
     float* ownedFloat;
     FloatType(float ownedType_) : ownedFloat(new float (ownedType_)) {}
     ~FloatType()
     {
         delete ownedFloat;
         ownedFloat = nullptr;
     }
     
     float add( float lhs, float rhs );
     float subtract( float lhs, float rhs );
     float multiply( float lhs, float rhs );
     float divide( float lhs, float rhs );
 
     FloatType& add(const IntType& lhs);
     FloatType& subtract(const IntType& lhs);
     FloatType& multiply(const IntType& lhs);
     FloatType& divide(const IntType& lhs);
 };
 
 
 float FloatType::add( float lhs, float rhs )
 {
 return lhs + rhs;
 }
 
 float FloatType::subtract( float lhs, float rhs )
 {
 return lhs - rhs;
 }
 
 float FloatType::multiply( float lhs, float rhs )
 {
 return lhs * rhs;
 }
 
 float FloatType::divide( float lhs, float rhs )
 {
 if (rhs == 0.f)
 {
     std::cout << "watch out when dividing with zero!\n" << std::endl;
 }
 
 return lhs / rhs;
 }
 
 //=============================================================
 //=============================================================
 
 struct DoubleType
 {
     double* ownedDouble;
     DoubleType(double doubleValue) : ownedDouble(new double (doubleValue)) { }
     ~DoubleType()
     {
         delete ownedDouble;
         ownedDouble = nullptr;
     }
 
     DoubleType& add( double lhs );
     DoubleType& subtract( double lhs );
     DoubleType& multiply( double lhs );
     DoubleType& divide( double lhs );
 
     DoubleType& add(const IntType& intType);
     DoubleType& substract(const IntType& intType);
     DoubleType& multiply(const IntType& intType);
     DoubleType& divide(const IntType& intType);
     
     DoubleType& add(const FloatType& intType);
     DoubleType& substract(const FloatType& intType);
     DoubleType& multiply(const FloatType& intType);
     DoubleType& divide(const FloatType& intType);
     
     DoubleType& add(const DoubleType& intType);
     DoubleType& substract(const DoubleType& intType);
     DoubleType& multiply(const DoubleType& intType);
     DoubleType& divide(const DoubleType& intType);
 };

//=============================================================
//=============================================================
 
 DoubleType& DoubleType::add( double lhs )
 {
     *ownedDouble += lhs;
     return *this;
 }
 
 DoubleType& DoubleType::subtract( double lhs )
 {
     *ownedDouble -= lhs;
     return *this;
 }
 
 DoubleType& DoubleType::multiply( double lhs )
 {
     *ownedDouble *= lhs;
     return *this;
 }
 
 DoubleType& DoubleType::divide( double lhs )
 {
     if (lhs == 0.)
     {
         std::cout << "watch out when dividing with zero!\n" << std::endl;
     }
 
     *ownedDouble /= lhs;
     return *this;
 }
 
//=============================================================
//=============================================================





//=============================================================
//=============================================================



//=============================================================
//=============================================================

struct IntType
{
    int* ownedInt;
    
    IntType(int intVal) : ownedInt(new int(intVal)) { }
    ~IntType()
    {
        delete ownedInt;
        ownedInt = nullptr;
    }
    
    IntType& add(int lhs);
    IntType& subtract(int lhs);
    IntType& multiply( int lhs );
    IntType& divide( int lhs );
    
    IntType& add(const IntType& lhs);
    IntType& subtract(const IntType& lhs);
    IntType& multiply(const IntType& lhs);
    IntType& divide(const IntType& lhs);
    
    IntType& add(const FloatType& lhs);
    IntType& subtract(const FloatType& lhs);
    IntType& multiply(const FloatType& lhs);
    IntType& divide(const FloatType& lhs);
    
    IntType& add(const DoubleType& lhs);
    IntType& subtract(const DoubleType& lhs);
    IntType& multiply(const DoubleType& lhs);
    IntType& divide(const DoubleType& lhs);
};

//=============================================================
// HOW DOES *this work? / it´s like return the new state of the instance
//=============================================================

IntType& IntType::add(int lhs)
{
    *ownedInt += lhs;
    return *this;
}

IntType& IntType::subtract( int lhs )
{
    *ownedInt -= lhs;
    return *this;
}

IntType& IntType::multiply( int lhs )
{
    *ownedInt *= lhs;
    return *this;
}

IntType& IntType::divide( int lhs )
{
    if(lhs == 0)
    {
        std::cout << "\nwatch out when dividing with zero! especially when using int. returned zero\n" << std::endl;
    }
    *ownedInt /= lhs;
    return *this;
}

//=============================================================
//=============================================================

IntType& IntType::add(const FloatType& lhs)
{
    return add(*lhs.ownedFloat);
}

IntType& IntType::subtract(const FloatType& lhs)
{
    return subtract(*lhs.ownedFloat);
}

IntType& IntType::multiply(const FloatType& lhs)
{
    return multiply(*lhs.ownedFloat);
}

IntType& IntType::divide(const FloatType& lhs)
{
    return divide(*lhs.ownedFloat);
}

//=============================================================
//=============================================================

IntType& IntType::add(const DoubleType& lhs)
{
    return add(*lhs.ownedDouble);
}

IntType& IntType::subtract(const DoubleType& lhs)
{
    return subtract(*lhs.ownedDouble);
}

IntType& IntType::multiply(const DoubleType& lhs)
{
    return multiply(*lhs.ownedDouble);
}

IntType& IntType::divide(const DoubleType& lhs)
{
    return divide(*lhs.ownedDouble);
}


//=============================================================
//=============================================================

int main()
{
    IntType it(3);
    FloatType ft(3.1f);
    DoubleType dt(3.63456);
    
    // modify ownedNumericType
    std::cout << "it value: " << *it.ownedInt << std::endl;
    it.multiply(3);
    std::cout << "it value after multiply: " << *it.ownedInt << std::endl;
    it.add(4);
    std::cout << "it value after addition: " << *it.ownedInt << std::endl;
    
    // chaining
    // dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
    
    it.add(2).subtract(4).multiply(5);
    std::cout << "it value after chain: " << *it.ownedInt << std::endl;
    
    /*
     4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
     These are in addition to your member functions that take primitives
     for example, IntType::divide(const DoubleType& dt);
     These functions should return the result of calling the function that takes the primitive.
     */
    
    it.add(ft).subtract(dt).multiply(dt);
    std::cout << "it value after chain with UDT inputs: " << *it.ownedInt << std::endl;
    
    std::cout << "good to go!" << std::endl;
}