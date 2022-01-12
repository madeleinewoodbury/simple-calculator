#include <iostream>
#include <string>

void display_menu()
{
    std::cout << "1) Multiplication \n";
    std::cout << "2) Division \n";
    std::cout << "3) Addition \n";
    std::cout << "4) Subtraction \n";
}

int get_calculation_choice()
{
    int choice;

    std::cout << "Select a calculation: ";
    std::cin >> choice;

    return choice;
}

float get_operand(int operand_nr)
{
    float operand;
    if (operand_nr == 1)
    {
        std::cout << "Enter first number: ";
    }
    else
    {
        std::cout << "Enter second number: ";
    }

    std::cin >> operand;
    return operand;
}

void multiply(int num_1, int num_2)
{
    float sum = num_1 * num_2;
    std::cout << num_1 << " * " << num_2 << " = " << sum << std::endl;
}

void divide(int num_1, int num_2)
{
    float sum = num_1 / num_2;
    std::cout << num_1 << " / " << num_2 << " = " << sum << std::endl;
}

void add(int num_1, int num_2)
{
    float sum = num_1 + num_2;
    std::cout << num_1 << " + " << num_2 << " = " << sum << std::endl;
}

void subtract(int num_1, int num_2)
{
    float sum = num_1 - num_2;
    std::cout << num_1 << " - " << num_2 << " = " << sum << std::endl;
}

void perform_calculation(int choice, int num_1, int num_2)
{
    switch (choice)
    {
        case 1:
            multiply(num_1, num_2);
            break;
        case 2:
            divide(num_1, num_2);
            break;
        case 3:
            add(num_1, num_2);
            break;
        case 4:
            subtract(num_1, num_2);
            break;
        default:
            std::cout << "Could not perform calculation\n";
            break;
    }
}

bool new_calculation()
{
    display_menu();
    int choice = get_calculation_choice();
    if (choice != 0)
    {
        float num_1{ get_operand(1) };
        float num_2{ get_operand(2) };
        perform_calculation(choice, num_1, num_2);
    }
    else
    {
        std::cout << "Invalid choice...\n";
    }

    std::string user_input;
    std::cout << "Perform another calculation? (y/n): ";
    getline(std::cin, user_input);

    if (user_input == "y" || user_input == "Y")
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{   
    bool keep_calculating{ true };
    std::cout << "The Simple C++ Calculator!\n";
    while (keep_calculating)
    {
      keep_calculating = new_calculation();
    }

    std::cout << "Goodbye\n";
}

