/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

.....just a little change for pushing again ... 
.....just a little change for pushing again ... 
.....just a little change for pushing again ... 

 Create a branch named Part3
 
 do not remove anything from main().  you'll be revising your main() to work with these new code changes.
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type - x
 
 2) remove any getValue() functions if you added them - x
 
 3) move all of your add/subtract/multiply/divide implementations out of the class. - x
  
 4) add user-defined conversion functions that convert to the numeric type your object holds. - x
        i.e. if your type holds an int, you'll need an operator int() function.
 
 5) make your member variable private. - x
         this conversion function should be the ONLY WAY to access the held value.
         use the proper casting technique to invoke this conversion function - x
 
 6) clean up any forward declaration that you might have.
 
 7) make sure it compiles & runs without errors.
 
 8) use your knowledge of casting to remove any conversion warnings. 
 
 */

#include <iostream>

struct IntVal
{
    int value;
    IntVal(int value_) : value(value_) {}

    operator int() { return value; }
};

int freeFunc(int v)
{
    IntVal iv(3);
    int sum = v + iv;
    return sum;
}

void test()
{
    IntVal testVal(5);
    std::cout << "test: " << freeFunc(testVal) << std::endl;
}

//============================================================

struct IntType;
struct DoubleType;

struct FloatType
{ 
    FloatType(float ownedType_) : ownedFloat(new float (ownedType_)) { }
    ~FloatType()
    {
        delete ownedFloat;
        ownedFloat = nullptr;
    }

    operator float() { return *ownedFloat; }
     
    FloatType& add( float value );
    FloatType& subtract( float value );
    FloatType& multiply( float value );
    FloatType& divide( float value );

private:
    float* ownedFloat;
};


struct DoubleType
{
    DoubleType(double doubleValue) : ownedDouble(new double (doubleValue)) { }
    ~DoubleType()
    {
        delete ownedDouble;
        ownedDouble = nullptr;
    }

    operator double() { std::cout << "dt_op" << std::endl; return *ownedDouble; } 

    DoubleType& add( double value );
    DoubleType& subtract( double value );
    DoubleType& multiply( double value );
    DoubleType& divide( double value );

private:
    double* ownedDouble;
};


struct IntType
{
    IntType(int intVal) : ownedInt(new int(intVal)) { }
    ~IntType()
    {
        delete ownedInt;
        ownedInt = nullptr;
    }
    
    operator int() { return *ownedInt; }

    IntType& add(int value);
    IntType& subtract(int value);
    IntType& multiply( int value );
    IntType& divide( int value );

private:
    int* ownedInt;
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
//=============================================================

int main()
{
    test();
    
    //====================
    
    IntType it(3);

    // std::cout << "no crash anymore: " << *it.divide(0).ownedInt << "\n";

    FloatType ft(3.1f);
    DoubleType dt(3.63456);

    /*
    whats the use case for this?
    I imagine: you have a class and dont want to have the risk that the member variables could be changed from outside. thus you would just make them accesible as with getter function right?
    */
    std::cout << "int test: " << it.add(static_cast<int>(dt)) << std::endl;
    
    //testing division
    std::cout << "division float: " << ft.divide(static_cast<int>(dt)) << std::endl;
    std::cout << "division double: " << dt.divide(static_cast<int>(dt)) << std::endl;

    /*
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

    
    it.add(ft).subtract(dt).multiply(dt);
    ft.divide(static_cast<float>(0.0001));
    std::cout << "it value after chain with UDT inputs: " << *it.ownedInt << std::endl;
    std::cout << "it value after chain with UDT inputs: " << *ft.ownedFloat << std::endl;

    std::cout << "good to go!" << std::endl;
    */
}
