#include <stdio.h>
#include <stdlib.h>

int main(void)
{
     fork();
     fork();
     fork();
     system("ps -l --forest -C fr");
     exit(0);
}


/*

F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000  4788  4734  0  80   0 -   502 wait   pts/1    00:00:00 fr
1 S  1000  4789  4788  0  80   0 -   502 wait   pts/1    00:00:00  \_ fr
1 S  1000  4791  4789  0  80   0 -   502 wait   pts/1    00:00:00  |   \_ fr
1 S  1000  4797  4791  0  80   0 -   502 wait   pts/1    00:00:00  |   |   \_ fr
1 S  1000  4792  4789  0  80   0 -   502 wait   pts/1    00:00:00  |   \_ fr
1 S  1000  4790  4788  0  80   0 -   502 wait   pts/1    00:00:00  \_ fr
1 S  1000  4795  4790  0  80   0 -   502 wait   pts/1    00:00:00  |   \_ fr
1 S  1000  4793  4788  0  80   0 -   502 wait   pts/1    00:00:00  \_ fr


*/
