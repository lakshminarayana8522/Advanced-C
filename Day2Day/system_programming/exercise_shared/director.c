#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<time.h>

typedef struct{
	int action;
	int data1;
	int data2;
}shm_data;

int main()
{
	int shm_id,sem_id;

	shm_id = shmget(10,300,IPC_CREAT|0666);
	perror("shmget");

	sem_id = semget(12,2,IPC_CREAT|0666);
	perror("semget");

	shm_data *addr,*ptr;

	addr = shmat(shm_id,0,0);
	perror("shmat");

	semctl(sem_id,0,SETVAL,0);
	perror("semctl");

	semctl(sem_id,1,SETVAL,0);
	perror("semctl");

	srand(time(0));

	int reqs = (rand()%(20-2+1))+2;
	printf("requests: %d\n",reqs);
	int i;
	ptr = addr;
	struct sembuf v1;
	for(i=0;i<reqs;i++)
	{
		ptr->action = rand()%6;
		ptr->data1 = (rand()%(100+100+1))-100;
		ptr->data2 = (rand()%(100+100+1))-100;
		
		v1.sem_num = 0;
		v1.sem_op = 1;

		semop(sem_id,&v1,1);

		v1.sem_num = 1;
		v1.sem_op = -1;

		semop(sem_id,&v1,1);

	}

	ptr->action = 0;
/*	v1.sem_num = 0;
	v1.sem_op = 1;

	semop(sem_id,&v1,1);
*/

	shmdt(addr);
	perror("shmdt");

	shmctl(shm_id,0,IPC_RMID);
	perror("shmctl");

	semctl(sem_id,0,IPC_RMID);
	perror("semctl");



	return 0;
}



