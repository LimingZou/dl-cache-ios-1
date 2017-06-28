//
//  DLRuntime.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/11.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DLFoundation/NSObject+DLProperty.h>
#import <DLFoundation/DLSingleton.h>
#import <DLFoundation/DLMacros.h>
#import <objc/runtime.h>


#pragma mark -

#undef	PRINT_CALLSTACK
#define PRINT_CALLSTACK( __n )	[DLRuntime printCallstack:__n]

#undef	BREAK_POINT
#define BREAK_POINT()			[DLRuntime breakPoint];

#undef	BREAK_POINT_IF
#define BREAK_POINT_IF( __x )	if ( __x ) { [DLRuntime breakPoint]; }

#undef	BB
#define BB						[DLRuntime breakPoint];

#pragma mark -

DL_STATIC_INLINE void ReplaceMethod(Class _class, SEL _originSelector, SEL _newSelector) {
    Method oriMethod = class_getInstanceMethod(_class, _originSelector);
    Method newMethod = class_getInstanceMethod(_class, _newSelector);
    BOOL isAddedMethod = class_addMethod(_class, _originSelector, method_getImplementation(newMethod), method_getTypeEncoding(newMethod));
    if (isAddedMethod) {
        class_replaceMethod(_class, _newSelector, method_getImplementation(oriMethod), method_getTypeEncoding(oriMethod));
    } else {
        method_exchangeImplementations(oriMethod, newMethod);
    }
}

#pragma mark -

@interface DLTypeEncoding : NSObject

AS_INT( UNKNOWN )
AS_INT( OBJECT )
AS_INT( NSNUMBER )
AS_INT( NSSTRING )
AS_INT( NSARRAY )
AS_INT( NSDICTIONARY )
AS_INT( NSDATE )

+ (BOOL)isReadOnly:(const char *)attr;

+ (NSUInteger)typeOf:(const char *)attr;
+ (NSUInteger)typeOfAttribute:(const char *)attr;
+ (NSUInteger)typeOfObject:(id)obj;

+ (NSString *)classNameOf:(const char *)attr;
+ (NSString *)classNameOfAttribute:(const char *)attr;

+ (Class)classOfAttribute:(const char *)attr;

+ (BOOL)isAtomClass:(Class)clazz;

@end

#pragma mark -

@interface DLCallFrame : NSObject

AS_INT( TYPE_UNKNOWN )
AS_INT( TYPE_OBJC )
AS_INT( TYPE_NATIVEC )

@property (nonatomic, assign) NSUInteger	type;
@property (nonatomic, retain) NSString *	process;
@property (nonatomic, assign) NSUInteger	entry;
@property (nonatomic, assign) NSUInteger	offset;
@property (nonatomic, retain) NSString *	clazz;
@property (nonatomic, retain) NSString *	method;

+ (id)parse:(NSString *)line;
+ (id)unknown;

@end

#pragma mark -

@interface DLRuntime : NSObject

@property (nonatomic, readonly) NSArray *	allClasses;
@property (nonatomic, readonly) NSArray *	callstack;
@property (nonatomic, readonly) NSArray *	callframes;

AS_SINGLETON( DLRuntime )

+ (id)allocByClass:(Class)clazz;
+ (id)allocByClassName:(NSString *)clazzName;

+ (NSArray *)allClasses;
+ (NSArray *)allSubClassesOf:(Class)clazz;

+ (NSArray *)allInstanceMethodsOf:(Class)clazz;
+ (NSArray *)allInstanceMethodsOf:(Class)clazz withPrefix:(NSString *)prefix;

+ (NSArray *)callstack:(NSUInteger)depth;
+ (NSArray *)callframes:(NSUInteger)depth;

+ (void)printCallstack:(NSUInteger)depth;
+ (void)breakPoint;

@end
