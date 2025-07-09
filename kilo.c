/*** Includes ***/
#include <ctype.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

/*** Defines ***/

#define CTRL_KEY(k) ((k) & 0x1f)

/*** Data ***/

struct termios orig_termios;

/*** Terminal ***/

    // Error Handling
void die(char* s) {
    perror(s);
    exit(1);
}

    // Turn Off Echo, Canonical Mode, & Other Flags
void disableRawMode() {
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1) {
        die("tcsetattr");
    }
}
void enableRowMode() {
    if(tcgetattr(STDIN_FILENO, &orig_termios) ==-1) {
        die("tcgetattr");
    }
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
        die("tcsetattr");
    }
}

/*** Init ***/

int main() {
    enableRowMode();

    while(1) {
        char c = '\0';
        if(read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN){
            die("read");
        }
        if(iscntrl(c)) {
            printf("%d\r\n",c);
        }
        else {
            printf("%d ('%c')\r\n",c,c);
        }
        if(c == CTRL_KEY('q')) break;
    }
    return 0;
}

// Resume: Error handling (step _) 