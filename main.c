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
     char * ls = "/.config/justinstall/mgrls.conf";
     char * mgrls = strcat(home, ls);
     char * contents = "testing";
     if (access(mgrls, F_OK) != 0) {
         fptr = fopen(mgrls, "w");
         fprintf(fptr, contents);
     }
    if ((argv[1] = "--add") || (argv[1] = "-a")) {
        //Opens in append mode if mgrs.conf exists, creates mrgs.conf and opens in
        //write mode if not. Fixes blank lines at the beginning of the mgrs.conf
        if (access(mgrsconfig, F_OK) == 0) {
       fptr = fopen(mgrsconfig, "a");
} else {
    fptr = fopen(mgrsconfig, "w");
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
    //else {
        //Get managers from mgrs.conf
        //Find search command in mgrls.conf
        //run search command with system()
        //repeat for each manager
        //let user select numerical option
        //run install command
    //}
    return 0;
  }
  
