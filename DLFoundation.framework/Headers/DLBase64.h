//
//  DLBase64.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/24.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLBase64 : NSObject

+ (NSData *)decodeAsData:(NSString *)string;
+ (NSString *)decodeAsString:(NSString *)string;
+ (NSString *)encodeData:(NSData *)data;
+ (NSString *)encodeString:(NSString *)string;

@end
