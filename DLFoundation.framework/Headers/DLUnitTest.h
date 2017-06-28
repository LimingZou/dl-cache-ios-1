//
//  DLUnitTest.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DLFoundation/DLLog.h>

#undef	TEST_CASE
#define	TEST_CASE( __name ) \
@interface TestCase__##__name : DLTestCase \
@end \
@implementation TestCase__##__name \
+ (NSString *)name { return [NSString stringWithUTF8String:#__name]; } \
+ (const char *)file { return __FILE__; } \
+ (unsigned int)line { return __LINE__; } \
+ (BOOL)runTests { \
NSAutoreleasePool * __testReleasePool = [[NSAutoreleasePool alloc] init]; \
BOOL __testCasePassed = YES; \
@try {

#undef	TEST_CASE_END
#define	TEST_CASE_END \
} \
@catch ( NSException * e ) { \
ERROR( [NSString stringWithFormat:@"%@\n%@", e.reason, e.callStackSymbols] ); \
__testCasePassed = NO; \
} \
@finally { \
} \
[__testReleasePool release]; \
return __testCasePassed; \
} \
@end

#undef	HERE
#define HERE( __x, __run ) \
__run

#undef	EXPECTED
#define EXPECTED( __condition ) \
if ( NO == (__condition) ) { \
@throw [NSException exceptionWithName:@"" \
reason:[NSString stringWithFormat:@"<%s> @ <%s(#%u)>", #__condition, __FILE__, __LINE__] \
userInfo:nil]; \
}

#undef	TIMES
#define TIMES( __n ) \
for ( int __i_##__LINE__ = 0; __i_##__LINE__ < __n; ++__i_##__LINE__ )


#pragma mark -

@interface DLTestCase : NSObject
+ (BOOL)runTests;
@end

#pragma mark -

@interface DLUnitTest : NSObject
+ (NSUInteger)failedCount;
+ (NSUInteger)succeedCount;
+ (BOOL)runTests;
@end

