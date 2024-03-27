#include <Foundation/Foundation.h>
#include <AppKit/AppKit.h>
#include <iostream>

void CopyToClipboard(const std::string& text) {
    @autoreleasepool {
        // Access the general pasteboard
        NSPasteboard *pasteboard = [NSPasteboard generalPasteboard];

        // Clear the pasteboard contents
        [pasteboard clearContents];

        // Create an NSString object
        NSString *nsString = [NSString stringWithUTF8String:text.c_str()];

        // Copy the text to the clipboard
        [pasteboard setString:nsString forType:NSPasteboardTypeString];
        
        std::cout << "\e[0;32m" << "Text copied to clipboard." << "\e[0m" << std::endl;
    }
}
