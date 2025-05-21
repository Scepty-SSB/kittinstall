#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct manager {
	const char* name;
	const char* search;
	const char* install;
	_Bool enabled;
};

struct pkg {
	char* name;
	char* hostManager;
};

struct manager managerList[3] = {
	{"apt", "apt-cache search", "apt install", true},
	{"yay", "yay -s", "yay -S", false},
	{"flatpak", "flatpak search", "flatpak install", true},
};

void print_usage(void) {
	fprintf(stderr, "Pass -a to add.\n");
}

/// Given an array of statically-known size N, expands to a constant N.
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

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
	else {
		printf("Enter the number of matches from each repository to list (0 to cancel)\n");
		int matches;
		scanf("%d", &matches);
		if (matches == 0) {
			printf("Program terminated by user");
			return 0;
		}
		else {
			printf("%d\n", matches);
		}
    //pointer arithmetic to get size of managerList[] because the size of elements 
    //varies depending on the manager's name and specific commands
    //I'll improve this at some point
		for (int i = 0; i < ARRAY_SIZE(managerList); i++) {
			//this is a placeholder
			printf ("%s, %s, %s, %s\n", managerList[i].name, managerList[i].search,
			        managerList[i].install, managerList[i].enabled?"true":"false");
    }


	// using scanf() to select a package number
	int pkgID;
      scanf("%d", &pkgID);
      if (pkgID == 0) {
          printf("Program terminated by user");
          return 0;
      }
		else {
		//4 is a place holder. It will eventually be replaced by the number of matches to list
		//(defined in .config) times the number of enabled package managers
		struct pkg packageList[4];

		//Placeholder, will fix
		// char* installCommand = malloc(strlen());
		}
    //wasn't sure this would work tbh
    //I plan to check for if the package manager exists in $PATH rather than
    //needing mgrs.conf at all
		char * path = getenv("PATH");
		printf("%s\n", path);
	}
	return 0;
}

