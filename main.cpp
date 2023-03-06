//Задача №2 Преобразовать матрицу, умножив элементы каждой строки на значение второго элемента этой строки.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

int main(){
    const int nrows = 3;
    const int ncols = 3;
    srand(double(time(NULL)));

    std::array<std::array<int, ncols>, nrows> mat;
    
    for (int i = 0; i < nrows; i++){
        for (int j = 0; j < ncols; j++){
            mat[i][j] = rand() % 100;
            std::cout << mat[i][j] << "  ";
        }
        std::cout << "\n";
    }
    
    std::cout << "\n";
    
    for (int i = 0; i < nrows; i++){
        for (int j = 0; j < ncols; j++){
            mat[i][j] *= mat[i][1];
            std::cout << mat[i][j] << "  ";
        }
        std::cout << "\n";
    }
    
    return 0;
}

//Задача №4 В квадратной матрице найти сумму положительных элементов, лежащих на и выше главной диагонали и расположенных в чётных столбцах

#include <iostream>
#include <array>
#include <stdlib.h>
#include <ctime>

int main(){
    const int nrows = 4;
    const int ncols = 4;
    srand(double(time(NULL)));
    int summ = 0;
    
    std::array<std::array<int, ncols>, nrows> mat;
    
    for (int i = 0; i < nrows; i++){
        for (int j = 0; j < ncols; j++){
            mat[i][j] = rand() % 200 - 100;
            std::cout << mat[i][j] << "  ";
        }
        std::cout << "\n";
    }
    
    std::cout << "\n";
    
    for (int i = 0; i < nrows; i++){
        for (int j = i; j < ncols; j++){ // просматриваем элементы на и выше главной оси
            if (j % 2 == 0 && mat[i][j] > 0){ // проверяем, что столбец четный и число положительное
                summ += mat[i][j];
            }
        }
    }
    std::cout << summ;
    
    return 0;
}

//Задача №7. Дана матрица. Элементы первой строки — количество осадков в соответствующий
//день, второй строки — сила ветра в этот день. Найти, был ли в эти дни ураган?
//(ураган — когда самый сильный ветер был в самый дождливый день).

#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cmath>

int main (){
    const int days = 7;
    const int sizeMatrix = 2;
    const int Min_Value = -5;
    const int Max_Value = 5;
    
    srand(double(time(NULL)));
    std::array<std::array<int, days>, sizeMatrix> matrix;
    for(int i = 0; i < sizeMatrix; i++){
        for(int j = 0; j < days ; j++){
            matrix[i][j]= Max_Value + rand() % (Max_Value - Min_Value + 1);
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    
    int Max_Rain = days;
    int Max_Wind = sizeMatrix;
    int max_Rian_index = -1;
    
    for(int i = 0; i < days; i++){
        int Wind = matrix[1][i];
        int Rain = matrix[i][0];
        
        if(Wind > Max_Wind){
            Max_Wind = Max_Rain;
            Max_Rain = Rain;
            max_Rian_index = i;
        }else if(Wind == Max_Wind && Rain > Max_Rain){
            Max_Rain = Rain;
            max_Rian_index = i;
        }
    }
    
    std::cout<<"Ураган был в день "<< max_Rian_index<<std::endl;
    
    
}

//Задача №9(b) Объявить, реализовать заполнение данными с клавиатуры ИЛИ из файла и вывести
//на экран матрицу, описывающую следующие сущности. Предложите свой вариант.
//Состояние робота на шахматной доске. Робот характеризуется уровнем заряда, скоростью движения.

#include<iostream>
#include<array>
#include<ctime>

struct Robot
{
    int power;
    int speed;
};

const int lines = 3;
const int colums = 3;

void func(std::array<std::array<Robot,colums>,lines> dask)
{
    for(int i=0;i<lines;i++)
    {
        for(int j=0;j<colums;j++)
        {
            std::cout<<dask[j][i].power<<";"<<dask[j][i].speed<<" ";
        }
        std::cout<<std::endl;
    }
}

int main(){
    std::array<std::array<Robot,colums>,lines> dask;
    for(int i=0;i<lines;i++)
    {
        for(int j=0;j<colums;j++)
        {
            std::cout<<"Power: ";
            std::cin>>dask[j][i].power;
            std::cout<<"Speed: ";
            std::cin>>dask[j][i].speed;
        }
    }
    std::cout<<std::endl;
    func(dask);
    return 0;
}
