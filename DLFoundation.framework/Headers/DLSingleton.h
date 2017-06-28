//
//  DLSingleton.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/11.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>
#pragma mark -

#if __has_feature(objc_instancetype)

#undef	AS_SINGLETON
#define AS_SINGLETON

#undef	AS_SINGLETON
#define AS_SINGLETON( ... ) \
- (instancetype)sharedInstance; \
+ (instancetype)sharedInstance;

#undef	DEF_SINGLETON
#define DEF_SINGLETON \
- (instancetype)sharedInstance \
{ \
return [[self class] sharedInstance]; \
} \
+ (instancetype)sharedInstance \
{ \
static dispatch_once_t once; \
static id __singleton__; \
dispatch_once( &once, ^{ __singleton__ = [[self alloc] init]; } ); \
return __singleton__; \
}

#undef	DEF_SINGLETON
#define DEF_SINGLETON( ... ) \
- (instancetype)sharedInstance \
{ \
return [[self class] sharedInstance]; \
} \
+ (instancetype)sharedInstance \
{ \
static dispatch_once_t once; \
static id __singleton__; \
dispatch_once( &once, ^{ __singleton__ = [[self alloc] init]; } ); \
return __singleton__; \
}

#else	// #if __has_feature(objc_instancetype)

#undef	AS_SINGLETON
#define AS_SINGLETON( __class ) \
- (__class *)sharedInstance; \
+ (__class *)sharedInstance;

#undef	DEF_SINGLETON
#define DEF_SINGLETON( __class ) \
- (__class *)sharedInstance \
{ \
return [__class sharedInstance]; \
} \
+ (__class *)sharedInstance \
{ \
static dispatch_once_t once; \
static __class * __singleton__; \
dispatch_once( &once, ^{ __singleton__ = [[[self class] alloc] init]; } ); \
return __singleton__; \
}

#endif	// #if __has_feature(objc_instancetype)

#undef	DEF_SINGLETON_AUTOLOAD
#define DEF_SINGLETON_AUTOLOAD( __class ) \
DEF_SINGLETON( __class ) \
+ (void)load \
{ \
[self sharedInstance]; \
}

#pragma mark -
