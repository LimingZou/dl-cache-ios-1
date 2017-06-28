//
//  DLKeychain.h
//  DLCache
//
//  Created by limingzou on 2017/5/18.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import "DLCacheProtocol.h"
#pragma mark -

#define AS_KEYCHAIN( __name )	AS_STATIC_PROPERTY( __name )
#define DEF_KEYCHAIN( __name )	DEF_STATIC_PROPERTY3( __name, @"keychain", [self description] )

#pragma mark -

@interface DLKeychain : NSObject<DLCacheProtocol>

@property (nonatomic, retain) NSString * defaultDomain;

AS_SINGLETON( DLKeychain )

+ (void)setDefaultDomain:(NSString *)domain;

+ (NSString *)readValueForKey:(NSString *)key;
+ (NSString *)readValueForKey:(NSString *)key andDomain:(NSString *)domain;

+ (void)writeValue:(NSString *)value forKey:(NSString *)key;
+ (void)writeValue:(NSString *)value forKey:(NSString *)key andDomain:(NSString *)domain;

+ (void)deleteValueForKey:(NSString *)key;
+ (void)deleteValueForKey:(NSString *)key andDomain:(NSString *)domain;

@end
