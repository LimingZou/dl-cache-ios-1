//
//  DLMacros.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/24.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#ifndef DLMacros_h
#define DLMacros_h

#import <Foundation/Foundation.h>

#ifdef __cplusplus
#define DL_EXTERN extern "C" __attribute__((visibility ("default")))
#else
#define DL_EXTERN extern __attribute__((visibility ("default")))
#endif

#define DL_STATIC_INLINE static inline

#define DL_NO_DESIGNATED_INITIALIZER() \
@throw [NSException exceptionWithName:NSInvalidArgumentException \
reason:[NSString stringWithFormat:@"unrecognized selector sent to instance %p", self] \
userInfo:nil]

#define DL_NOT_DESIGNATED_INITIALIZER(DESIGNATED_INITIALIZER) \
@throw [NSException exceptionWithName:NSInvalidArgumentException \
reason:[NSString stringWithFormat:@"Please use the designated initializer [%p %@]", \
self, \
NSStringFromSelector(@selector(DESIGNATED_INITIALIZER))] \
userInfo:nil]

#endif /* DLMacros_h */
