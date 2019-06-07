#include "pch.h"
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <ctime>

	
using namespace std;
	int mas[9] = { 1,2,3,4,5,6,7,8,9 };
	int A = 1, B = 2, C = 3;
	int i, j, p = 2;

	int main()
	{
		setlocale(LC_ALL, "Russian");
		setlocale(LC_ALL, "rus");

		MPI_Init(0, 0); //инициализация MPI
		int rank, size; //узнаем ранг каждого процесса и их общее число
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		MPI_Comm_size(MPI_COMM_WORLD, &size);

		if (rank == 0)
		{
			cout << "Rabota zavershena";
		}

		srand(time(NULL) * rank);
		int q = 2, w = 3;
			int i, proizv = 1;

			int tru = 0;
			if (rank != 0)
			{
				int x = 0;
				int ind = rank - 1;
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						for (int k = ind; k < 9; k = k + size)
						{
							for (int z = 0; z < 9; z++)
							{
								if (mas[i] == A * mas[j] + B * mas[k] + C * mas[z])
								{					
									cout << "Process number: " << ind << ". Troika, pri kotoroy vipolnyaetsya ravenstvo:\n" << mas[i] << mas[j] << mas[k] << mas[z] << "\n";
									printf("%d = %d %d %d \n", mas[i], mas[j], mas[k], mas[z]);		

								}
							}
						}
					}
				}
			}

			MPI_Finalize(); 
			return 1;
		}

