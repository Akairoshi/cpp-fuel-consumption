#include <iostream>
#include <cstdio>

void loop(bool &exitbool)
{
    printf("Do you want continue? [Y/N]: ");
    std::string c{};
    bool exitloop{};
    while (!exitloop)
    {
        std::cin >> c;
        if (c.empty())
        {
            printf("Error: empty input. Try again.\n");
            continue;
        }
        switch (c[0])
        {
        case 'Y':
            exitloop = true;
            break;
        case 'y':
            exitloop = true;
            break;
        case 'N':
            exitloop = true;
            exitbool = true;
            break;
        case 'n':
            exitloop = true;
            exitbool = true;
            break;

        default:
            printf("Enter Y or N: ");
            break;
        }
    }
}

void getNumChar(double &a, double &b, char &operation)
{
    std::string input;

    while (true)
    {
        printf("Enter number a: ");
        std::cin >> input;

        if (input.empty())
        {
            printf("Error: empty input. Try again.\n");
            continue;
        }

        try
        {
            size_t pos;
            a = std::stod(input, &pos);
            if (pos == input.size())
            {
                break;
            }
            else
            {
                printf("Error: invalid number format. Try again.\n");
            }
        }
        catch (const std::invalid_argument &)
        {
            printf("Error: not a valid number. Try again.\n");
        }
        catch (const std::out_of_range &)
        {
            printf("Error: number out of range. Try again.\n");
        }
    }

    while (true)
    {
        printf("Enter number b: ");
        std::cin >> input;

        if (input.empty())
        {
            printf("Error: empty input. Try again.\n");
            continue;
        }

        try
        {
            size_t pos;
            b = std::stod(input, &pos);
            if (pos == input.size())
            {
                break;
            }
            else
            {
                printf("Error: invalid number format. Try again.\n");
            }
        }
        catch (const std::invalid_argument &)
        {
            printf("Error: not a valid number. Try again.\n");
        }
        catch (const std::out_of_range &)
        {
            printf("Error: number out of range. Try again.\n");
        }
    }

    while (true)
    {
        printf("Enter action ac [+ - * /]: ");
        std::cin >> input;

        if (input.empty())
        {
            printf("Error: empty input. Try again.\n");
            continue;
        }

        if (input.size() != 1)
        {
            printf("Error: enter exactly one character. Try again.\n");
            continue;
        }

        operation = input[0];
        if (operation == '+' || operation == '-' || operation == '*' || operation == '/')
        {
            break;
        }
        else
        {
            printf("Error: allowed operations are +, -, *, /. Try again.\n");
        }
    }
}

double calc(double a, double b, char operation, bool &hasError)
{
    switch (operation)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            printf("Error: Divide by zero! (b == %f)\n", b);
            hasError = true;
            return 0;
        }
        else
        {
            return a / b;
        }
    default:
        printf("Error: unknown action\n");
        hasError = true;
        return 0;
    }
}
int main()
{

    bool hasError{}, exitbool{};
    double a{}, b{}, result{};
    char operation{};

    while (!exitbool)
    {
        getNumChar(a, b, operation);
        result = calc(a, b, operation, hasError);
        if (!hasError)
        {
            printf("%f %c %f = %f\n", a, operation, b, result);
        }
        else
        {
            printf("Errors detected!\n");
        }
        loop(exitbool);
    }

    return 0;
}