#include <bits/stdc++.h>
using namespace std;

int count_digits(int num)
{
    int count = 0;
    while (num > 0)
    {
        num = num / 10;
        count++;
    }

    return count;
}

int reverse_number(int num)
{
    int reverse_number = 0;
    while (num > 0)
    {
        int last_num = num % 10;
        num = num / 10;
        reverse_number = (reverse_number * 10) + last_num;
    }

    return reverse_number;
}

string check_pallindrome_for_number(int num)
{
    int reverse_number = 0;
    int dup_num = num;
    while (num > 0)
    {
        int last_num = num % 10;
        num = num / 10;
        reverse_number = (reverse_number * 10) + last_num;
    }

    return dup_num == reverse_number ? "true" : "false";
}

string check_armstrong(int num)
{
    int sum = 0;
    int dup_num = num;
    while (num > 0)
    {
        int last_num = num % 10;
        num = num / 10;
        sum = sum + last_num * last_num * last_num;
    }

    return dup_num == sum ? "true" : "false";
}

void get_all_divisors_badway(int num)
{
    vector<int> divisors;
    int count = 0;

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            divisors.push_back(i);
        }
        count++;
    }

    for (int dv : divisors)
    {
        cout << dv << endl;
    }

    cout << "Badway ran " << count << " many times";
}

void get_all_divisors(int num)
{
    vector<int> divisors;
    int count = 0;

    int sqrt_num = sqrt(num);
    for (int i = 1; i <= sqrt_num; i++) // alternatively we could have used for (int i = 1; i*i <= num; i++)
    {
        if (num % i == 0)
        {
            divisors.push_back(i);
            if ((num / i) != i)
            {
                divisors.push_back(num / i);
            }
        }

        count++;
    }

    sort(divisors.begin(), divisors.end());

    for (int dv : divisors)
    {
        cout << dv << endl;
    }

    cout << "Goodway ran " << count << " many times";
}

string check_prime_number(int num)
{
    int count = 0;
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {

            count++;
            if (num / i != i)
            {
                count++;
            }
        }
    }

    return count > 2 ? "false" : "true";
}

/*
** GCD (Greatest Common Divisor)/HCF (Highest Common Factor):
** Euclidean Algorithm gcd(a,b) = gcd(a%b,b)  a > b; do the same operation till any number becomes zero;
** Eg gcd(12,9) factors of 12=> {1,2,3,4,6,12} factors of 9=> {1,3,9} so from these factors common factors are {1,3} but we will considered 3 because it is greatest one Greatest Common Divisor(GCD)
**Time Complexity O(logϕ(min(a,b)))  where ϕ is a base ,why because it does not know how many division are going to occur, number of division differs depending upon the different values  
*/
int greatest_common_divisor(int num1, int num2)
{
    while (num1 > 0 && num2 > 0)
    {
        if (num1 > num2)
            num1 = num1 % num2;
        else
            num2 = num2 % num1;
    }

    return num1 == 0 ? num2 : num1;
}

int main()
{
    int input1, input2;
    cin >> input1 >> input2;
    // auto result = count_digits(input);
    // auto result = reverse_number(input);
    // auto result = check_pallindrome_for_number(input);
    // auto result = check_armstrong(input);
    // get_all_divisors_badway(input);
    // get_all_divisors(input);
    // auto result = check_prime_number(input);
    auto result = greatest_common_divisor(input1, input2);
    cout << result << endl;
    return 0;
}