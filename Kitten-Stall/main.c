#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void print_usage(void) {
  fprintf(stderr, "Pass -a to add.\n");
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    print_usage();
    return 1;
  }
  if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
    print_usage();
    return 0;
  }
  
  //creating the variable that points to the config file. Done this way because 
  //every other methood I tried didn't work. I know it's probably bad, but I spent
  //way too long figuring this out to care. If it ain't broke...
  char const* const home = getenv("HOME");
  char const config[] = "/.config/kittenstall/mgrs.conf";
  
  // build concatenated full path to config.
  char* const mgrs_config = malloc(strlen(home) + strlen(config) + 1);
  strcpy(mgrs_config, home);
  strcat(mgrs_config, config);
  
  if (strcmp(argv[1], "--add") == 0 || strcmp(argv[1], "-a") == 0) {
    //Opens in append mode if mgrs.conf exists, creates mrgs.conf and opens in
    //write mode if not. Fixes blank lines at the beginning of the mgrs.conf
    
    FILE* const fptr = fopen(mgrs_config, access(mgrs_config, R_OK | W_OK) == 0 ? "a" : "w");
    
    if (fptr == NULL) {
      fprintf(stderr, "opening %s failed.\n", mgrs_config);
      return 2;
    }
    for (int i = 2; i < argc; i++) {
      fprintf(fptr, "%s\n", argv[i]);
    }
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
  
