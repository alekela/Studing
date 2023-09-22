#include <iostream>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>


using namespace std;


int* split(string str, char separator){
    
}


int main(){
    string music[14] = {"Master of puppets Metallica", "Брошу Pyrokinesis", "Homebody PH1","Червяк Даргомыжский","Russian Ebunny","Enemy Imagine dragons"," Зизазай Огги и тараканы","Valentine Justice","Swimming pools Kendrick Lamar","Night Call Kovinsky","Yesterday The Beatles","Так закалялась сталь Гражданская оборона","За деньги да Инстасамка","Bad habits Ed sheeran"}; 
    string movies[14] ={"Короткое замыкание", "Трансформеры", "Полночь", "По соображениям совести","Джентльмены","Ван Хельсинк","Операция Ы","Драйв","Большая игра","Игра в имитацию","Всё везде и сразу","Форрест Гамп","Терминал","Не смотрите наверх"};
    string actors[14] = {"Райан Гослинг", "Кристиан Бейл", "Джеки Чан","Эндрю Гарфилд","Леонардо ДиКаприо","Бенедикт Кембербетч","Мэтью Макконахи","Дэвид Линч","Дэниэлл Рэдклифф","Джейк Джиллехолл","Александр Петров","Рональд Рейган","Том Круз","Брэд Питт"} ;
    string actriss[14] = {"Наталия Крачковская", "Меган Фокс", "Джениффер Лопез","Эмма Стоун","Эмма Уотсон","Кира Найтли","Милла Йовович","Марго Робби","Мерил Стрип","Скарлет Йоханссон","Александра Бортич","Анджелина Джоли","Шарлиз Терон","Ингеборга Дапкунайте"} ;
    string celeb[14] = {"Дейв Майнстейн", "Иван Зола", "Сергей Мавроди", "Екатерина Гордеева", "Роберт Опенгеймер", "Лионель Месси", "Папич", "Хидэо Кодзима", "Ляйсан Утяшева","Павел Воля","Криштиану Роналду","Борис Бурда","Ким Кардашьян","Клава Кока"};

    string name, surname;
    string date;

    cout << "Введите имя:" << endl;
    cin >> name >> surname;
    cout << "Введите дату рождения:" << endl;
    cin >> date;

    srand(time(NULL));

    int sum = 0;
    int month = 0;
    bool start = false;
    for (int i = 0; i < date.length(); i++){
        if (date[i] != '.'){
            sum += (int) (date[i] - '0');
        }
        if (date[i] == '.'){
            start = (start == true) ? false : true; 
        }
        if (start == true && date[i] != '.'){
            month += (int) (date[i] - '0');
        }
    }
    long long int seed = pow(sum, month / 2);
    int r = rand() % 3;
    if (r == 0) {
        seed = seed;
    }
    else if (r == 1) {
        seed += 11111111;
    }
    else {
        seed += 22222222;
    }
    
    int bits[20];
    for (int i = 0; i < 20; i++){
        bits[i] = seed % 2;
        seed /= 2;
    }
    
    int counter = 0;
    for (int i = 0; i < 5; i++){
        int tmp = 0;
        for (int j = 0; j < 4; j++){
            tmp += bits[4 * i + j] * pow(2, j);
        }
        tmp = tmp % 14;
        if (counter == 0){
            cout << music[tmp] << endl;
        }
        else if (counter == 1){
            cout << movies[tmp] << endl;
        }
        else if (counter == 2){
            cout << actors[tmp] << endl;
        }
        else if (counter == 3){
            cout << actriss[tmp] << endl;
        }
        else if (counter == 4){
            cout << celeb[tmp] << endl;
        }
        counter++;
    }



    return 0;
}
