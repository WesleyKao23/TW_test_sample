#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>

pthread_mutex_t glock;
pthread_cond_t gcond;

void *release(void *tmp) {
	pthread_cond_signal(&gcond);
	pthread_cond_signal(&gcond);
}

void *test(void *tmp) {
	pthread_mutex_lock(&glock);
	printf("%s main lock getpid:%d\n", __TIME__, /*syscall(SYS_gettid)*/getpid());
	printf("%s main lock syscall(SYS_gettid):%ld\n", __TIME__, syscall(SYS_gettid));
	printf("%s main lock pthread_self:%lu\n", __TIME__, /*syscall(SYS_gettid)*/pthread_self());
	//printf("%s cond:%p\n", __TIME__, &gcond);
	//pthread_cond_wait(&gcond, &glock);
	//printf("%s signaled %d\n", __TIME__, syscall(SYS_gettid));
	pthread_mutex_unlock(&glock);
}

int main() {
	pthread_t pid_1, pid_2, pid_3;
	printf("Wez : E\n");
		
	pthread_mutex_init(&glock, NULL);
	//pthread_cond_init(&gcond, NULL);

	pthread_create(&pid_1, NULL, &test, NULL);
	pthread_create(&pid_2, NULL, &test, NULL);
	//sleep(3);
	//pthread_create(&pid_3, NULL, &release, NULL);
	//printf("%s\n", __TIME__);
	sleep (3);
	//pthread_join(pid_1, NULL);
	//pthread_join(pid_2, NULL);

	printf("Wez : X\n");

 	return 0;
}
	
