/*
 * COMP2011 (Fall 2020) Assignment 1: Binary Numbers
 *
 * Student name: WU,Jingyu
 * Student ID: 20677550
 * Student email: jwubv@connect.ust.hk
 *
 * Note:
 * 1. You CANNOT define and use any arrays.
 * 2. You CANNOT define and use any global variables.
 * 3. You CANNOT use the static keyword.
 * 4. You CANNOT include any extra libraries other than iostream.
 * 5. You CANNOT use any bitwise operators: ~, ^, |, & (since they are not taught in this course).
 * 6. You CANNOT change the function headers of the functions given in the tasks.
 * 7. You CANNOT use any string operations.
 * 8. You can add helper functions.
 */
//helper function
int twopower(int pow)
{
    int result = 1;
    for (int i = 0; i < pow; i++)
    {
        result *= 2;
    }
    return result;
}

#include <iostream>

using namespace std;

// Task 1
int get_min_bits_length(int x)
{
    int factorial = 1;
    int count = 0;
    if (x == 0 || x == -1 || x == 1)
    {
        return 2;
    }
    
    else if (x > 1)
    {
        while (factorial <= x)
        {
            factorial *= 2;
            count++;
        }
        return count + 1;
    }
    else if (x < -1)
    {
        while (factorial <= (-x-1))
        {
            factorial *= 2;
            count++;
        }
        return count + 1;
    }
}

// Task 2
int get_bit_positive(int x, int n)
{
    if ( x<0 || n<0 )
    {
        return -1;
    }
    else if ( n >= get_min_bits_length(x)-1 )
    {
        return 0;
    }
    else
    {   int min_length = get_min_bits_length(x) ;
        for (int i = min_length-1; (i-1)>n ;i--)
        {
            if (x>=twopower(i-1))
            {  
                x = x - twopower(i-1) ;
            }       
        }
        return x >= twopower(n) ? 1 : 0;
    }
    
}

// Task 3
int get_bit_negative(int x, int n)
{
    if ( x>=0 || n<0)
    {
        return -1;
    }
    else
    {
        if ( n >= get_min_bits_length(x)-1 )
        {
            return 1;
        }
        else
        {
            return (get_bit_positive( -x-1, n )+1)%2;
        }
        
    }
    
}

// Task 4
void print_2s_complement_representation(int x)
{
    if (x>=0)
    {
        for (int i = get_min_bits_length(x)-1; i >= 0; i--)
        {
            cout<<get_bit_positive(x,i);
        }
        cout<<endl;
    }
    else
    {
        for (int i = get_min_bits_length(x)-1; i >= 0; i--)
        {
            cout<<get_bit_negative(x,i);
        }
        cout<<endl;
    }
    
}

// helper function
int get_bit(int x, int n)
{
	if (x >= 0)
	{
		return get_bit_positive(x, n);
	}
	else
	{
		return get_bit_negative(x, n);
	}
}
// Task 5
void print_addition_carry_out(int a, int b)
{
    int carryout = 0;
    int total = 0;
    int max_length = (get_min_bits_length(a) >= get_min_bits_length(b)) ? get_min_bits_length(a) : get_min_bits_length(b);
    for (int i = 0; i < max_length; i++)
    {
        if ( get_bit(a,i) + get_bit(b,i) + carryout >=2 )
        {
            carryout = 1;
            total += twopower(i);
        }
        else 
        {
            carryout = 0;
        }
    }
    for (int i = max_length - 1; i >= 0; i--)
	{
		cout << get_bit(total, i);
	}
    cout<<endl;
    
}

// DO NOT WRITE ANYTHING AFTER THIS LINE. ANYTHING AFTER THIS LINE WILL BE REPLACED

int main()
{
    while (true)
    {
        int option = 0;

        do
        {
            cout << "1. Task 1" << endl;
            cout << "2. Task 2" << endl;
            cout << "3. Task 3" << endl;
            cout << "4. Task 4" << endl;
            cout << "5. Task 5" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter an option (0-5): ";
            cin >> option;
        } while (option < 0 || option > 5);

        if (option == 0)
            break;
        else if (option == 1)
        {
            int number;
            cout << "Enter a number: ";
            cin >> number;
            cout << number << " needs " << get_min_bits_length(number) << " bits." << endl;
        }
        else if (option == 2)
        {
            int number;
            int bit;

            cout << "Enter a number: ";
            cin >> number;

            cout << "Which bit? ";
            cin >> bit;

            cout << "The number " << bit << " bit of " << number << " is " << get_bit_positive(number, bit) << endl;
        }
        else if (option == 3)
        {
            int number;
            int bit;

            cout << "Enter a number: ";
            cin >> number;

            cout << "Which bit? ";
            cin >> bit;

            cout << "The number " << bit << " bit of " << number << " is " << get_bit_negative(number, bit) << endl;
        }
        else if (option == 4)
        {
            int number;
            cout << "Enter a number: ";
            cin >> number;
            cout << "The 2's complement representation of " << number << " is:" << endl;
            print_2s_complement_representation(number);
        }
        else if (option == 5)
        {
            int a, b;
            cout << "Enter number A: ";
            cin >> a;
            cout << "Enter number B: ";
            cin >> b;
            cout << "The sum of " << a << " and " << b << " is " << a + b << ". The carry bits are:" << endl;
            print_addition_carry_out(a, b);
        }

        cout << endl;
    }

    return 0;
}