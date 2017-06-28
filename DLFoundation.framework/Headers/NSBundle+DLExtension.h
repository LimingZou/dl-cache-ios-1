//
//  NSBundle+DLExtension.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface NSBundle (DLExtension)

@property (nonatomic, readonly) NSString *fullPath;
@property (nonatomic, readonly) NSString *pathName;

- (NSData *)data:(NSString *)resName;
- (NSString *)string:(NSString *)resName;

@end
