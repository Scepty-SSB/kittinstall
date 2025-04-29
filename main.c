#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    FILE *fptr;
    //creating the variable that points to the config file. Done this way because 
    //every other methood I tried didn't work. I know it's probably bad, but I spent
    //way too long figuring this out to care. If it ain't broke...
     char * home = getenv("HOME");
     char * config = "/.config/justinstall/mgrs.conf";
     char * mgrsconfig = strcat(home, config);
    if ((argv[1] = "--add") || (argv[1] = "-a")) {

        //Opens in append mode if mgrs.conf exists, creates mrgs.conf and opens in
        //write mode if not. Fixes blank lines at the beginning of the mgrs.conf
        if (access(fname, F_OK) == 0) {
       fptr = fopen(mgrsconfig, "a");
} else {
    fptr = fopen(mgrsconfig, "w")
}
       for (int i = 2; i<=argc; i++) {
       fprintf(fptr, argv[i]);
       if (i != argc){
        fprintf(fptr, "\n");
       }
       }
       // Close the file
       fclose(fptr);
    } 
    else {
        //read each line of mgrsconfig, lookup the relevant search command, and run it
        //with system()
    }
    return 0;
  }
  
