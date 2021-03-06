/*
Copyright 2011 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef VUSB_H
#define VUSB_H

#include "host_driver.h"

typedef struct usbDescriptorHeader {
    uchar bLength;
    uchar bDescriptorType;
} __attribute__((packed)) usbDescriptorHeader_t;

typedef struct usbStringDescriptor {
    usbDescriptorHeader_t header;
    int                   bString[];
} __attribute__((packed)) usbStringDescriptor_t;

#define USB_STRING_LEN(s) (sizeof(usbDescriptorHeader_t) + ((s) << 1))

host_driver_t *vusb_driver(void);
void           vusb_transfer_keyboard(void);

#endif
