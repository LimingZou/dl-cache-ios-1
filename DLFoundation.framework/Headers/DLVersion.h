//
//  DLVersion.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/15.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLVersion : NSObject
{
@protected   // all instance variables are private
    NSUInteger _major;
    NSUInteger _minor;
    NSUInteger _maintenance;
    NSUInteger _build;
}
@property (nonatomic, readonly) NSUInteger major;
@property (nonatomic, readonly) NSUInteger minor;
@property (nonatomic, readonly) NSUInteger maintenance;
@property (nonatomic, readonly) NSUInteger build;

- (DLVersion *)major:(NSUInteger)major minor:(NSUInteger)minor maintenance:(NSUInteger)maintenance;
- (DLVersion *)major:(NSUInteger)major minor:(NSUInteger)minor maintenance:(NSUInteger)maintenance build:(NSUInteger)build;
+ (DLVersion *)version:(NSString *)other;
+ (DLVersion *)appVersion;
+ (DLVersion *)appShortVersion;

+ (BOOL)isLessThen:(NSString *)other;
+ (BOOL)isGreaterThen:(NSString *)other;
- (BOOL)lessThenVersion:(DLVersion *)version;
- (BOOL)greaterThenVersion:(DLVersion *)version;
- (BOOL)lessThenVersionString:(NSString *)other;
- (BOOL)greaterThenVersionString:(NSString *)other;
- (BOOL)equalToVersion:(DLVersion *)version;
- (BOOL)equalToString:(NSString *)other;
- (BOOL)equal:(id)obj;

@end
