//
//  platform_changer.m
//  simforge
//
//  Created by Ethan Arbuckle on 1/18/25.
//

#import <Foundation/Foundation.h>
#include "machoe.h"


bool convert_to_simulator_platform(const char *input_path) {
    if (input_path == NULL || input_path[0] == '\0') {
        return false;
    }

    tool_config_t config = {0};
    config.input_path = input_path;
    config.recursive = true;
    config.modify_platform = true;
    if (!platform_name_to_id("ios-simulator", &config.target_platform) || !parse_version("15.0", &config.target_minos) || !parse_version("15.0", &config.target_sdk)) {
        return false;
    }
    
    process_binaries_in_directory(config.input_path, &config);
    
    return true;
}
