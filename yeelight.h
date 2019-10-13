#include <ntsid.h>

#ifndef YEELIGHT_IO_C_YEELIGHT_H
#define YEELIGHT_IO_C_YEELIGHT_H

#include <stdio.h>
#include <stdint.h>

int command(const char *ip, const char *command, size_t commandLen);

/**
 * Toggle a Yeelight bulb
 * @param ip IP Address of Yeelight bulb
 * @return 0 if success else failed
 */
int __unused toggle(const char *ip);

/**
 * Turn on a Yeelight bulb
 * @param ip IP Address of Yeelight bulb
 * @return 0 if success else failed
 */
int on(const char *ip);

/**
 * Turn off a Yeelight bulb
 * @param ip IP Address of Yeelight bulb
 * @return 0 if success else failed
 */
int off(const char *ip);

/**
 * Change brightness of Yeelight bulb
 * @param ip IP Address of Yeelight bulb
 * @param level brightness level, 0 ~ 100
 * @return 0 if success else failed
 */
int brightness(const char *ip, uint8_t level);

/**
 * Change color of Yeelight bulb
 * @param ip IP Address of Yeelight bulb
 * @param r red in RGB, 0 ~ 255
 * @param g green in RGB, 0 ~ 255
 * @param b blue in RGB, 0 ~ 255
 * @return 0 if success else failed
 */
int color(const char *ip, uint8_t r, uint8_t g, uint8_t b);


#endif //YEELIGHT_IO_C_YEELIGHT_H
