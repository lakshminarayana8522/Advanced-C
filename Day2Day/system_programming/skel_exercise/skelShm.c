/* Write a multiple concurrent process program that does the following
   1. Displays "ascii modern art" composed of a series of 
      randomly generated blocks of 2 or more repeating characters

   The program should perform this task in the following way:
   1. Create a semaphore set of size 2 -- use IPC_PRIVATE as your key
      a. Initialize the semaphore representing the child to available
      b. Initialize the semaphore representing the parent to in use
   2. Create a segment of shared memory -- use IPC_PRIVATE as your key

   3. Create a child process that:
      a. Attaches the segment of shared memory
      b. Seeds the random number generator 
      c. Reserves the child semaphore
      d. Generates and stores the total number of blocks to generate. 
         This should be between 10 and 20
      c. For each block, generate and store the following values:
         1. The length of the block (i.e. the number of characters to display)
            This should be between 2 and 10
         2. The character that comprises the block.
            This should be between 'a' and 'z'
      d. Release the parent semaphore
      e. Reserve the child semaphore
      f. Detach the shared memory segment
      g. Release the child semaphore

   4. Create a parent process that:
      a. Attaches the segment of shared memory
      b. Seeds the random number generator
      c. Reserve the parent semaphore 
      d. Generate a random width for the ASCII art. 
         This should be between 10 and 15
      e. Using the data stored in the shared memory segment, output an image
         Use the following tips: 
         1. One value stored in the segment should represent the number
            of (length, character) pairings. For each (length, character)
            pairing, you should output length instances of the given 
            character. This means if the pairing was (3, 'b'), you would
            output "bbb".
         2. The random image has basically been encoded use run-length
            encoding (RLE); RLE doesn't including the location of new lines.
            The location of new lines is determined by the random width 
            generated in step d. Each time you output width total characters,
            output a new line.
      f. Release the child semaphore
      g. Reserve the parent semaphore
      h. Detach the shared memory segment

   5. Delete the semaphore
   6. Delete the shared memory
   
   -- You can use/should use the binary semaphore protocol introduced in class
 */

/* Problem 3 -- List the inlcude files you need for this program. */
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<unistd.h>
#include<time.h>

/* Problem 4 -- remember to declare a structure that represents the data
   stored in the shared memory */
typedef struct{
	int length;
	char ch;
}shm_data;


/* Problem 5 -- create a function to handle the code for the child. 
   Be certain to pass this function the id values for both the semaphore 
   and the shared memory segment */
void child_function(int sem_id,int shm_id)
{
	shm_data *addr,*ptr;
	/*! attaching the shared memory to the child process */
	addr = shmat(shm_id,0,0);
	
	/*! seeding random generator */
	srand(time(0));

	struct sembuf v1;

	/*! reserving the child semaphore */
	v1.sem_num = 0;
	v1.sem_op = -1;

	semop(sem_id,&v1,1);
	/*! generating the block size between the range of 10 to 20 */
	int blocks_num = (rand()%(20-10+1))+10;

	int i;
	ptr = addr;
	/*! initializing each block */
	for(i=0;i<blocks_num;i++)
	{
		ptr->length = (rand()%(10-2+1))+2;
		ptr->ch = 'a' + (rand()%26);
		ptr++;
	}
	
	/*! relesing the parent semaphore */
	v1.sem_num = 1;
	v1.sem_op = 1;

	semop(sem_id,&v1,1);
	
	/*! detaching the shared memory */
	shmdt(addr);
	

}


/* Problem 6 -- create a function to handle the code for the parent. 
   Be certain to pass this function the id values for both the semaphore 
   and the shared memory segment */
void parent_function(int sem_id,int shm_id)
{
	shm_data *addr,*ptr;
	/*! attaching the shared memory */
	addr = shmat(shm_id,0,0);
	/*! seeding random generator */
	srand(time(0));

	struct sembuf v1;
	/*! reserving the parent semaphore */
	v1.sem_num = 1;
	v1.sem_op = -1;
	/*! generating random width between the range 10 to 15 */
	int width = (rand()%(15-10+1))+10;

	int i,count = 0;
	ptr = addr;
	
	/*! reading the data from the shared memory and creating modern ascii art */
	while(ptr->length)
	{
		for(i=0;i<ptr->length;i++)
		{
			printf("%c",ptr->ch);
			count++;

			if(count == width)
			{
				printf("\n");
				count = 0;
			}
		}

		ptr++;
	}
	
	/*! releasing child semaphore */
	v1.sem_num = 0;
	v1.sem_op = 1;

	semop(sem_id,&v1,1);
	
	/*! detaching the shared memory */
	shmdt(addr);




}

/* Problem 7 -- implement function main */

int main(int argc, char *argv[])
{
	int sem_id,shm_id;
	/*! creating semaphore set contains 2 semaphores */
	sem_id = semget(IPC_PRIVATE,2,IPC_CREAT|0666);
	perror("semget");
	/*! initializing semaphore represents the child to available */
	semctl(sem_id,0,SETVAL,1);
	perror("semctl");
	/*! initializing semaphore represents the parent in use */
	semctl(sem_id,1,SETVAL,0);
	perror("semctl");
	/*! creating shared memory segmanet of size 300 bytes */
	shm_id = shmget(IPC_PRIVATE,300,IPC_CREAT|0666);
	perror("shmget");

	pid_t pid;
	/*!creating child process */
	pid = fork();

	if(pid==0)
	{	/*! child process */
		child_function(sem_id,shm_id);
	}
	else
	{
		/*! parent process */
		parent_function(sem_id,shm_id);

		/*! deleting the semaphore */
		semctl(sem_id,0,IPC_RMID);
		perror("semctl");
		/*! deleting the shared memory */
		shmctl(shm_id,0,IPC_RMID);
		perror("shmctl");
	}
	return 0;

}
