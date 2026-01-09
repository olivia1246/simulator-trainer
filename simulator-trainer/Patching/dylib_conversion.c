//
//  dylib_conversion.c
//  simulator-trainer
//
//  Created by m1book on 5/25/25.
//

#include "machoe.h"

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>


bool convert_to_dylib_inplace(const char *input_path) {
    if (input_path == NULL || input_path[0] == '\0') {
        return false;
    }

    struct stat st;
    if (stat(input_path, &st) != 0) {
        return false;
    }

    if (!S_ISREG(st.st_mode)) {
        return false;
    }

    if (access(input_path, R_OK | W_OK) != 0) {
        return false;
    }

    tool_config_t config = {0};
    config.input_path = input_path;
    config.convert_to_dylib = true;

    process_binaries_in_directory(config.input_path, &config);

    return true;
}
