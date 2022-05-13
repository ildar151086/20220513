/*
Разработать приложение, имитирующее пе-
чать принтера . Должны быть клиенты, посылающие
запросы на принтер, у каждого из которых есть свой
приоритет. Необходимо
сохранять статистику печати (пользователь, время). Предусмотреть вывод статистики на экран.
*/
#include <iostream>

enum PRIORITY {
    BOSS,
    FREND,
    OTHER
};

using namespace std;

class Print {
    // Количество постановок на печать у кождого приоритета
    int sizeBoss;
    int sizefrend;
    int sizeOther;
    // Ссылки на очереди с приоритетом
    int* boss;
    int* frend;
    int* other;
public:
    Print() {
        sizeBoss = 0;
        sizefrend = 0;
        sizeOther = 0;
        boss = nullptr;
        frend = nullptr;
        other = nullptr;
    }

    // Добавляем в очередь на печать в зависимости от приоритета
    void Push(int printComand, int priority) {
        int* temp;
        switch (priority)
        {
            case BOSS:
                if (boss == nullptr) {
                    // Если нету еще команд на печать то создаем очередь
                    boss = new int[++sizeBoss];
                    *boss = printComand;
                    break;
                }
                temp = new int[sizeBoss + 1];
                for (int i = 0; i < sizeBoss; i++) {
                    // Переприсываеввыем старые команды
                    *(temp + i) = *(boss + i);
                }
                //delete[] boss;
                // Добавляем новую команду
                *(temp + sizeBoss) = printComand;
                boss = temp;
                sizeBoss++;
            break;
            case FREND:
                if (frend == nullptr) {
                    // Если нету еще команд на печать то создаем очередь
                    frend = new int[++sizefrend];
                    *frend = printComand;
                    break;
                }
                temp = new int[sizefrend + 1];
                for (int i = 0; i < sizefrend; i++) {
                    // Переприсываеввыем старые команды
                    *(temp + i) = *(frend + i);
                }
                //delete[] frend;
                // Добавляем новую команду
                *(temp + sizefrend) = printComand;
                frend = temp;
                sizefrend++;
            break;
            case OTHER:
                if (other == nullptr) {
                    // Если нету еще команд на печать то создаем очередь
                    other = new int[++sizeOther];
                    *other = printComand;
                    break;
                }
                temp = new int[sizeOther + 1];
                for (int i = 0; i < sizeOther; i++) {
                    // Переприсываеввыем старые команды
                    *(temp + i) = *(other + i);
                }
                //delete[] other;
                // Добавляем новую команду
                *(temp + sizeOther) = printComand;
                other = temp;
                sizeOther++;
            break;
            default:
                cout << "Введенное значение приоритета недопустимо" << endl;
            break;
        }
    }

    void pop() {
        int* temp;
        if (sizeBoss != 0) {
            cout << "Отправлена команда на печать босс " << *(boss + sizeBoss - 1) << endl;
            temp = new int[sizeBoss - 1];
            for (int i = 0; i < sizeBoss; i++) {
                *(temp + i) = *(boss + i);
            }
            sizeBoss--;
            boss = temp;
            return;
        }
        if (sizefrend != 0) {
            cout << "Отправлена команда на печать друг " << *(frend + sizefrend - 1) << endl;
            temp = new int[sizefrend - 1];
            for (int i = 0; i < sizefrend; i++) {
                *(temp + i) = *(frend + i);
            }
            sizefrend--;
            frend = temp;
            return;
        }
        if (sizeOther != 0) {
            cout << "Отправлена команда на печать другое " << *(other + sizeOther - 1) << endl;
            temp = new int[sizeOther - 1];
            for (int i = 0; i < sizeOther; i++) {
                *(temp + i) = *(other + i);
            }
            sizeOther--;
            other = temp;
            return;
        }
        cout << "Очередь на печать пуста";
    }

    void show() {
        cout << "Очередь Босс ";
        for (int i = 0; i < sizeBoss; i++) {
            cout << *(boss + i) << " ";
        }
        cout << endl;
        cout << "Очередь Друг ";
        for (int i = 0; i < sizefrend; i++) {
            cout << *(frend + i) << " ";
        }
        cout << endl;
        cout << "Очередь Другое ";
        for (int i = 0; i < sizeOther; i++) {
            cout << *(other + i) << " ";
        }
        cout << endl;
    }

    bool inEmty() {
        if (sizeBoss != 0 || sizefrend != 0 || sizeOther != 0) {
            return 1;
        }
        return 0;
    }

    ~Print() {
        //if (boss != nullptr) {
        //    delete[] boss;
        //}
        //if (frend != nullptr) {
        //    delete[] frend;
        //}
        //if (other != nullptr) {
        //    delete[] other;
        //}
    }

};


int main()
{
    setlocale(LC_ALL, "RUS");
    Print print;

    for (int i = 0; i < 3; i++) {
        print.Push(i, BOSS);
    }
    for (int i = 0; i < 6; i++) {
        print.Push(i, FREND);
    }
    for (int i = 0; i < 10; i++) {
        print.Push(i, OTHER);
    }

    print.show();

    while (print.inEmty()) {
        print.pop();
    }
}
