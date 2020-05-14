/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

 Create a branch named Part3
 
 do not remove anything from main().  you'll be revising your main() to work with these new code changes.
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type
 
 2) remove any getValue() functions if you added them
 
 3) move all of your add/subtract/multiply/divide implementations out of the class.
  
 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
 
 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
         use the proper casting technique to invoke this conversion function
 
 6) clean up any forward declaration that you might have.
 
 7) make sure it compiles & runs without errors.
 
 8) use your knowledge of casting to remove any conversion warnings. 
 
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
    return add(static_cast<float>(*dt.ownedDouble));
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
    }
    else
    {
        *ownedInt /= value;
    }
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
    std::cout << "division float: " << *ft.divide(0.f).ownedFloat << std::endl;
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
