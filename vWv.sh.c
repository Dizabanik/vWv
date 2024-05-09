#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fiss.h"
int vWv_run(int argc, char** argv){
	FILE *fp;
	size_t cur_size = 1024;
	fiss_disable(time);
    char* path = malloc(cur_size * sizeof(char)); // Start with a single character
	if(argc < 2) {
		fiss_error("Not enough arguments");
		fiss_info("Usage", "%s", "vWv [link]", "\n\tFor example", "\'vWv https://0x0.st/\'");
		return 1;
	}
    if (path == NULL) {
        fiss_fatal("vWv: Memory allocation failed\n");
        return 1;
    }
	if(strcmp(argv[1], "fiss") == 0 || strcmp(argv[1], "fissure") == 0){
		fiss_info("Downloading fissure...");
		char* argk = malloc(sizeof("https://raw.githubusercontent.com/Dizabanik/diz_install_shell_scripts/main/fissure.sh")+1);
		strcpy(argk,"https://raw.githubusercontent.com/Dizabanik/diz_install_shell_scripts/main/fissure.sh");
		argv[1] = argk;
		if(vWv_run(2, argv) == 0){
			fiss_info("Fissure installation successful!");
			return 0;
		}
		else{
			fiss_error("Fissure installation error");
			return 1;
		}
		
	}
    /* Open the command for reading. */
    char* command = malloc((strlen(argv[1]) + sizeof("wget -q -O -") + 1) * sizeof(char));
    strcpy(command, "wget ");
    strcat(command, argv[1]);
    strcat(command, " -q -O -");
    fp = popen(command, "r");
    free(command);

    if (fp == NULL) {
        fiss_error("vWv: Failed to run wget\n");
		fiss_info("vWv: check for a wget installation");
        return 1;
    }

    /* Read the output dynamically - output it. */
    size_t path_size = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
		if((path_size+2) > cur_size){
			if(cur_size < 10000) cur_size *= 2;
			else { cur_size = path_size + 128;}
			path = realloc(path, cur_size * sizeof(char)); // Allocate space for one more character an null
			
		}
        path[path_size++] = c;
        path[path_size] = '\0'; // Null-terminate the string
    }
	execl("/bin/sh", "/bin/sh", "-c", path, 0);	
    /* Close */
    pclose(fp);
    free(path);

    return 0;

}
int main(int argc, char** argv) {
	return vWv_run(argc, argv);    
}
