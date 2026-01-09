//
//  platform_changer.h
//  simforge
//
//  Created by Ethan Arbuckle on 1/18/25.
//

#import <Foundation/Foundation.h>

/**
  * Add the Simulator platform tag (7) into binaries within a bundle/directory
  * @param dirpath The path to the bundle/directory
 */
bool convert_to_simulator_platform(const char *input_path);
