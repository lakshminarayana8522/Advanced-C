
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<unistd.h>

typedef struct{
	int action;
	int data1;
	int data2;
}shm_data;


int main()
{
	int shm_id,sem_id;

	shm_id = shmget(10,100,IPC_CREAT|0666);
	perror("shmget");

	sem_id = semget(12,2,IPC_CREAT|0666);
	perror("semget");

	shm_data *addr,*ptr;

	addr = shmat(shm_id,0,0);
	perror("shmat");

	shmctl(shm_id,0,IPC_RMID);
	semctl(sem_id,0,IPC_RMID);




	int i;

	ptr = addr;
	struct sembuf v1;
	v1.sem_num = 0;
	v1.sem_op = -1;
	semop(sem_id,&v1,1);
	while(ptr->action){
	
		printf("data recevied...\n");
		printf("action: %d\n",ptr->action);
		printf("data1: %d\n",ptr->data1);
		printf("data2: %d\n",ptr->data2);

		v1.sem_num = 1;
		v1.sem_op = 1;

		semop(sem_id,&v1,1);

		v1.sem_num = 0;
		v1.sem_op = -1;

		semop(sem_id,&v1,1);

	}

	v1.sem_num = 1;
	v1.sem_op = 1;

	semop(sem_id,&v1,1);



	shmdt(addr);
	perror("shmdt");


	return 0;

}


	

