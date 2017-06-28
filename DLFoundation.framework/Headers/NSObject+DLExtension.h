//
//  NSObject+DLExtension.h
//  DLUIKit
//
//  Created by limingzou on 2017/6/8.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark -

#undef	DISPOSABLE
#define	DISPOSABLE( __class, __name ) \
__class * __name = [__class disposable]

#pragma mark -

typedef void ( *ImpFuncType )( id a, SEL b, void * c );

@interface NSObject (DLExtension)

+ (instancetype)object;
+ (instancetype)disposable;

- (void)load;
- (void)unload;

- (void)performLoad;
- (void)performUnload;

- (void)performSelectorAlongChain:(SEL)sel;
- (void)performSelectorAlongChainReversed:(SEL)sel;

- (void)copyPropertiesFrom:(id)obj;

- (BOOL)hasOverrideMethod:(SEL)selector ofSuperclass:(Class)superclass;

- (id)performSelectorToSuperclass:(SEL)aSelector;
- (id)performSelectorToSuperclass:(SEL)aSelector withObject:(id)object;

- (void)methodsUsingBlock:(void (^)(SEL selector))block;
+ (void)methodsFromClass:(Class)aClass usingBlock:(void (^)(SEL selector))block;
+ (void)methodsFromProtocol:(Protocol *)protocol usingBlock:(void (^)(SEL selector))block;

+ (id)performBlock:(void (^)(void))block afterDelay:(NSTimeInterval)delay;
+ (id)performBlock:(void (^)(id arg))block withObject:(id)anObject afterDelay:(NSTimeInterval)delay;
- (id)performBlock:(void (^)(void))block afterDelay:(NSTimeInterval)delay;
- (id)performBlock:(void (^)(id arg))block withObject:(id)anObject afterDelay:(NSTimeInterval)delay;

@end

@interface NSObject (DLStuff)

- (id) nextRunloopProxy;
- (id) proxyWithDelay:(float)time;
- (id) performOnMainThreadProxy;

@end
