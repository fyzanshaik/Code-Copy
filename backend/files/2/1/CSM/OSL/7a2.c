#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#define SIZE 128
typedef struct msgbuf {
    long mtype;
    char mtext[SIZE];
} message_buf;


int main() {
    int msqid;
    key_t key;
    message_buf rbuf;
    key = 1234;
    if ((msqid = msgget(key, 0666)) < 0) {
        printf("msgget- can not open Message Queue");
        exit(1);
    }

    if (msgrcv(msqid, &rbuf, SIZE, 1, 0) < 0) {
        printf("msgrcv- error in recieving");
        exit(1);
    }
    printf("\n Message Recievied From the Queue %s \n", rbuf.mtext);
    exit(0);
}