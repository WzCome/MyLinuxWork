#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <wait.h>
#include <string.h>
#include <pthread.h>
#include <limits.h>
struct sendval{
   int n;
   int s;
};
#define NUM 4
