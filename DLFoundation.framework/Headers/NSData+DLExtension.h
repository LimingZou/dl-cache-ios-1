//
//  NSData+DLExtension.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (DLExtension)

@property (nonatomic, readonly) NSData *	MD5;
@property (nonatomic, readonly) NSString *	MD5String;

+ (NSString *)fromResource:(NSString *)resName;

@end
