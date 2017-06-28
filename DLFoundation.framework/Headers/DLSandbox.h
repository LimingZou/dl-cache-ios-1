//
//  DLSandbox.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DLFoundation/DLSingleton.h>

@interface DLSandbox : NSObject

@property (nonatomic, readonly) NSString *	appPath;
@property (nonatomic, readonly) NSString *	docPath;
@property (nonatomic, readonly) NSString *	libPrefPath;
@property (nonatomic, readonly) NSString *	libCachePath;
@property (nonatomic, readonly) NSString *	tmpPath;

AS_SINGLETON( DLSandbox )

+ (NSString *)appPath;
+ (NSString *)docPath;
+ (NSString *)libPrefPath;
+ (NSString *)libCachePath;
+ (NSString *)tmpPath;

+ (BOOL)remove:(NSString *)path;
+ (BOOL)touch:(NSString *)path;
+ (BOOL)touchFile:(NSString *)file;

@end
