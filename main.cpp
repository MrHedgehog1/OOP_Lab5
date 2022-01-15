#include <iostream>
#include "exception"
#pragma clang diagnostic pop

const int ARRSIZE = 12;
int maxinumModuloElement(signed int* arr,const int SIZE);
void sort_zero(signed int* arr, int as);
void sum_between(signed int* arr, int as);

class zero_error
{
private:
    std::string _my_err;
public:
    zero_error(std::string my_error);
    const char* getError();
};
zero_error::zero_error(std::string my_error) {
    _my_err = my_error;
}
const char* zero_error::getError()
{
    return _my_err.c_str();
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
int main() {
    signed int* arr = new signed int[ARRSIZE];

    char command;
    bool create_arr = false;
    std::cout << "Каким способом вы хотите создать массив? \n";
    std::cout << "\t1. Заполнить его случайными числами.\n";
    std::cout << "\t2. Ввести числа в массив вручную.\n";
    std::cin >> command;
    std::cin.ignore();
    while (!create_arr)
    {
        if (command == '1')
        {
            // заполнение массива случайными числами заданного диапазона (от -99 до 99)
            //srand(time(NULL) || clock());
            for (int i = 0; i < ARRSIZE; i++)
            {
                arr[i] = ((-99) + rand()%198);
            }
            create_arr = true;
        }
        else if (command == '2')
        {
            // заполнение массива с клавиатурного ввода
            std::cout << "\nВведите значения в массив, положительные и отрицательные\n (максимальное значение int - 2147483647 :" << std::endl;
            for (int i = 0; i < ARRSIZE; i++)
            {
                std::cin >> arr[i];
            }
            create_arr = true;
        }
        else
        {
            std::cout << "\nВы ввели неверную команду, введите 1 или 2." << std::endl;
            std::cin >> command;
        }
    }

    // отображение созданного массива
    std::cout << std::endl;
    std::cout << "Элементы массива:\n";
    for (int i = 0; i < ARRSIZE; i++)
    {
        std::cout << " #" << i << ": " << arr[i];
        if (i % 10 == 0)
        {
            std::cout << std::endl;
        }

    }

    bool exit = false;
    while (!exit)
    {
        std::cout << "\nКак вы хотите обработать массив? \n";
        std::cout << "\t1. Максимальный по модулю элемент массива.\n";
        std::cout << "\t2. сумму элементов массива, расположенных между первым и вторым положительными\n"
                     "элементами.\n";
        std::cout << "\t3. Преобразовать массив так чтобы элементы, равные нулю, располагались после\n"
                     "всех остальных.\n";
        std::cout << "\t4. Выход из программы.\n";
        std::cout << "Команда: ";
        std::cin >> command;
        std::cin.ignore();
        switch (command)
        {
            case '1':
                try
                {
                    maxinumModuloElement(arr, ARRSIZE);
                }
                catch (...)
                {
                    std::cout << "ERROR!\nЗначение слишком большое!" << std::endl;
                }
                break;
            case '2':
                try
                {
                    sum_between(arr, ARRSIZE);
                }
                catch (zero_error& error)
                {
                    std::cout << "ERROR!\nОшибка выполнения расчетов!" << std::endl;
                    std::cerr <<  error.getError() << std::endl;
                }
                break;
            case '3':
                sort_zero(arr, ARRSIZE);
                break;
            case '4':
                exit = true;
                break;
            default:
                std::cout << "Вы ввели некорректную команду. Введите от 1 до 8." << std::endl;
                break;
        }
    }

    delete[] arr;
    return 0;
}

void sum_between(signed int* arr, int as)
{
    std::cout << "Введите размер массива ";
    std::cin >> as;
    // ищем первый нулевой элемент
    int first_zero = 0;
    while ((arr[first_zero] < 0) && (first_zero < as))
    {
        first_zero++;
    }

    // ищем последний нулевой элемент
    int last_zero = first_zero +1;
    while ((arr[last_zero] < 0) && (last_zero < as))
    {
        last_zero++;
    }


    int sum = 0;
    while (first_zero != last_zero)
    {
        sum += arr[first_zero];
        first_zero++;
    }
    std::cout << "Сумма чисел между первым и вторым положтельным равна " << (sum = sum + arr[last_zero]) << std::endl;
}

void sort_zero(signed int* arr, int as)
{
    // нужно вытеснить нули
    // Преобразовать массив так чтобы элементы, равные нулю, располагались после\n"
    //                     "всех остальных
    for (int i = as; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] == 0)
            {-1
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                break;
            }
        }
    }

    for (int i = 0; i < as; i++){
        std::cout << arr[i] << " ";
    }
}

int maxinumModuloElement(signed int* arr,const int SIZE){
    int max = -1;
    int c;
    for (int i = 0; i < SIZE; i++)
    {
        c = abs(arr[i]);
        if ( c > max)
        {
            std::cout << abs(arr[i]) << std::endl;
            std::cout << (max = abs(arr[i])) << std::endl;
        }
    }
    std::cout << std::endl << "Максимальный по модулю элемент массива - " <<  max << std::endl;
}