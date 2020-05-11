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
struct DoubleType;

struct FloatType
{
    float* ownedFloat;
    FloatType(float ownedType_) : ownedFloat(new float (ownedType_)) { }
    ~FloatType()
    {
        delete ownedFloat;
        ownedFloat = nullptr;
    }
     
    FloatType& add( float value );
    FloatType& subtract( float value );
    FloatType& multiply( float value );
    FloatType& divide( float value );
 
    FloatType& add(const IntType& value);
    FloatType& subtract(const IntType& value);
    FloatType& multiply(const IntType& value);
    FloatType& divide(const IntType& value);

    FloatType& add(const DoubleType& value);
    FloatType& subtract(const DoubleType& value);
    FloatType& multiply(const DoubleType& value);
    FloatType& divide(const DoubleType& value);

    FloatType& add(const FloatType& value);
    FloatType& subtract(const FloatType& value);
    FloatType& multiply(const FloatType& value);
    FloatType& divide(const FloatType& value);
};

struct DoubleType
{
    double* ownedDouble;
    DoubleType(double doubleValue) : ownedDouble(new double (doubleValue)) { }
    ~DoubleType()
    {
        delete ownedDouble;
        ownedDouble = nullptr;
    }

    DoubleType& add( double value );
    DoubleType& subtract( double value );
    DoubleType& multiply( double value );
    DoubleType& divide( double value );

    DoubleType& add(const IntType& intType);
    DoubleType& subtract(const IntType& intType);
    DoubleType& multiply(const IntType& intType);
    DoubleType& divide(const IntType& intType);
    
    DoubleType& add(const FloatType& intType);
    DoubleType& subtract(const FloatType& intType);
    DoubleType& multiply(const FloatType& intType);
    DoubleType& divide(const FloatType& intType);
    
    DoubleType& add(const DoubleType& intType);
    DoubleType& subtract(const DoubleType& intType);
    DoubleType& multiply(const DoubleType& intType);
    DoubleType& divide(const DoubleType& intType);
};

struct IntType
{
    int* ownedInt;
    
    IntType(int intVal) : ownedInt(new int(intVal)) { }
    ~IntType()
    {
        delete ownedInt;
        ownedInt = nullptr;
    }
    
    IntType& add(int value);
    IntType& subtract(int value);
    IntType& multiply( int value );
    IntType& divide( int value );
    
    IntType& add(const IntType& value);
    IntType& subtract(const IntType& value);
    IntType& multiply(const IntType& value);
    IntType& divide(const IntType& value);
    
    IntType& add(const FloatType& value);
    IntType& subtract(const FloatType& value);
    IntType& multiply(const FloatType& value);
    IntType& divide(const FloatType& value);
    
    IntType& add(const DoubleType& value);
    IntType& subtract(const DoubleType& value);
    IntType& multiply(const DoubleType& value);
    IntType& divide(const DoubleType& value);
};

//=============================================================
// FLOAT TYPE
 //=============================================================
 
FloatType& FloatType::add( float value )
{
    *ownedFloat += value;
    return *this;
}

FloatType& FloatType::subtract( float value )
{
    *ownedFloat -= value;
    return *this;
}

FloatType& FloatType::multiply( float value )
{
    *ownedFloat *= value;
    return *this;
}

FloatType& FloatType::divide( float value )
{
    if (value == 0.f)
    {
        std::cout << "watch out when dividing with zero!\n" << std::endl;
        return *this;
    }

    *ownedFloat /= value;
    return *this;
}

  //=============================================================
  // 2
 //=============================================================

FloatType& FloatType::add( const FloatType& ft )
{
    return add(*ft.ownedFloat);
}

FloatType& FloatType::subtract( const FloatType& ft )
{
    return subtract(*ft.ownedFloat);
}

FloatType& FloatType::multiply( const FloatType& ft )
{
    return multiply(*ft.ownedFloat);
}

FloatType& FloatType::divide( const FloatType& ft )
{
    return divide(*ft.ownedFloat); // divide checks for 0
}

  //=============================================================
  // 3
 //=============================================================

FloatType& FloatType::add( const DoubleType& dt )
{
    return add((float)*dt.ownedDouble);
}

FloatType& FloatType::subtract( const DoubleType& dt )
{
    return subtract(*dt.ownedDouble);
}

FloatType& FloatType::multiply( const DoubleType& dt )
{
    return multiply(*dt.ownedDouble);
}

FloatType& FloatType::divide( const DoubleType& dt )
{
    return divide(*dt.ownedDouble); // divide checks for 0
}

//=============================================================
// 4
//=============================================================

FloatType& FloatType::add( const IntType& it )
{
    return add(*it.ownedInt);
}

FloatType& FloatType::subtract( const IntType& it )
{
    return subtract(*it.ownedInt);
}

FloatType& FloatType::multiply( const IntType& it )
{
    return multiply(*it.ownedInt);
}

FloatType& FloatType::divide( const IntType& it )
{
    return divide(*it.ownedInt); // divide checks for 0
}

 //=============================================================
 //=============================================================
 
 

//=============================================================
// 1
//=============================================================
DoubleType& DoubleType::add( double value )
{
    *ownedDouble += value;
    return *this;
}

DoubleType& DoubleType::subtract( double value )
{
    *ownedDouble -= value;
    return *this;
}

DoubleType& DoubleType::multiply( double value )
{
    *ownedDouble *= value;
    return *this;
}

DoubleType& DoubleType::divide( double value )
{
    if (value == 0.)
    {
    std::cout << "watch out when dividing with zero!\n" << std::endl;
    return *this;
    }

    *ownedDouble /= value;
    return *this;
}

//=============================================================
// 2
//=============================================================

DoubleType& DoubleType::add( const IntType& it )
{
    return add(*it.ownedInt);
}

DoubleType& DoubleType::subtract( const IntType& it )
{
    return subtract(*it.ownedInt);
}

DoubleType& DoubleType::multiply( const IntType& it )
{
    return multiply(*it.ownedInt);
}

DoubleType& DoubleType::divide( const IntType& it )
{
    return divide(*it.ownedInt); // divide checks for 0
}



//=============================================================
// 3
//=============================================================
DoubleType& DoubleType::add( const DoubleType& dt )
{
    return add(*dt.ownedDouble);
}

DoubleType& DoubleType::subtract( const DoubleType& dt )
{
    return subtract(*dt.ownedDouble);
}

DoubleType& DoubleType::multiply( const DoubleType& dt )
{
    return multiply(*dt.ownedDouble);
}

DoubleType& DoubleType::divide( const DoubleType& dt )
{
    return divide(*dt.ownedDouble); // divide checks for 0
}


//=============================================================
// 4
//=============================================================

DoubleType& DoubleType::add( const FloatType& ft )
{
    return add(*ft.ownedFloat);
}

DoubleType& DoubleType::subtract( const FloatType& ft )
{
    return subtract(*ft.ownedFloat);
}

DoubleType& DoubleType::multiply( const FloatType& ft )
{
    return multiply(*ft.ownedFloat);
}

DoubleType& DoubleType::divide( const FloatType& ft )
{
    return divide(*ft.ownedFloat); // divide checks for 0
}

//=============================================================
//=============================================================

//=============================================================
// 1
//=============================================================

IntType& IntType::add(int value)
{
    *ownedInt += value;
    return *this;
}

IntType& IntType::subtract( int value )
{
    *ownedInt -= value;
    return *this;
}

IntType& IntType::multiply( int value )
{
    *ownedInt *= value;
    return *this;
}

IntType& IntType::divide( int value )
{
    if(value == 0)
    {
        std::cout << "\nwatch out when dividing with zero! especially when using int. returned zero\n" << std::endl;
        return *this;
    }
    *ownedInt /= value;
    return *this;
    
}
//=============================================================
// 2
//=============================================================

IntType& IntType::add(const FloatType& value)
{
    return add(*value.ownedFloat);
}

IntType& IntType::subtract(const FloatType& value)
{
    return subtract(*value.ownedFloat);
}

IntType& IntType::multiply(const FloatType& value)
{
    return multiply(*value.ownedFloat);
}

IntType& IntType::divide(const FloatType& value)
{
    return divide(*value.ownedFloat);
}

//=============================================================
// 3
//=============================================================

IntType& IntType::add(const DoubleType& value)
{
    return add(*value.ownedDouble);
}

IntType& IntType::subtract(const DoubleType& value)
{
    return subtract(*value.ownedDouble);
}

IntType& IntType::multiply(const DoubleType& value)
{
    return multiply(*value.ownedDouble);
}

IntType& IntType::divide(const DoubleType& value)
{
    return divide(*value.ownedDouble);
}


//=============================================================
// 4
//=============================================================
IntType& IntType::add(const IntType& it)
{
    return add(*it.ownedInt);
}

IntType& IntType::subtract(const IntType& it)
{
    return subtract(*it.ownedInt);
}

IntType& IntType::multiply(const IntType& it)
{
    return multiply(*it.ownedInt);
}

IntType& IntType::divide(const IntType& it)
{
    return divide(*it.ownedInt);
}

//=============================================================
//=============================================================

int main()
{
    IntType it(3);

    std::cout << "no crash anymore: " << *it.divide(0).ownedInt << "\n";

    FloatType ft(3.1f);
    DoubleType dt(3.63456);

    //testing division
    std::cout << "division float: " << *ft.divide(0).ownedFloat << std::endl;
    std::cout << "division double: " << *dt.divide(0).ownedDouble << std::endl;

    
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
    ft.divide(0.0001);
    std::cout << "it value after chain with UDT inputs: " << *it.ownedInt << std::endl;
    std::cout << "it value after chain with UDT inputs: " << *ft.ownedFloat << std::endl;

    std::cout << "good to go!" << std::endl;


}
