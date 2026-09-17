#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t m;
void* robot(void* id){
  sem_wait(&m);
  printf("Robot %d charging\n",*(int*)id);
  printf("Robot %d done\n",*(int*)id);
  sem_post(&m);
}

int main(){
  sem_init(&m,0,1);
  pthread_t t[3];
  int id[3] = {1,2,3};

  for(int i=0;i<3;i++)
    pthread_create(&t[i], NULL, robot, &id[i]);

  for(int i=0;i<3;i++)
    pthread_join(t[i], NULL);

  return 0;
}
